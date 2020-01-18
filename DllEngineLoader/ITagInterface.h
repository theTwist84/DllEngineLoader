#pragma once

struct IDatumHandle
{
	UINT16 m_Index;
	UINT16 m_Salt;

	IDatumHandle(UINT32 value)
	{
		m_Salt = (UINT16)((value >> 16) & 0xFFFF);
		m_Index = (UINT16)(value & 0xFFFF);
	}

	UINT32 AsU32()
	{
		UINT16 value[2];

		value[0] = m_Index;
		value[1] = m_Salt;

		return *reinterpret_cast<UINT32 *>(value);
	}

	INT32 AsI32()
	{
		INT16 value[2];

		value[0] = m_Index;
		value[1] = m_Salt;

		return *reinterpret_cast<INT32 *>(value);
	}
};

struct IGlobalTagInstance
{
	UINT32       m_GroupTag = 'null';
	IDatumHandle m_DatumHandle = IDatumHandle(0xFFFFFFFF);

	IGlobalTagInstance(UINT32 groupTag, IDatumHandle datumHandle)
	{
		m_GroupTag = groupTag;
		m_DatumHandle = datumHandle;
	}
};

struct ITagInstance
{
	INT16  m_GroupIndex;
	UINT16 m_Identifier;
	UINT32 m_Address;
};

struct ITagBlock
{
	INT32  m_Count;
	UINT32 m_Address;
	UINT32 m_DefinitionAddress;
};

template<typename T>
struct ITagSection
{
	INT32  m_Count;
	UINT32 m_PostCountSignature;
	T     *m_Instances;
};

struct ITagInfo
{
	IDatumHandle Handle;
	char         Name[MAX_PATH];
	char         Group[5];
	char         GroupName[65];

	ITagInfo() : Handle(0xFFFFFFFF), Name("null_tag_name"), Group("null"), GroupName("null_tag_group")
	{
	}

	ITagInfo(UINT32 datumIndex, LPCSTR pName, LPCSTR pGroup, LPCSTR pGroupName) : Handle(datumIndex)
	{
		strcpy_s(Name, sizeof(Name), pName);
		strcpy_s(Group, sizeof(Group), pGroup);
		strcpy_s(GroupName, sizeof(GroupName), pGroupName);
	}
};

class ITagInterface
{
public:
	ITagInterface();
	~ITagInterface();

	static void         SetCacheFilePointerOffset(size_t cacheFilePointerOffset);
	static void         SetTagInstancesOffset(size_t tagInstancesOffset);
	static void         SetTagAddressTableOffset(size_t tagAddressTableOffset);

	template<typename T = char *>
	static T            GetHeader(size_t offset = 0);
	static std::string  GetCacheName();
	static IDatumHandle GetGlobalHandle(UINT32 groupTag);

	template<typename T = LPVOID>
	static T           &GetTagDefinition(LPCSTR pName);
	template<typename T>
	static T           &GetBlockDefinition(ITagBlock &block, size_t index);

	static size_t       s_CacheFilePointerOffset;
	static size_t       s_TagInstancesOffset;
	static size_t       s_TagAddressTableOffset;
private:
};

size_t ITagInterface::s_CacheFilePointerOffset = 0;
size_t ITagInterface::s_TagInstancesOffset     = 0;
size_t ITagInterface::s_TagAddressTableOffset  = 0;

ITagInterface::ITagInterface()
{
	SetCacheFilePointerOffset(0x1826077A0);
	SetTagInstancesOffset(0x1826887B8);
	SetTagAddressTableOffset(0x1838D86C0);
}

ITagInterface::~ITagInterface()
{
}

void ITagInterface::SetCacheFilePointerOffset(size_t cacheFilePointerOffset)
{
	s_CacheFilePointerOffset = cacheFilePointerOffset;
}

void ITagInterface::SetTagInstancesOffset(size_t tagInstancesOffset)
{
	s_TagInstancesOffset = tagInstancesOffset;
}

void ITagInterface::SetTagAddressTableOffset(size_t tagAddressTableOffset)
{
	s_TagAddressTableOffset = tagAddressTableOffset;
}

std::string ITagInterface::GetCacheName()
{
	static std::string name = "";
	char *pCacheFile = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, s_CacheFilePointerOffset);
	if (pCacheFile)
	{
		name = &pCacheFile[0x10 + 0x198];
	}

	return name;
}

template<typename T>
T ITagInterface::GetHeader(size_t offset)
{
	char *pCacheFile = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, s_CacheFilePointerOffset);
	if (pCacheFile)
	{
		return *reinterpret_cast<T *>(&pCacheFile[0x10 + offset]);
	}
	return T();
}

IDatumHandle ITagInterface::GetGlobalHandle(UINT32 groupTag)
{
	char *pCacheFile = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, s_CacheFilePointerOffset);
	ITagSection<IGlobalTagInstance> globalTagSection = *reinterpret_cast<ITagSection<IGlobalTagInstance> *>(&pCacheFile[0xA028]);

	for (size_t i = 0; i < globalTagSection.m_Count; ++i)
	{
		if (globalTagSection.m_Instances[i].m_GroupTag == groupTag)
			return globalTagSection.m_Instances[i].m_DatumHandle;
	}

	return IDatumHandle(0xFFFFFFFF);
}

class ITagList
{

public:
	ITagList();
	~ITagList();

	static void                                          Add(ITagInfo tagInfo);
	static void                                          FromFile();

	static std::vector<ITagInfo>                         GetList();
	static std::set<std::pair<std::string, std::string>> GetSet();

	static IDatumHandle                                  GetHandle(LPCSTR pName);
	static LPCSTR                                        GetName(IDatumHandle handle);

	static ITagInfo                                      Get(LPCSTR pName);
	static ITagInfo                                      Get(IDatumHandle handle);

private:
	static std::vector<ITagInfo> s_List;
};

std::vector<ITagInfo> ITagList::s_List;

template<typename T>
T &ITagInterface::GetTagDefinition(LPCSTR pName)
{
	ITagInstance *pTagInstances = IModuleInterface::Read<ITagInstance *>(IGameInterface::s_modulePath, s_TagInstancesOffset);
	UINT32 *(&rTagAddressTable)[] = IModuleInterface::Read<UINT32 *[]>(IGameInterface::s_modulePath, s_TagAddressTableOffset);

	IDatumHandle datumHandle = ITagList::GetHandle(pName);
	return *reinterpret_cast<T *>(&rTagAddressTable[pTagInstances[datumHandle.m_Index].m_Address >> 28][pTagInstances[datumHandle.m_Index].m_Address]);
}

template<typename T>
T &ITagInterface::GetBlockDefinition(ITagBlock &block, size_t index)
{
	UINT32 *(&rTagAddressTable)[] = IModuleInterface::Read<UINT32 *[]>(IGameInterface::s_modulePath, s_TagAddressTableOffset);

	T *block_definition = reinterpret_cast<T *>(&rTagAddressTable[block.m_Address >> 28][block.m_Address]);

	for (size_t i = 0; i < block.m_Count; i++)
	{
		block_definition++;
		if (i == index)
			break;
	}
	return *block_definition;
}

ITagList::ITagList()
{
}

ITagList::~ITagList()
{
}

void ITagList::Add(ITagInfo tagInfo)
{
	s_List.push_back(tagInfo);
}

void ITagList::FromFile()
{
	static bool once = false;

	if (!once)
	{
		std::string engineName = SplitString(GetFileName(IGameInterface::s_modulePath), ".")[0];
		std::string cacheName = ITagInterface::GetCacheName();

		if (cacheName.c_str()[0])
		{
			char path[MAX_PATH] = {};
			sprintf(path, "%s\\maps\\%s.csv", engineName.c_str(), cacheName.c_str());

			std::filebuf fb;
			if (fb.open(path, std::ios::in))
			{
				std::istream is(&fb);
				while (is)
				{
					char line[1024];
					is.getline(line, 1024);

					if (line[0])
					{
						std::vector<std::string> parts = SplitString(line, ",");
						UINT32 datumIndex = std::stoul(parts[0], 0, 16);
						LPCSTR tagName = parts[1].c_str();
						LPCSTR tagGroup = parts[2].c_str();
						LPCSTR tagGroupName = parts[3].c_str();

						char tagPath[MAX_PATH] = {};
						sprintf(tagPath, "%s.%s", tagName, tagGroupName);

						if (datumIndex != ITagList::GetHandle(tagPath).AsU32())
						{
							Add({ datumIndex, tagName, tagGroup, tagGroupName });
						}
					}
				}
				fb.close();
			}

			once = true;
		}
	}
}

std::vector<ITagInfo> ITagList::GetList()
{
	return s_List;
}

std::set<std::pair<std::string, std::string>> ITagList::GetSet()
{
	std::set<std::pair<std::string, std::string>> groups;
	for (ITagInfo &tagInfo : ITagList::GetList())
	{
		groups.emplace(std::make_pair(tagInfo.Group, tagInfo.GroupName));
	}

	return groups;
}

IDatumHandle ITagList::GetHandle(LPCSTR pName)
{
	std::vector<std::string> parts = SplitString(pName, ".");
	for (ITagInfo &tag : s_List)
	{
		if (strcmp(tag.Name, parts[0].c_str()) == 0 && (strcmp(tag.Group, parts[1].c_str()) == 0 || strcmp(tag.GroupName, parts[1].c_str()) == 0))
		{
			return tag.Handle;
		}
	}

	return IDatumHandle(0xFFFFFFFF);
}

LPCSTR ITagList::GetName(IDatumHandle handle)
{
	for (ITagInfo &tag : s_List)
	{
		if (tag.Handle.AsU32() == handle.AsU32())
		{
			return tag.Name;
		}
	}

	return "";
}

ITagInfo ITagList::Get(LPCSTR pName)
{
	std::vector<std::string> parts = SplitString(pName, ".");
	for (ITagInfo &tag : s_List)
	{
		if (strcmp(tag.Name, parts[0].c_str()) == 0 && (strcmp(tag.Group, parts[1].c_str()) == 0 || strcmp(tag.GroupName, parts[1].c_str()) == 0))
		{
			return tag;
		}
	}

	return ITagInfo();
}

ITagInfo ITagList::Get(IDatumHandle handle)
{
	for (ITagInfo &tag : s_List)
	{
		if (tag.Handle.AsU32() == handle.AsU32())
		{
			return tag;
		}
	}

	return ITagInfo();
}

class c_tag_reference
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	template<typename T>
	T &get_definition()
	{
		LPCSTR name = ITagList::GetName(m_index);

		return ITagInterface::GetTagDefinition<T>(name);
	}

	void get_field(LPCSTR pName)
	{
		ITagInfo tag = ITagList::Get(m_index);
		printf("%s = %s %s.%s\n", pName, tag.Group, tag.Name, tag.GroupName);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		char taggroup_buffer[5] = {};
		char tagname_buffer[MAX_PATH] = {};
		if (scanf("%s %s\n", &taggroup_buffer, &tagname_buffer))
		{
			memcpy(m_group_tag, taggroup_buffer, 4);
			m_index = ITagList::GetHandle(tagname_buffer).AsI32();
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	char m_group_tag[4];
	long : 32;
	long : 32;
	long m_index;
};
static_assert(sizeof(c_tag_reference) == 0x10, "sizeof(c_tag_reference) != 0x10");

class c_tag_block
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	template<typename T>
	T &get_definition(size_t index = 0)
	{
		return ITagInterface::GetBlockDefinition<T>(*reinterpret_cast<ITagBlock*>(this), index);
	}

	void get_field(LPCSTR pName, size_t index = -1)
	{
		for (long i = 0; i < m_count; i++)
		{
			if (index == i || index == -1)
			{
				printf("%s[%i] = 0x%X 0x%X\n", pName, i, m_address, m_definition_address);
			}
		}
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%u %u\n", &m_address, &m_definition_address))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

//private:
	long m_count;
	unsigned long m_address;
	unsigned long m_definition_address;
};
static_assert(sizeof(c_tag_block) == 0xC, "sizeof(c_tag_block) != 0xC");

template<typename T>
class c_field_definition
{
public:
	std::string m_Name;
	size_t      m_Offset;
	T           m_Type;
	size_t      m_Size;

	template<typename T>
	T type()
	{
		static T s_value;
		return s_value;
	}

	bool is_valid()
	{
		UINT32 valid = -1;
		valid += !m_Name.empty() ? 1 : 0;
		return valid >= 0;
	}
};

class c_int8_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %hhi\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%hhi\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	char m_value;
};
static_assert(sizeof(c_int8_field) == 0x1, "sizeof(c_int8_field) != 0x1");

class c_uint8_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %hhu\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%hhu\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	unsigned char m_value;
};
static_assert(sizeof(c_uint8_field) == 0x1, "sizeof(c_uint8_field) != 0x1");

class c_int16_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %hi\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%hi\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	short m_value;
};
static_assert(sizeof(c_int16_field) == 0x2, "sizeof(c_int16_field) != 0x2");

class c_uint16_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %hu\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%hu\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	unsigned short m_value;
};
static_assert(sizeof(c_uint16_field) == 0x2, "sizeof(c_uint16_field) != 0x2");

class c_int32_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %i\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%i\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	int m_value;
};
static_assert(sizeof(c_int32_field) == 0x4, "sizeof(c_int32_field) != 0x4");

class c_uint32_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %u\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%u\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	unsigned long m_value;
};
static_assert(sizeof(c_uint32_field) == 0x4, "sizeof(c_uint32_field) != 0x4");

class c_int64_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %lli\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%lli\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	long long m_value;
};
static_assert(sizeof(c_int64_field) == 0x8, "sizeof(c_int64_field) != 0x8");

class c_uint64_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %llu\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%llu\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	unsigned long long m_value;
};
static_assert(sizeof(c_uint64_field) == 0x8, "sizeof(c_uint64_field) != 0x8");

class c_float32_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %.8f\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%f\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	float m_value;
};
static_assert(sizeof(c_float32_field) == 0x4, "sizeof(c_float32_field) != 0x4");

