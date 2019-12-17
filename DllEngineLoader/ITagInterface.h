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

template<typename T = char *>
T GetCacheFileHeader(size_t offset = 0)
{
	auto pCacheFile = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, 0x1826077A0);
	if (pCacheFile)
	{
		return *reinterpret_cast<T *>(&pCacheFile[0x10 + offset]);
	}
	return T();
}

std::string GetCacheFileName()
{
	static std::string name = "";
	auto pCacheFile = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, 0x1826077A0);
	if (pCacheFile)
	{
		name = &pCacheFile[0x10 + 0x198];
	}

	return name;
}

template<typename T>
ITagSection<T> &TagCacheGetSection(size_t sectionOffset)
{
	auto pCacheFile = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, 0x1826077A0);
	return *reinterpret_cast<ITagSection<T> *>(&pCacheFile[sectionOffset]);
}

IDatumHandle CacheGlobalTagGet(UINT32 groupTag)
{
	auto globalTagSection = TagCacheGetSection<IGlobalTagInstance>(0xA028);

	for (size_t i = 0; i < globalTagSection.m_Count; ++i)
	{
		if (globalTagSection.m_Instances[i].m_GroupTag == groupTag)
			return globalTagSection.m_Instances[i].m_DatumHandle;
	}

	return IDatumHandle(0xFFFFFFFF);
}

void CacheGlobalTagPrint(UINT32 groupTag = -1)
{
	auto tagSection = TagCacheGetSection<IGlobalTagInstance>(0xA028);

	for (int i = 0; i < tagSection.m_Count; ++i)
	{
		auto group = tagSection.m_Instances[i].m_GroupTag;
		group = ((group >> 24) & 0xff) | ((group << 8) & 0xff0000) | ((group >> 8) & 0xff00) | ((group << 24) & 0xff000000);
		char groupStr[5] = {};
		memcpy(groupStr, &group, 4);

		if (groupTag == -1 || groupTag == tagSection.m_Instances[i].m_GroupTag)
		{
			printf("[%s, %04i]\n", groupStr, i);
		}
	}
}

UINT32 CacheTagGet(UINT32 groupIndex)
{
	auto tagSection = TagCacheGetSection<ITagInstance>(0xA018);

	for (size_t i = 0; i < tagSection.m_Count; ++i)
	{
		if (tagSection.m_Instances[i].m_GroupIndex == groupIndex)
			return tagSection.m_Instances[i].m_Address;
	}

	return UINT32(0xFFFFFFFF);
}

void CacheTagPrint(UINT32 groupTag = -1)
{
	auto tagSection = TagCacheGetSection<ITagInstance>(0xA018);

	for (int i = 0; i < tagSection.m_Count; ++i)
	{
		printf("[%06i, %06i, %06i, 0x%08X]\n", i, tagSection.m_Instances[i].m_GroupIndex, tagSection.m_Instances[i].m_Identifier, tagSection.m_Instances[i].m_Address);
	}
}

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

class ITagList
{

public:
	ITagList();
	~ITagList();

	static void Add(ITagInfo tagInfo);
	static void FromFile();

	static std::vector<ITagInfo> Get();

	static IDatumHandle GetHandle(LPCSTR pName);

private:
	static std::vector<ITagInfo> s_List;
};

std::vector<ITagInfo> ITagList::s_List;

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
		auto mapName = GetCacheFileName();

		if (mapName.c_str()[0])
		{
			char path[MAX_PATH] = {};
			sprintf(path, "%s\\maps\\%s.map.csv", engineName.c_str(), mapName.c_str());

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
						auto parts = SplitString(line, ", ");
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

template<typename T = LPVOID>
T TagGetDefinition(UINT32 groupTag, IDatumHandle datumHandle)
{
	auto pTagInstances    = IModuleInterface::Read<ITagInstance *>(IGameInterface::s_modulePath, 0x1826887B8);
	auto pTagAddressTable = IModuleInterface::Read<UINT32 *[]>(IGameInterface::s_modulePath, 0x1838D86C0);

	// TODO: add some sort of groupIndex check

	return (T)&pTagAddressTable[pTagInstances[datumHandle.m_Index].m_Address >> 28][pTagInstances[datumHandle.m_Index].m_Address];
};

template<typename T = LPVOID>
T TagGetDefinition(LPCSTR pName)
{
	auto pTagInstances = IModuleInterface::Read<ITagInstance *>(IGameInterface::s_modulePath, 0x1826887B8);
	auto pTagAddressTable = IModuleInterface::Read<UINT32 * []>(IGameInterface::s_modulePath, 0x1838D86C0);

	IDatumHandle datumHandle = ITagList::GetHandle(pName);
	return (T)&pTagAddressTable[pTagInstances[datumHandle.m_Index].m_Address >> 28][pTagInstances[datumHandle.m_Index].m_Address];
};