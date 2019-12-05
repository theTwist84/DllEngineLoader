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

	IModuleInterface::Update();
	auto updateCallBack = [](IGameEngine *pEngine)
	{
		/*printf("Running!\n");*/

		static auto external_launch_state_previous = -1;
		auto &external_launch_state = IModuleInterface::GetReference<int>(0x180D494F4, IGameInterface::s_modulePath);
		if (external_launch_state != external_launch_state_previous)
		{
			const char *external_launch_state_names[] =
			{
				"initializing",
				"creating_local_squad",
				"selecting_game_mode",
				"saved_film_selected",
				"selected_campaign",
				"selected_campaign_resume",
				"selected_multiplayer",
				"selected_survival",
				"waiting_for_party",
				"joining_remote_squad",
				"unused",
				"starting_game",
				"game_started"
			};

			printf("external_launch_state(%s)\n", external_launch_state_names[external_launch_state]);
			external_launch_state_previous = external_launch_state;
		}

		if (gameRasterizer.IsWindowFocused())
		{
			if (GetKeyState(VK_END) & 0x80)
			{
				pEngine->UpdateEngineState(EngineState::eEndGameWriteStats);
				g_running = false;
			}
		}
	};

	UINT8 patch[] = { 0xE9, 0xA3, 0x00, 0x00, 0x00, 0x90 };
	IModuleInterface::Write(0x18037A252, patch, IGameInterface::s_modulePath);

	gameInterface.SetLocale("ko-KR", "ja-JP", "en-US");
	gameInterface.LaunchTitle(gameEngineHost, gameRasterizer, gameContext, g_running, updateCallBack);
}