class c_float64_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %lf\n", pName, m_value);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%lf\n", &m_value))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	double m_value;
};
static_assert(sizeof(c_float64_field) == 0x8, "sizeof(c_float64_field) != 0x8");

class c_float32_vec3_field
{
private:
	template<typename T>
	T default_value(T &value, bool reset = false)
	{
		static T s_value = value;

		if (reset)
			value = s_value;

		return s_value;
	}

public:
	void get_field(LPCSTR pName)
	{
		printf("%s = %.8f %.8f %.8f\n", pName, m_iValue, m_jValue, m_kValue);
	}

	void edit_field(LPCSTR pName)
	{
		default_value(*this);
		get_field(pName);

		printf("[%s, Enter new values]: ", pName);
		if (scanf("%f %f %f\n", &m_iValue, &m_jValue, &m_kValue))
		{
			get_field(pName);
		}
	}

	void reset_field(LPCSTR pName)
	{
		default_value(*this, true);
		get_field(pName);
	}

private:
	float m_iValue, m_jValue, m_kValue;
};
static_assert(sizeof(c_float32_vec3_field) == 0xC, "sizeof(c_float32_vec3_field) != 0xC");

template<size_t size>
class c_static_string
{
public:
	char m_data[size];

	const char *c_str()
	{
		return m_data;
	}
};

template<INT32 group, size_t size>
class c_tag_definition
{
public:
	char   m_data[size];

	bool is_valid()
	{
		UINT32 valid = -1;

		try
		{
			for (size_t i = 0; i < sizeof(m_data); i++)
				valid += m_data[i] != 0 ? 1 : 0;
		}
		catch (const std::exception &e)
		{
			printf("%s\n", e.what());
		}

		return valid >= 0;
	}

	std::vector<c_field_definition<c_tag_reference>> &tag_reference_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_tag_reference>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	template<typename T>
	std::vector<c_field_definition<c_tag_block>> &tag_block_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_tag_block>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });

		for (c_field_definition<c_tag_block> &field : fields)
			if (strcmp(field.m_Name.c_str(), pFieldName) == 0 && sizeof(T) > 0)
				field.type<T>();

		return fields;
	}

	std::vector<c_field_definition<c_int8_field>> &int8_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_int8_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_uint8_field>> &uint8_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_uint8_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_int16_field>> &int16_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_int16_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_uint16_field>> &uint16_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_uint16_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_int32_field>> &int32_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_int32_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_uint32_field>> &uint32_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_uint32_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_int64_field>> &int64_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_int64_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_uint64_field>> &uint64_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_uint64_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_float32_field>> &float32_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_float32_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_float64_field>> &float64_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_float64_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}
	std::vector<c_field_definition<c_float32_vec3_field>> &float32_vec3_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_float32_vec3_field>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
		return fields;
	}

	template<typename T>
	T &field_accessor(size_t offset)
	{
		return *reinterpret_cast<T *>(&m_data[offset]);
	}

	template<typename T>
	void fields_accessor(LPCSTR pInputCommand, LPCSTR pInputArgument, std::vector<c_field_definition<T>> vFields)
	{
		for (c_field_definition<T> &field : vFields)
		{
			if (field.is_valid())
			{
				if (strcmp(pInputArgument, field.m_Name.c_str()) == 0)
				{
					if (ICommand({ "Get" }).Match(pInputCommand))
					{
						field_accessor<decltype(field.m_Type)>(field.m_Offset).get_field(field.m_Name.c_str());
						break;
					}
					if (ICommand({ "Edit" }).Match(pInputCommand))
					{
						field_accessor<decltype(field.m_Type)>(field.m_Offset).edit_field(field.m_Name.c_str());
						break;
					}
					if (ICommand({ "Reset" }).Match(pInputCommand))
					{
						field_accessor<decltype(field.m_Type)>(field.m_Offset).reset_field(field.m_Name.c_str());
						break;
					}
				}
			}
		}
	}

	INT32 tag_group()
	{
		static INT32 Group = group;
		return Group;
	}

	bool edit(LPCSTR pTagName)
	{
		if (is_valid())
		{
			static char input_buffer[1024] = {};
			while (true)
			{
				printf("%s> ", pTagName);

				memset(input_buffer, 0, 1024);
				fgets(input_buffer, 1024, stdin);

				char *newline = strchr(input_buffer, '\n');
				if (newline) *newline = '\0';

				if (strlen(input_buffer) == 0)
					continue;

				std::vector<std::string> inputs = SplitString(input_buffer, " ");
				LPCSTR pInputCommand = inputs.size() >= 1 ? inputs[0].c_str() : "\0";
				LPCSTR pInputArgument = inputs.size() >= 2 ? inputs[1].c_str() : "\0";

				if (ICommand({ "Exit" }).Match(pInputCommand))
					break;

				if (ICommand({ "Get", "Edit", "Reset" }).Match(pInputCommand))
				{
					fields_accessor(pInputCommand, pInputArgument, tag_reference_field());
					fields_accessor(pInputCommand, pInputArgument, int8_field());
					fields_accessor(pInputCommand, pInputArgument, uint8_field());
					fields_accessor(pInputCommand, pInputArgument, int16_field());
					fields_accessor(pInputCommand, pInputArgument, uint16_field());
					fields_accessor(pInputCommand, pInputArgument, int32_field());
					fields_accessor(pInputCommand, pInputArgument, uint32_field());
					fields_accessor(pInputCommand, pInputArgument, int64_field());
					fields_accessor(pInputCommand, pInputArgument, uint64_field());
					fields_accessor(pInputCommand, pInputArgument, float32_field());
					fields_accessor(pInputCommand, pInputArgument, float64_field());
					fields_accessor(pInputCommand, pInputArgument, float32_vec3_field());

					continue;
				}

				enum class TagCommand : int
				{
					Get,
					Edit,
					Reset,

					kCount
				};
				LPCSTR commands[static_cast<int>(TagCommand::kCount)] =
				{
					"Get",
					"Edit",
					"Reset"
				};
				size_t commandCount = static_cast<size_t>(TagCommand::kCount);

				printf("enum TagCommand\n{\n");
				for (size_t i = 0; i < commandCount; i++)
				{
					printf((i == commandCount - 1 ? "\t%s\n" : "\t%s,\n"), commands[i]);
				}
				printf("};\n");
			}
		}

		return false;
	}
};

class c_weapon_attachments_block_definition : public c_tag_definition<'null', 0x20>
{
public:
	c_weapon_attachments_block_definition &apply(bool force = false)
	{
		static bool applied = false;
		if (!applied || force)
		{
			tag_reference_field("attachment", 0x0);
			int32_field("marker", 0x10);
			int16_field("change_color", 0x14);
			int16_field("unknown16", 0x16);
			int32_field("primary_scale", 0x18);
			int32_field("secondary_scale", 0x1C);

			applied = true;
		}
		return *this;
	}
};

class c_scenario_definition : public c_tag_definition<'scnr', 0x884>
{
public:
	c_scenario_definition &apply(bool force = false)
	{
		static bool applied = false;
		if (!applied || force)
		{
			int16_field("map_type", 0x0);
			int32_field("campaign_id", 0x8);
			int32_field("map_id", 0xC);
			int16_field("campaign_level_index", 0x14);
			tag_reference_field("performance_throttle_profile", 0x3C);
			tag_reference_field("performance_throttles", 0x750);

			applied = true;
		}
		return *this;
	}
};

class c_weapon_definition : public c_tag_definition<'weap', 0x500>
{
public:
	c_weapon_definition &apply(bool force = false)
	{
		static bool applied = false;
		if (!applied || force)
		{
			tag_reference_field("Model", 0x64);
			tag_block_field<c_weapon_attachments_block_definition>("attachments", 0x108);
			float32_vec3_field("first_person_weapon_offset", 0x4CC);

			applied = true;
		}
		return *this;
	}
};

class c_user_interface_shared_globals_definition : public c_tag_definition<'wigl', 0x174>
{
public:
	c_user_interface_shared_globals_definition &apply(bool force = false)
	{
		static bool applied = false;
		if (!applied || force)
		{
			float32_field("near_clip_plane_distance", 0x4);
			float32_field("projection_plane_distance", 0x8);
			float32_field("far_clip_plane_distance", 0xC);
			int32_field("music_fade_time", 0x70);

			applied = true;
		}
		return *this;
	}
};

bool EditTag(LPCSTR pInput)
{
	auto list_tag_groups = []()
	{
		std::set<std::pair<std::string, std::string>> tagGroups = ITagList::GetSet();
		auto &last = (*tagGroups.rbegin());

		printf("enum TagGroup\n{\n");
		for (auto &group : tagGroups)
		{
			if (strcmp(group.first.c_str(), last.first.c_str()) == 0)
				printf("\t{ %s, %s }\n", group.first.c_str(), group.second.c_str());
			else
				printf("\t{ %s, %s },\n", group.first.c_str(), group.second.c_str());
		}
		printf("};\n");

		return false;
	};

	auto list_tags_in_group = [](LPCSTR pGroup)
	{
		std::set<std::pair<std::string, std::string>> tagGroups = ITagList::GetSet();
		for (auto &group : tagGroups)
		{
			if (strcmp(group.first.c_str(), pGroup) == 0 || strcmp(group.second.c_str(), pGroup) == 0)
			{
				ITagInfo last = *ITagList::GetList().rbegin();

				printf("enum %s\n{\n", pGroup);
				for (ITagInfo &tagInfo : ITagList::GetList())
				{
					if (strcmp(tagInfo.Group, pGroup) == 0 || strcmp(tagInfo.GroupName, pGroup) == 0)
					{
						if (strcmp(tagInfo.Group, last.Group) == 0 || strcmp(tagInfo.GroupName, last.GroupName) == 0)
							printf("\t%s.%s\n", tagInfo.Name, tagInfo.GroupName);
						else
							printf("\t%s.%s,\n", tagInfo.Name, tagInfo.GroupName);
					}
				}
				printf("};\n");
			}
		}

		return false;
	};

	if (strcmp(pInput, "") == 0)
		return list_tag_groups();

	std::string groupName = strstr(pInput, ".") != 0 ? SplitString(pInput, ".")[1] : pInput;

	if (strcmp(groupName.c_str(), "scenario") == 0)
		return ITagInterface::GetTagDefinition<c_scenario_definition>(pInput).apply().edit(pInput);

	if (strcmp(groupName.c_str(), "weapon") == 0)
		return ITagInterface::GetTagDefinition<c_weapon_definition>(pInput).apply().edit(pInput);

	if (strcmp(groupName.c_str(), "user_interface_shared_globals_definition") == 0)
		return ITagInterface::GetTagDefinition<c_user_interface_shared_globals_definition>(pInput).apply().edit(pInput);

	for (const std::pair<std::string, std::string> &group : ITagList::GetSet())
		if (strcmp(group.first.c_str(), groupName.c_str()) == 0 || strcmp(group.second.c_str(), groupName.c_str()) == 0)
			list_tags_in_group(group.first.c_str());

	return false;
};

struct e_script_type
{
	enum : short
	{
		_startup,
		_dormant,
		_continuous,
		_static,
		_command_script,
		_stub,

		k_number_of_script_types
	} value;

	e_script_type(short val)
	{
		if (val >= 0 && val < k_number_of_script_types)
		{
			value = static_cast<decltype(value)>(val);
		}
	}

	const char *c_str()
	{
		const char *strings[k_number_of_script_types] =
		{
			"startup",
			"dormant",
			"continuous",
			"static",
			"command_script",
			"stub"
		};

		return strings[value];
	}
};

struct e_value_type
{
	enum : short
	{
		_unparsed,
		_special_form,
		_function_name,
		_passthrough,
		_void,
		_boolean,
		_real,
		_short,
		_long,
		_string,
		_script,
		_string_id,
		_unit_seat_mapping,
		_trigger_volume,
		_cutscene_flag,
		_cutscene_camera_point,
		_cutscene_title,
		_cutscene_recording,
		_device_group,
		_ai,
		_ai_command_list,
		_ai_command_script,
		_ai_behavior,
		_ai_orders,
		_ai_line,
		_starting_profile,
		_conversation,
		_player,
		_zone_set,
		_designer_zone,
		_point_reference,
		_style,
		_object_list,
		_folder,
		_sound,
		_effect,
		_damage,
		_looping_sound,
		_animation_graph,
		_damage_effect,
		_object_definition,
		_bitmap,
		_shader,
		_render_model,
		_structure_definition,
		_lightmap_definition,
		_cinematic_definition,
		_cinematic_scene_definition,
		_cinematic_transition_definition,
		_bink_definition,
		_cui_screen_definition,
		_any_tag,
		_any_tag_not_resolving,
		_game_difficulty,
		_team,
		_mp_team,
		_controller,
		_button_preset,
		_joystick_preset,
		_player_color,
		_player_model_choice,
		_voice_output_setting,
		_voice_mask,
		_subtitle_setting,
		_actor_type,
		_model_state,
		_event,
		_character_physics,
		_skull,
		_firing_point_evaluator,
		_damage_region,
		_object,
		_unit,
		_vehicle,
		_weapon,
		_device,
		_scenery,
		_effect_scenery,
		_object_name,
		_unit_name,
		_vehicle_name,
		_weapon_name,
		_device_name,
		_scenery_name,
		_effect_scenery_name,
		_cinematic_lightprobe,
		_animation_budget_reference,
		_looping_sound_budget_reference,
		_sound_budget_reference,

		k_number_of_value_types
	} value;

	e_value_type(short val)
	{
		if (val >= 0 && val < k_number_of_value_types)
		{
			value = static_cast<decltype(value)>(val);
		}
	}

