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

	ITagInfo() : Handle(0xFFFFFFFF), Name("")
	{
	}

	ITagInfo(UINT32 datumIndex, LPCSTR pName) : Handle(datumIndex)
	{
		strcpy_s(Name, MAX_PATH, pName);
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
	static T           &GetDefinition(LPCSTR pName);

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
	auto pCacheFile = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, s_CacheFilePointerOffset);
	if (pCacheFile)
	{
		name = &pCacheFile[0x10 + 0x198];
	}

	return name;
}

template<typename T>
T ITagInterface::GetHeader(size_t offset)
{
	auto pCacheFile = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, s_CacheFilePointerOffset);
	if (pCacheFile)
	{
		return *reinterpret_cast<T *>(&pCacheFile[0x10 + offset]);
	}
	return T();
}

IDatumHandle ITagInterface::GetGlobalHandle(UINT32 groupTag)
{
	auto pCacheFile = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, s_CacheFilePointerOffset);
	auto globalTagSection = *reinterpret_cast<ITagSection<IGlobalTagInstance> *>(&pCacheFile[0xA028]);

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

	static void                  Add(ITagInfo tagInfo);
	static void                  FromFile();

	static std::vector<ITagInfo> Get();

	static IDatumHandle          GetHandle(LPCSTR pName);
	static LPCSTR                GetName(IDatumHandle handle);

private:
	static std::vector<ITagInfo> s_List;
};

std::vector<ITagInfo> ITagList::s_List;

template<typename T>
T &ITagInterface::GetDefinition(LPCSTR pName)
{
	auto pTagInstances = IModuleInterface::Read<ITagInstance *>(IGameInterface::s_modulePath, s_TagInstancesOffset);
	auto pTagAddressTable = IModuleInterface::Read<UINT32 * []>(IGameInterface::s_modulePath, s_TagAddressTableOffset);

	IDatumHandle datumHandle = ITagList::GetHandle(pName);
	return *reinterpret_cast<T *>(&pTagAddressTable[pTagInstances[datumHandle.m_Index].m_Address >> 28][pTagInstances[datumHandle.m_Index].m_Address]);
};

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
		auto engineName = SplitString(GetFileName(IGameInterface::s_modulePath), ".")[0];
		auto cacheName = ITagInterface::GetCacheName();

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
						auto parts = SplitString(line, ",");
						auto datumIndex = std::stoul(parts[0], 0, 16);
						auto tagName = parts[1].c_str();

						if (datumIndex != ITagList::GetHandle(tagName).AsU32())
						{
							Add({ datumIndex, tagName });
						}
					}
				}
				fb.close();
			}

			once = true;
		}
	}
}

std::vector<ITagInfo> ITagList::Get()
{
	return s_List;
}

IDatumHandle ITagList::GetHandle(LPCSTR pName)
{
	for (auto &tag : s_List)
	{
		if (strcmp(tag.Name, pName) == 0)
		{
			return tag.Handle;
		}
	}

	return IDatumHandle(0xFFFFFFFF);
}

LPCSTR ITagList::GetName(IDatumHandle handle)
{
	for (auto &tag : s_List)
	{
		if (tag.Handle.AsU32() == handle.AsU32())
		{
			return tag.Name;
		}
	}

	return "";
}

struct WeaponDefinition
{
	char m_data[0x500];

	bool IsNull()
	{
		UINT32 valid = -1;
		for (size_t i = 0; i < sizeof(m_data); i++)
			valid += m_data[i] != 0 ? 1 : 0;
		return valid == -1;
	}

	template<typename T>
	T &Get(size_t offset)
	{
		return *reinterpret_cast<T *>(&m_data[offset]);
	}
};


template<typename T>
struct DefinitionMember
{
	std::string m_Name;
	size_t      m_Offset;
	T           m_Type;

	bool IsNull()
	{
		UINT32 valid = -1;
		valid += !m_Name.empty() ? 1 : 0;
		return valid == -1;
	}
};


union DefinitionUnion
{
	DefinitionMember<real_vector3d> _real_vector3d;
	DefinitionMember<float> _float;
	DefinitionMember<int> _int;
};