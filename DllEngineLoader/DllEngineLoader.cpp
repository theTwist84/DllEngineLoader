#include <windows.h>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <stdio.h>

#include "IGameRenderer.h"
#include "IGameEvents.h"
#include "IGameEngineHost.h"

#include "c_file.h"
#include "c_engine.h"

const char *pathf(LPCSTR fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	static char path[MAX_PATH];
	int result = vsnprintf_s(path, MAX_PATH, _TRUNCATE, fmt, args);
	va_end(args);

	return path;
};

LPCSTR GetUserprofileVariable()
{
	static char szBuf[MAX_PATH] = { 0 };
	GetEnvironmentVariableA("USERPROFILE", szBuf, MAX_PATH);
	return szBuf;
};

void SetupGameContext(char *&rGameContext, c_engine_interface &rEngineInterface, LPCSTR pEngineName, LPCSTR pGameVarianName, LPCSTR pMapVarianName, LPCSTR pSavedFilmName)
{
	auto pEngineData = rEngineInterface.GetEngineData();

	static char s_GameContext[0x2B708];
	memset(s_GameContext, 0, sizeof(s_GameContext));

	if (pSavedFilmName)
	{
		static LPCSTR pSavedFilmPath = pathf("%s\\AppData\\LocalLow\\MCC\\Temporary\\UserContent\\%s\\Movie\\%s.mov", GetUserprofileVariable(), pEngineName, pSavedFilmName);
		*(LPCSTR *)(s_GameContext + 0x2B438) = pSavedFilmPath;

		size_t savedFilmSize = -1;
		auto file = c_file(pSavedFilmPath);
		if (file.FileOpen())
		{
			auto saved_film = pEngineData->SaveFilmMetadataCreateFromFile(file.GetBuffer(savedFilmSize), savedFilmSize);

			// get variant name and description
			auto name = ((wchar_t *(*)(char *))(*(LPVOID **)saved_film)[5])(saved_film);
			auto desc = ((wchar_t *(*)(char *))(*(LPVOID **)saved_film)[6])(saved_film);
			printf("%S - %S\n\n", name, desc);

			file.FileClose();
		}
	}
	else
	{
		// set IGameContext::m_mode to multiplayer
		*(int *)s_GameContext = 3;

		// set local client as host
		*(bool *)(s_GameContext + 0x2B450) = true;

		// set peer and player count to 1
		*(int64_t *)(s_GameContext + 0x2B4E0) = *(int64_t *)(s_GameContext + 0x2B6E8) = 1;

		{
			size_t variantSize = -1;
			auto file = c_file(pathf("%s\\game_variants\\%s.bin", pEngineName, pGameVarianName));
			if (file.FileOpen())
			{
				auto variant = pEngineData->GameVariantCreateFromFile(file.GetBuffer(variantSize), variantSize);

				// copy IGameVariant::m_data to IGameContext::m_gameVariant
				memcpy(s_GameContext + 4, &variant[sizeof(LPVOID)], variantSize);

				// get variant name and description
				auto name = ((wchar_t *(*)(char *))(*(LPVOID **)variant)[1])(variant);
				auto desc = ((wchar_t *(*)(char *))(*(LPVOID **)variant)[2])(variant);
				printf("%S - %S\n\n", name, desc);

				//char *data; size_t dataSize = 0;
				//if (((bool(*)(char *, char **, size_t *))(*(LPVOID **)variant)[8])(variant, &data, &dataSize)) { }

				file.FileClose();
			}
		}
		{
			size_t variantSize = -1;
			auto file = c_file(pathf("%s\\map_variants\\%s.mvar", pEngineName, pMapVarianName));
			if (file.FileOpen())
			{
				auto variant = pEngineData->MapVariantCreateFromFile(file.GetBuffer(variantSize), variantSize);

				// copy IMapVariant::m_data to IGameContext::m_mapVariant
				memcpy(s_GameContext + 0x1CC04, &variant[sizeof(LPVOID)], variantSize);

				// set IGameContext::m_mapId to the result of IMapVariant::GetId()
				*(int *)(s_GameContext + 0x2B404) = ((int(*)(char *))(*(LPVOID **)variant)[9])(variant);

				// get variant name and description
				auto name = ((wchar_t *(*)(char *))(*(LPVOID **)variant)[1])(variant);
				auto desc = ((wchar_t *(*)(char *))(*(LPVOID **)variant)[2])(variant);
				printf("%S - %S\n\n", name, desc);

				//char *data; size_t dataSize = 0;
				//if (((bool(*)(char *, char **, size_t *))(*(LPVOID **)variant)[8])(variant, &data, &dataSize)) { }

				file.FileClose();
			}
		}
	}


	rGameContext = s_GameContext;
}

int main(int argc, LPSTR *argv)
{
	LPCSTR pEngineName = "HaloReach";
	LPCSTR pGameVarianName = "slayer_classic_054";
	LPCSTR pMapVarianName = "beaver_creek_cl_031";
	LPCSTR pSavedFilmName = "";

	if (argc == 2)
	{
		pSavedFilmName = argv[1];
	}

	auto engine_interface = c_engine_interface(pathf("%s\\%s.dll", pEngineName, pEngineName));
	auto pEngine = engine_interface.GetEngine();

	LoadLibraryA("MCC\\Binaries\\Win64\\bink2w64.dll");

	static auto gameRenderer = IGameRenderer(1280, 720, true);
	pEngine->InitGraphics(gameRenderer.s_pDevice, gameRenderer.s_pDeviceContext, gameRenderer.s_pSwapChain, 0);

	char *pGameContext = {};
	SetupGameContext(pGameContext, engine_interface, pEngineName, pGameVarianName, pMapVarianName, pSavedFilmName);

	static auto gameEngineHost = IGameEngineHost();
	auto hMainGameThread = pEngine->InitThread(&gameEngineHost, pGameContext);

	// main loop
	while (true)
	{
		//Update();
	}

	WaitForSingleObject(hMainGameThread, INFINITE);
}
