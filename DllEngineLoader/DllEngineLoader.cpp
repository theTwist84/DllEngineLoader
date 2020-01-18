#include "stdafx.h"

int main(int argc, LPSTR *argv)
{
#ifndef _DEBUG
	//FreeConsole();
#elif _DEBUG
	printf("main(%i, \"%s\"", argc, GetFileName(argv[0]).c_str());
	for (size_t i = 1; i < argc; i++) printf(" \"%s\"", argv[i]);
	printf(");\n");
#endif

	EnsureModuleIsLoaded("MCC\\Binaries\\Win64\\bink2w64.dll");

	LPCSTR pEngine = "";
	LPCSTR pGame   = "";
	LPCSTR pMap    = "";
	LPCSTR pFilm   = "";

	switch (argc)
	{
	case 2:
		pEngine = argv[1];
		break;
	case 3:
		pEngine = argv[1];
		pFilm   = argv[2];
		break;
	case 4:
		pEngine = argv[1];
		pGame   = argv[2];
		pMap    = argv[3];
		break;
	default:
		pEngine = "HaloReach";
		pGame   = "campaign_default_054";
		pMap    = "m10";
		//pFilm   = "asq_m30_EF0E4721";
		break;
	}

	static IGameInterface  gameInterface  = IGameInterface(pEngine);

	IModuleInterface::Update();

	// Return input for map_id coversion function
	IPatch("HaloReach.dll", 0x18004BF10, { 0x89, 0xC8, 0xC3 }).Apply(); // to reach map_id
	IPatch("HaloReach.dll", 0x18004C140, { 0x89, 0xC8, 0xC3 }).Apply(); // to mcc map_id

	// Enable original Halo Reach pause screen, this will crash the engine
	/*1.1246.0.0*/ //IPatch("HaloReach.dll", 0x18037A252, { 0xE9, 0xA3, 0x00, 0x00, 0x00, 0x90 }).Apply();
	/*1.1270.0.0*/ //IPatch("HaloReach.dll", 0x18037A2E2, { 0xE9, 0xA3, 0x00, 0x00, 0x00, 0x90 }).Apply();

	// Enable spawning AI via scripts or effects, props to Zeddikins
	/*1.1246.0.0*/ //IPatch("HaloReach.dll", 0x1807301F7, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 }).Apply();
	/*1.1246.0.0*/ //IPatch("HaloReach.dll", 0x18076F4F1, { 0xEB }).Apply();
	/*1.1270.0.0*/ IPatch("HaloReach.dll", 0x180730287, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 }).Apply();
	/*1.1270.0.0*/ IPatch("HaloReach.dll", 0x18076F581, { 0xEB }).Apply();

	// Return input for armor option coversion function
	IPatch("HaloReach.dll", 0x18004E800, { 0x89, 0xC8, 0xC3 }).Apply(); // to reach armor option

	// Enable changing crosshair location
	/*1.1270.0.0*/ IPatch("HaloReach.dll", 0x1805DFA64, { 0xE9, 0x88, 0x00, 0x00, 0x00, 0x90 }).Apply();

	// Enable debug hud coordinates
	/*1.1270.0.0*/ IPatch("HaloReach.dll", 0x1800DC9DA, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 }).Apply();
	/*1.1270.0.0*/ IPatch("HaloReach.dll", 0x1800DC9E7, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 }).Apply();

	ITagInterface::ITagInterface();
	ITagList::ITagList();

	static IGameEngineHost gameEngineHost = IGameEngineHost();
	static IGameRasterizer gameRasterizer = IGameRasterizer(1280, 720, true);
	static IGameContext    gameContext    = IGameContext(gameInterface.GetDataAccess(), pEngine, pGame, pMap, pFilm);

	//gameContext.SetMapInsertionPoint(0);

	IConsoleAccess::IConsoleAccess().SetGameInterface(gameInterface);

	gameContext.SetupSession(true, 0x7F7F86B0EE577202, 0x29EF835E2A9E63DE/*, 0x7F7F86B0EE577202, { 0x7F7F86B0EE577202 }, { 0x0009000002D75AC8 }*/);
	gameContext.SetMapInsertionPoint(1);

	hs_function_get("print")->replace_evaluate(hs_print_evaluate);

	//halo_script().generate_csv();
	//halo_script().generate_idc();

	//printf("Sleep(-1);\n");
	//Sleep(-1);

	auto updateCallBack = [](IGameEngine *pEngine)
	{
		/*printf("Running!\n");*/

		print_internal_enum(0x180D494F4, "external_launch_state", { 
			"_initialize", "_create_local_squad", "_select_game_mode", "_select_saved_film", "_select_campaign", "_select_campaign_resume", 
			"_select_multiplayer", "_select_survival", "_wait_for_party", "_join_remote_squad", "_unused", "_start_game", "_game_start" 
			});

		if (gameRasterizer.IsWindowFocused())
		{
			if (GetKeyState(VK_END) & 0x80)
			{
				pEngine->UpdateEngineState(EngineState::eEndGameWriteStats);
				g_running = false;
			}

			if (GetKeyState('P') & 0x80)
			{
				print_insecure_ip_at(0x1838BB3D0);
				print_secure_ip_at(0x1838BB3C2);
			}
		}

		bool &g_output_debug_frame_time = IModuleInterface::Read<bool>(IGameInterface::s_modulePath, 0x1838CF3C9);
		if (!g_output_debug_frame_time)
		{
			g_output_debug_frame_time = true;
		}

		ITagList::FromFile();
	};

	//gameInterface.SetLocale("ko-KR", "ja-JP", "en-US");
	gameInterface.LaunchTitle(gameEngineHost, gameRasterizer, gameContext, g_running, updateCallBack);

	printf("Sleep(-1);\n");
	Sleep(-1);
}