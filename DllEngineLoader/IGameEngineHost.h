#pragma once

class IGameEngineHost
{
#pragma pack(push, 1)
	struct InputBuffer
	{
		int     unknown0;
		char    keyboardState[256];
		float   MouseX;
		float   MouseY;
		__int64 unknown10C;
		char    mouseButtonBits;
		char    unknown115[19];
	};
#pragma pack(pop)


public:
	IGameEngineHost();
	~IGameEngineHost();

	/* 00 */ virtual char         Member00();
	/* 01 */ virtual void         FrameEnd(IDXGISwapChain *, __int64);
	/* 02 */ virtual void         Member02(__int64, unsigned int, __int64, float, float, float, float);
	/* 03 */ virtual void         EngineStateUpdate(EngineState);
	/* 04 */ virtual INT64        GameExited(unsigned int, char *, int);
	/* 05 */ virtual INT64        GameStateWriteHandler(char *, size_t);
	/* 06 */ virtual void         Member06(char *buffer);
	/* 07 */ virtual void         GamePauseHandler(unsigned int);
	/* 08 */ virtual void         Member08(const wchar_t *, const wchar_t *);
	/* 09 */ virtual void         Member09(wchar_t[1024], wchar_t[1024]);
	/* 10 */ virtual IGameEvents *GetGameEvents();
	/* 11 */ virtual void         GameVariantWrite(IGameVariant *);
	/* 12 */ virtual void         MapVariantWrite(IMapVariant *);
	/* 13 */ virtual void         Member13(const wchar_t *, const wchar_t *, const void *, unsigned int);
	/* 14 */ virtual char         Member14(int, BYTE *);
	/* 15 */ virtual char         Member15(int, BYTE *);
	/* 16 */ virtual char         GetNextLevelInfo(MapID *, int *, FILETIME *, __int32 *);
	/* 17 */ virtual bool         Member17(int);
	/* 18 */ virtual void         Member18(int);
	/* 19 */ virtual INT64        MapLoadPecentStatus(__int64, __int64, float);
	/* 20 */ virtual void         Member20(__int64, __int8);
	/* 21 */ virtual INT64        GetMachineIDentifier(__int64);
	/* 22 */ virtual INT64        Member22(char *, __int64);
	/* 23 */ virtual char         ScoreboardHandler(__int64, __int64);
	/* 24 */ virtual void         GetSessionInfo(char *);
	/* 25 */ virtual void         MembershipUpdate(char *, uint32_t);
	/* 26 */ virtual bool         Member26();
	/* 27 */ virtual bool         Member27();
	/* 28 */ virtual bool         Member28(char *);
	/* 29 */ virtual INT64        Member29(wchar_t [4][32], char *);
	/* 30 */ virtual bool         UpdateInput(__int64, InputBuffer *);
	/* 31 */ virtual void         Member31();
	/* 32 */ virtual void         XInputSetState(__int32 , XINPUT_VIBRATION *);
	/* 33 */ virtual bool         SetPlayerNames(__int64 *, wchar_t [4][32], size_t );
	/* 34 */ virtual void         Member34(const wchar_t *, const wchar_t *);
	/* 35 */ virtual bool         Member35(wchar_t *, __int64);
	/* 36 */ virtual INT64        NetworkSendTo(int , char *, uint32_t, int);
	/* 37 */ virtual INT64        NetworkReceiveFrom(char *, uint32_t, __int64 , struct s_transport_address *);
	/* 38 */ virtual char *       Member38(unsigned int);
	/* 39 */ virtual int          Member39(BYTE *);
	/* 40 */ virtual bool         Member40(signed int, __int64, __int64);
	/* 41 */ virtual void         FirefightNew(__int64, float);
	/* 42 */ virtual BOOL         Member42(__int64, __int64);
	/* 43 */ virtual bool         GetPathByType(int , char *, size_t);
	/* 44 */ virtual bool         GetWidePathByType(int , wchar_t *, size_t);
	/* 45 */ virtual UINT8       *Member45(__int64, unsigned __int8 *, __int64);
	/* 46 */ virtual __int64      Member46(__int64, __int64);

	IGameEvents *pGameEvents = 0;
	UINT8 data1[46904] = {};
};

IGameEngineHost::IGameEngineHost()
{
#ifdef _DEBUG
	printf("IGameEngineHost();\n");
#endif

	pGameEvents = new IGameEvents();
}

IGameEngineHost::~IGameEngineHost()
{
}

