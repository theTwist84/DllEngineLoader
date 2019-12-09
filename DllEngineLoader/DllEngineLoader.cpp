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
		pGame   = "00_basic_editing_054";
		pMap    = "cex_timberland";
		//pFilm   = "asq_45_laun_217D482C";
		break;
	}

	static IGameInterface  gameInterface  = IGameInterface(pEngine);
	static IGameEngineHost gameEngineHost = IGameEngineHost();
	static IGameRasterizer gameRasterizer = IGameRasterizer(1280, 720, true);
	static IGameContext    gameContext    = IGameContext(gameInterface.GetDataAccess(), pEngine, pGame, pMap, pFilm);

	IConsoleAccess::IConsoleAccess().SetGameInterface(gameInterface);

	gameContext.SetupSession(true, 0x7F7F86B0EE577202, 0x29EF835E2A9E63DE/*, 0x7F7F86B0EE577202, { 0x7F7F86B0EE577202 }, { 0x0009000002D75AC8 }*/);

	IModuleInterface::Update();
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
	};

	UINT8 classic_reach_pause_menu_patch[] = { 0xE9, 0xA3, 0x00, 0x00, 0x00, 0x90 };
	IModuleInterface::Write(IGameInterface::s_modulePath, 0x18037A252, classic_reach_pause_menu_patch);

	gameInterface.SetLocale("ko-KR", "ja-JP", "en-US");
	gameInterface.LaunchTitle(gameEngineHost, gameRasterizer, gameContext, g_running, updateCallBack);
}