#include "stdafx.h"

int main(int argc, LPSTR *argv)
{
	LPCSTR pEngineStr = "";
	LPCSTR pGame      = "";
	LPCSTR pMap       = "";
	LPCSTR pFilm      = "";

	switch (argc)
	{
	case 2:
		pEngineStr = argv[1];
		break;
	case 3:
		pEngineStr = argv[1];
		pFilm      = argv[2];
		break;
	case 4:
		pEngineStr = argv[1];
		pGame      = argv[2];
		pMap       = argv[3];
		break;
	default:
		pEngineStr = "HaloReach";
		pGame      = "00_basic_editing_054";
		pMap       = "forge_halo";
		break;
	}


	char windowText[1024] = "";

	static c_engine_interface s_engineInterface = c_engine_interface(pathf("%s\\%s.dll", pEngineStr, pEngineStr));
	static IGameRenderer      s_gameRenderer    = IGameRenderer(1280, 720, true);
	static IGameEngineHost    s_gameEngineHost  = IGameEngineHost();
	static IGameContext       s_gameContext     = IGameContext(s_engineInterface.GetDataAccess(), pEngineStr, pGame, pMap, pFilm, windowText);

	SetWindowTextA(IGameRenderer::GetWindowHandle(), windowText);
	
	s_engineInterface.LaunchTitle(s_gameRenderer, s_gameEngineHost, s_gameContext, g_running, []() { printf("Running!\n"); });
}