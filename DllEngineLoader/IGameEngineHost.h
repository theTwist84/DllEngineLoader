#pragma once
#pragma comment(lib, "XInput.lib")

#define sign(value) (value < 0 ? -1 : 1)
#define clamp(value, min_value, max_value) ((value) > (max_value) ? (max_value) : ((value) < (min_value) ? (min_value) : (value)))
#define CONTROLLER_JOYSTICK_THRESHOLD 0.15f

static std::atomic<int> s_uiStackLength = 0;

class IGameEngineHost
{
	enum class InputSource : int
	{
		Gamepad,
		MouseAndKeyboard
	};
#pragma pack(push, 1)
	struct InputBuffer
	{
		IGameEngineHost::InputSource inputSource;
		char                         keyboardState[256];
		float                        MouseX;
		float                        MouseY;
		UINT64                       unknown10C;
		char                         mouseButtonBits;
		char                         __padding[3];
		DWORD                        wButtons;
		BYTE                         bLeftTrigger;
		BYTE                         bRightTrigger;
		SHORT                        sThumbLX;
		SHORT                        sThumbLY;
		SHORT                        sThumbRX;
		SHORT                        sThumbRY;
		char                         __padding2[2];
	};
#pragma pack(pop)

	struct s_player_configuration
	{
		INT32   option0;
		char    padding4[12];
		char    unknown10;
		char    padding11;
		char    option12;
		char    option13;
		char    option14;
		char    padding15;
		char    auto_center_look_option;
		char    crouch_lock_option;
		char    padding18;
		char    clench_protection_option;
		char    unknown1A[14];
		char    option28;
		char    padding29[7];
		INT32   option30_customization_related;
		INT32   option34_customization_related;
		INT32   option38_customization_related;
		INT32   option3C_customization_related;
		INT32   option40_customization_related;
		INT32   option44_customization_related;
		INT32   option48_customization_related;
		INT32   option4C_customization_related;
		INT32   option50_customization_related;
		INT32   option54_customization_related;
		INT32   option58_customization_related;
		INT32   option5C_customization_related;
		INT32   option60_customization_related;
		INT32   option64_customization_related;
		INT32   option68_customization_related;
		char    padding6C[4];
		wchar_t service_tag[5];
		char    padding7A[2];
		INT32   option7C;
		INT32   option80;
		INT32   option84;
		float   option88;
		float   option8C;
		char    padding90[8];
		INT32   controller_layout_option;
		INT32   option9C;
		INT32   optionA0;
		char    paddingA4[16];
		INT32   look_sensitivity_option;
		INT32   optionB8;
		INT32   optionBC;
		INT32   optionC0;
		char    optionC4;
		char    optionC5;
		char    unknownC6;
		char    paddingC7;
		char    unknownC8[56];
		char    unknown100[256];
		char    unknown200[512];
		char    unknown400[512];
		char    unknown600[128];
	};


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
	/* 28 */ virtual bool         UpdateGraphics(char *);
	/* 29 */ virtual INT64        UpdatePlayerConfiguration(LPWSTR, s_player_configuration *);
	/* 30 */ virtual bool         UpdateInput(__int64, InputBuffer *);
	/* 31 */ virtual void         Member31(UINT64, float *);
	/* 32 */ virtual void         Member32();
	/* 33 */ virtual void         XInputSetState(__int32, XINPUT_VIBRATION *);
	/* 34 */ virtual bool         SetPlayerNames(__int64 *, wchar_t[4][32], size_t);
	/* 35 */ virtual void         Member35(const wchar_t *, const wchar_t *);
	/* 36 */ virtual bool         Member36(wchar_t *, __int64);
	/* 37 */ virtual INT64        NetworkSendTo(int, char *, int, UINT16);
	/* 38 */ virtual INT64        NetworkReceiveFrom(char *, int, __int64, UINT16);
	/* 39 */ virtual char        *Member39(unsigned int);
	/* 40 */ virtual int          Member40(BYTE *);
	/* 41 */ virtual bool         Member41(signed int, __int64, __int64);
	/* 42 */ virtual void         FirefightNew(UINT64, float);
	/* 43 */ virtual BOOL         Member43(__int64, __int64);
	/* 44 */ virtual bool         GetPathByType(int, char *, size_t);
	/* 45 */ virtual bool         GetWidePathByType(int, wchar_t *, size_t);
	/* 46 */ virtual UINT8       *Member46(__int64, LPVOID *, __int64);
	/* 47 */ virtual __int64      IsAntiCheatDisabled(UINT64, UINT64);

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
	printf("IGameEngineHost::EngineStateUpdateHandler(EngineState::%s);\n", EngineStateFromID(state));

