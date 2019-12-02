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

	/* 00 */ virtual char         BeginFrame();
	/* 01 */ virtual void         EndFrame(IDXGISwapChain *, __int64);
	/* 02 */ virtual void         Member02(__int64, unsigned int, __int64, float, float, float, float);
	/* 03 */ virtual void         EngineStateUpdateHandler(EngineState);
	/* 04 */ virtual INT64        GameExitHandler(unsigned int, char *, int);
	/* 05 */ virtual INT64        GameStateWriteHandler(char *, size_t);
	/* 06 */ virtual void         Member06(char *);
	/* 07 */ virtual void         GamePauseHandler(int);
	/* 08 */ virtual void         Member08(wchar_t *, wchar_t *);
	/* 09 */ virtual void         Member09(wchar_t *, wchar_t *);
	/* 10 */ virtual IGameEvents *GetGameEvents();
	/* 11 */ virtual void         GameVariantWrite(IGameVariant *);
	/* 12 */ virtual void         MapVariantWrite(IMapVariant *);
	/* 13 */ virtual void         Member13(wchar_t *, wchar_t *, LPVOID, UINT32);
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
	/* 36 */ virtual INT64        NetworkSendTo(int, char *, int, UINT16);
	/* 37 */ virtual INT64        NetworkReceiveFrom(char *, int, __int64, UINT16);
	/* 38 */ virtual char *       Member38(unsigned int);
	/* 39 */ virtual int          Member39(BYTE *);
	/* 40 */ virtual bool         Member40(signed int, __int64, __int64);
	/* 41 */ virtual void         FirefightNew(UINT64, float);
	/* 42 */ virtual BOOL         Member42(__int64, __int64);
	/* 43 */ virtual bool         GetPathByType(int , char *, size_t);
	/* 44 */ virtual bool         GetWidePathByType(int , wchar_t *, size_t);
	/* 45 */ virtual UINT8       *Member45(__int64, LPVOID *, __int64);
	/* 46 */ virtual __int64      Member46(UINT64, UINT64);

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

char IGameEngineHost::BeginFrame()
{
	//printf("IGameEngineHost::BeginFrame();\n");
	return 0;
}

void IGameEngineHost::EndFrame(IDXGISwapChain *pSwapChain, __int64 a2)
{
	//printf("IGameEngineHost::EndFrame(0x%08llX %lli);\n", (UINT64)pBuffer, a2);
}

void IGameEngineHost::Member02(__int64 player_identifier, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7)
{
	//printf("IGameEngineHost::Member02\n");
}

void IGameEngineHost::EngineStateUpdateHandler(EngineState state)
{
	printf("IGameEngineHost::EngineStateUpdateHandler(%s);\n", EngineStateFromID(state));

	// `Unknown16` also needs a second arg so we skip it
	if (state != EngineState::eUnknown16)
	{
		IGameInterface::GetEngine()->UpdateEngineState(state);
	}
}

__int64 IGameEngineHost::GameExitHandler(unsigned int a1, char *a2, int a3)
{
	printf("IGameEngineHost::GameExitHandler(%u, \"%s\", %i);\n", a1, a2, a3);
	g_running = false;
	return __int64(0);
}

__int64 IGameEngineHost::GameStateWriteHandler(char *pBuffer, size_t size)
{
	printf("IGameEngineHost::GameStateWriteHandler(0x%08llX %zi);\n", (UINT64)pBuffer, size);
	return __int64(0);
}

void IGameEngineHost::Member06(char *buffer)
{
	printf("IGameEngineHost::Member06(0x%08llX);\n", (UINT64)buffer);
}

void IGameEngineHost::GamePauseHandler(int controllerIndex)
{
	printf("IGameEngineHost::GamePauseHandler(%i);\n", controllerIndex);
}

void IGameEngineHost::Member08(wchar_t *a1, wchar_t *a2)
{
	printf("IGameEngineHost::Member08(\"%S\", \"%S\");\n", a1, a2);
}

void IGameEngineHost::Member09(wchar_t *a1, wchar_t *a2)
{
	printf("IGameEngineHost::Member09(\"%S\", \"%S\");\n", a1, a2);
}

