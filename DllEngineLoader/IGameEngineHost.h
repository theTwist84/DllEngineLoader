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

	/* 00 */ virtual char               Member00();
	/* 01 */ virtual void               FrameEnd(IDXGISwapChain *, __int64);
	/* 02 */ virtual void               Member02(__int64, unsigned int, __int64, float, float, float, float);
	/* 03 */ virtual void               EngineStateUpdate(__int32);
	/* 04 */ virtual INT64              GameExited(unsigned int, char *, int);
	/* 05 */ virtual INT64 __fastcall   GameStateWriteHandler(LPVOID, size_t);
	/* 06 */ virtual void               Member06(char *buffer);
	/* 07 */ virtual void               GamePauseHandler(unsigned int);
	/* 08 */ virtual void               Member08(const wchar_t *, const wchar_t *);
	/* 09 */ virtual void               Member09(wchar_t[1024], wchar_t[1024]);
	/* 10 */ virtual IGameEvents       *GetGameEvents();
	/* 11 */ virtual void               GameVariantWrite(IGameVariant *);
	/* 12 */ virtual void               MapVariantWrite(IMapVariant *);
	/* 13 */ virtual void               Member13(const wchar_t *, const wchar_t *, const void *, unsigned int);
	/* 14 */ virtual char               Member14(int, BYTE *);
	/* 15 */ virtual char               Member15(int, BYTE *);
	/* 16 */ virtual char               GetNextLevelInfo(MapID *, int *, FILETIME *, __int32 *);
	/* 17 */ virtual bool               Member17(int);
	/* 18 */ virtual void               Member18(int);
	/* 19 */ virtual INT64 __fastcall   MapLoadPecentStatus(__int64, __int64, float);
	/* 20 */ virtual void               Member20(__int64, __int8);
	/* 21 */ virtual INT64 __fastcall   GetMachineIDentifier(__int64);
	/* 22 */ virtual INT64              Member22(char *, __int64);
	/* 23 */ virtual char               Member23(__int64, __int64);
	/* 24 */ virtual void               GetSessionInfo(char *);
	/* 25 */ virtual void __fastcall    MembershipUpdate(char *, uint32_t);
	/* 26 */ virtual bool __fastcall    Member26();
	/* 27 */ virtual bool __fastcall    Member27();
	/* 28 */ virtual bool __fastcall    Member28(char *);
	/* 29 */ virtual INT64 __fastcall   Member29(wchar_t [4][32], char *);
	/* 30 */ virtual bool __fastcall    UpdateInput(__int64, InputBuffer *);
	/* 31 */ virtual void               Member31();
	/* 32 */ virtual void               XInputSetState(__int32 , XINPUT_VIBRATION *);
	/* 33 */ virtual bool __fastcall    UpdatePlayerNames(__int64 *, wchar_t [4][32], size_t );
	/* 34 */ virtual void __fastcall    Member34(const wchar_t *, const wchar_t *);
	/* 35 */ virtual bool __fastcall    Member35(wchar_t *, __int64);
	/* 36 */ virtual INT64 __fastcall   NetworkSendTo(int , char *, uint32_t, int);
	/* 37 */ virtual INT64 __fastcall   NetworkReceiveFrom(char *, uint32_t, __int64 , struct s_transport_address *);
	/* 38 */ virtual char *__fastcall   Member38(unsigned int);
	/* 39 */ virtual int __fastcall     Member39(BYTE *);
	/* 40 */ virtual bool __fastcall    Member40(signed int, __int64, __int64);
	/* 41 */ virtual void __fastcall    FirefightNew(__int64, float);
	/* 42 */ virtual BOOL __fastcall    Member42(__int64, __int64);
	/* 43 */ virtual bool __fastcall    GetPathByType(int , char *, size_t);
	/* 44 */ virtual bool __fastcall    GetWidePathByType(int , wchar_t *, size_t);
	/* 45 */ virtual UINT8 *__fastcall  Member45(__int64, unsigned __int8 *, __int64);
	/* 46 */ virtual __int64 __fastcall Member46(__int64, __int64);

	// DATA
	IGameEvents *pGameEvents = 0;
	UINT8 data1[46904] = {};
};

IGameEngineHost::IGameEngineHost()
{
	printf("IGameEngineHost();\n");

	pGameEvents = new IGameEvents();
}

IGameEngineHost::~IGameEngineHost()
{
}

char __fastcall IGameEngineHost::Member00()
{
	////WriteLineVerbose("IGameEngineHost::Member00");
	return 0;
}

void __fastcall IGameEngineHost::FrameEnd(IDXGISwapChain *pSwapChain, __int64 a2)
{
	//DebugUI::RenderFrame();
}

