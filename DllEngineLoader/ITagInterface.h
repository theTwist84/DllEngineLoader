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
	return *reinterpret_cast<T *>(&pCacheFile[0x10 + offset]);
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

template<typename T = LPVOID>
T TagGetDefinition(UINT32 groupTag, IDatumHandle datumHandle)
{
	auto pTagInstances    = IModuleInterface::Read<ITagInstance *>(IGameInterface::s_modulePath, 0x1826887B8);
	auto pTagAddressTable = IModuleInterface::Read<UINT32 *[]>(IGameInterface::s_modulePath, 0x1838D86C0);

	// TODO: add some sort of groupIndex check

	return (T)&pTagAddressTable[pTagInstances[datumHandle.m_Index].m_Address >> 28][pTagInstances[datumHandle.m_Index].m_Address];
};