char __fastcall IGameEngineHost::Member00()
{
	//printf("IGameEngineHost::Member00\n");
	return 0;
}

void __fastcall IGameEngineHost::FrameEnd(IDXGISwapChain *pSwapChain, __int64 a2)
{
	//printf("GameEngineHost: FrameEnd\n");
}

void __fastcall IGameEngineHost::Member02(__int64 player_identifier, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7)
{
	//printf("IGameEngineHost::Member02\n");
}

void __fastcall IGameEngineHost::EngineStateUpdate(EngineState state)
{
	printf("GameEngineHost: EngineStateUpdate(%s)\n", EngineStateFromID(state));

	// `Unknown16` also needs a second arg so we skip it
	if (state != EngineState::eUnknown16)
	{
		IGameInterface::GetEngine()->UpdateEngineState(state);
	}
}

__int64 __fastcall IGameEngineHost::GameExited(unsigned int a1, char *a2, int a3)
{
	printf("GameExited %u [%s]\n", a1, a2);
	g_running = false;
	return __int64(0);
}

__int64 __fastcall IGameEngineHost::GameStateWriteHandler(char *pBuffer, size_t size)
{
	printf("GameEngineHost: GameStateWriteHandler 0x%08IIX %016llx\n", (UINT64)pBuffer, size);
	return __int64(0);
}

void __fastcall IGameEngineHost::Member06(char *buffer)
{
	printf("IGameEngineHost::Member06\n");
}

void __fastcall IGameEngineHost::GamePauseHandler(unsigned int a1)
{
	printf("GameEngineHost: GamePauseHandler\n");
}

void __fastcall IGameEngineHost::Member08(const wchar_t *, const wchar_t *)
{
	printf("IGameEngineHost::Member08\n");
}

void __fastcall IGameEngineHost::Member09(wchar_t buffer0[1024], wchar_t buffer1[1024])
{
	printf("IGameEngineHost::Member09\n");
}

IGameEvents *__fastcall IGameEngineHost::GetGameEvents()
{
	//printf("GameEngineHost: GetGameEvents\n"); // spams
	return pGameEvents;
}

void __fastcall IGameEngineHost::GameVariantWrite(IGameVariant *pGameVariant)
{
	printf("GameEngineHost: GameVariantWrite\n");
	//char *data; size_t dataSize = 0;
	//if (pGameVariant->CreateFileFromBuffer(&data, &dataSize)) {}
}

void __fastcall IGameEngineHost::MapVariantWrite(IMapVariant *pMapVariant)
{
	printf("GameEngineHost: MapVariantWrite\n");

	//char *data; size_t dataSize = 0;
	//if (pMapVariant->CreateFileFromBuffer(&data, &dataSize)) {}
}

void __fastcall IGameEngineHost::Member13(const wchar_t *, const wchar_t *, const void *, unsigned int)
{
	printf("IGameEngineHost::Member13\n");
}

char __fastcall IGameEngineHost::Member14(int controllerIndex, BYTE *flags)
{
	printf("IGameEngineHost::Member14\n");
	return 0;
}

char __fastcall IGameEngineHost::Member15(int controllerIndex, BYTE *buffer)
{
	printf("IGameEngineHost::Member15\n");
	return 0;
}

char __fastcall IGameEngineHost::GetNextLevelInfo(MapID *pMapID, int *pInsertionPoint, FILETIME *pFileTime, __int32 *)
{
	printf("GameEngineHost: GetNextLevelInfo\n");
	return 0;
}

bool __fastcall IGameEngineHost::Member17(int a1)
{
	printf("IGameEngineHost::Member17\n");
	return false;
}

void __fastcall IGameEngineHost::Member18(int)
{
	printf("IGameEngineHost::Member18\n");
}

__int64 __fastcall IGameEngineHost::MapLoadPecentStatus(__int64 a1, __int64 a2, float a3)
{
	//printf("GameEngineHost: MapLoadPecentStatus %016llx\n", a1); // spams
	return __int64(0);
}

void __fastcall IGameEngineHost::Member20(__int64 a1, __int8 a2)
{
	printf("IGameEngineHost::Member20\n");
}

__int64 __fastcall IGameEngineHost::GetMachineIDentifier(__int64 a1)
{
	//printf("GameEngineHost: GetMachineIDentifier\n"); // spams
	return __int64(3);
}

__int64 __fastcall IGameEngineHost::Member22(char *buffer, __int64 a2)
{
	printf("IGameEngineHost::Member22\n");
	return __int64(0);
}

