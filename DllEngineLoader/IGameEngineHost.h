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

	struct MCC_Callback28Structure
	{
		int VIDEO_SizeX;
		int VIDEO_SizeY;
		int VIDEO_TextureQuality;
		int VIDEO_AF_Qual;
		int VIDEO_SSAOQuality;
		int unknown10_4;
		int VIDEO_ShadowMapQual;
		int VIDEO_LodDistQualityFactor;
		int unknown20;
		int WindowMode;
		bool VIDEO_UseEdgeAA;
		bool VIDEO_Wait_VSync;
		bool VIDEO_FPS_Lock;
		char unknown2B;
		char unknown2C[168];
		float unknownD4_0;
		float unknownD4_4;
		float unknownD4_8;
		float unknownD4_C;
		float unknownD4_10;
		float unknownD4_14;
		float unknownD4_18;
		float unknownD4_1C;
		float unknownD4_20;
		float unknownD4_24;
		float unknownD4_28;
		float unknownD4_2C;
		float unknownD4_30;
		float unknownD4_34;
		float unknownD4_38;
		float unknownD4_3C;
		float unknownD4_40;
		float unknownD4_44;
		float unknownD4_48;
		float unknownD4_4C;
		float unknownD4_50;
		float unknownD4_54;
		float unknownD4_58;
		float unknownD4_5C;
		float unknownD4_60;
		float unknownD4_64;
		float unknownD4_68;
		float unknownD4_6C;
		float unknownD4_70;
		float unknownD4_74;
		float unknownD4_78;
		float unknownD4_7C;
		float unknownD4_80;
		float unknownD4_84;
		int unknownD4_88;
		int unknownD4_8C;
		int unknownD4_90;
		int unknownD4_94;
		int unknownD4_98;
		int unknownD4_9C;
		int unknownD4_A0;
		int unknownD4_A4;
		int unknownD4_A8;
	};


	struct s_player_configuration
	{
		INT32   option0;
		INT32   is_centered_crosshair;
		INT32   option8;
		INT32   optionC;
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
		char    unknown1A;
		char    option1B;
		char    unknown1C[12];
		bool    is_elite;
		char    padding29[7];
		INT32   armor_helmet_option;
		INT32   armor_left_shoulder_option;
		INT32   armor_right_shoulder_option;
		INT32   armor_chest_option;
		INT32   armor_wrist_option;
		INT32   armor_leg_utility_option;
		INT32   armor_knees_option;
		INT32   option4C_customization_related;
		INT32   armor_effect_dupe_option;
		INT32   option54_customization_option;
		INT32   elite_armor_option;
		INT32   armor_effect_option;
		INT32   firefight_voice_option;
		INT32   primary_color_option;
		INT32   secondary_color_option;
		char    padding6C[4];
		wchar_t service_tag[5];
		char    padding7A[2];
		INT32   option7C;
		INT32   option80;
		INT32   option84;
		float   option88;
		float   option8C;
		INT32   option90;
		INT32   option94;
		INT32   controller_button_preset_option;
		INT32   option9C;
		INT32   optionA0;
		char    paddingA4[16];
		INT32   camera_look_sensitivity_option;
		INT32   camera_panning_option;
		INT32   camera_flying_movement_option;
		INT32   camera_flying_thrust_option;
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
	/* 02 */ virtual void         Member02(INT64, UINT32, INT64, float, float, float, float);
	/* 03 */ virtual void         EngineStateUpdateHandler(EngineState);
	/* 04 */ virtual INT64        GameExitHandler(unsigned int, char *, int);
	/* 05 */ virtual INT64        GameStateWriteHandler(char *, size_t);
	/* 06 */ virtual void         Member06(char *);
	/* 07 */ virtual void         GamePauseHandler(int);
	/* 08 */ virtual void         Member08(LPWSTR, LPWSTR);
	/* 09 */ virtual void         Member09(LPWSTR, LPWSTR);
	/* 10 */ virtual IGameEvents *GetGameEvents();
	/* 11 */ virtual void         GameVariantWrite(IGameVariant *);
	/* 12 */ virtual void         MapVariantWrite(IMapVariant *);
	/* 13 */ virtual void         Member13(LPWSTR, LPWSTR, LPVOID, UINT32);
	/* 14 */ virtual char         Member14(int, BYTE *);
	/* 15 */ virtual char         Member15(int, BYTE *);
	/* 16 */ virtual char         GetNextLevelInfo(MapID *, int *, FILETIME *, __int32 *);
	/* 17 */ virtual bool         Member17(int);
	/* 18 */ virtual void         Member18(int);
	/* 19 */ virtual INT64        MapLoadPecentStatus(INT64, INT64, float);
	/* 20 */ virtual void         Member20(INT64, __int8);
	/* 21 */ virtual INT64        GetMachineIDentifier(INT64);
	/* 22 */ virtual INT64        Member22(char *, INT64);
	/* 23 */ virtual char         ScoreboardHandler(INT64, INT64);
	/* 24 */ virtual void         GetSessionInfo(char *);
	/* 25 */ virtual void         MembershipUpdate(char *, UINT32);
	/* 26 */ virtual bool         Member26();
	/* 27 */ virtual bool         Member27();
	/* 28 */ virtual bool         UpdateGraphics(MCC_Callback28Structure *);
	/* 29 */ virtual INT64        UpdatePlayerConfiguration(LPWSTR, s_player_configuration &);
	/* 30 */ virtual bool         UpdateInput(INT64, InputBuffer *);
	/* 31 */ virtual void         Member31(UINT64, float *);
	/* 32 */ virtual void         Member32();
	/* 33 */ virtual void         XInputSetState(__int32, XINPUT_VIBRATION *);
	/* 34 */ virtual bool         SetPlayerNames(INT64 *, wchar_t[4][32], size_t);
	/* 35 */ virtual void         Member35(LPCWSTR, LPCWSTR);
	/* 36 */ virtual bool         Member36(LPWSTR, INT64);
	/* 37 */ virtual INT64        NetworkSendTo(int, char *, int, UINT16);
	/* 38 */ virtual INT64        NetworkReceiveFrom(char *, int, INT64, UINT16);
	/* 39 */ virtual char        *Member39(UINT32);
	/* 40 */ virtual int          Member40(BYTE *);
	/* 41 */ virtual bool         Member41(INT32, INT64, INT64);
	/* 42 */ virtual void         FirefightNew(UINT64, float);
	/* 43 */ virtual BOOL         Member43(INT64, INT64);
	/* 44 */ virtual bool         GetPathByType(int, LPSTR, size_t);
	/* 45 */ virtual bool         GetWidePathByType(int, LPWSTR, size_t);
	/* 46 */ virtual UINT8       *Member46(INT64, LPVOID *, INT64);
	/* 47 */ virtual INT64        IsAntiCheatDisabled(UINT64, UINT64);

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

void IGameEngineHost::Member02(INT64 player_identifier, UINT32 a2, INT64 a3, float a4, float a5, float a6, float a7)
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

void IGameEngineHost::Member08(LPWSTR a1, LPWSTR a2)
{
	printf("IGameEngineHost::Member08(\"%S\", \"%S\");\n", a1, a2);
}

void IGameEngineHost::Member09(LPWSTR a1, LPWSTR a2)
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
	LPCWSTR name = pGameVariant->GetName();
	if (!name[0])
	{
		pGameVariant->SetName(L"Temp");
	}
	printf("IGameEngineHost::GameVariantWrite(\"%S\");\n", name);

	char *buffer; size_t size = 0;
	if (pGameVariant->CreateFileFromBuffer(&buffer, &size))
	{
		IFileAccess file = IFileAccess("%s%S.bin", GetFilePath(GetCommandLineArg(0)).c_str(), name);
		if (file.FileOpen(FileAccessType::Write))
		{
			file.FileWrite(buffer, size);
		}
		file.FileClose();
	}
}