	const char *c_str()
	{
		const char *strings[k_number_of_value_types] =
		{
			"unparsed",
			"special_form",
			"function_name",
			"passthrough",
			"void",
			"boolean",
			"real",
			"short",
			"long",
			"string",
			"script",
			"string_id",
			"unit_seat_mapping",
			"trigger_volume",
			"cutscene_flag",
			"cutscene_camera_point",
			"cutscene_title",
			"cutscene_recording",
			"device_group",
			"ai",
			"ai_command_list",
			"ai_command_script",
			"ai_behavior",
			"ai_orders",
			"ai_line",
			"starting_profile",
			"conversation",
			"player",
			"zone_set",
			"designer_zone",
			"point_reference",
			"style",
			"object_list",
			"folder",
			"sound",
			"effect",
			"damage",
			"looping_sound",
			"animation_graph",
			"damage_effect",
			"object_definition",
			"bitmap",
			"shader",
			"render_model",
			"structure_definition",
			"lightmap_definition",
			"cinematic_definition",
			"cinematic_scene_definition",
			"cinematic_transition_definition",
			"bink_definition",
			"cui_screen_definition",
			"any_tag",
			"any_tag_not_resolving",
			"game_difficulty",
			"team",
			"mp_team",
			"controller",
			"button_preset",
			"joystick_preset",
			"player_color",
			"player_model_choice",
			"voice_output_setting",
			"voice_mask",
			"subtitle_setting",
			"actor_type",
			"model_state",
			"event",
			"character_physics",
			"skull",
			"firing_point_evaluator",
			"damage_region",
			"object",
			"unit",
			"vehicle",
			"weapon",
			"device",
			"scenery",
			"effect_scenery",
			"object_name",
			"unit_name",
			"vehicle_name",
			"weapon_name",
			"device_name",
			"scenery_name",
			"effect_scenery_name",
			"cinematic_lightprobe",
			"animation_budget_reference",
			"looping_sound_budget_reference",
			"sound_budget_reference"
		};

		return strings[value];
	}
};

bool print_scenario_scripts()
{
	static auto scenario_execute_script = (UINT32(*)(INT16 script_index, INT32 script_type, UINT32 a3))(IModuleInterface::GetAddress<UINT64>(IGameInterface::s_modulePath, 0x1801EE100));
	c_scenario_definition *pScenario = IModuleInterface::Read<c_scenario_definition *>(IGameInterface::s_modulePath, 0x180D495B0);

	if (!pScenario)
	{
		printf("No scenario loaded\n");
		return false;
	}

	printf("Scenario =\n");
	printf("{\n");
	c_tag_block &rScripts = *(c_tag_block*)&pScenario->m_data[0x450];
	for (int scriptIndex = 0; scriptIndex < rScripts.m_count; scriptIndex++)
	{
		c_tag_definition<'null', 0x18> &rScript = rScripts.get_definition<c_tag_definition<'null', 0x18>>(scriptIndex);
		UINT32 &rName = *(UINT32 *)&rScript.m_data[0x0];
		INT16 &rScriptType = *(INT16 *)&rScript.m_data[0x4];
		INT16 &rReturnType = *(INT16 *)&rScript.m_data[0x6];
		UINT16 &rRootExpressionIndex = *(UINT16 *)&rScript.m_data[0x8];
		UINT16 &rRootExpressionSalt = *(UINT16 *)&rScript.m_data[0xA];
		c_tag_block &rParameters = *(c_tag_block *)&rScript.m_data[0xC];

		printf("\tScripts[%i] =\n", scriptIndex);
		printf("\t{\n");
		printf("\t\tName:                  0x%04X,\n", rName);
		printf("\t\tScript Type:           %s,\n", e_script_type(rScriptType).c_str());
		printf("\t\tReturn Type:           %s,\n", e_script_type(rReturnType).c_str());
		printf("\t\tRoot Expression Index: 0x%04X,\n", rRootExpressionIndex);
		printf("\t\tRoot Expression Salt:  0x%04X,\n", rRootExpressionSalt);


		for (int parameterIndex = 0; parameterIndex < rParameters.m_count; parameterIndex++)
		{
			c_tag_definition<'null', 0x24> &rParameter = rParameters.get_definition<c_tag_definition<'null', 0x24>>(parameterIndex);
			c_static_string<32> &rScriptName = *(c_static_string<32> *)&rParameter.m_data[0x0];
			INT16 &rType = *(INT16 *)&rParameter.m_data[0x20];
			INT16 &rUnknown = *(INT16 *)&rParameter.m_data[0x22];

			printf("\t\tParameters[%i] =\n", parameterIndex);
			printf("\t\t{\n");
			printf("\t\t\tName:    \"%s\",\n", rScriptName.c_str());
			printf("\t\t\tType:    %s,\n", e_value_type(rType).c_str());
			printf("\t\t\tUnknown: 0x%04X\n", rUnknown);
			printf("\t\t}%s\n", parameterIndex + 1 == rParameters.m_count ? "" : ",");

			//if (strcmp(rScriptName.c_str(), pScriptName) == 0 && parameterIndex == 0)
			//{
			//	if (scenario_execute_script(scriptIndex, *(INT16 *)&rScript.m_data[0x4], 0) == -1)
			//	{
			//		printf("Failed execution failed\n");
			//		return false;
			//	}
			//	return true;
			//}
		}
		printf("\t}%s\n", scriptIndex + 1 == rScripts.m_count ? "" : ",");
	}
	printf("}\n");

	//printf("Script not found\n");
	return false;
}

#pragma pack(push, 4)
struct hs_script_op
{
	__int16 return_type;
	__int16 flags;
	__int32 __unused4;
	void(__fastcall *evaluate)(INT64 function_index, UINT64 expression_index, bool execute);
	const char *parameter_info;
	__int16 parameter_count;
	__int16 parameter_types;

	bool evaluate_match(UINT64 offset)
	{
		return get_file_addr(*(UINT64 *)&evaluate) == offset;
	}
	void replace(hs_script_op &new_op)
	{
		hs_script_op &op = *(hs_script_op *)this;
		virtual_memcpy(&op, &new_op, sizeof(*this));
	}
	void replace_evaluate(LPVOID new_evaluate)
	{
		virtual_memcpy(&evaluate, &new_evaluate, sizeof(&evaluate));
	}
};
#pragma pack(pop)

template<typename t_element, size_t count>
class c_static_array
{
public:
	t_element m_elements[count];

	inline c_static_array<const char *, count> &get_element_names()
	{
		static c_static_array<const char *, count> names;

		return names;
	}

	inline t_element *operator->()
	{
		return m_elements;
	}
	inline t_element &operator[](const size_t index)
	{
		return m_elements[index];
	}
	inline t_element *begin()
	{
		return m_elements;
	}
	inline t_element *end()
	{
		return &m_elements[count];
	}
	inline explicit operator bool()
	{
		return m_elements != nullptr;
	}
	inline size_t get_count()
	{
		return count;
	}
};

class c_halo_script
{
public:
	c_halo_script();

	static c_static_array<hs_script_op *, 1995> &get_function_table();
	static const char *&get_function_name(const size_t index);
	static void generate_csv();
	static void generate_idc();
private:

};