	if (state != EngineState::eUnknown16) // `Unknown16` also needs a second arg so we skip it
	{
		switch (state)
		{
		case EngineState::ePushUIPage:
			printf("Push UI stack\n");
			s_uiStackLength++;
			break;
		case EngineState::ePopUIPage:
			printf("Pop UI stack\n");
			s_uiStackLength--;
			break;
		}

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
	auto name = pGameVariant->GetName();
	if (!name[0])
	{
		pGameVariant->SetName(L"Temp");
	}
	printf("IGameEngineHost::GameVariantWrite(\"%S\");\n", name);

	char *buffer; size_t size = 0;
	if (pGameVariant->CreateFileFromBuffer(&buffer, &size))
	{
		auto file = IFileAccess("%s%S.bin", GetFilePath(GetCommandLineArg(0)).c_str(), name);
		if (file.FileOpen(FileAccessType::Write))
		{
			file.FileWrite(buffer, size);
		}
		file.FileClose();
	}
}

void IGameEngineHost::MapVariantWrite(IMapVariant *pMapVariant)
{
	auto name = pMapVariant->GetName();
	if (!name[0])
	{
		pMapVariant->SetName(L"Temp");
	}
	printf("IGameEngineHost::MapVariantWrite(\"%S\");\n", name);

	char *buffer; size_t size = 0;
	if (pMapVariant->CreateFileFromBuffer(&buffer, &size))
	{
		auto file = IFileAccess("%s%S.mvar", GetFilePath(GetCommandLineArg(0)).c_str(), name);
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

bool IGameEngineHost::UpdateGraphics(char *buffer)
{
	printf("IGameEngineHost::UpdateGraphics(0x%08llX);\n", (UINT64)buffer);

	auto &width     = *(INT32  *)&buffer[000];
	auto &height    = *(INT32  *)&buffer[004];
	auto &fps_limit = *(UINT16 *)&buffer[041];
	auto &settings  = *(float  *)&buffer[208];

	width     = 3840;
	height    = 2160;
	fps_limit = false;

	for (size_t i = 0; i < 35; i++)
	{
		(&settings)[i] = 10.f;
	}

	return fps_limit;
}

INT64 IGameEngineHost::UpdatePlayerConfiguration(LPWSTR UserID, s_player_configuration *pPlayerConfiguration)
{
	printf("IGameEngineHost::UpdatePlayerConfiguration(\"Player0\", 0x%08llX)\n", (UINT64)&pPlayerConfiguration);

	memset(pPlayerConfiguration, 0, sizeof(*pPlayerConfiguration));

	_snwprintf(pPlayerConfiguration->service_tag, 5, L"%S\0", "UNSC");
	//buffer->option30_customization_related = 1;
	//buffer->option34_customization_related = 1;
	//buffer->option38_customization_related = 1;
	//buffer->option3C_customization_related = 1;
	//buffer->option40_customization_related = 1;
	//buffer->option44_customization_related = 1;
	//buffer->option48_customization_related = 1;
	//buffer->option4C_customization_related = 1;
	//buffer->option50_customization_related = 1;
	//buffer->option54_customization_related = 1;
	//buffer->option58_customization_related = 1;
	//buffer->option5C_customization_related = 1;
	//buffer->option60_customization_related = 1;
	//buffer->option64_customization_related = 1;
	//buffer->option68_customization_related = 1;

	return INT64(1);
}

bool IGameEngineHost::UpdateInput(__int64, InputBuffer *pInputBuffer)
{
	memset(pInputBuffer, 0, sizeof(*pInputBuffer));

	bool windowFocused = IGameRasterizer::IsWindowFocused();

	MouseMode mode = MouseMode::None;
	if (windowFocused)
	{
		mode = MouseMode::Exclusive;
	}
	IGameInput::SetMode(mode, IGameRasterizer::GetWindowHandle());

	static InputSource sCurrentInputSource = InputSource::MouseAndKeyboard;

	// grab controller
	// grab mouse and keyboard

	BYTE keyboardState[256] = {};
	float mouseInputX = 0;
	float mouseInputY = 0;
	bool leftButtonPressed = 0;
	bool rightButtonPressed = 0;
	bool middleButtonPressed = 0;

	bool hasControllerInput = false;
	bool hasMouseAndKeyboardInput = false;

	float fThumbLX = 0;
	float fThumbLY = 0;
	float fThumbRX = 0;
	float fThumbRY = 0;
	float fThumbL_Length = 0;
	float fThumbR_Length = 0;
	XINPUT_STATE xinputState = {};

	if (windowFocused || true)
	{
		DWORD xinputGetStateResult = XInputGetState(0, &xinputState);
		if (xinputGetStateResult == ERROR_SUCCESS)
		{
			hasControllerInput |= xinputState.Gamepad.wButtons != 0;
			hasControllerInput |= xinputState.Gamepad.bLeftTrigger != 0;
			hasControllerInput |= xinputState.Gamepad.bRightTrigger != 0;

			fThumbLX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLX));
			fThumbLY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLY));
			fThumbRX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRX));
			fThumbRY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRY));

			fThumbLX /= static_cast<float>(fThumbLX > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbLY /= static_cast<float>(fThumbLY > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbRX /= static_cast<float>(fThumbRX > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbRY /= static_cast<float>(fThumbRY > 0.0f ? INT16_MAX : -INT16_MIN);

			fThumbL_Length = sqrtf(fThumbLX * fThumbLX + fThumbLY * fThumbLY);
			fThumbR_Length = sqrtf(fThumbRX * fThumbRX + fThumbRY * fThumbRY);

			fThumbLX = sign(fThumbLX) * clamp(abs(fThumbLX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbLY = sign(fThumbLY) * clamp(abs(fThumbLY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbRX = sign(fThumbRX) * clamp(abs(fThumbRX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbRY = sign(fThumbRY) * clamp(abs(fThumbRY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);

			hasControllerInput |= fThumbL_Length > CONTROLLER_JOYSTICK_THRESHOLD;
			hasControllerInput |= fThumbR_Length > CONTROLLER_JOYSTICK_THRESHOLD;
		}

		{
			GetKeyState(-1); // force keys to update
			if (!GetKeyboardState(keyboardState))
				ZeroMemory(keyboardState, sizeof(keyboardState));

			mouseInputX = IGameInput::GetMouseX();
			mouseInputY = IGameInput::GetMouseY();

			leftButtonPressed = IGameInput::GetMouseButton(MouseInputButton::Left);
			rightButtonPressed = IGameInput::GetMouseButton(MouseInputButton::Right);
			middleButtonPressed = IGameInput::GetMouseButton(MouseInputButton::Middle);

			{
				//for (size_t i = 0; i < sizeof(keyboardState); i++)
				//	hasMouseAndKeyboardInput |= keyboardState[i] != 0;

				hasMouseAndKeyboardInput |= mouseInputX != 0.0f;
				hasMouseAndKeyboardInput |= mouseInputY != 0.0f;
				hasMouseAndKeyboardInput |= leftButtonPressed;
				hasMouseAndKeyboardInput |= rightButtonPressed;
				hasMouseAndKeyboardInput |= middleButtonPressed;

				if (hasMouseAndKeyboardInput)
				{
					sCurrentInputSource = InputSource::MouseAndKeyboard;
				}
			}
		}
	}

	if (hasControllerInput)
	{
		sCurrentInputSource = InputSource::Gamepad;
	}
	else if (hasMouseAndKeyboardInput)
	{
		sCurrentInputSource = InputSource::MouseAndKeyboard;
	}

	if (sCurrentInputSource == InputSource::MouseAndKeyboard)
	{
		for (int i = 0; i < 256; i++)
		{
			pInputBuffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
		}
		pInputBuffer->MouseX += mouseInputX;
		pInputBuffer->MouseY += mouseInputY;
		pInputBuffer->mouseButtonBits |= BYTE(leftButtonPressed) << 0;
		pInputBuffer->mouseButtonBits |= BYTE(middleButtonPressed) << 1;
		pInputBuffer->mouseButtonBits |= BYTE(rightButtonPressed) << 2;
	}

	if (sCurrentInputSource == InputSource::Gamepad)
	{
		pInputBuffer->wButtons = xinputState.Gamepad.wButtons;
		pInputBuffer->bLeftTrigger = xinputState.Gamepad.bLeftTrigger;
		pInputBuffer->bRightTrigger = xinputState.Gamepad.bRightTrigger;
		pInputBuffer->sThumbLX = static_cast<SHORT>(fThumbLX * static_cast<float>(fThumbLX > 0 ? INT16_MAX : -INT16_MIN));
		pInputBuffer->sThumbLY = static_cast<SHORT>(fThumbLY * static_cast<float>(fThumbLY > 0 ? INT16_MAX : -INT16_MIN));
		pInputBuffer->sThumbRX = static_cast<SHORT>(fThumbRX * static_cast<float>(fThumbRX > 0 ? INT16_MAX : -INT16_MIN));
		pInputBuffer->sThumbRY = static_cast<SHORT>(fThumbRY * static_cast<float>(fThumbRY > 0 ? INT16_MAX : -INT16_MIN));
	}

	pInputBuffer->inputSource = sCurrentInputSource;

	return unsigned __int8(1);
}

void IGameEngineHost::Member31(UINT64 a1, float *a2)
{
	//*a2 = 0.f;
	// printf("IGameEngineHost::Member31\n"); spams
}

void IGameEngineHost::Member32()
{
	printf("IGameEngineHost::Member32\n");
	// appears to be usermanagement related?
	// we haven't seen this fire yet and don't know its structure so throw an error
	throw;
}

void IGameEngineHost::XInputSetState(__int32 dwUserIndex, XINPUT_VIBRATION *pVibration)
{
	//printf("IGameEngineHost::XInputSetState\n"); // spams
	::XInputSetState(dwUserIndex, pVibration);
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

void IGameEngineHost::Member35(const wchar_t *a1, const wchar_t *a2)
{
	printf("IGameEngineHost::Member35\n");
}

bool IGameEngineHost::Member36(wchar_t *a1, __int64 a2)
{
	printf("IGameEngineHost::Member36\n");
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

char *__fastcall IGameEngineHost::Member39(unsigned int a1)
{
	printf("IGameEngineHost::Member39\n");
	return 0;
}

int IGameEngineHost::Member40(BYTE *buffer)
{
	printf("IGameEngineHost::Member40\n");
	return 0;
}

bool IGameEngineHost::Member41(signed int a1, __int64 a2, __int64 a3)
{
	printf("IGameEngineHost::Member41\n");
	return 0;
}

// new wave/set
void IGameEngineHost::FirefightNew(UINT64 a1, float a2)
{
	printf("IGameEngineHost::FirefightNew(0x%08llX, %f);\n", a1, a2);
}

BOOL IGameEngineHost::Member43(__int64 a1, __int64 a2)
{
	printf("IGameEngineHost::Member43\n");
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

unsigned __int8 *IGameEngineHost::Member46(__int64 a1, LPVOID *a2, __int64 a3)
{
	//printf("IGameEngineHost::Member46\n"); // spams
	return 0;
}

__int64 IGameEngineHost::IsAntiCheatDisabled(UINT64 a1, UINT64 a2)
{
	printf("IGameEngineHost::IsAntiCheatDisabled(0x%08llX, 0x%08llX);\n", a1, a2); 
	// security related
	return 1;
}