void IGameEngineHost::MapVariantWrite(IMapVariant *pMapVariant)
{
	LPCWSTR name = pMapVariant->GetName();
	if (!name[0])
	{
		pMapVariant->SetName(L"Temp");
	}
	printf("IGameEngineHost::MapVariantWrite(\"%S\");\n", name);

	char *buffer; size_t size = 0;
	if (pMapVariant->CreateFileFromBuffer(&buffer, &size))
	{
		IFileAccess file = IFileAccess("%s%S.mvar", GetFilePath(GetCommandLineArg(0)).c_str(), name);
		if (file.FileOpen(FileAccessType::Write))
		{
			file.FileWrite(buffer, size);
		}
		file.FileClose();
	}
}

void IGameEngineHost::Member13(LPWSTR a1, LPWSTR a2, LPVOID a3, UINT32 a4)
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

__int64 IGameEngineHost::MapLoadPecentStatus(INT64 a1, INT64 a2, float a3)
{
	//printf("IGameEngineHost::MapLoadPecentStatus %016llx\n", a1); // spams
	return __int64(0);
}

void IGameEngineHost::Member20(INT64 a1, __int8 a2)
{
	printf("IGameEngineHost::Member20(0x%08llX, %i);\n", a1, a2);
}

__int64 IGameEngineHost::GetMachineIDentifier(INT64 a1)
{
	//printf("IGameEngineHost::GetMachineIDentifier\n"); // spams
	return __int64(3);
}

