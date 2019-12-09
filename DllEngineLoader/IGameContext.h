#pragma once

enum class GameMode : INT32
{
	eBase,
	eCampaign,
	eUnknown2,
	eMultiplayer,
	eUnknown4,
	eSurvival,

	kCount
};

LPCSTR GameModeFromID(GameMode id)
{
	switch (id)
	{
	case GameMode::eCampaign:
		return "Campaign";
	case GameMode::eMultiplayer:
		return "Multiplayer";
	case GameMode::eSurvival:
		return "Survival";
	}
	return nullptr;
}

enum class Difficulty : INT32
{
	eEasy,
	eNormal,
	eHard,
	eImpossible,

	kCount
};

LPCSTR DifficultyFromID(Difficulty id)
{
	switch (id)
	{
	case Difficulty::eEasy:
		return "Easy";
	case Difficulty::eNormal:
		return "Normal";
	case Difficulty::eHard:
		return "Heroic";
	case Difficulty::eImpossible:
		return "Legendary";
	}
	return nullptr;
}

enum class MapID : INT32
{
	eUndefined = -1,

	eM05 = 178,
	eM10,
	eM20,
	eM30,
	eM35,
	eM45,
	eM50,
	eM52,
	eM60,
	eM70,
	eM70_A,
	eM70_Bonus,

	ePanopticon,
	eBoneyard,
	eLaunchStation,
	eSettlement,
	eIvoryTower,
	eIsland,
	eSwordSlayer,
	eAftship,

	eDLC_Slayer,
	eDLC_Invasion,
	eDLC_Medium,

	eCondemned,
	eTrainingPreserve,

	eCEX_BeaverCreek,
	eCEX_Damnation,
	eCEX_Timberland,
	eCEX_Prisoner,
	eCEX_HangEmHigh,
	eCEX_Headlong,

	eForge_Halo,

	eFF_Park,
	eFF_Corvette,
	eFF_Courtyard,
	eFF_Icecave,
	eFF_Holdout,
	eFF_Ruins,
	eFF_Prototype,
	eFF_Waterfront,
	eFF_Unearthed,

	eCEX_FF_Halo,

	kCount
};

LPCSTR MapNameFromID(MapID id)
{
	switch (id)
	{
	case MapID::eM05:
		return "m05";
	case MapID::eM10:
		return "m10";
	case MapID::eM20:
		return "m20";
	case MapID::eM30:
		return "m30";
	case MapID::eM35:
		return "m35";
	case MapID::eM45:
		return "m45";
	case MapID::eM50:
		return "m50";
	case MapID::eM52:
		return "m52";
	case MapID::eM60:
		return "m60";
	case MapID::eM70:
		return "m70";
	case MapID::eM70_A:
		return "m70_a";
	case MapID::eM70_Bonus:
		return "m70_bonus";
	case MapID::ePanopticon:
		return "50_panopticon";
	case MapID::eBoneyard:
		return "70_boneyard";
	case MapID::eLaunchStation:
		return "45_launch_station";
	case MapID::eSettlement:
		return "30_settlement";
	case MapID::eIvoryTower:
		return "52_ivory_tower";
	case MapID::eIsland:
		return "35_island";
	case MapID::eSwordSlayer:
		return "20_sword_slayer";
	case MapID::eAftship:
		return "45_aftship";
	case MapID::eDLC_Slayer:
		return "dlc_slayer";
	case MapID::eDLC_Invasion:
		return "dlc_invasion";
	case MapID::eDLC_Medium:
		return "dlc_medium";
	case MapID::eCondemned:
		return "condemned";
	case MapID::eTrainingPreserve:
		return "trainingpreserve";
	case MapID::eCEX_BeaverCreek:
		return "cex_beaver_creek";
	case MapID::eCEX_Damnation:
		return "cex_damnation";
	case MapID::eCEX_Timberland:
		return "cex_timberland";
	case MapID::eCEX_Prisoner:
		return "cex_prisoner";
	case MapID::eCEX_HangEmHigh:
		return "cex_hangemhigh";
	case MapID::eCEX_Headlong:
		return "cex_headlong";
	case MapID::eForge_Halo:
		return "forge_halo";
	case MapID::eFF_Park:
		return "ff50_park";
	case MapID::eFF_Corvette:
		return "ff45_corvette";
	case MapID::eFF_Courtyard:
		return "ff20_courtyard";
	case MapID::eFF_Icecave:
		return "ff60_icecave";
	case MapID::eFF_Holdout:
		return "ff70_holdout";
	case MapID::eFF_Ruins:
		return "ff60_ruins";
	case MapID::eFF_Prototype:
		return "ff10_prototype";
	case MapID::eFF_Waterfront:
		return "ff30_waterfront";
	case MapID::eFF_Unearthed:
		return "ff_unearthed";
	case MapID::eCEX_FF_Halo:
		return "cex_ff_halo";
	}
	return nullptr;
}