char __fastcall IGameEngineHost::ScoreboardHandler(__int64 a1, __int64 a2)
{
	printf("GameEngineHost: ScoreboardHandler\n");
	return 1;
}

void __fastcall IGameEngineHost::GetSessionInfo(char *buffer)
{
	printf("GameEngineHost: GetSessionInfo\n");
}

void __fastcall IGameEngineHost::MembershipUpdate(char *pSessionMembership, uint32_t playercount)
{
	printf("GameEngineHost: MembershipUpdate\n");

	//WriteLineVerbose("s_session_membership count: %i", pSessionMembership->Count);
	//for (int i = 0; i < pSessionMembership->Count; i++)
	//{
	//	//WriteLineVerbose("MachineIDentifier[%i]: 0x%llx", i, pSessionMembership->Members[i].MachineIDentifier);

	//	pSessionMembership->Members[i].SecureAddress = -1;
	//}

	//if (g_isHost)
	//{
	//	pSessionMembership->Count = 2;
	//	static int x = 1;
	//	pSessionMembership->Members[1].MachineIDentifier = x;
	//}

	//auto x = &pSessionMembership->Members[0].SecureAddress;
};

bool __fastcall IGameEngineHost::Member26()
{
	printf("IGameEngineHost::Member26\n");
	return false;
}

bool __fastcall IGameEngineHost::Member27()
{
	printf("IGameEngineHost::Member27\n");
	return false;
}

bool __fastcall IGameEngineHost::Member28(char *buffer)
{
	printf("IGameEngineHost::Member28\n");
	if (!buffer)
	{
		return false;
	}
	return true;
}

__int64 __fastcall IGameEngineHost::Member29(wchar_t playerNames[4][32], char *buffer)
{
	printf("IGameEngineHost::Member29\n");
	//_snwprintf(buffer->service_tag, 5, L"%s\0", "UNSC");
	return __int64(1);
}

bool __fastcall IGameEngineHost::UpdateInput(__int64, InputBuffer *pInputBuffer)
{
	memset(pInputBuffer, 0, sizeof(*pInputBuffer));
	pInputBuffer->unknown0 = 1;

	bool windowFocused = IGameRasterizer::IsWindowFocused();

	MouseMode mode = MouseMode::None;
	if (windowFocused)
	{
		mode = MouseMode::Exclusive;
	}
	IGameInput::SetMode(mode, IGameRasterizer::GetWindowHandle());

	// get keyboard state
	BYTE keyboardState[256] = {};
	pInputBuffer->MouseX = 0.0f;
	pInputBuffer->MouseY = 0.0f;
	pInputBuffer->mouseButtonBits = 0;

	if (windowFocused)
	{
		GetKeyState(-1); // force keys to update
		if (GetKeyboardState(keyboardState))
		{
			for (int i = 0; i < 256; i++)
			{
				pInputBuffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
			}
		}

		{
			float mouseInputX = IGameInput::GetMouseX();
			float mouseInputY = IGameInput::GetMouseY();

			pInputBuffer->MouseX += mouseInputX;
			pInputBuffer->MouseY += mouseInputY;

			bool leftButtonPressed = IGameInput::GetMouseButton(MouseInputButton::Left);
			bool rightButtonPressed = IGameInput::GetMouseButton(MouseInputButton::Right);
			bool middleButtonPressed = IGameInput::GetMouseButton(MouseInputButton::Middle);

			pInputBuffer->mouseButtonBits |= BYTE(leftButtonPressed) << 0;
			pInputBuffer->mouseButtonBits |= BYTE(middleButtonPressed) << 1;
			pInputBuffer->mouseButtonBits |= BYTE(rightButtonPressed) << 2;
		}
	}

	return unsigned __int8(1);
}

void IGameEngineHost::Member31()
{
	printf("IGameEngineHost::Member31\n");
	// appears to be usermanagement related?
	// we haven't seen this fire yet and don't know its structure so throw an error
	throw;
}

void IGameEngineHost::XInputSetState(__int32 dwUserIndex, XINPUT_VIBRATION *pVibration)
{
	//printf("GameEngineHost: XInputSetState\n"); // spams
	//::XInputSetState(dwUserIndex, pVibration);
}

