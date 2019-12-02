#include "stdafx.h"

int main(int argc, LPSTR *argv)
{
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
		pMap    = "forge_halo";
		break;
	}

	g_pGameEvents     = new IGameEvents();
	g_pGameEngineHost = new IGameEngineHost();

	g_pGameRasterizer = new IGameRasterizer(1280, 720, true);

	g_pGameInterface  = new IGameInterface(pEngine);
	g_pGameContext    = new IGameContext(g_pGameInterface->GetDataAccess(), pEngine, pGame, pMap, pFilm);

	g_pGameInterface->SetLocale("ko-KR", "ja-JP", "en-US");
	g_pGameInterface->LaunchTitle(g_running, []() { printf("Running!\n"); });
}