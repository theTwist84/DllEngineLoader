#include "stdafx.h"

void EnsureModuleIsLoaded(LPCSTR pLibPath)
{
#ifdef _DEBUG
	printf("EnsureModuleIsLoaded(\"%s\");\n", pLibPath);
#endif

	HMODULE hModule = GetModuleHandleA(pLibPath);
	if (!hModule)
	{
		if (hModule = LoadLibraryA(pLibPath), !hModule)
		{
			MessageBoxA(NULL, pLibPath, "failed to load library", MB_ICONERROR);
		}
		assert(hModule);
	}
}

int main(int argc, LPSTR *argv)
{
#ifndef _DEBUG
	FreeConsole();
#endif
#ifdef _DEBUG
	printf("main(%i, \"%s\"", argc, std::string(argv[0]).substr(std::string(argv[0]).find_last_of("/\\") + 1).c_str());
	for (size_t i = 1; i < argc; i++)
	{
		printf(" \"%s\"", argv[i]);
	}
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
		pMap    = "forge_halo";
		break;
	}

	static auto gameEngineHost = IGameEngineHost();
	static auto gameRasterizer = IGameRasterizer(1280, 720, true);
	static auto gameInterface  = IGameInterface(pEngine);
	static auto gameContext    = IGameContext(gameInterface.GetDataAccess(), pEngine, pGame, pMap, pFilm);

	auto updateCallBack = [](IGameEngine *pEngine)
	{
		/*printf("Running!\n");*/

		if (GetKeyState(VK_END) & 0x80)
		{
			pEngine->UpdateEngineState(EngineState::eEndGameWriteStats);
			g_running = false;
		}
	};

	gameInterface.SetLocale("ko-KR", "ja-JP", "en-US");
	gameInterface.LaunchTitle(gameEngineHost, gameRasterizer, gameContext, g_running, updateCallBack);
}