__int64 IGameEngineHost::Member22(char *buffer, INT64 a2)
{
	printf("IGameEngineHost::Member22(0x%08llX, %lli);\n", (UINT64)buffer, a2);
	return __int64(0);
}

char IGameEngineHost::ScoreboardHandler(INT64 a1, INT64 a2)
{
	// printf("IGameEngineHost::ScoreboardHandler\n"); // spams
	return 1;
}

void IGameEngineHost::GetSessionInfo(char *buffer)
{
	printf("IGameEngineHost::GetSessionInfo(0x%08llX);\n", (UINT64)buffer);
}

void IGameEngineHost::MembershipUpdate(char *pSessionMembership, UINT32 playercount)
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

bool IGameEngineHost::UpdateGraphics(MCC_Callback28Structure *video_settings)
{
	printf("IGameEngineHost::UpdateGraphics(0x%08llX);\n", (UINT64)&video_settings);

	video_settings->VIDEO_SizeX					  = 2 * 1920;
	video_settings->VIDEO_SizeY					  = 2 * 1080;

	video_settings->VIDEO_Wait_VSync			  = false;
	video_settings->VIDEO_FPS_Lock				  = false;

	video_settings->VIDEO_TextureQuality		  = 2;
	video_settings->VIDEO_AF_Qual				  = 2;
	video_settings->VIDEO_SSAOQuality			  = 2;
	video_settings->VIDEO_ShadowMapQual			  = 2;
	video_settings->VIDEO_LodDistQualityFactor	  = 2;
	video_settings->VIDEO_UseEdgeAA				  = true;

	return video_settings->VIDEO_FPS_Lock;
}