INT32 MapNameToID(LPCSTR pName)
{
	for (INT32 i = static_cast<INT32>(MapID::eM05); i < static_cast<INT32>(MapID::kCount); i++)
	{
		MapID mapID = static_cast<MapID>(i);
		LPCSTR mapIDStr = MapNameFromID(mapID);

		if (mapIDStr != nullptr && (strcmp(pName, mapIDStr) == 0))
		{
			return i;
		}
	}
	return static_cast<INT32>(MapID::eUndefined);
}

class IGameContext
{
	struct s_session
	{
		struct s_session_player
		{
			INT64  m_XboxUserId;
			UINT64 unknown8;
			UINT64 unknown10;
			UINT32 unknown18;
			UINT32 unknown1C;
		};

		INT64            m_PartySAddr;
		INT64            m_LocalSAddr;
		bool             m_IsHost;
		UINT8            m_Padding0[7];
		INT64            m_PeerSAddrs[17];
		size_t           m_PeerCount;
		s_session_player m_Players[16];
		size_t           m_PlayerCount;
		INT64            m_HostSAddr;
	};
public:
	IGameContext(IDataAccess *pDataAccess, LPCSTR pEngine, LPCSTR pGame, LPCSTR pMap, LPCSTR pFilm, bool setWindowText);
	~IGameContext();

	void SetGameMode(GameMode gameMode)
	{
#ifdef _DEBUG
		printf("IGameContext::SetGameMode(\"%s\");\n", GameModeFromID(gameMode));
#endif

		m_GameMode = gameMode;
	}
	void SetDifficulty(Difficulty difficulty)
	{
#ifdef _DEBUG
		printf("IGameContext::SetDifficulty(\"%s\");\n", DifficultyFromID(difficulty));
#endif

		m_Difficulty = difficulty;
	}
	void SetMapID(INT32 mapID)
	{
#ifdef _DEBUG
		printf("IGameContext::SetMapID(\"%s\");\n", MapNameFromID(static_cast<MapID>(mapID)));
#endif

		m_MapID = static_cast<MapID>(mapID);
	}
	void SetSavedFilmPath(LPCSTR pSavedFilmPath)
	{
#ifdef _DEBUG
		printf("IGameContext::SetSavedFilmPath(\"%s\");\n", pSavedFilmPath);
#endif

		m_pSavedFilmPath = pSavedFilmPath;
	}
	void SetupSession(bool isHost, INT64 localID, INT64 partyID, INT64 hostID = {}, std::vector<INT64> peerSAddrs = {}, std::vector<INT64> xboxUserIds = {})
	{
		m_Session.m_LocalSAddr = localID;
		m_Session.m_PartySAddr = partyID;

		if (m_Session.m_IsHost = isHost, !m_Session.m_IsHost)
		{
			if (!peerSAddrs.size())
			{
				peerSAddrs = { localID };
			}
			m_Session.m_PeerCount = peerSAddrs.size();
			for (size_t i = 0; i < m_Session.m_PeerCount; i++)
			{
				m_Session.m_PeerSAddrs[i] = peerSAddrs[i];
			}

			if (!xboxUserIds.size())
			{
				xboxUserIds = { 0 };
			}
			m_Session.m_PlayerCount = xboxUserIds.size();
			for (size_t i = 0; i < m_Session.m_PlayerCount; i++)
			{
				m_Session.m_Players[i].m_XboxUserId = xboxUserIds[i];
				m_Session.m_Players[i].unknown1C = -1;
			}
		}
		else
		{
			m_Session.m_HostSAddr = hostID;
		}
	}

private:
	GameMode   m_GameMode;
	char       m_GameVariant[117760];
	char       m_MapVariant[59392];
	MapID      m_MapID;
	Difficulty m_Difficulty;
	UINT16     m_MapInsertionPoint;
	UINT8      padding0[10];
	UINT64     m_ActiveSkullFlags;
	UINT8      padding1[8];
	LPVOID     m_pGameStateHeader;
	size_t     m_GameStateHeaderSize;
	LPCSTR     m_pSavedFilmPath;
	s_session  m_Session;
	bool       m_unknown0;            // used in some networking function (if true ? 2 : 0)
	UINT8      padding2;
	bool       m_UseCustomEngineName;
	UINT8      padding3[5];
	wchar_t   *m_CustomEngineName;
};

