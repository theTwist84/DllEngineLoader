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

struct ICacheTag
{
	UINT32       m_GroupTag = 'null';
	IDatumHandle m_DatumHandle = IDatumHandle(0xFFFFFFFF);

	ICacheTag(UINT32 groupTag, IDatumHandle datumHandle)
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

IDatumHandle TagCacheGetGlobal(UINT32 groupTag)
{
	auto pCacheFile    = IModuleInterface::Read<char *>(IGameInterface::s_modulePath, 0x1826077A0);
	auto cacheTagCount = *reinterpret_cast<INT32 *>(&pCacheFile[0xA028]);
	auto pCacheTags    = *reinterpret_cast<ICacheTag **>(&pCacheFile[0xA030]);

	for (size_t i = 0; i < cacheTagCount; ++i)
	{
		if (pCacheTags[i].m_GroupTag == groupTag)
			return pCacheTags[i].m_DatumHandle;
	}

	return IDatumHandle(0xFFFFFFFF);
}

template<typename T = LPVOID>
T TagGetDefinition(UINT32 groupTag, IDatumHandle datumHandle)
{
	auto pTagInstances    = IModuleInterface::Read<ITagInstance *>(IGameInterface::s_modulePath, 0x1826887B8);
	auto pTagAddressTable = IModuleInterface::Read<UINT32 *[]>(IGameInterface::s_modulePath, 0x1838D86C0);

	// TODO: add some sort of groupTag check

	return (T)&pTagAddressTable[pTagInstances[datumHandle.m_Index].m_Address >> 28][pTagInstances[datumHandle.m_Index].m_Address];
};