INT64 IGameEngineHost::UpdatePlayerConfiguration(LPWSTR UserID, s_player_configuration &rPlayerConfiguration)
{
	printf("IGameEngineHost::UpdatePlayerConfiguration(\"Player0\", 0x%08llX)\n", (UINT64)&rPlayerConfiguration);

	rPlayerConfiguration = {}; // reset values


	// sub_18004E800 applies customization conversion from MCC to Reach
	// TODO: get conversion table from sub_18004E800
	// sub_18004E800 converts customization from MCC to Reach
	rPlayerConfiguration.is_centered_crosshair          = false;
	rPlayerConfiguration.is_elite 	                    = true;
	rPlayerConfiguration.armor_helmet_option            = 0;
	rPlayerConfiguration.armor_left_shoulder_option     = 0;
	rPlayerConfiguration.armor_right_shoulder_option    = 0;
	rPlayerConfiguration.armor_chest_option             = 0;
	rPlayerConfiguration.armor_wrist_option             = 0;
	rPlayerConfiguration.armor_leg_utility_option       = 0;
	rPlayerConfiguration.armor_knees_option             = 0;
	rPlayerConfiguration.option4C_customization_related = 6;
	rPlayerConfiguration.armor_effect_dupe_option       = 0;
	rPlayerConfiguration.elite_armor_option             = 0;
	rPlayerConfiguration.armor_effect_option            = 0;
	rPlayerConfiguration.firefight_voice_option         = 0;
	rPlayerConfiguration.primary_color_option           = 6;   // HR_Color_Sage
	rPlayerConfiguration.secondary_color_option         = 6;   // HR_Color_Sage
	rPlayerConfiguration.crouch_lock_option             = true;

	_snwprintf(rPlayerConfiguration.service_tag, 5, L"%S\0", "UNSC");

	WriteStackTrace("IGameEngineHost::UpdatePlayerConfiguration");

	return INT64(1);
}

bool IGameEngineHost::UpdateInput(INT64, InputBuffer *pInputBuffer)
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

	if (windowFocused)
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

	return true;
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

bool IGameEngineHost::SetPlayerNames(INT64 *playerIndices, wchar_t playerNames[4][32], size_t size_in_bytes)
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

void IGameEngineHost::Member35(LPCWSTR a1, LPCWSTR a2)
{
	printf("IGameEngineHost::Member35\n");
}

bool IGameEngineHost::Member36(LPWSTR a1, INT64 a2)
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

__int64 IGameEngineHost::NetworkReceiveFrom(char *buf, int len, INT64 a4, UINT16 port)
{
	//printf("IGameEngineHost::NetworkReceiveFrom\n"); // spams
	// returns the number of bytes received
	return SOCKET_ERROR;
}

char *__fastcall IGameEngineHost::Member39(UINT32 a1)
{
	printf("IGameEngineHost::Member39\n");
	return 0;
}

int IGameEngineHost::Member40(BYTE *buffer)
{
	printf("IGameEngineHost::Member40\n");
	return 0;
}

bool IGameEngineHost::Member41(INT32 a1, INT64 a2, INT64 a3)
{
	printf("IGameEngineHost::Member41\n");
	return 0;
}

// new wave/set
void IGameEngineHost::FirefightNew(UINT64 a1, float a2)
{
	printf("IGameEngineHost::FirefightNew(0x%08llX, %f);\n", a1, a2);
}

BOOL IGameEngineHost::Member43(INT64 a1, INT64 a2)
{
	printf("IGameEngineHost::Member43\n");
	return 0;
}

bool IGameEngineHost::GetPathByType(int pathType, LPSTR buffer, size_t bufferlength)
{
	std::string pModule = std::string(IGameInterface::s_modulePath).substr(std::string(IGameInterface::s_modulePath).find_last_of("/\\") + 1);
	LPCSTR      pEngine = pModule.erase(pModule.find_last_of("."), std::string::npos).c_str();

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
bool IGameEngineHost::GetWidePathByType(int pathType, LPWSTR wbuffer, size_t len)
{
	char *buffer = new char[len];
	GetPathByType(pathType, buffer, len);
	swprintf_s(wbuffer, len, L"%S", buffer);
	printf("IGameEngineHost::GetWidePathByType [%S]\n", wbuffer);

	return 1;
}

unsigned __int8 *IGameEngineHost::Member46(INT64 a1, LPVOID *a2, INT64 a3)
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