void __fastcall IGameEngineHost::Member02(__int64 player_identifier, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7)
{
	////WriteLineVerbose("IGameEngineHost::Member02");
}

void __fastcall IGameEngineHost::EngineStateUpdate(__int32 state)
{
	//WriteLineVerbose("IGameEngineHost::EngineStateUpdate(%d)", state);

	// `Unknown16` also needs a second arg so we skip it
	//if (state != eEngineState::Unknown16)
	//{
	//	GameLauncher::s_pHaloReachEngine->UpdateEngineState(state);
	//}
}

__int64 __fastcall IGameEngineHost::GameExited(unsigned int a1, char *a2, int a3)
{
	g_running = false;
	//WriteLineVerbose("GameExited %u [%s]", a1, a2);
	return __int64(0);
}

__int64 __fastcall IGameEngineHost::GameStateWriteHandler(LPVOID pBuffer, size_t bufferSize)
{
	//WriteLineVerbose("GameEngineHost: GameStateWriteHandler %p %016llx", pBuffer, bufferSize);
	return __int64(0);
}

void __fastcall IGameEngineHost::Member06(char *buffer)
{
	//WriteLineVerbose("IGameEngineHost::Member06");
}

void __fastcall IGameEngineHost::GamePauseHandler(unsigned int a1)
{
	//WriteLineVerbose("GameEngineHost: GamePauseHandler");
}

void __fastcall IGameEngineHost::Member08(const wchar_t *, const wchar_t *)
{
	//WriteLineVerbose("IGameEngineHost::Member08");
}

void __fastcall IGameEngineHost::Member09(wchar_t buffer0[1024], wchar_t buffer1[1024])
{
	//WriteLineVerbose("IGameEngineHost::Member09");
}

IGameEvents *__fastcall IGameEngineHost::GetGameEvents()
{
	return pGameEvents;
}

void __fastcall IGameEngineHost::GameVariantWrite(IGameVariant *pGameVariant)
{
	//char *data; size_t dataSize = 0;
	//if (pGameVariant->CreateFileFromBuffer(&data, &dataSize)) {}

	//WriteLineVerbose("GameEngineHost: GameVariantWrite");
}

void __fastcall IGameEngineHost::MapVariantWrite(IMapVariant *pMapVariant)
{
	//char *data; size_t dataSize = 0;
	//if (pMapVariant->CreateFileFromBuffer(&data, &dataSize)) {}

	//WriteLineVerbose(" IGameEngineHost: MapVariantWrite");
}

void __fastcall IGameEngineHost::Member13(const wchar_t *, const wchar_t *, const void *, unsigned int)
{
	//WriteLineVerbose("IGameEngineHost::Member12");
}

char __fastcall IGameEngineHost::Member14(int controllerIndex, BYTE *flags)
{
	//WriteLineVerbose("IGameEngineHost::Member13");
	return 0;
}

char __fastcall IGameEngineHost::Member15(int controllerIndex, BYTE *buffer)
{
	//WriteLineVerbose("IGameEngineHost::Member15");
	return 0;
}

char __fastcall IGameEngineHost::GetNextLevelInfo(MapID *pMapID, int *pInsertionPoint, FILETIME *pFileTime, __int32 *)
{
	//WriteLineVerbose("IGameEngineHost::Member16 GetNextLevelInfo");
	return 0;
}

bool __fastcall IGameEngineHost::Member17(int a1)
{
	//WriteLineVerbose("IGameEngineHost::Member17");
	return false;
}

void __fastcall IGameEngineHost::Member18(int)
{
	//WriteLineVerbose("IGameEngineHost::Member18");
}

__int64 __fastcall IGameEngineHost::MapLoadPecentStatus(__int64 a1, __int64 a2, float a3)
{
	/*//WriteLineVerbose("GameEngineHostCallback::Member19 MapLoadPecentStatus %016llx", a1);*/
	return __int64(0);
}

void __fastcall IGameEngineHost::Member20(__int64 a1, __int8 a2)
{
	//WriteLineVerbose("IGameEngineHost::Member20");
}

__int64 __fastcall IGameEngineHost::GetMachineIDentifier(__int64 a1)
{
	return __int64(3);
}

__int64 __fastcall IGameEngineHost::Member22(char *buffer, __int64 a2)
{
	//WriteLineVerbose("IGameEngineHost::Member22");
	return __int64(0);
}

char __fastcall IGameEngineHost::Member23(__int64 a1, __int64 a2)
{
	//WriteLineVerbose("IGameEngineHost::Member23 ScoreboardOpened");
	return 1;
}