IGameEvents *__fastcall IGameEngineHost::GetGameEvents()
{
	//printf("IGameEngineHost::GetGameEvents\n"); // spams
	return pGameEvents;
}

void IGameEngineHost::GameVariantWrite(IGameVariant *pGameVariant)
{
	printf("IGameEngineHost::GameVariantWrite(\"%S\");\n", pGameVariant->GetName());
	char *buffer; size_t size = 0;
	if (pGameVariant->CreateFileFromBuffer(&buffer, &size))
	{
		auto file = IFileAccess("%s%S.bin", GetPath(GetCommandLineToArg(0)).c_str(), pGameVariant->GetName());
		if (file.FileOpen(FileAccessType::Write))
		{
			file.FileWrite(buffer, size);
		}
		file.FileClose();
	}
}

void IGameEngineHost::MapVariantWrite(IMapVariant *pMapVariant)
{
	printf("IGameEngineHost::MapVariantWrite(\"%S\");\n", pMapVariant->GetName());

	char *buffer; size_t size = 0;
	if (pMapVariant->CreateFileFromBuffer(&buffer, &size))
	{
		auto file = IFileAccess("%s%S.mvar", GetPath(GetCommandLineToArg(0)).c_str(), pMapVariant->GetName());
		if (file.FileOpen(FileAccessType::Write))
		{
			file.FileWrite(buffer, size);
		}
		file.FileClose();
	}
}

void IGameEngineHost::Member13(wchar_t *a1, wchar_t *a2, LPVOID a3, UINT32 a4)
{
	printf("IGameEngineHost::Member13\n");
}

char IGameEngineHost::Member14(int controllerIndex, BYTE *flags)
{
	printf("IGameEngineHost::Member14(%i, %u);\n", controllerIndex, *flags);
	return 0;
}

char IGameEngineHost::Member15(int controllerIndex, BYTE *buffer)
{
	printf("IGameEngineHost::Member15(%i, 0x%08llX);\n", controllerIndex, (UINT64)buffer);
	return 0;
}

char IGameEngineHost::GetNextLevelInfo(MapID *pMapID, int *pInsertionPoint, FILETIME *pFileTime, __int32 *)
{
	printf("IGameEngineHost::GetNextLevelInfo\n");
	return 0;
}

bool IGameEngineHost::Member17(int a1)
{
	printf("IGameEngineHost::Member17(0x%08X);\n", a1);
	return false;
}

void IGameEngineHost::Member18(int a1)
{
	printf("IGameEngineHost::Member18(0x%08X);\n", a1);
}

__int64 IGameEngineHost::MapLoadPecentStatus(__int64 a1, __int64 a2, float a3)
{
	//printf("IGameEngineHost::MapLoadPecentStatus %016llx\n", a1); // spams
	return __int64(0);
}

void IGameEngineHost::Member20(__int64 a1, __int8 a2)
{
	printf("IGameEngineHost::Member20(0x%08llX, %i);\n", a1, a2);
}

__int64 IGameEngineHost::GetMachineIDentifier(__int64 a1)
{
	//printf("IGameEngineHost::GetMachineIDentifier\n"); // spams
	return __int64(3);
}

__int64 IGameEngineHost::Member22(char *buffer, __int64 a2)
{
	printf("IGameEngineHost::Member22(0x%08llX, %lli);\n", (UINT64)buffer, a2);
	return __int64(0);
}

char IGameEngineHost::ScoreboardHandler(__int64 a1, __int64 a2)
{
	// printf("IGameEngineHost::ScoreboardHandler\n"); // spams
	return 1;
}

void IGameEngineHost::GetSessionInfo(char *buffer)
{
	printf("IGameEngineHost::GetSessionInfo(0x%08llX);\n", (UINT64)buffer);
}

