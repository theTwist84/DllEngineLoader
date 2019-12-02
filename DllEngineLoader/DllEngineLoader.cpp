#include "stdafx.h"

int main(int argc, LPSTR *argv)
{
	LPCSTR pEngineName = "";
	LPCSTR pGameName = "";
	LPCSTR pMapName = "";
	LPCSTR pSavedFilmName = "";

	if (argc == 3)
	{
		pEngineName = argv[1];
		pSavedFilmName = argv[2];
	}
	else if (argc == 4)
	{
		pEngineName = argv[1];
		pGameName = argv[2];
		pMapName = argv[3];
	}

	auto pEngineInterface = new c_engine_interface(pathf("%s\\%s.dll", pEngineName, pEngineName));
	auto pDataAccess = pEngineInterface->GetDataAccess();
	auto pEngine = pEngineInterface->GetEngine();

	if (!LoadLibraryA("MCC\\Binaries\\Win64\\bink2w64.dll"))
	{
		printf("unable to load bink\n");
	}

	char windowText[1024] = "";

	static IGameContext gameContext = IGameContext();
	IGameVariant *pGameVariant = {};
	IMapVariant *pMapVariant = {};
	ISaveFilmMetadata *pSaveFilmMetadata = {};

	if (pSavedFilmName == "")
	{
		if (pGameVariant = pDataAccess->GetGameVariant(pEngineName, pGameName), pGameVariant)
		{
			printf("%S - %S\n\n", pGameVariant->GetName(), pGameVariant->GetDescription());
		}

		if (pMapVariant = pDataAccess->GetMapVariant(pEngineName, pMapName), pMapVariant)
		{
			printf("%S - %S\n\n", pMapVariant->GetName(), pMapVariant->GetDescription());
		}
		else
		{
			pMapVariant = pDataAccess->MapVariantCreateFromMapID(MapNameToMapID(pMapName));
		}

		if (pGameVariant && pMapVariant)
		{
			LPCSTR pGameVariantName = ""; LPCSTR pMapVariantName = "";
			if (pGameVariant->GetName()[0])
			{
				pGameVariantName = pathf("%S", pGameVariant->GetName());
			}
			else
			{
				pGameVariantName = pGameName;
			}

			if (pMapVariant->GetName()[0])
			{
				pMapVariantName = pathf("%S", pGameVariant->GetName());
			}
			else
			{
				pMapVariantName = pMapName;
			}

			std::time_t ct = std::time(0);
			sprintf(windowText, "%s on %s, %s", pGameVariantName, pMapVariantName, ctime(&ct));
		}
	}
	else
	{
		if (pSaveFilmMetadata = pDataAccess->GetSaveFilmMetadata(pEngineName, pSavedFilmName), pSaveFilmMetadata)
		{
			gameContext.SetSavedFilmPath(pSavedFilmName);
			printf("%S - %S\n\n", pSaveFilmMetadata->GetName(), pSaveFilmMetadata->GetDescription());
			sprintf(windowText, "%S", pSaveFilmMetadata->GetDescription());
		}
	}

	if (pGameVariant)
	{
		GameMode gameMode = GameMode::eBase;
		switch (*reinterpret_cast<INT32 *>(pGameVariant->GetData()))
		{
		case 1:
			gameMode = GameMode::eMultiplayer;
			break;
		case 2:
			gameMode = GameMode::eMultiplayer;
			break;
		case 3:
			gameMode = GameMode::eCampaign;
			break;
		case 4:
			gameMode = GameMode::eSurvival;
			break;
		}
		gameContext.SetGameVariant(pGameVariant);
		gameContext.SetGameMode(gameMode);
	}

	if (pMapVariant)
	{
		gameContext.SetMapVariant(pMapVariant);
		gameContext.SetMapID(pMapVariant->GetID());
	}


	gameContext.SetupSession();

	SetWindowTextA(IGameRenderer::GetWindowHandle(), windowText);

	HANDLE hMainGameThread = NULL;
	if (hMainGameThread = pEngine->Init(s_gameRenderer, s_gameEngineHost, gameContext), hMainGameThread)
	{
		g_running = true;

		while (g_running)
		{
			s_gameRenderer.Update();
		}

		WaitForSingleObject(hMainGameThread, INFINITE);
	}

	pDataAccess->Free();
	pEngine->Free();
}