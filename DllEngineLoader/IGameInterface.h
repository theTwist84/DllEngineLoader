#pragma once

class IGameInterface
{
public:
	IGameInterface(LPCSTR);
	~IGameInterface();

	static void         LaunchTitle(bool &, void(*)());
	static void         SetLocale(LPCSTR, LPCSTR, LPCSTR);

	static IGameEngine *GetEngine();
	static IDataAccess *GetDataAccess();

private:
	static char         s_modulePath[MAX_PATH];
	static HMODULE      s_hLibModule;

	static IGameEngine *s_pEngine;
	static IDataAccess *s_pDataAccess;
};

char         IGameInterface::s_modulePath[MAX_PATH] = {};
HMODULE      IGameInterface::s_hLibModule           = 0;
IGameEngine *IGameInterface::s_pEngine              = 0;
IDataAccess *IGameInterface::s_pDataAccess          = 0;

static IGameInterface *g_pGameInterface = 0;

IGameInterface::IGameInterface(LPCSTR pEngine)
{
	strcpy(s_modulePath, pathf("%s\\%s.dll", pEngine, pEngine));

	if (!s_hLibModule)
	{
		s_hLibModule = LoadLibraryA(s_modulePath);
		//printf("%p [%s]\n", s_hLibModule, s_modulePath);
	}

	if (s_hLibModule)
	{
		if (!s_pEngine)
		{
			auto pCreateGameEngine = (int(*)(IGameEngine **))GetProcAddress(s_hLibModule, "CreateGameEngine");
			pCreateGameEngine(&s_pEngine);
		}
		if (!s_pDataAccess)
		{
			auto pCreateDataAccess = (int(*)(IDataAccess **))GetProcAddress(s_hLibModule, "CreateDataAccess");
			pCreateDataAccess(&s_pDataAccess);
		}
	}
}

IGameInterface::~IGameInterface()
{
	if (s_hLibModule)
	{
		FreeLibrary(s_hLibModule);
	}
	strcpy(s_modulePath, "");
}

IGameEngine *IGameInterface::GetEngine()
{
	return s_pEngine;
}

IDataAccess *IGameInterface::GetDataAccess()
{
	return s_pDataAccess;
}

void IGameInterface::LaunchTitle(bool &rRunning, void(*pCallback)() = nullptr)
{
	if (!LoadLibraryA("MCC\\Binaries\\Win64\\bink2w64.dll"))
	{
		printf("unable to load bink\n");
		return;
	}

	auto pEngine = GetEngine();
	auto pDataAccess = GetDataAccess();

	//LPCSTR pLocale = "en-US";
	//SetLocale(pLocale, pLocale, pLocale);
	pEngine->InitGraphics(g_pGameRasterizer->GetDevice(), NULL/*g_pGameRasterizer->GetContext()*/, g_pGameRasterizer->GetSwapChain(), 0);
	HANDLE hMainGameThread = pEngine->InitThread(g_pGameEngineHost, g_pGameContext);

	if (rRunning = hMainGameThread ? true : false)
	{
		while (rRunning)
		{
			g_pGameRasterizer->Update();

			if (pCallback)
			{
				pCallback();
			}
		}

		WaitForSingleObject(hMainGameThread, INFINITE);
	}

	g_pGameRasterizer->DisposeWindow();
	pDataAccess->Free();
	pEngine->Free();
}

void IGameInterface::SetLocale(LPCSTR pAudio = "en-US", LPCSTR pUi = "en-US", LPCSTR pUnknown = "en-US")
{
	static int(*pSetLibrarySettings)(wchar_t *) = nullptr;
	if (!pSetLibrarySettings)
	{
		pSetLibrarySettings = (int(*)(wchar_t *))GetProcAddress(s_hLibModule, "SetLibrarySettings");
	}

	wchar_t language[3 * 85] = {};
	memset(language, 0, sizeof(language));

	_snwprintf(&language[85 * 0], 84, L"%S", pAudio);
	_snwprintf(&language[85 * 1], 84, L"%S", pUi);
	_snwprintf(&language[85 * 2], 84, L"%S", pUnknown);

	pSetLibrarySettings(language);
}