bool __fastcall IGameEngineHost::SetPlayerNames(__int64 *playerIndices, wchar_t playerNames[4][32], size_t dataSize)
{
	//printf("GameEngineHost: SetPlayerNames\n"); // spams
	if (playerNames && dataSize)
	{
		const wchar_t *ppNames[] = { L"Player", L"Player2", L"Player3",L"Player4" };

		for (int i = 0; i < 4; i++)
		{
			static wchar_t pPlayerNameBuffer[4][16] = {};
			if (pPlayerNameBuffer[i][0] == 0)
			{
				const wchar_t *pName = ppNames[i];
				if (i == 0)
				{
					//if (Settings::ReadStringValueW(SettingsSection::Player, "Name", pPlayerNameBuffer[i], sizeof(pPlayerNameBuffer[i]), ppNames[i]) > 0)
					{
						pName = pPlayerNameBuffer[i];
					}
				}

				{
					if (wcsncmp(playerNames[i], pName, 16) == 0)
					{
						return true;
					}
					wcsncpy_s(playerNames[i], 32, pName, 16);
					//WriteLineVerbose("player[%d].Name: set %ls", i, pName);
				}
			}
		}


		return true;
	}
	return false;
}

void IGameEngineHost::Member34(const wchar_t *a1, const wchar_t *a2)
{
	printf("IGameEngineHost::Member34\n");
}

bool IGameEngineHost::Member35(wchar_t *a1, __int64 a2)
{
	printf("IGameEngineHost::Member35\n");
	return 0;
}

__int64 __fastcall IGameEngineHost::NetworkSendTo(int networkID, char *buffer, uint32_t buffersize, int a5)
{
	printf("GameEngineHost: NetworkSendTo\n");
	return 0;// NetworkManager::SendTo(buffer, buffersize);
}

__int64 IGameEngineHost::NetworkReceiveFrom(char *buffer, uint32_t buffersize, __int64 a4, s_transport_address *transport_address)
{
	//printf("GameEngineHost: NetworkReceiveFrom\n"); // spams
	return 0;// NetworkManager::RecieveFrom(buffer, buffersize);
}

char *__fastcall IGameEngineHost::Member38(unsigned int a1)
{
	printf("IGameEngineHost::Member38\n");
	return 0;
}

int __fastcall IGameEngineHost::Member39(BYTE *buffer)
{
	printf("IGameEngineHost::Member39\n");
	return 0;
}

bool __fastcall IGameEngineHost::Member40(signed int a1, __int64 a2, __int64 a3)
{
	printf("IGameEngineHost::Member40\n");
	return 0;
}

// new wave/set
void __fastcall IGameEngineHost::FirefightNew(__int64 a1, float a2)
{
	printf("GameEngineHost: FirefightNew\n");
}

BOOL __fastcall IGameEngineHost::Member42(__int64 a1, __int64 a2)
{
	printf("IGameEngineHost::Member42\n");
	return 0;
}

bool __fastcall IGameEngineHost::GetPathByType(int pathType, char *buffer, size_t bufferlength)
{
	auto pModule = std::string(IGameInterface::s_modulePath).substr(std::string(IGameInterface::s_modulePath).find_last_of("/\\") + 1);
	auto pEngine = pModule.erase(pModule.find_last_of("."), std::string::npos).c_str();

	// this this should be in its function
	switch (pathType)
	{
	case 0:
		sprintf_s(buffer, bufferlength, "%s\\DebugLogs\\", pEngine);
		break;
	case 1:
		sprintf_s(buffer, bufferlength, "%s\\Config\\", pEngine);
		break;
	case 2:
		sprintf_s(buffer, bufferlength, "%s\\Temporary\\", pEngine);
		break;
	case 3:
		sprintf_s(buffer, bufferlength, "%s\\", pEngine);
		break;
	}
	printf("GameEngineHost: GetPathByType [%s]\n", buffer);

	return 1;
}

// this is correct implementation inline with MCC
bool __fastcall IGameEngineHost::GetWidePathByType(int pathType, wchar_t *wbuffer, size_t len)
{
	char *buffer = new char[len];
	GetPathByType(pathType, buffer, len);
	swprintf_s(wbuffer, len, L"%S", buffer);
	printf("GameEngineHost: GetWidePathByType [%S]\n", wbuffer);

	return 1;
}

unsigned __int8 *IGameEngineHost::Member45(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
	//printf("IGameEngineHost::Member45\n"); // spams
	return 0;
}

__int64 __fastcall IGameEngineHost::Member46(__int64, __int64)
{
	printf("IGameEngineHost::Member46\n");
	// security related
	return 0;
}