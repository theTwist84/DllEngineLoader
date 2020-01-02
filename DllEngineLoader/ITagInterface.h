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
	template<typename T = LPVOID>
	static T           &GetBlockDefinition(ITagBlock &block, size_t index);

private:
	static size_t       s_CacheFilePointerOffset;
	static size_t       s_TagInstancesOffset;
	static size_t       s_TagAddressTableOffset;
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
	UINT32 *(&rTagAddressTable)[] = IModuleInterface::Read<UINT32 * []>(IGameInterface::s_modulePath, s_TagAddressTableOffset);

	IDatumHandle datumHandle = ITagList::GetHandle(pName);
	return *reinterpret_cast<T *>(&rTagAddressTable[pTagInstances[datumHandle.m_Index].m_Address >> 28][pTagInstances[datumHandle.m_Index].m_Address]);
}

template<typename T>
T &ITagInterface::GetBlockDefinition(ITagBlock &block, size_t index)
{
	UINT32 *(&rTagAddressTable)[] = IModuleInterface::Read<UINT32 * []>(IGameInterface::s_modulePath, s_TagAddressTableOffset);

	return *reinterpret_cast<T *>(&rTagAddressTable[block.m_Address >> 28][block.m_Address + sizeof(T) * index]);
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
	void get_field(LPCSTR pName)
	{
		for (long i = 0; i < m_count; i++)
		{
			//auto &block_definition = ITagInterface::GetBlockDefinition(, i);
			printf("%s[%i] = 0x%X 0x%X\n", pName, i, m_address, m_definition_address);
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

private:
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
	std::vector<c_field_definition<c_tag_block>> &tag_block_field(LPCSTR pFieldName = "", size_t fieldOffset = -1)
	{
		static std::vector<c_field_definition<c_tag_block>> fields;
		if (fieldOffset >= 0 && fieldOffset < sizeof(m_data))
			fields.push_back({ pFieldName, fieldOffset });
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
					if (ICommand({ "Get", "get" }).Match(pInputCommand))
					{
						field_accessor<decltype(field.m_Type)>(field.m_Offset).get_field(field.m_Name.c_str());
						break;
					}
					if (ICommand({ "Edit", "edit" }).Match(pInputCommand))
					{
						field_accessor<decltype(field.m_Type)>(field.m_Offset).edit_field(field.m_Name.c_str());
						break;
					}
					if (ICommand({ "Reset", "reset" }).Match(pInputCommand))
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

				if (ICommand({ "Exit", "exit" }).Match(pInputCommand))
					break;

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
			tag_block_field("attachments", 0x108);
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