inline c_halo_script::c_halo_script()
{
	get_function_table().get_element_names() =
	{
		"begin",
		"begin_random",
		"begin_count",
		"begin_random_count",
		"if",
		"cond",
		"set",
		"and",
		"or",
		"add",
		"subtract",
		"multiply",
		"divide",
		"inc",
		"min",
		"max",
		"equal",
		"not_equal",
		"greater_than",
		"less_than",
		"greater_than_or_equal",
		"less_than_or_equal",
		"sleep",
		"sleep_forever",
		"sleep_until",
		"sleep_until_game_ticks",
		"wake",
		"cinematic_sleep",
		"inspect",
		"branch",
		"unit",
		"vehicle",
		"weapon",
		"device",
		"scenery",
		"effect_scenery",
		"evaluate",
		"not",
		"pin",
		"",
		"print",
		"print_if",
		"log_print",
		"debug_scripting_show_thread",
		"debug_script_thread",
		"debug_scripting",
		"debug_scripting_globals",
		"debug_scripting_variable",
		"debug_scripting_variable_all",
		"breakpoint",
		"kill_active_scripts",
		"get_executing_running_thread",
		"kill_thread",
		"script_started",
		"script_finished",
		"local_players",
		"players",
		"players_human",
		"players_elite",
		"player_get",
		"player_in_game_get",
		"human_player_in_game_get",
		"elite_player_in_game_get",
		"player_is_in_game",
		"editor_mode",
		"kill_volume_enable",
		"kill_volume_disable",
		"volume_teleport_players_not_inside",
		"volume_test_object",
		"volume_test_objects",
		"volume_test_objects_all",
		"volume_test_players",
		"volume_test_players_all",
		"volume_return_objects",
		"volume_return_objects_by_type",
		"volume_return_objects_by_campaign_type",
		"zone_set_trigger_volume_enable",
		"list_get",
		"list_count",
		"list_count_not_dead",
		"effect_new",
		"effect_new_random0",
		"effect_new_random1",
		"effect_new_at_ai_point",
		"effect_new_at_point_set_point",
		"effect_new_on_object_marker",
		"effect_new_on_object_marker_loop",
		"effect_stop_object_marker",
		"effect_new_on_ground",
		"damage_new",
		"damage_object_effect",
		"damage_objects_effect",
		"damage_object",
		"damage_objects",
		"damage_players",
		"soft_ceiling_enable",
		"object_create",
		"object_create_variant",
		"object_create_clone",
		"object_create_anew",
		"object_create_if_necessary",
		"object_create_folder",
		"object_create_folder_anew",
		"object_destroy",
		"object_destroy_all",
		"object_destroy_type_mask",
		"objects_delete_by_definition",
		"object_destroy_folder",
		"object_hide",
		"object_set_shadowless",
		"object_set_allegiance",
		"object_buckling_magnitude_get",
		"object_function_set",
		"object_set_function_variable",
		"object_set_cinematic_function_variable",
		"object_clear_cinematic_function_variable",
		"object_clear_all_function_variables",
		"object_dynamic_simulation_disable",
		"object_set_phantom_power",
		"object_wake_physics",
		"object_get_at_rest",
		"object_set_ranged_attack_inhibited",
		"object_set_melee_attack_inhibited",
		"objects_dump_memory",
		"object_get_health",
		"object_get_shield",
		"object_set_shield_effect",
		"object_set_physics",
		"object_get_parent",
		"objects_attach",
		"object_at_marker",
		"objects_detach",
		"object_set_scale",
		"object_set_velocity0",
		"object_get_bsp",
		"object_set_as_fireteam_target",
		"object_is_reserved",
		"object_set_velocity1",
		"object_set_deleted_when_deactivated",
		"object_copy_player_appearance",
		"object_model_target_destroyed",
		"object_model_targets_destroyed",
		"object_enable_damage_section",
		"object_disable_damage_section",
		"object_damage_damage_section",
		"object_cannot_die",
		"object_cannot_die_except_kill_volumes",
		"object_ignores_emp",
		"object_vitality_pinned",
		"garbage_collect_now",
		"garbage_collect_unsafe",
		"garbage_collect_multiplayer",
		"object_cannot_take_damage",
		"object_get_recent_body_damage",
		"object_get_recent_shield_damage",
		"object_can_take_damage",
		"object_immune_to_friendly_damage",
		"object_cinematic_lod",
		"object_cinematic_collision",
		"object_cinematic_visibility",
		"objects_predict",
		"objects_predict_high",
		"objects_predict_low",
		"object_type_predict_high",
		"object_type_predict_low",
		"object_type_predict",
		"object_teleport",
		"object_teleport_to_ai_point",
		"object_set_facing",
		"object_set_shield",
		"object_set_shield_stun",
		"object_set_shield_stun_infinite",
		"object_set_permutation",
		"object_set_variant",
		"object_set_region_state",
		"object_set_model_state_property",
		"objects_can_see_object",
		"objects_can_see_flag",
		"objects_distance_to_object",
		"objects_distance_to_flag",
		"objects_distance_to_point",
		"map_info",
		"position_predict",
		"shader_predict",
		"bitmap_predict",
		"script_recompile",
		"script_doc",
		"help",
		"game_engine_objects",
		"random_range",
		"real_random_range",
		"physics_constants_reset",
		"physics_set_gravity",
		"physics_set_velocity_frame",
		"physics_disable_character_ground_adhesion_forces",
		"havok_debug_start",
		"havok_debug_stop",
		"havok_dump_world",
		"havok_dump_world_close_movie",
		"havok_profile_start",
		"havok_profile_end",
		"havok_profile_range",
		"havok_reset_allocated_state",
		"breakable_surfaces_enable",
		"breakable_surfaces_reset",
		"recording_play",
		"recording_play_and_delete",
		"recording_play_and_hover",
		"recording_kill",
		"recording_time",
		"render_lights",
		"print_light_state",
		"render_lights_enable_cinematic_shadow",
		"texture_camera_set_object_marker",
		"texture_camera_set_position",
		"texture_camera_set_target",
		"texture_camera_attach_to_object",
		"texture_camera_target_object",
		"texture_camera_position_world_offset",
		"texture_camera_on",
		"texture_camera_bink",
		"texture_camera_off",
		"texture_camera_set_aspect_ratio",
		"texture_camera_set_resolution",
		"texture_camera_render_mode",
		"texture_camera_set_fov",
		"texture_camera_set_fov_frame_target",
		"texture_camera_enable_dynamic_lights",
		"hud_camera_on",
		"hud_camera_off",
		"hud_camera_set_position",
		"hud_camera_set_target",
		"hud_camera_attach_to_object",
		"hud_camera_target_object",
		"hud_camera_structure",
		"hud_camera_highlight_object",
		"hud_camera_clear_objects",
		"hud_camera_spin_around",
		"hud_camera_from_player_view",
		"hud_camera_window",
		"render_debug_texture_camera",
		"render_debug_cheap_particles",
		"render_debug_rain_occlusion",
		"render_debug_rain_fog",
		"debug_rain_toggle",
		"weather_animate",
		"weather_animate_force",
		"debug_structure_cluster",
		"",
		"",
		"",
		"",
		"",
		"render_debug_structure_all_fog_planes",
		"render_debug_structure_all_cluster_errors",
		"render_debug_structure_line_opacity",
		"render_debug_structure_text_opacity",
		"render_debug_structure_opacity",
		"render_debug_structure_non_occluded_fog_planes",
		"render_debug_structure_lightmaps_use_pervertex",
		"render_debug_structure_lightmaps_use_reset",
		"render_debug_structure_lightmaps_sample_enable",
		"render_debug_structure_lightmaps_sample_disable",
		"render_debug_query_object_bitmaps",
		"render_debug_query_bsp_resources",
		"",
		"",
		"render_debug_text_using_simple_font",
		"render_postprocess_color_tweaking_reset",
		"render_debug_wrinkle_weights_a",
		"render_debug_wrinkle_weights_b",
		"render_debug_wrinkle_weights_from_console",
		"scenery_animation_start",
		"scenery_animation_start_loop",
		"scenery_animation_start_relative",
		"scenery_animation_start_relative_loop",
		"scenery_animation_start_at_frame",
		"scenery_animation_start_relative_at_frame",
		"scenery_animation_idle",
		"scenery_get_animation_time",
		"unit_can_blink",
		"unit_set_active_camo",
		"unit_open",
		"unit_close",
		"unit_kill",
		"unit_kill_silent",
		"unit_is_emitting",
		"unit_is_emp_stunned",
		"unit_get_custom_animation_time",
		"unit_stop_custom_animation",
		"custom_animation",
		"custom_animation_loop",
		"custom_animation_relative",
		"custom_animation_relative_loop",
		"custom_animation_list",
		"unit_custom_animation_at_frame",
		"unit_custom_animation_relative_at_frame",
		"unit_is_playing_custom_animation",
		"unit_has_mandibles_hidden",
		"animation_capture_set_file_name",
		"animation_capture_set_origin_object_name",
		"animation_capture_start_recording",
		"animation_capture_stop_recording",
		"sync_action_create",
		"object_running_sync_action",
		"object_set_custom_animations_hold_on_last_frame",
		"object_set_custom_animations_prevent_lipsync_head_movement",
		"preferred_animation_list_add",
		"preferred_animation_list_clear",
		"unit_get_team_index",
		"unit_aim_without_turning",
		"unit_set_enterable_by_player",
		"unit_get_enterable_by_player",
		"unit_only_takes_damage_from_players_team",
		"unit_enter_vehicle",
		"unit_enter_vehicle_immediate",
		"unit_falling_damage_disable",
		"unit_in_vehicle_type",
		"object_get_turret_count",
		"object_get_turret",
		"unit_board_vehicle",
		"unit_set_emotion",
		"unit_set_emotion_by_name",
		"unit_enable_eye_tracking",
		"unit_set_integrated_flashlight",
		"unit_in_vehicle",
		"unit_get_vehicle",
		"vehicle_set_player_interaction",
		"vehicle_set_unit_interaction",
		"vehicle_test_seat_unit_list",
		"vehicle_test_seat_unit",
		"vehicle_test_seat",
		"unit_set_prefer_tight_camera_track",
		"unit_exit_vehicle0",
		"unit_exit_vehicle1",
		"unit_exit_vehicle3",
		"unit_set_maximum_vitality",
		"units_set_maximum_vitality",
		"unit_set_current_vitality",
		"units_set_current_vitality",
		"vehicle_load_magic",
		"vehicle_unload",
		"unit_set_animation_mode",
		"magic_melee_attack",
		"vehicle_riders",
		"vehicle_driver",
		"vehicle_gunner",
		"unit_get_health",
		"unit_get_shield",
		"unit_get_total_grenade_count",
		"unit_has_weapon",
		"unit_has_weapon_readied",
		"unit_has_any_equipment",
		"unit_has_equipment",
		"unit_lower_weapon",
		"unit_raise_weapon",
		"unit_drop_support_weapon",
		"unit_spew_action",
		"unit_force_reload",
		"animation_stats_dump",
		"unit_animation_forced_seat",
		"unit_doesnt_drop_items",
		"unit_impervious",
		"unit_suspended",
		"unit_add_equipment",
		"weapon_set_primary_barrel_firing",
		"weapon_hold_trigger",
		"weapon_enable_warthog_chaingun_light",
		"device_set_never_appears_locked",
		"device_set_power",
		"device_set_position_transition_time",
		"device_get_power",
		"device_set_position",
		"device_get_position",
		"device_set_position_immediate",
		"device_group_get",
		"device_group_set",
		"device_group_set_immediate",
		"device_one_sided_set",
		"",
		"device_operates_automatically_set",
		"device_closes_automatically_set",
		"device_group_change_only_once_more_set",
		"device_set_position_track",
		"device_set_overlay_track",
		"device_animate_position",
		"device_animate_overlay",
		"cheat_all_powerups",
		"cheat_all_weapons",
		"cheat_all_vehicles",
		"cheat_teleport_to_camera",
		"cheat_active_camouflage",
		"cheat_active_camouflage_by_player",
		"cheats_load",
		"drop_safe",
		"drop",
		"drop_variant",
		"drop_permutation",
		"update_dropped_tag_permutation",
		"ai_enable",
		"ai_enabled",
		"ai_grenades",
		"ai_dialogue_enable",
		"ai_dialogue_updating_enable",
		"ai_player_dialogue_enable",
		"ai_actor_dialogue_enable",
		"ai_actor_dialogue_effect_enable",
		"ai_infection_suppress",
		"ai_fast_and_dumb",
		"ai_lod_full_detail_actors0",
		"ai_lod_full_detail_actors1",
		"ai_force_full_lod",
		"ai_force_low_lod",
		"",
		"ai_dialogue_log_reset",
		"ai_dialogue_log_dump",
		"ai_get_object",
		"ai_get_unit",
		"ai_get_squad",
		"ai_get_turret_ai",
		"ai_random_smart_point",
		"ai_nearest_point",
		"ai_get_point_count",
		"ai_point_set_get_point",
		"ai_debug_dump_behavior_tree",
		"ai_place0",
		"ai_place1",
		"ai_place_in_limbo0",
		"ai_place_in_limbo1",
		"ai_place_in_vehicle",
		"ai_cannot_die",
		"ai_vitality_pinned",
		"ai_place_wave0",
		"ai_place_wave1",
		"ai_place_wave_in_limbo0",
		"ai_place_wave_in_limbo1",
		"ai_set_clump",
		"ai_designer_clump_perception_range",
		"ai_designer_clump_targeting_group",
		"ai_index_from_spawn_formation",
		"ai_resurrect",
		"ai_kill",
		"ai_kill_silent",
		"ai_kill_no_statistics",
		"ai_erase",
		"ai_erase_all",
		"ai_disposable",
		"ai_select",
		"ai_deselect",
		"ai_set_deaf",
		"ai_set_blind",
		"ai_set_weapon_up",
		"ai_flood_disperse",
		"ai_add_navpoint",
		"ai_magically_see",
		"ai_magically_see_object",
		"ai_set_active_camo",
		"ai_suppress_combat",
		"ai_engineer_explode",
		"ai_grunt_kamikaze",
		"ai_squad_enumerate_immigrants",
		"ai_migrate",
		"ai_migrate_persistent",
		"ai_allegiance",
		"ai_allegiance_remove",
		"ai_allegiance_break",
		"ai_braindead",
		"ai_braindead_by_unit",
		"ai_disregard",
		"ai_disregard_orphans",
		"ai_prefer_target",
		"ai_prefer_target_team",
		"ai_prefer_target_ai",
		"ai_set_targeting_group0",
		"ai_set_targeting_group1",
		"ai_teleport_to_starting_location_if_outside_bsp",
		"ai_teleport_to_spawn_point_if_outside_bsp",
		"ai_teleport",
		"ai_bring_forward",
		"ai_renew",
		"ai_force_active",
		"ai_force_active_by_unit",
		"ai_exit_limbo",
		"ai_playfight",
		"ai_reconnect",
		"ai_berserk",
		"ai_set_team",
		"ai_allow_dormant",
		"ai_is_attacking",
		"ai_fighting_count",
		"ai_living_count",
		"ai_living_fraction",
		"ai_in_vehicle_count",
		"ai_body_count",
		"ai_strength",
		"ai_swarm_count",
		"ai_nonswarm_count",
		"ai_actors",
		"ai_allegiance_broken",
		"ai_spawn_count",
		"object_get_ai",
		"ai_set_task",
		"ai_set_objective",
		"ai_task_status",
		"ai_set_task_condition",
		"ai_leadership",
		"ai_leadership_all",
		"ai_task_count",
		"ai_reset_objective",
		"ai_squad_patrol_objective_disallow",
		"ai_place_cue",
		"ai_remove_cue",
		"generate_pathfinding",
		"ai_render_paths_all",
		"ai_render_evaluations_shading_none",
		"ai_render_evaluations_shading_all",
		"ai_render_evaluations_shading",
		"ai_activity_set",
		"ai_activity_abort",
		"ai_object_set_team",
		"ai_object_set_targeting_bias",
		"ai_object_set_targeting_ranges",
		"ai_object_enable_targeting_from_vehicle",
		"ai_object_enable_grenade_attack",
		"ai_vehicle_get",
		"ai_vehicle_get_from_starting_location",
		"ai_vehicle_get_from_spawn_point",
		"ai_vehicle_get_squad_count",
		"ai_vehicle_get_from_squad",
		"ai_vehicle_reserve_seat",
		"ai_vehicle_reserve",
		"ai_player_get_vehicle_squad",
		"ai_vehicle_count",
		"ai_carrying_player",
		"player_in_vehicle",
		"ai_player_needs_vehicle",
		"ai_player_any_needs_vehicle",
		"ai_vehicle_enter0",
		"ai_vehicle_enter1",
		"ai_vehicle_enter_immediate0",
		"ai_vehicle_enter_immediate1",
		"ai_enter_squad_vehicles",
		"ai_vehicle_exit0",
		"ai_vehicle_exit1",
		"vehicle_overturned",
		"vehicle_flip",
		"ai_squad_group_get_squad",
		"ai_squad_group_get_squad_count",
		"ai_squad_patrol_enable",
		"ai_combat_status",
		"ai_set_combat_status",
		"flock_start",
		"flock_stop",
		"flock_create",
		"flock_delete",
		"flock_destroy",
		"flock_definition_set",
		"flock_unperch",
		"flock_set_targeting_group",
		"flock_destination_set_enabled",
		"flock_destination_set_position",
		"flock_destination_copy_position",
		"drop_ai",
		"ai_create_runtime_squad",
		"ai_create_runtime_point_set",
		"ai_add_runtime_point_to_set",
		"ai_add_runtime_point_to_set_from_camera",
		"ai_add_starting_location_to_squad",
		"ai_add_starting_location_to_squad_from_camera",
		"ai_add_cell_to_runtime_squad",
		"ai_get_runtime_squad_cell_count",
		"ai_set_squad_team",
		"ai_set_spawn_point_weapons",
		"ai_set_spawn_point_vehicle",
		"ai_set_spawn_point_variants",
		"ai_set_squad_cell_spawn_count",
		"ai_clear_runtime_squads",
		"ai_remove_pointset",
		"ai_verify_tags",
		"ai_wall_lean",
		"ai_fire_dialogue_event",
		"play_vocalization_on_team0",
		"play_vocalization_on_team1",
		"ai_play_line",
		"ai_play_line_at_player",
		"ai_play_line_on_object0",
		"ai_play_line_on_object1",
		"ai_play_line_on_point_set0",
		"ai_play_line_on_point_set1",
		"campaign_metagame_time_pause",
		"campaign_metagame_award_points",
		"campaign_metagame_award_skull",
		"campaign_metagame_enabled",
		"campaign_survival_enabled",
		"thespian_performance_activate0",
		"thespian_folder_activate",
		"thespian_folder_deactivate",
		"thespian_performance_activate1",
		"thespian_performance_setup_and_begin",
		"performance_new",
		"cast_squad_in_performance",
		"performance_begin",
		"thespian_performance_kill_by_name",
		"thespian_performance_kill_by_ai",
		"thespian_fake_task_transition",
		"performance_play_line_by_id",
		"performance_play_line",
		"performance_get_actor_by_index",
		"performance_get_actor",
		"performance_get_actor_count",
		"performance_get_role_count",
		"performance_get_line_count",
		"performance_get_last_played_line_index",
		"thespian_performance_is_blocked",
		"actor_from_performance",
		"ai_player_add_fireteam_squad",
		"ai_player_remove_fireteam_squad",
		"ai_player_set_fireteam_max",
		"ai_player_set_no_fireteam_max",
		"ai_player_set_fireteam_max_squad_absorb_distance",
		"ai_set_fireteam_absorber",
		"ai_set_fireteam_fallback_squad",
		"ai_is_in_fireteam",
		"cs_run_command_script",
		"cs_queue_command_script",
		"cs_stack_command_script",
		"vs_cast0",
		"vs_cast1",
		"vs_cast2",
		"vs_cast3",
		"vs_cast4",
		"vs_cast5",
		"vs_cast6",
		"vs_role",
		"vs_abort_on_alert",
		"vs_abort_on_damage",
		"vs_abort_on_combat_status",
		"vs_abort_on_vehicle_exit",
		"cs_abort_on_alert0",
		"vs_abort_on_alert1",
		"cs_abort_on_damage0",
		"vs_abort_on_damage1",
		"cs_abort_on_combat_status0",
		"vs_abort_on_combat_status1",
		"cs_abort_on_vehicle_exit0",
		"vs_abort_on_vehicle_exit1",
		"cs_command_script_running",
		"cs_command_script_attached",
		"cs_number_queued",
		"",
		"",
		"cs_fly_to0",
		"vs_fly_to0",
		"cs_fly_to1",
		"vs_fly_to1",
		"cs_fly_to_and_face0",
		"vs_fly_to_and_face0",
		"cs_fly_to_and_face1",
		"vs_fly_to_and_face1",
		"cs_fly_by0",
		"vs_fly_by0",
		"cs_fly_by1",
		"vs_fly_by1",
		"cs_go_to0",
		"vs_go_to0",
		"cs_go_to1",
		"vs_go_to1",
		"cs_go_by2",
		"vs_go_by2",
		"cs_go_by3",
		"vs_go_by3",
		"cs_go_to_and_face",
		"vs_go_to_and_face",
		"cs_go_to_and_posture",
		"vs_go_to_and_posture",
		"cs_attach_to_spline",
		"vs_go_to_nearest0",
		"cs_go_to_nearest",
		"vs_go_to_nearest1",
		"cs_move_in_direction",
		"vs_move_in_direction",
		"cs_move_towards0",
		"vs_move_towards0",
		"cs_move_towards1",
		"vs_move_towards1",
		"cs_move_towards_point",
		"vs_move_towards_point",
		"cs_swarm_to",
		"vs_swarm_to",
		"cs_swarm_from",
		"vs_swarm_from",
		"cs_pause",
		"vs_pause",
		"cs_grenade",
		"vs_grenade",
		"cs_use_equipment",
		"vs_use_equipment",
		"cs_jump",
		"vs_jump",
		"cs_jump_to_point",
		"vs_jump_to_point",
		"cs_vocalize",
		"vs_vocalize",
		"cs_play_sound0",
		"vs_play_sound0",
		"cs_play_sound1",
		"vs_play_sound1",
		"cs_play_sound2",
		"vs_play_sound2",
		"cs_action",
		"vs_action",
		"cs_action_at_object",
		"vs_action_at_object",
		"cs_action_at_player",
		"vs_action_at_player",
		"cs_custom_animation0",
		"vs_custom_animation0",
		"cs_custom_animation1",
		"vs_custom_animation1",
		"cs_custom_animation_death0",
		"vs_custom_animation_death0",
		"cs_custom_animation_death1",
		"vs_custom_animation_death1",
		"cs_custom_animation_loop0",
		"vs_custom_animation_loop0",
		"cs_custom_animation_loop1",
		"vs_custom_animation_loop1",
		"cs_play_line",
		"vs_play_line",
		"cs_die",
		"vs_die",
		"cs_deploy_turret",
		"vs_deploy_turret",
		"cs_approach",
		"vs_approach",
		"cs_approach_player",
		"vs_approach_player",
		"cs_go_to_vehicle0",
		"vs_go_to_vehicle0",
		"cs_go_to_vehicle1",
		"vs_go_to_vehicle1",
		"cs_set_style",
		"vs_set_style",
		"cs_force_combat_status",
		"vs_force_combat_status",
		"cs_enable_targeting",
		"vs_enable_targeting",
		"cs_enable_looking",
		"vs_enable_looking",
		"cs_enable_moving",
		"vs_enable_moving",
		"cs_enable_dialogue",
		"vs_enable_dialogue",
		"cs_suppress_activity_termination",
		"vs_suppress_activity_termination",
		"cs_suppress_dialogue_global",
		"vs_suppress_dialogue_global",
		"cs_look",
		"vs_look",
		"cs_look_player",
		"vs_look_player",
		"cs_look_object",
		"vs_look_object",
		"cs_aim",
		"vs_aim",
		"cs_aim_player",
		"vs_aim_player",
		"cs_aim_object",
		"vs_aim_object",
		"cs_face",
		"vs_face",
		"cs_face_player",
		"vs_face_player",
		"cs_face_object",
		"vs_face_object",
		"cs_shoot0",
		"vs_shoot0",
		"cs_shoot1",
		"vs_shoot1",
		"cs_shoot_point",
		"vs_shoot_point",
		"cs_shoot_secondary_trigger",
		"vs_shoot_secondary_trigger",
		"cs_lower_weapon",
		"vs_lower_weapon",
		"cs_vehicle_speed",
		"vs_vehicle_speed",
		"cs_vehicle_speed_instantaneous",
		"vs_vehicle_speed_instantaneous",
		"cs_vehicle_boost",
		"vs_vehicle_boost",
		"cs_turn_sharpness",
		"vs_turn_sharpness",
		"cs_enable_pathfinding_failsafe",
		"vs_enable_pathfinding_failsafe",
		"cs_set_pathfinding_radius",
		"vs_set_pathfinding_radius",
		"cs_ignore_obstacles",
		"vs_ignore_obstacles",
		"cs_approach_stop",
		"vs_approach_stop",
		"cs_push_stance",
		"vs_movement_mode",
		"cs_crouch0",
		"vs_crouch0",
		"cs_crouch1",
		"vs_crouch1",
		"cs_walk",
		"vs_walk",
		"cs_posture_set",
		"vs_posture_set",
		"cs_posture_exit",
		"vs_posture_exit",
		"cs_stow",
		"vs_stow",
		"cs_teleport",
		"vs_teleport",
		"cs_stop_custom_animation",
		"vs_stop_custom_animation",
		"cs_stop_sound",
		"vs_stop_sound",
		"cs_player_melee",
		"vs_player_melee",
		"cs_melee_direction",
		"vs_melee_direction",
		"cs_smash_direction",
		"vs_smash_direction",
		"camera_control",
		"camera_set",
		"camera_set_relative",
		"camera_set_animation",
		"camera_set_animation_relative",
		"camera_set_animation_with_speed",
		"camera_set_animation_relative_with_speed",
		"camera_set_animation_relative_with_speed_loop",
		"camera_set_animation_relative_with_speed_loop_offset",
		"camera_predict_resources_at_frame",
		"camera_predict_resources_at_point",
		"camera_set_first_person",
		"camera_set_cinematic",
		"camera_set_cinematic_scene",
		"camera_place_relative",
		"camera_place_worldspace",
		"camera_time",
		"camera_set_field_of_view",
		"cinematic_camera_set_easing_in",
		"cinematic_camera_set_easing_out",
		"cinematic_print",
		"camera_set_pan",
		"camera_pan",
		"debug_camera_save",
		"debug_camera_load",
		"debug_camera_save_name",
		"debug_camera_load_name",
		"debug_camera_save_simple_name",
		"debug_camera_load_simple_name",
		"debug_camera_load_text",
		"director_debug_camera",
		"director_print_camera_transform",
		"director_print_deterministic_camera_transform",
		"game_difficulty_get",
		"game_difficulty_get_real",
		"game_insertion_point_get",
		"pvs_set_object",
		"pvs_set_camera",
		"pvs_clear",
		"pvs_reset",
		"players_unzoom_all",
		"player_enable_input",
		"player_disable_movement",
		"player_disable_weapon_pickup",
		"player_night_vision_on",
		"unit_night_vision_on",
		"player_active_camouflage_on",
		"player_camera_control",
		"player_action_test_reset",
		"player_action_test_primary_trigger",
		"player_action_test_grenade_trigger",
		"player_action_test_vision_trigger",
		"player_action_test_rotate_weapons",
		"player_action_test_rotate_grenades",
		"player_action_test_jump",
		"player_action_test_equipment",
		"player_action_test_context_primary",
		"player_action_test_vehicle_trick_primary",
		"player_action_test_vehicle_trick_secondary",
		"player_action_test_melee",
		"player_action_test_action",
		"player_action_test_accept",
		"player_action_test_cancel",
		"player_action_test_look_relative_up",
		"player_action_test_look_relative_down",
		"player_action_test_look_relative_left",
		"player_action_test_look_relative_right",
		"player_action_test_look_relative_all_directions",
		"player_action_test_move_relative_all_directions",
		"player_action_test_cinematic_skip",
		"player_action_test_start",
		"player_action_test_back",
		"player_action_test_dpad_up",
		"player_action_test_dpad_down",
		"player_action_test_dpad_left",
		"player_action_test_dpad_right",
		"unit_action_test_reset",
		"unit_action_test_primary_trigger",
		"unit_action_test_grenade_trigger",
		"unit_action_test_vision_trigger",
		"unit_action_test_rotate_weapons",
		"unit_action_test_rotate_grenades",
		"unit_action_test_jump",
		"unit_action_test_equipment",
		"unit_action_test_context_primary",
		"unit_action_test_vehicle_trick_primary",
		"unit_action_test_vehicle_trick_secondary",
		"unit_action_test_melee",
		"unit_action_test_action",
		"unit_action_test_accept",
		"unit_action_test_cancel",
		"unit_action_test_look_relative_up",
		"unit_action_test_look_relative_down",
		"unit_action_test_look_relative_left",
		"unit_action_test_look_relative_right",
		"unit_action_test_look_relative_all_directions",
		"unit_action_test_move_relative_all_directions",
		"unit_action_test_cinematic_skip",
		"unit_action_test_start",
		"unit_action_test_back",
		"unit_action_test_dpad_up",
		"unit_action_test_dpad_down",
		"unit_action_test_dpad_left",
		"unit_action_test_dpad_right",
		"unit_confirm_message",
		"unit_confirm_cancel_message",
		"unit_enable_soft_ping_region",
		"unit_print_soft_ping_regions",
		"player0_looking_up",
		"player0_looking_down",
		"player_set_pitch",
		"player_has_female_voice",
		"player_action_test_lookstick_forward",
		"player_action_test_lookstick_backward",
		"debug_teleport_player",
		"scenario_content_status_reload",
		"scenario_content_status_force_local",
		"scenario_content_status_force_content",
		"scenario_content_status_force_clear",
		"map_reset",
		"",
		"switch_zone_set",
		"",
		"",
		"current_zone_set",
		"current_zone_set_fully_active",
		"switch_map_and_zone_set",
		"crash",
		"version",
		"status",
		"record_movie",
		"record_movie_distributed",
		"screenshot",
		"screenshot_debug",
		"screenshot_big",
		"screenshot_big_raw",
		"screenshot_size",
		"",
		"",
		"",
		"cubemap_dynamic_generate",
		"object_snapshot",
		"structure_instance_snapshot",
		"object_thumbnail",
		"main_menu",
		"main_halt",
		"map_name",
		"module",
		"",
		"",
		"game_player_count",
		"game_set_variant",
		"game_splitscreen",
		"game_difficulty",
		"",
		"",
		"",
		"",
		"game_start",
		"game_start_when_ready",
		"game_start_when_joined",
		"game_rate",
		"texture_cache_flush",
		"geometry_cache_flush",
		"sound_cache_flush",
		"animation_cache_flush",
		"font_cache_flush",
		"language_set",
		"texture_cache_test_malloc",
		"tags_verify_all0",
		"debug_memory_by_file",
		"debug_memory_for_file",
		"debug_tags",
		"debug_single_tag",
		"tags_verify_all1",
		"trace_next_frame",
		"trace_next_frame_to_file",
		"trace_tick",
		"collision_log_enable",
		"damage_control_get",
		"damage_control_set",
		"",
		"ai_dialogue_break_on_vocalization",
		"fade_in",
		"fade_out",
		"fade_in_for_player",
		"fade_out_for_player",
		"cinematic_tag_fade_out_from_game",
		"cinematic_tag_fade_in_to_cinematic",
		"cinematic_tag_fade_out_from_cinematic",
		"cinematic_tag_fade_in_to_game",
		"cinematic_transition_fade_out_from_game",
		"cinematic_transition_in_to_cinematic",
		"cinematic_transition_out_from_cinematic",
		"cinematic_transition_fade_in_to_game",
		"cinematic_run_script_by_name",
		"cinematic_start",
		"cinematic_stop",
		"cinematic_skip_start_internal",
		"cinematic_skip_stop_internal",
		"cinematic_show_letterbox",
		"cinematic_show_letterbox_immediate",
		"cinematic_set_title",
		"cinematic_set_title_delayed",
		"cinematic_suppress_bsp_object_creation",
		"cinematic_subtitle",
		"cinematic_set",
		"cinematic_set_shot",
		"cinematic_get_shot",
		"cinematic_set_early_exit",
		"cinematic_get_early_exit",
		"cinematic_set_active_camera",
		"cinematic_object_create",
		"cinematic_object_create_cinematic_anchor",
		"cinematic_object_destroy",
		"cinematic_objects_destroy_all",
		"cinematic_destroy",
		"cinematic_in_progress",
		"cinematic_can_be_skipped",
		"cinematic_clips_initialize_for_shot",
		"cinematic_clips_destroy",
		"cinematic_lights_initialize_for_shot",
		"cinematic_lights_destroy",
		"cinematic_lights_destroy_shot",
		"cinematic_light_object",
		"cinematic_light_object_off",
		"cinematic_lighting_rebuild_all",
		"",
		"",
		"",
		"",
		"",
		"cinematic_object_get",
		"cinematic_unit_get",
		"cinematic_weapon_get",
		"",
		"camera_set_briefing",
		"cinematic_tag_reference_get_cinematic",
		"cinematic_tag_reference_get_scene",
		"cinematic_tag_reference_get_effect",
		"cinematic_tag_reference_get_dialogue",
		"cinematic_tag_reference_get_music",
		"cinematic_tag_reference_get_music_looping",
		"cinematic_tag_reference_get_animation",
		"cinematic_scripting_object_coop_flags_valid",
		"cinematic_scripting_fade_out",
		"cinematic_scripting_create_object",
		"cinematic_scripting_create_cinematic_object",
		"cinematic_scripting_start_animation",
		"cinematic_scripting_destroy_object",
		"cinematic_scripting_destroy_objects",
		"cinematic_scripting_create_scene",
		"cinematic_scripting_destroy_scene",
		"cinematic_scripting_start_effect",
		"cinematic_scripting_start_music",
		"cinematic_scripting_start_dialogue",
		"cinematic_scripting_stop_music",
		"cinematic_scripting_start_screen_effect",
		"cinematic_scripting_stop_screen_effect",
		"cinematic_scripting_create_and_animate_object",
		"cinematic_scripting_create_and_animate_cinematic_object",
		"cinematic_scripting_create_and_animate_object_no_animation",
		"cinematic_scripting_create_and_animate_cinematic_object_no_animation",
		"cinematic_scripting_set_user_input_constraints",
		"attract_mode_start",
		"attract_mode_set_seconds",
		"game_won",
		"game_lost",
		"game_revert",
		"game_award_level_complete_achievements",
		"game_is_cooperative",
		"game_is_playtest",
		"game_can_use_flashlights",
		"game_save_and_quit",
		"game_save_unsafe",
		"game_insertion_point_unlock",
		"game_insertion_point_lock",
		"game_insertion_point_set",
		"saved_games_delete_campaign_save",
		"saved_games_autosave_free_up_space",
		"achievement_grant_to_player",
		"achievement_grant_to_controller",
		"achievement_grant_to_all_players",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"debug_spawning_target",
		"debug_spawning_use_history",
		"debug_initial_spawn_point_objects",
		"debug_respawn_point_objects",
		"game_export_variant_settings",
		"game_engine_event_test_general",
		"game_engine_event_test_flavor",
		"core_load",
		"core_load_name",
		"core_save",
		"core_save_name",
		"core_load_game",
		"core_load_game_name",
		"core_regular_upload_to_debug_server",
		"core_set_upload_option",
		"core_force_immediate_save_on_core_load",
		"force_debugger_not_present",
		"force_debugger_always_present",
		"game_safe_to_save",
		"game_safe_to_speak",
		"game_all_quiet",
		"game_save",
		"game_save_cancel",
		"game_save_no_timeout",
		"game_save_immediate",
		"game_saving",
		"game_reverted",
		"survival_mode_respawn_dead_players",
		"survival_mode_lives_get",
		"survival_mode_lives_set",
		"survival_mode_get_mp_round_count",
		"survival_mode_get_mp_round_current",
		"survival_mode_set_get",
		"survival_mode_round_get",
		"survival_mode_waves_per_round",
		"survival_mode_rounds_per_set",
		"survival_mode_wave_get",
		"survival_mode_set_multiplier_get",
		"survival_mode_set_multiplier_set",
		"survival_mode_bonus_multiplier_get",
		"survival_mode_bonus_multiplier_set",
		"survival_mode_get_wave_squad",
		"survival_mode_current_wave_is_initial",
		"survival_mode_current_wave_is_boss",
		"survival_mode_current_wave_is_bonus",
		"survival_mode_current_wave_is_last_in_set",
		"survival_mode_begin_new_set",
		"survival_mode_begin_new_wave",
		"survival_mode_end_set",
		"survival_mode_end_wave",
		"survival_mode_award_hero_medal",
		"survival_mode_incident_new",
		"chud_bonus_round_show_timer",
		"chud_bonus_round_start_timer",
		"chud_bonus_round_set_timer",
		"survival_mode_get_time_limit",
		"survival_mode_get_set_count",
		"survival_mode_get_round_count",
		"survival_mode_get_wave_count",
		"survival_mode_get_shared_team_life_count",
		"survival_mode_get_elite_life_count",
		"survival_mode_max_lives",
		"survival_mode_generator_count",
		"survival_mode_bonus_lives_elite_death",
		"survival_mode_scenario_extras_enable",
		"survival_mode_weapon_drops_enable",
		"survival_mode_ammo_crates_enable",
		"survival_mode_generator_defend_all",
		"survival_mode_generator_random_spawn",
		"survival_mode_current_wave_uses_dropship",
		"survival_mode_get_current_wave_time_limit",
		"survival_mode_get_respawn_time_seconds",
		"survival_mode_team_respawns_on_wave",
		"survival_mode_sudden_death",
		"survival_increment_human_score",
		"survival_increment_elite_score",
		"survival_mode_set_spartan_license_plate",
		"survival_mode_set_elite_license_plate",
		"survival_mode_player_count_by_team",
		"survival_mode_players_by_team",
		"sound_impulse_predict",
		"sound_impulse_trigger",
		"sound_impulse_start",
		"sound_impulse_start_cinematic",
		"sound_impulse_start_effect",
		"sound_impulse_start_with_subtitle",
		"sound_impulse_time0",
		"sound_impulse_time1",
		"sound_impulse_language_time",
		"sound_impulse_stop",
		"sound_impulse_start_3d",
		"sound_impulse_mark_as_outro",
		"sound_impulse_start_naked",
		"sound_preload_dialogue_sounds",
		"sound_looping_predict",
		"sound_looping_start0",
		"sound_looping_start1",
		"",
		"sound_looping_stop",
		"sound_looping_stop_immediately",
		"sound_looping_set_scale",
		"sound_looping_set_alternate",
		"sound_looping_activate_layer",
		"sound_looping_deactivate_layer",
		"sound_loop_spam",
		"sound_class_show_channel",
		"sound_class_debug_sound_start",
		"debug_sounds_enable",
		"sound_class_set_gain",
		"sound_class_set_gain_db",
		"sound_class_enable_ducker",
		"debug_sound_environment_parameter",
		"sound_start_global_effect0",
		"sound_start_global_effect1",
		"sound_stop_global_effect",
		"sound_enable_acoustic_palette",
		"sound_disable_acoustic_palette",
		"vehicle_force_alternate_state",
		"vehicle_auto_turret",
		"vehicle_hover",
		"vehicle_count_bipeds_killed",
		"biped_ragdoll",
		"water_float_reset",
		"hud_show_training_text",
		"hud_set_training_text",
		"hud_enable_training",
		"player_training_activate_flashlight",
		"player_training_activate_crouch",
		"player_training_activate_stealth",
		"player_training_activate_equipment",
		"player_training_activate_jump",
		"player_training_reset",
		"",
		"chud_show_all",
		"",
		"chud_show_crosshair",
		"chud_show_shield",
		"chud_show_grenades",
		"chud_show_messages",
		"chud_show_motion_sensor",
		"chud_show_cinematics",
		"chud_fade_weapon_stats_for_player",
		"chud_fade_crosshair_for_player",
		"chud_fade_shield_for_player",
		"chud_fade_grenades_for_player",
		"chud_fade_messages_for_player",
		"chud_fade_motion_sensor_for_player",
		"chud_fade_chapter_title_for_player",
		"",
		"chud_cinematic_fade",
		"chud_track_object",
		"chud_track_object_with_priority0",
		"chud_track_object_with_priority1",
		"chud_track_flag",
		"chud_track_flag_with_priority0",
		"chud_track_flag_with_priority1",
		"chud_track_object_for_player",
		"chud_track_object_for_player_with_priority0",
		"chud_track_object_for_player_with_priority1",
		"chud_track_flag_for_player",
		"chud_track_flag_for_player_with_priority0",
		"chud_track_flag_for_player_with_priority1",
		"chud_track_object_set_vertical_offset",
		"chud_track_flag_set_vertical_offset",
		"chud_post_message",
		"",
		"",
		"chud_set_static_hs_variable",
		"chud_set_countdown_hs_variable",
		"chud_set_countup_hs_variable",
		"chud_clear_hs_variable",
		"",
		"chud_show_arbiter_ai_navpoint",
		"chud_show_screen_objective",
		"chud_show_screen_chapter_title",
		"chud_show_screen_training",
		"cls",
		"error_overflow_suppression",
		"error_geometry_show",
		"error_geometry_hide",
		"error_geometry_show_all",
		"error_geometry_hide_all",
		"error_geometry_list",
		"player_effect_set_max_translation",
		"player_effect_set_max_rotation",
		"player_effect_set_max_rumble",
		"player_effect_start",
		"player_effect_stop",
		"player_effect_set_max_translation_for_player",
		"player_effect_set_max_rotation_for_player",
		"player_effect_set_max_rumble_for_player",
		"player_effect_start_for_player",
		"player_effect_stop_for_player",
		"time_code_show",
		"time_code_start",
		"time_code_reset",
		"script_screen_effect_set_value",
		"cinematic_screen_effect_start",
		"cinematic_screen_effect_set_crossfade0",
		"cinematic_screen_effect_set_crossfade1",
		"cinematic_screen_effect_stop",
		"cinematic_set_near_clip_distance",
		"cinematic_set_far_clip_distance",
		"render_atmosphere_fog",
		"motion_blur",
		"antialias_blur",
		"render_weather",
		"render_patchy_fog",
		"render_ssao",
		"",
		"motion_blur_enabled",
		"",
		"cinematic_set_environment_map_attenuation",
		"cinematic_set_environment_map_bitmap",
		"cinematic_reset_environment_map_bitmap",
		"cinematic_set_environment_map_tint",
		"cinematic_reset_environment_map_tint",
		"cinematic_layer",
		"player_has_skills",
		"player_has_mad_secret_skills",
		"controller_invert_look",
		"controller_look_speed",
		"player_invert_look",
		"controller_unlock_solo_levels",
		"controller_set_look_inverted",
		"controller_set_vibration_enabled",
		"controller_set_flight_stick_aircraft_controls",
		"controller_set_auto_center_look",
		"controller_set_crouch_lock",
		"controller_set_southpaw",
		"controller_set_clench_protection",
		"controller_set_button_preset",
		"controller_set_custom_button",
		"controller_set_joystick_preset",
		"controller_set_look_sensitivity",
		"controller_unlock_single_player_levels",
		"controller_lock_single_player_levels",
		"controller_unlock_skulls",
		"controller_lock_skulls",
		"controller_unlock_models",
		"controller_lock_models",
		"controller_set_single_player_level_completed",
		"controller_set_primary_change_color",
		"controller_set_secondary_change_color",
		"controller_set_tertiary_change_color",
		"controller_set_primary_emblem_color",
		"controller_set_secondary_emblem_color",
		"controller_set_background_emblem_color",
		"controller_set_player_character_type",
		"controller_set_emblem_info",
		"controller_set_voice_output_setting",
		"controller_set_subtitle_setting",
		"controller_set_nag_message_data",
		"controller_temporary_users_always_attached",
		"controller_set_new_user_experience",
		"controller_set_initial_bonus_toast",
		"controller_set_loyalty_bonus_toast",
		"controller_set_generic_bonus_toast",
		"controller_set_unsignedin_user",
		"controller_display_storage_device_selection",
		"font_cache_bitmap_save",
		"ui_debug_load_main_menu",
		"ui_debug_text_bounds",
		"ui_debug_text_font",
		"ui_debug_show_title_safe_bounds",
		"ui_debug_element_bounds",
		"ui_memory_dump",
		"ui_time_scale_step",
		"xoverlapped_debug_render",
		"shader_compile_target_platform",
		"shader_compile_shader_pipeline",
		"shader_compile_filter_shader_type",
		"shader_compile_filter_category_option",
		"gui_load_screen",
		"gui_reset",
		"gui_start",
		"gui_stop",
		"gui_error_post",
		"gui_error_post_toast",
		"gui_error_resolve",
		"gui_error_clear",
		"gui_dialog_show",
		"gui_debug_music_state",
		"cc_enable",
		"cc_test",
		"objectives_clear",
		"objectives_show_up_to",
		"objectives_finish_up_to",
		"objectives_show",
		"objectives_finish",
		"objectives_unavailable",
		"objectives_secondary_show",
		"objectives_secondary_finish",
		"objectives_secondary_unavailable",
		"objectives_set_string",
		"objectives_secondary_set_string",
		"objectives_show_string",
		"objectives_finish_string",
		"objectives_unavailable_string",
		"objectives_secondary_show_string",
		"objectives_secondary_finish_string",
		"objectives_secondary_unavailable_string",
		"input_suppress_rumble",
		"input_disable_claw_button_combos",
		"update_remote_camera",
		"net_build_network_config",
		"net_build_game_variant",
		"net_verify_game_variant",
		"net_load_and_use_game_variant",
		"net_use_hopper_directory",
		"net_lsp_dump_services_and_servers",
		"net_lsp_force_server",
		"net_lsp_disable_server",
		"net_lsp_disable_service",
		"net_quality_dump",
		"net_quality_clear",
		"net_quality_set_connection_badness_history",
		"net_quality_set_squad_host_badness_history",
		"net_quality_set_squad_client_badness_history",
		"net_quality_set_squad_speculative_migration_badness_history",
		"net_quality_set_squad_bridging_badness_history",
		"net_quality_set_group_host_badness_history",
		"net_quality_set_group_client_badness_history",
		"net_quality_set_group_speculative_migration_badness_history",
		"net_quality_set_group_bridging_badness_history",
		"net_join_friend",
		"net_join_squad_to_friend",
		"net_join_sessionid",
		"net_join_squad_to_sessionid",
		"net_enable_join_friend_loop",
		"net_set_maximum_player_count",
		"net_status_filter",
		"net_test_ping",
		"net_test_channel_delete",
		"net_test_delegate_host",
		"net_test_delegate_leader",
		"net_test_map_name",
		"net_test_variant",
		"net_test_campaign_difficulty",
		"net_test_player_color",
		"net_test_reset_objects",
		"net_test_fatal_error",
		"net_set_machine_name",
		"events_enabled",
		"events_suppression",
		"events_suppress_display",
		"events_global_display",
		"events_global_log",
		"events_global_debugger",
		"events_global_datamine",
		"events_category_display",
		"events_category_force_display",
		"events_category_log",
		"events_category_debugger",
		"events_category_debugger_break",
		"events_category_halt",
		"events_category_datamine",
		"events_dump_file",
		"event_logs_snapshot",
		"events_disable_suppression",
		"event_global_display_category",
		"event_global_log_category",
		"event_global_remote_log_category",
		"event_display_category",
		"event_force_display_category",
		"event_debugger_break_category",
		"event_halt_category",
		"event_list_categories",
		"events_suppress_console_display",
		"play_bink_movie",
		"play_bink_movie_from_tag",
		"play_credits",
		"bink_time",
		"set_global_doppler_factor",
		"set_global_mixbin_headroom",
		"debug_sound_environment_source_parameter",
		"data_mine_set_mission_segment",
		"data_mine_insert",
		"data_mine_upload",
		"data_mine_enable",
		"data_mine_flush",
		"data_mine_debug_menu_setting",
		"data_mine_open_debug_menu",
		"data_mine_set_display_mission_segment",
		"data_mine_set_header_flag",
		"test_memory_allocators0",
		"test_memory_allocators1",
		"display_video_standard",
		"test_xcr_monkey_enable",
		"test_show_guide_status",
		"test_show_users_xuids",
		"test_show_are_users_friends",
		"test_invite_friend",
		"test_get_squad_session_id",
		"cui_get_active_screens",
		"cui_get_screen_components",
		"cui_get_component_properties",
		"cui_send_button_press",
		"cui_invoke_list_item_by_string_id",
		"cui_invoke_list_item_by_long",
		"cui_invoke_list_item_by_boolean",
		"cui_invoke_list_item_by_text",
		"test_download_storage_file",
		"test_game_results_save_to_file",
		"test_game_results_load_from_file",
		"test_game_results_make_random",
		"test_fragment_utility_drive",
		"clear_webcache",
		"online_files_upload",
		"online_files_throttle_bandwidth",
		"online_marketplace_refresh",
		"webstats_disable",
		"webstats_test_submit",
		"webstats_test_submit_random_realistic",
		"webstats_throttle_bandwidth",
		"webstats_log_uploads",
		"flag_new",
		"flag_new_at_look",
		"flags_clear",
		"flags_default_name",
		"flags_default_comment",
		"flags_set_filter",
		"bug_now",
		"bug_now_lite",
		"bug_now_auto",
		"bug_now_on_next_kill",
		"object_list_children",
		"voice_set_outgoing_channel_count",
		"voice_set_voice_repeater_peer_index",
		"voice_set_mute",
		"net_leaderboard_clear_hopper",
		"net_leaderboard_clear_global_unarbitrated",
		"net_leaderboard_refresh",
		"ai_selected_actor_jump",
		"dump_loaded_tags",
		"interpolator_start",
		"interpolator_stop",
		"interpolator_stop_all",
		"interpolator_dump",
		"interpolator_dump_all",
		"set_pc_runtime_language",
		"animation_cache_stats_reset",
		"cinematic_clone_players_weapon",
		"cinematic_move_attached_objects",
		"vehicle_enable_ghost_effects",
		"set_global_sound_environment",
		"reset_dsp_image",
		"game_save_cinematic_skip",
		"cinematic_outro_start",
		"cinematic_enable_ambience_details",
		"rasterizer_bloom_override",
		"rasterizer_bloom_override_reset",
		"rasterizer_bloom_override_blur_amount",
		"rasterizer_bloom_override_threshold",
		"rasterizer_bloom_override_brightness",
		"rasterizer_bloom_override_box_factor",
		"rasterizer_bloom_override_max_factor",
		"rasterizer_bloom_override_silver_bullet",
		"rasterizer_bloom_override_only",
		"rasterizer_bloom_override_high_res",
		"rasterizer_bloom_override_brightness_alpha",
		"rasterizer_bloom_override_max_factor_alpha",
		"cache_block_for_one_frame",
		"sound_suppress_ambience_update_on_revert",
		"render_autoexposure_enable",
		"render_exposure_full",
		"render_exposure_fade_in",
		"render_exposure_fade_out",
		"render_exposure",
		"render_autoexposure_instant",
		"render_exposure_set_environment_darken",
		"render_depth_of_field_enable",
		"render_depth_of_field",
		"",
		"render_dof_blur_animate",
		"render_debug_video_mode",
		"cinematic_lightmap_shadow_disable",
		"cinematic_lightmap_shadow_enable",
		"predict_animation",
		"mp_player_count_by_team",
		"mp_players_by_team",
		"mp_active_player_count_by_team",
		"deterministic_end_game",
		"mp_game_won",
		"mp_respawn_override_timers",
		"mp_ai_allegiance",
		"mp_allegiance",
		"mp_round_started",
		"mp_round_end_with_winning_player",
		"mp_round_end_with_winning_team",
		"mp_round_end",
		"mp_scripts_reset",
		"tag_file_set_backend",
		"mp_debug_goal_object_boundary_geometry",
		"mp_dump_candy_monitor_state",
		"determinism_debug_manager_enable_logging",
		"determinism_debug_manager_set_trace_flags",
		"determinism_debug_manager_enable_game_state_checksum",
		"determinism_debug_manager_enable_trace",
		"determinism_debug_manager_set_consumer_sample_level",
		"determinism_log_compare_log_files",
		"determinism_debug_manager_enable_log_file_comparision_on_oos",
		"saved_film_play",
		"saved_film_play_last",
		"saved_film_disable_version_checking",
		"saved_film_toggle_debug_saving",
		"saved_films_show_timestamp",
		"mover_set_program",
		"floating_point_exceptions_enable",
		"tag_reload_force",
		"tag_unload_force",
		"tag_load_force",
		"predict_bink_movie",
		"predict_bink_movie_from_tag",
		"profiler_dump_history",
		"camera_set_mode",
		"camera_set_flying_cam_at_point",
		"camera_set_target",
		"camera_set_orbiting_cam_at_target_relative_point",
		"director_cycle_debug_camera",
		"game_coop_player_count",
		"player_force_mode",
		"profiler_output_pulse",
		"string_id_name",
		"find",
		"add_recycling_volume",
		"add_recycling_volume_by_type",
		"tag_resources_set_per_frame_publish",
		"",
		"",
		"",
		"",
		"network_storage_set_storage_subdirectory",
		"network_storage_set_storage_user",
		"network_storage_run_locally",
		"status_line_dump",
		"game_tick_get",
		"loop_it",
		"loop_clear",
		"status_lines_enable",
		"status_lines_disable",
		"on_target_platform",
		"f7_profiler_enable",
		"f7_profiler_substring_activate",
		"f7_profiler_substring_deactivate",
		"net_game_set_player_standing",
		"net_get_game_id",
		"generate_rsa_2048_key_pair",
		"create_secure_test_file",
		"net_test_matchmaking_hopper_list",
		"net_test_matchmaking_hopper_game_list",
		"net_test_matchmaking_hopper_set_game",
		"net_test_matchmaking_set_voting_system",
		"net_test_matchmaking_set_arena_season",
		"net_test_matchmaking_suppress_arena_popup",
		"net_test_matchmaking_test_arena_screen",
		"net_test_matchmaking_set_arena_stats",
		"saved_film_set_playback_game_speed",
		"noguchis_mystery_tour",
		"designer_zone_sync",
		"dump_designer_zone",
		"designer_zone_activate",
		"designer_zone_deactivate",
		"object_set_always_active",
		"saved_film_seek_to_film_tick",
		"saved_film_seek_to_film_timestamp",
		"tag_is_active",
		"tag_resources_set_incremental_publish",
		"tag_resources_enable_optional_caching",
		"dump_active_resources",
		"object_set_persistent",
		"display_zone_size_estimates",
		"report_zone_size_estimates",
		"net_test_disconnect_squad",
		"net_test_disconnect_group",
		"net_test_clear_squad_session_parameter",
		"net_test_clear_group_session_parameter",
		"net_test_life_cycle_pause",
		"net_test_life_cycle_display_states",
		"net_test_life_cycle_abort_matchmaking",
		"overlapped_display_task_descriptions",
		"overlapped_task_inject_error",
		"net_leaderboard_clear_hopper_all_users",
		"net_leaderboard_clear_global_unarbitrated_all_users",
		"",
		"",
		"",
		"",
		"decorators_split",
		"bandwidth_profiler_enable",
		"bandwidth_profiler_set_context",
		"simulation_priority_display_set_enabled",
		"simulation_priority_display_set_object_names",
		"simulation_priority_display_set_machine_filter",
		"simulation_priority_display_set_priority_scope_tick",
		"simulation_priority_display_set_priority_scope_second_worst",
		"simulation_priority_display_set_priority_scope_second_best",
		"simulation_priority_display_set_color_by_relevance",
		"simulation_priority_display_set_color_by_update_period",
		"simulation_priority_display_set_color_by_final_priority",
		"overlapped_task_pause",
		"net_banhammer_set_controller_cheat_flags",
		"net_banhammer_set_controller_ban_flags",
		"net_banhammer_dump_strings",
		"net_banhammer_dump_repeated_play_list",
		"net_banhammer_set_locality_override",
		"net_leaderboard_set_user_stats",
		"net_leaderboard_set_user_game_stats",
		"net_build_map_variant",
		"net_verify_map_variant",
		"net_load_and_use_map_variant",
		"write_current_map_variant",
		"read_map_variant_and_make_current",
		"async_set_thread_work_delay_milliseconds",
		"tag_resources_set_demand_throttle_to_io",
		"tag_resources_flush_optional",
		"set_performance_throttle",
		"get_performance_throttle",
		"voice_set_headset_boost",
		"cinematic_zone_activate",
		"cinematic_zone_deactivate",
		"cinematic_zone_activate_from_editor",
		"cinematic_zone_deactivate_from_editor",
		"tiling_current",
		"unit_limit_lipsync_to_mouth_only",
		"dump_active_zone_tags",
		"",
		"tag_resources_enable_fast_prediction",
		"unit_start_first_person_custom_animation",
		"unit_is_playing_custom_first_person_animation",
		"unit_stop_first_person_custom_animation",
		"prepare_to_switch_to_zone_set",
		"cinematic_zone_activate_for_debugging",
		"unit_play_random_ping",
		"player_control_fade_out_all_input",
		"player_control_fade_in_all_input",
		"player_control_lock_gaze",
		"player_control_unlock_gaze",
		"player_control_scale_all_input",
		"",
		"profiler_auto_core_save",
		"6E6",
		"cinematic_tag_reference_get_bink",
		"voice_set_force_match_configurations",
		"voice_set_force_hud",
		"object_set_custom_animation_speed",
		"scenery_animation_start_at_frame_loop",
		"film_manager_set_reproduction_mode",
		"font_set_emergency",
		"biped_force_ground_fitting_on",
		"cinematic_set_chud_objective",
		"chud_show_cinematic_title",
		"unit_get_primary_weapon",
		"budget_resource_get_animation_graph",
		"budget_resource_get_looping_sound",
		"game_safe_to_respawn0",
		"game_safe_to_respawn1",
		"test_create_content_item_slayer",
		"test_create_content_item_screenshot",
		"test_create_content_blf_screenshot",
		"test_create_content_blf_film",
		"test_create_content_blf_film_clip",
		"test_create_content_blf_game_variant",
		"test_create_content_blf_map_variant",
		"ai_migrate_infanty",
		"render_cinematic_motion_blur",
		"ai_dont_do_avoidance",
		"cinematic_scripting_clean_up",
		"ai_erase_inactive",
		"ai_survival_cleanup",
		"ai_enable_stuck_flying_kill",
		"ai_set_stuck_velocity_threshold",
		"stop_bink_movie",
		"play_credits_unskippable",
		"budget_resource_get_sound",
		"controller_set_single_player_level_unlocked",
		"physical_memory_dump",
		"tag_resources_validate_all_pages",
		"cinematic_set_debug_mode",
		"cinematic_scripting_get_object",
		"player_override_team",
		"unit_set_stance",
		"player_set_stance",
		"sound_impulse_start_editor",
		"sound_impulse_start_effect_editor",
		"sound_impulse_start_3d_editor",
		"sound_looping_start_editor",
		"debug_sound_channels_log_start",
		"debug_sound_channels_log_start_named",
		"debug_sound_channels_log_stop",
		"simulation_profiler_enable",
		"saved_film_insert_marker",
		"saved_film_seek_to_marker",
		"game_currency_issue_award_to_team",
		"",
		"",
		"net_simulation_set_stream_bandwidth",
		"debug_sound_fadeout_time",
		"render_model_marker_name_filter",
		"skull_enable",
		"allow_object_to_be_lased",
		"is_object_being_lased",
		"simulation_profiler_detail_level",
		"simulation_profiler_enable_downstream_processing",
		"campaign_metagame_get_player_score",
		"collision_debug_lightmaps_print",
		"load_binary_game_engine",
		"network_storage_files_display_file_names",
		"network_storage_files_force_download",
		"debug_lightmap_inspect",
		"render_debug_colorbars",
		"voice_force_global_repeater_use",
		"levels_add_campaign_map_with_id",
		"levels_add_campaign_map",
		"levels_add_multiplayer_map",
		"",
		"clear_map_slot",
		"clear_map_type",
		"",
		"debug_objects_unit_seats_filter",
		"debug_lock_enforcement",
		"lsp_presence_dump_blfs",
		"lsp_leaderboard_dump_blfs",
		"rewards_flush",
		"rewards_profile_write",
		"rewards_lsp_sync",
		"rewards_force_unlock_all_purchasable_items",
		"rewards_grant_to_controller",
		"rewards_grant_to_player",
		"rewards_commendation_increment_for_controller",
		"rewards_commendation_increment_for_player",
		"rewards_commendation_set_for_controller",
		"rewards_purchase",
		"rewards_set_player_appearance_from_purchase",
		"rewards_dump",
		"rewards_reinitialize_from_storage",
		"rewards_reset_to_default_state",
		"rewards_get_total",
		"",
		"challenges_enable_lsp_synchronization",
		"challenges_clear",
		"challenges_activate_challenge",
		"challenges_list_active_challenges_for_controller",
		"challenge_advance_for_controller",
		"challenge_complete_for_controller",
		"challenge_advance_for_controller_by_indices",
		"challenge_complete_for_controller_by_indices",
		"cui_set_screen_name_override_prefix",
		"cui_load_screen",
		"cui_load_themed_screen",
		"rewards_get_grade",
		"",
		"exit_experience_set_params",
		"player_profile_clear_to_default_values",
		"submit_incident",
		"submit_incident_with_cause_player",
		"submit_incident_with_cause_team",
		"submit_incident_with_cause_player_and_effect_player",
		"submit_incident_with_cause_player_and_effect_team",
		"submit_incident_with_cause_team_and_effect_player",
		"submit_incident_with_cause_team_and_effect_team",
		"submit_incident_with_cause_campaign_team",
		"net_set_campaign_insertion_point",
		"hs_make_interactive_scripts_deterministic",
		"threadlib_runtests",
		"player_set_respawn_vehicle",
		"teleport_players_into_vehicle",
		"content_test_set_active",
		"content_test_set_active_test_pass",
		"command_buffer_cache_playback_enable",
		"player_set_spartan_loadout",
		"player_set_elite_loadout",
		"auto_graph",
		"auto_graph_reset",
		"auto_graph_enable_list",
		"auto_graph_filter_list",
		"auto_graph_list",
		"auto_graph_hide",
		"location_names_print",
		"net_force_host",
		"net_force_host_squad",
		"net_force_host_posse",
		"net_force_host_group",
		"sandbox_load_label_strings",
		"net_dump_network_statistics",
		"net_enable_block_detection",
		"main_enable_block_detection",
		"main_synchronous_networking_request_vblank_slip",
		"debug_button_action_mapping_set",
		"player_appearance_force_model_area",
		"player_appearance_force_model_area_disable",
		"debug_instanced_geometry_names_filter",
		"stream_manager_load_core",
		"stream_manager_save_cores",
		"controller_set_waypoint_flags",
		"waypoint_set_unlock_flag",
		"async_test_hang",
		"incidents_force_campaign",
		"incidents_force_firefight",
		"incidents_force_multiplayer",
		"incidents_force_matchmaking",
		"incidents_force_custom_games",
		"incidents_force_solo",
		"incidents_force_coop",
		"incidents_force_four_player_coop",
		"game_sound_stress_test_message_queue",
		"net_log_channel_message_queue_state",
		"global_preferences_set_campaign_state",
		"net_load_machine_file",
		"",
		"",
		"",
		"airstrike_weapons_exist",
		"airstrike_set_launches",
		"cui_debug_add_global_property_watch",
		"cui_debug_add_property_watch",
		"cui_debug_remove_global_property_watch",
		"cui_debug_remove_property_watch",
		"cui_debug_clear_global_property_watches",
		"cui_debug_clear_property_watches",
		"cui_debug_add_global_binding_watch",
		"cui_debug_add_binding_watch",
		"cui_debug_remove_global_binding_watch",
		"cui_debug_remove_binding_watch",
		"",
		"",
		"",
		"",
		"game_grief_record_custom_penalty",
		"game_grief_reset",
		"game_grief_force_social_matchmaking",
		"game_grief_force_ranked_matchmaking",
		"game_grief_set_ranked_matchmaking_multiplier",
		"game_grief_set_social_matchmaking_multiplier",
		"game_grief_set_custom_game_multiplier",
		"game_grief_set_objects_in_sphere_radius",
		"game_grief_set_ai_multiplier",
		"game_grief_set_enemy_ai_nearby_multiplier",
		"game_grief_set_enemy_player_nearby_multiplier",
		"game_grief_set_same_squad_multiplier",
		"game_grief_set_shield_damage_base_penalty",
		"game_grief_set_body_damage_base_penalty",
		"game_grief_set_betrayal_base_penalty",
		"game_grief_set_betrayal_boot_cutoff",
		"game_grief_set_ejection_cutoff",
		"game_grief_set_betrayal_decay_seconds",
		"game_grief_set_eject_decay_seconds",
		"net_disconnect_and_reconnect_all_channels",
		"player_set_profile0",
		"player_set_profile1",
		"security_run_unit_tests",
		"network_session_security_set_challenge_response",
		"",
		"",
		"",
		"test_player_appearance_encode_for_sneakernet",
		"test_player_appearance_decode_from_sneakernet",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"unit_action_test_secondary_trigger",
		""
	};
}