void __fastcall IGameEngineHost::GetSessionInfo(char *buffer)
{
	//WriteVerbose("IGameEngineHost::GetSessionInfo");
}

void __fastcall IGameEngineHost::MembershipUpdate(char *pSessionMembership, uint32_t playercount)
{
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

	//WriteLineVerbose("IGameEngineHost::Member25 MembershipUpdate");
};

bool __fastcall IGameEngineHost::Member26()
{
	//WriteLineVerbose("IGameEngineHost::Member26");
	return false;
}

bool __fastcall IGameEngineHost::Member27()
{
	////WriteLineVerbose("IGameEngineHost::Member27");
	return false;
}

bool __fastcall IGameEngineHost::Member28(char *buffer)
{
	//WriteStackBackTrace("IGameEngineHost::Member28");
	if (!buffer)
	{
		return false;
	}
	//WriteLineVerbose("IGameEngineHost::Member28");
	return true;
}

__int64 __fastcall IGameEngineHost::Member29(wchar_t playerNames[4][32], char *buffer)
{
	//Settings::ReadStringValueW(SettingsSection::Player, "ServiceTag", buffer->service_tag, 5, L"UNSC");

	// todo: find a good home for this
	//SplashScreen::Destroy();

	//WriteStackBackTrace("IGameEngineHost::Member29");
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
	//WriteLineVerbose("IGameEngineHost::Member31");
	// appears to be usermanagement related?
	// we haven't seen this fire yet and don't know its structure so throw an error
	throw;
}

void IGameEngineHost::XInputSetState(__int32 dwUserIndex, XINPUT_VIBRATION *pVibration)
{
	//::XInputSetState(dwUserIndex, pVibration);
}

bool __fastcall IGameEngineHost::UpdatePlayerNames(__int64 *playerIndices, wchar_t playerNames[4][32], size_t dataSize)
{
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
	//WriteLineVerbose("IGameEngineHost::Member34");
}

bool IGameEngineHost::Member35(wchar_t *a1, __int64 a2)
{
	//WriteLineVerbose("IGameEngineHost::Member35");
	return 0;
}

__int64 __fastcall IGameEngineHost::NetworkSendTo(int networkID, char *buffer, uint32_t buffersize, int a5)
{
	return 0;// NetworkManager::SendTo(buffer, buffersize);
}

__int64 IGameEngineHost::NetworkReceiveFrom(char *buffer, uint32_t buffersize, __int64 a4, s_transport_address *transport_address)
{
	return 0;// NetworkManager::RecieveFrom(buffer, buffersize);
}

char *__fastcall IGameEngineHost::Member38(unsigned int a1)
{
	//WriteLineVerbose("IGameEngineHost::Member38");
	return 0;
}

int __fastcall IGameEngineHost::Member39(BYTE *buffer)
{
	//WriteLineVerbose("IGameEngineHost::Member39");
	return 0;
}

bool __fastcall IGameEngineHost::Member40(signed int a1, __int64 a2, __int64 a3)
{
	//WriteLineVerbose("IGameEngineHost::Member40");
	return 0;
}

// new wave/set
void __fastcall IGameEngineHost::FirefightNew(__int64 a1, float a2)
{
	//WriteLineVerbose("IGameEngineHost::FirefightNew");
}

BOOL __fastcall IGameEngineHost::Member42(__int64 a1, __int64 a2)
{
	//WriteLineVerbose("IGameEngineHost::Member42");
	return 0;
}

bool __fastcall IGameEngineHost::GetPathByType(int pathType, char *buffer, size_t bufferlength)
{
	auto pEngine = GetCommandLineToArg(1);

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

	return 1;
}

// this is correct implementation inline with MCC
bool __fastcall IGameEngineHost::GetWidePathByType(int pathType, wchar_t *buffer, size_t bufferlength)
{
	auto pEngine = GetCommandLineToArg(1);

	// this this should be in its function
	switch (pathType)
	{
	case 0:
		swprintf_s(buffer, bufferlength, L"%S\\DebugLogs\\", pEngine);
		break;
	case 1:
		swprintf_s(buffer, bufferlength, L"%S\\Config\\", pEngine);
		break;
	case 2:
		swprintf_s(buffer, bufferlength, L"%S\\Temporary\\", pEngine);
		break;
	case 3:
		swprintf_s(buffer, bufferlength, L"%S\\", pEngine);
		break;
	}

	return 1;
}

unsigned __int8 *IGameEngineHost::Member45(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
	return 0;
}

__int64 __fastcall IGameEngineHost::Member46(__int64, __int64)
{
	// appears to be security related
	//WriteLineVerbose("IGameEngineHost::Member46");
	return 0;
}