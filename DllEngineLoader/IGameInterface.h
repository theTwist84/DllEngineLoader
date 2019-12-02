#pragma once

class IGameInterface
{
public:
	IGameInterface(LPCSTR);
	~IGameInterface();

	static void         LaunchTitle(IGameEngineHost &, IGameRasterizer &, IGameContext &, bool &, void(*)(IGameEngine *) = nullptr);
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

IGameInterface::IGameInterface(LPCSTR pEngine)
{
#ifdef _DEBUG
	printf("IGameInterface(\"%s\");\n", pEngine);
#endif

	strcpy(s_modulePath, pathf("%s\\%s.dll", pEngine, pEngine));

	if (!s_hLibModule)
	{
		s_hLibModule = LoadLibraryA(s_modulePath);
		//printf("0x%p [%s]\n", s_hLibModule, s_modulePath);
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

void IGameInterface::LaunchTitle(IGameEngineHost &rGameEngineHost, IGameRasterizer &rGameRasterizer, IGameContext &rGameContext, bool &rRunning, void(*pCallback)(IGameEngine *))
{
#ifdef _DEBUG
	printf("IGameInterface::LaunchTitle(0x%p, 0x%p, 0x%p, %s, 0x%p);\n", &rGameEngineHost, &rGameRasterizer, &rGameContext, rRunning ? "true" : "false", pCallback);
#endif

	auto pEngine     = GetEngine();
	auto pDataAccess = GetDataAccess();

	HANDLE hGameThread = pEngine->Initialize(rGameRasterizer, rGameEngineHost, rGameContext);
	assert(hGameThread);

	rRunning = true;

	while (rRunning)
	{
		if (pCallback) pCallback(pEngine);

		rGameRasterizer.Update();
	}

	WaitForSingleObject(hGameThread, INFINITE);

	rGameRasterizer.DisposeWindow();
	pDataAccess->Free();
	pEngine->Free();
}

void IGameInterface::SetLocale(LPCSTR pAudio = "en-US", LPCSTR pUi = "en-US", LPCSTR pUnknown = "en-US")
{
#ifdef _DEBUG
	printf("IGameInterface::SetLocale(\"%s\", \"%s\", \"%s\");\n", pAudio, pUi, pUnknown);
#endif

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