inline c_static_array<hs_script_op *, 1995> &c_halo_script::get_function_table()
{
	static c_static_array<hs_script_op *, 1995> &result = IModuleInterface::Read<c_static_array<hs_script_op *, 1995>>(IGameInterface::s_modulePath, 0x180ABC230);

	return result;
}
inline const char *&c_halo_script::get_function_name(const size_t index)
{
	const char *&result = get_function_table().get_element_names()[index];

	return result;
}
inline void c_halo_script::generate_csv()
{
	static c_static_array<UINT64, 1> hs_null_evaluates = { 0x1802A6130 };
	static c_static_array<UINT64, 2> hs_return_evaluates = { 0x1802A6140, 0x1802AB750 };

	//printf("%i, hs_script_op *hs_script_ops[%i] // 0x%08llX\n", _count, 0x180ABC230);

	printf("op code, op addr, op name, evaluate addr, evaluate name\n");

	decltype(c_halo_script::get_function_table()) &hs_function_table = c_halo_script::get_function_table();
	decltype(hs_function_table.get_element_names()) &hs_function_names = hs_function_table.get_element_names();

	for (int i = 0; i < hs_function_table.get_count(); i++)
	{
		UINT64 hs_function_op = get_file_addr((UINT64)hs_function_table[i]);
		UINT64 hs_function_evaluate = get_file_addr(*(UINT64 *)&hs_function_table[i]->evaluate);
		const char *hs_function_name = hs_function_names[i];

		bool is_unknown = (strcmp(hs_function_name, "") == 0);

		bool is_null = false;
		for (int j = 0; j < hs_null_evaluates.get_count(); j++)
		{
			if (hs_function_table[i]->evaluate_match(hs_null_evaluates[j]))
			{
				if (hs_null_evaluates.get_count() > 1)
				{
					if (is_unknown)
						printf("0x%03X, 0x%09llX, hs_unknown%X_op, 0x%09llX, hs_null%i_evaluate\n", i, hs_function_op, i, hs_function_evaluate, j);
					else
						printf("0x%03X, 0x%09llX, hs_%s_op, 0x%09llX, hs_null%i_evaluate\n", i, hs_function_op, hs_function_name, hs_function_evaluate, j);
				}
				else
				{
					if (is_unknown)
						printf("0x%03X, 0x%09llX, hs_unknown%X_op, 0x%09llX, hs_null_evaluate\n", i, hs_function_op, i, hs_function_evaluate);
					else
						printf("0x%03X, 0x%09llX, hs_%s_op, 0x%09llX, hs_null_evaluate\n", i, hs_function_op, hs_function_name, hs_function_evaluate);
				}
				is_null = true;
			}
		}

		if (is_null)
			continue;

		bool is_return = false;
		for (int j = 0; j < hs_return_evaluates.get_count(); j++)
		{
			if (hs_function_table[i]->evaluate_match(hs_return_evaluates[j]))
			{
				if (hs_return_evaluates.get_count() > 1)
				{
					if (is_unknown)
						printf("0x%03X, 0x%09llX, hs_unknown%X_op, 0x%09llX, hs_null%i_evaluate\n", i, hs_function_op, i, hs_function_evaluate, j);
					else
						printf("0x%03X, 0x%09llX, hs_%s_op, 0x%09llX, hs_return%i_evaluate\n", i, hs_function_op, hs_function_name, hs_function_evaluate, j);
				}
				else
				{
					if (is_unknown)
						printf("0x%03X, 0x%09llX, hs_unknown%X_op, 0x%09llX, hs_null_evaluate\n", i, hs_function_op, i, hs_function_evaluate);
					else
						printf("0x%03X, 0x%09llX, hs_%s_op, 0x%09llX, hs_return_evaluate\n", i, hs_function_op, hs_function_name, hs_function_evaluate);
				}
				is_return = true;
			}
		}

		if (is_return)
			continue;

		bool is_base = false;
		if (hs_function_table[i]->evaluate_match(IModuleInterface::GetBase(IGameInterface::s_modulePath, true)))
		{
			if (is_unknown)
				printf("0x%03X, 0x%09llX, hs_unknown%X_op, 0x%09llX, (null)\n", i, hs_function_op, i, 0ll);
			else
				printf("0x%03X, 0x%09llX, hs_%s_op, 0x%09llX, (null)\n", i, hs_function_op, hs_function_name, 0ll);
			is_base = true;
		}

		if (is_base)
			continue;

		if (is_unknown)
			printf("0x%03X, 0x%09llX, hs_unknown%X_op, 0x%09llX, hs_unknown%X_evaluate\n", i, hs_function_op, i, hs_function_evaluate, i);
		else
			printf("0x%03X, 0x%09llX, hs_%s_op, 0x%09llX, hs_%s_evaluate\n", i, hs_function_op, hs_function_name, hs_function_evaluate, hs_function_name);
	}
}
inline void c_halo_script::generate_idc()
{
	static c_static_array<UINT64, 1> hs_null_evaluates = { 0x1802A6130 };
	static c_static_array<UINT64, 2> hs_return_evaluates = { 0x1802A6140, 0x1802AB750 };

	printf("#include <idc.idc>\n\n");

	printf("/* add hs_script_op to local_types before running the script\n");
	printf("#pragma pack(push, 4)\n");
	printf("struct hs_script_op\n");
	printf("{\n");
	printf("\t__int16 return_type;\n");
	printf("\t__int16 flags;\n");
	printf("\t__int32 __unused4;\n");
	printf("\tvoid (__fastcall *evaluate)(INT64 function_index, UINT64 expression_index, bool execute);\n");
	printf("\tconst char *parameter_info;\n");
	printf("\t__int16 parameter_count;\n");
	printf("\t__int16 parameter_types;\n");
	printf("};\n");
	printf("#pragma pack(pop)\n");
	printf("*/\n\n");

	printf("static main()\n");
	printf("{\n");

	decltype(c_halo_script::get_function_table()) &hs_function_table = c_halo_script::get_function_table();
	decltype(hs_function_table.get_element_names()) &hs_function_names = hs_function_table.get_element_names();

	for (int i = 0; i < hs_function_table.get_count(); i++)
	{
		UINT64 hs_function_op = get_file_addr((UINT64)hs_function_table[i]);
		UINT64 hs_function_evaluate = get_file_addr(*(UINT64 *)&hs_function_table[i]->evaluate);
		const char *hs_function_name = hs_function_names[i];

		bool is_unknown = (strcmp(hs_function_name, "") == 0);

		printf("\t// 0x%03X, %s\n", i, is_unknown ? "unknown" : hs_function_name);
		printf("\tSetType(0x%08llX, \"hs_script_op\");\n", hs_function_op);

		bool is_null = false;
		for (int j = 0; j < hs_null_evaluates.get_count(); j++)
		{
			if (hs_function_table[i]->evaluate_match(hs_null_evaluates[j]))
			{
				if (hs_null_evaluates.get_count() > 1)
				{
					if (is_unknown)
						printf("\tMakeName(0x%08llX, \"hs_unknown%03X_op\");\n", hs_function_op, i);
					else
						printf("\tMakeName(0x%08llX, \"hs_%s_op\");\n", hs_function_op, hs_function_name);
					printf("\tMakeName(0x%08llX, \"hs_null%i_evaluate\");\n", hs_function_evaluate, j);
				}
				else
				{
					if (is_unknown)
						printf("\tMakeName(0x%08llX, \"hs_unknown%03X_op\");\n", hs_function_op, i);
					else
						printf("\tMakeName(0x%08llX, \"hs_%s_op\");\n", hs_function_op, hs_function_name);
					printf("\tMakeName(0x%08llX, \"hs_null_evaluate\");\n", hs_function_evaluate);
				}
				is_null = true;
			}
		}

		if (is_null)
			continue;

		bool is_return = false;
		for (int j = 0; j < hs_return_evaluates.get_count(); j++)
		{
			if (hs_function_table[i]->evaluate_match(hs_return_evaluates[j]))
			{
				if (hs_return_evaluates.get_count() > 1)
				{
					if (is_unknown)
						printf("\tMakeName(0x%08llX, \"hs_unknown%03X_op\");\n", hs_function_op, i);
					else
						printf("\tMakeName(0x%08llX, \"hs_%s_op\");\n", hs_function_op, hs_function_name);
					printf("\tMakeName(0x%08llX, \"hs_return%i_evaluate\");\n", hs_function_evaluate, j);
				}
				else
				{
					if (is_unknown)
						printf("\tMakeName(0x%08llX, \"hs_unknown%03X_op\");\n", hs_function_op, i);
					else
						printf("\tMakeName(0x%08llX, \"hs_%s_op\");\n", hs_function_op, hs_function_name);
					printf("\tMakeName(0x%08llX, \"hs_return_evaluate\");\n", hs_function_evaluate);
				}
				is_return = true;
			}
		}

		if (is_return)
			continue;

		bool is_base = false;
		if (hs_function_table[i]->evaluate_match(IModuleInterface::GetBase(IGameInterface::s_modulePath, false)))
		{
			if (is_unknown)
				printf("\tMakeName(0x%08llX, \"hs_unknown%03X_op\");\n", hs_function_op, i);
			else
				printf("\tMakeName(0x%08llX, \"hs_%s_op\");\n", hs_function_op, hs_function_name);;
			is_base = true;
		}

		if (is_base)
			continue;

		if (is_unknown)
		{
			printf("\tMakeName(0x%08llX, \"hs_unknown%03X_op\");\n", hs_function_op, i);
			printf("\tMakeName(0x%08llX, \"hs_unknown%03X_evaluate\");\n", hs_function_evaluate, i);
		}
		else
		{
			printf("\tMakeName(0x%08llX, \"hs_%s_op\");\n", hs_function_op, hs_function_name);
			printf("\tMakeName(0x%08llX, \"hs_%s_evaluate\");\n", hs_function_evaluate, hs_function_name);
		}
	}

	printf("}\n");
	return;
}

hs_script_op *hs_function_get(__int16 opcode)
{
	decltype(c_halo_script::get_function_table()) &hs_function_table = c_halo_script::get_function_table();
	return hs_function_table[opcode];
}

hs_script_op *hs_function_get(LPCSTR opname)
{
	decltype(c_halo_script::get_function_table()) &hs_function_table = c_halo_script::get_function_table();
	decltype(hs_function_table.get_element_names()) &hs_function_names = hs_function_table.get_element_names();

	size_t opcode = 0;
	for (size_t i = 0; i < hs_function_table.get_count(); i++)
	{
		const char *hs_function_name = hs_function_names[i];

		if (strcmp(hs_function_name, opname) == 0)
		{
			opcode = i;
			break;
		}
	}

	return hs_function_table[opcode];
}

void hs_print_evaluate(__int16 opcode, unsigned __int16 expression_index, char execute)
{ 
	hs_function_get("chud_post_message")->evaluate(opcode, expression_index, execute);
}
