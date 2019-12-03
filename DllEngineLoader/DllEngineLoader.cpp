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

	auto updateCallBack = [](IGameEngine *pEngine)
	{
		/*printf("Running!\n");*/

		if (gameRasterizer.IsWindowFocused())
		{
			if (GetKeyState(VK_END) & 0x80)
			{
				pEngine->UpdateEngineState(EngineState::eEndGameWriteStats);
				g_running = false;
			}
		}
	};

	gameInterface.SetLocale("ko-KR", "ja-JP", "en-US");
	gameInterface.LaunchTitle(gameEngineHost, gameRasterizer, gameContext, g_running, updateCallBack);
}