void IGameEngineHost::MembershipUpdate(char *pSessionMembership, uint32_t playercount)
{
	printf("IGameEngineHost::MembershipUpdate(0x%08llX, %i);\n", (UINT64)pSessionMembership, playercount);
	 
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

bool IGameEngineHost::Member26()
{
	printf("IGameEngineHost::Member26();\n");
	return false;
}

bool IGameEngineHost::Member27()
{
	printf("IGameEngineHost::Member27();\n");
	return false;
}

bool IGameEngineHost::Member28(char *buffer)
{
	printf("IGameEngineHost::Member28(0x%08llX);\n", (UINT64)buffer);
	if (!buffer)
	{
		return false;
	}
	return true;
}

__int64 IGameEngineHost::Member29(wchar_t playerNames[4][32], char *buffer)
{
	printf("IGameEngineHost::Member29\n");
	//_snwprintf(buffer->service_tag, 5, L"%s\0", "UNSC");
	return __int64(1);
}

bool IGameEngineHost::UpdateInput(__int64, InputBuffer *pInputBuffer)
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
	//printf("IGameEngineHost::XInputSetState\n"); // spams
	//::XInputSetState(dwUserIndex, pVibration);
}

bool IGameEngineHost::SetPlayerNames(__int64 *playerIndices, wchar_t playerNames[4][32], size_t size_in_bytes)
{
	//printf("IGameEngineHost::SetPlayerNames\n"); // spams
	if (playerNames && size_in_bytes)
	{
		const wchar_t *ppNames[] = { L"Player0", L"Player1", L"Player2", L"Player3" };

		for (int i = 0; i < 4; i++)
		{
			if (wcsstr(playerNames[i], ppNames[i]) == 0)
			{
				printf("wcsncpy(player[%i].Name, \"%S\", %zi);\n", i, ppNames[i], size_in_bytes / sizeof(wchar_t));

				if (wcsncmp(playerNames[i], ppNames[i], size_in_bytes / sizeof(wchar_t)) != 0)
				{
					wcsncpy(playerNames[i], ppNames[i], size_in_bytes / sizeof(wchar_t));
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

__int64 IGameEngineHost::NetworkSendTo(int ipv4, char *buf, int len, UINT16 port)
{
	//printf("IGameEngineHost::NetworkSendTo\n"); // spams
	// returns the total number of bytes sent
	return SOCKET_ERROR;
}

__int64 IGameEngineHost::NetworkReceiveFrom(char *buf, int len, __int64 a4, UINT16 port)
{
	//printf("IGameEngineHost::NetworkReceiveFrom\n"); // spams
	// returns the number of bytes received
	return SOCKET_ERROR;
}

char *__fastcall IGameEngineHost::Member38(unsigned int a1)
{
	printf("IGameEngineHost::Member38\n");
	return 0;
}

int IGameEngineHost::Member39(BYTE *buffer)
{
	printf("IGameEngineHost::Member39\n");
	return 0;
}

bool IGameEngineHost::Member40(signed int a1, __int64 a2, __int64 a3)
{
	printf("IGameEngineHost::Member40\n");
	return 0;
}

// new wave/set
void IGameEngineHost::FirefightNew(UINT64 a1, float a2)
{
	printf("IGameEngineHost::FirefightNew(0x%08llX, %f);\n", a1, a2);
}

BOOL IGameEngineHost::Member42(__int64 a1, __int64 a2)
{
	printf("IGameEngineHost::Member42\n");
	return 0;
}

bool IGameEngineHost::GetPathByType(int pathType, char *buffer, size_t bufferlength)
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
	printf("IGameEngineHost::GetPathByType [%s]\n", buffer);

	return 1;
}

// this is correct implementation inline with MCC
bool IGameEngineHost::GetWidePathByType(int pathType, wchar_t *wbuffer, size_t len)
{
	char *buffer = new char[len];
	GetPathByType(pathType, buffer, len);
	swprintf_s(wbuffer, len, L"%S", buffer);
	printf("IGameEngineHost::GetWidePathByType [%S]\n", wbuffer);

	return 1;
}

unsigned __int8 *IGameEngineHost::Member45(__int64 a1, LPVOID *a2, __int64 a3)
{
	//printf("IGameEngineHost::Member45\n"); // spams
	return 0;
}

__int64 IGameEngineHost::Member46(UINT64 a1, UINT64 a2)
{
	printf("IGameEngineHost::Member46(0x%08llX, 0x%08llX);\n", a1, a2); 
	// security related
	return 0;
}