IGameContext::IGameContext(IDataAccess *pDataAccess, LPCSTR pEngine, LPCSTR pGame, LPCSTR pMap, LPCSTR pFilm, bool setWindowText = true)
{
#ifdef _DEBUG
	printf("IGameContext(0x%08llX, \"%s\", \"%s\", \"%s\", \"%s\", %s);\n", (UINT64)pDataAccess, pEngine, pGame, pMap, pFilm, setWindowText ? "true" : "false");
#endif

	IGameVariant      *pGameVariant      = {};
	IMapVariant       *pMapVariant       = {};
	ISaveFilmMetadata *pSaveFilmMetadata = {};

	char               windowText[1024]  = {};

	if (pFilm == "")
	{
		{
			IFileAccess file = IFileAccess("%s%s.mpvr", GetFilePath(GetCommandLineArg(0)).c_str(), pGame);
			if (file.FileOpen(FileAccessType::Read))
			{
				size_t size = 0;
				pGameVariant = pDataAccess->GameVariantCreateDefault(file.FileRead(size));
			}
			file.FileClose();

			if (!pGameVariant)
			{
				pGameVariant = pDataAccess->GetGameVariant(pEngine, pGame);
			}
			assert(pGameVariant);

			pGameVariant->CopyTo(&m_GameVariant);

			GameMode gameMode = GameMode::eBase;
			switch (*reinterpret_cast<INT32 *>(&m_GameVariant[0]))
			{
			case 1:
				gameMode = GameMode::eMultiplayer;
				break;
			case 2:
				gameMode = GameMode::eMultiplayer;
				break;
			case 3:
				gameMode = GameMode::eCampaign;
				break;
			case 4:
				gameMode = GameMode::eSurvival;
				break;
			}
			SetGameMode(gameMode);
		}

		{
			IFileAccess file = IFileAccess("%s%s.mvar", GetFilePath(GetCommandLineArg(0)).c_str(), pMap);
			if (file.FileOpen(FileAccessType::Read))
			{
				size_t size = 0;
				pMapVariant = pDataAccess->MapVariantCreateDefault(file.FileRead(size));
			}
			file.FileClose();

			if (!pMapVariant)
			{
				if (pMapVariant = pDataAccess->GetMapVariant(pEngine, pMap), !pMapVariant)
				{
					pMapVariant = pDataAccess->MapVariantCreateFromMapID(MapNameToID(pMap));
				}
			}
			assert(pMapVariant);

			pMapVariant->CopyTo(m_MapVariant);
			SetMapID(pMapVariant->GetID());
		}

		char gameVariantName[64] = { 0 }; sprintf(gameVariantName, "%S", pGameVariant->GetName());
		if (!gameVariantName[0]) sprintf(gameVariantName, "%s", pGame);

		char mapVariantName[64] = { 0 }; sprintf(mapVariantName, "%S", pMapVariant->GetName());
		if (!mapVariantName[0]) sprintf(mapVariantName, "%s", pMap);

		std::time_t ct = std::time(0);
		sprintf(windowText, "%s on %s, %s", gameVariantName, mapVariantName, ctime(&ct));
	}
	else
	{
		pSaveFilmMetadata = pDataAccess->GetSaveFilmMetadata(pEngine, pFilm);
		assert(pSaveFilmMetadata);

		SetSavedFilmPath(pFilm);

		sprintf(windowText, "%S", pSaveFilmMetadata->GetDescription());
	}

	if (windowText[0])
	{
		SetConsoleTitleA(windowText);
		SetWindowTextA(IGameRasterizer::GetWindowHandle(), windowText);
	}
}

IGameContext::~IGameContext()
{
}