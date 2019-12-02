#pragma once

// ====================================================================
//							Engine Stub
// ====================================================================

class c_engine
{
public:
	virtual int InitGraphics(ID3D11Device *pDevice, ID3D11DeviceContext *pDeviceContext, IDXGISwapChain *pSwapchain, IDXGISwapChain *pFallbackSwapchain) = 0;
	virtual HANDLE InitThread(IGameEngineHost *pGameEngineHost, /*struct GameContext*/char *pGameContext) = 0;
	virtual int UpdateEngineState(int state, LPVOID unknown) = 0;
	virtual int Free() = 0;
	virtual void Function4() = 0;
	virtual void Function5() = 0;
	virtual void Function6() = 0;
	virtual void Function7() = 0;
	virtual void Function8() = 0;
	virtual int Function9(LPVOID unknown) = 0;
	virtual void Function10() = 0;

private:
	static char s_data[0x460];
};


// ====================================================================
//							Engine Data
// ====================================================================

class c_engine_data
{
public:
	virtual void Free() = 0;
	virtual char *MapVariantCreateFromFile(char *pFileBuffer, size_t) = 0;
	virtual char *MapVariantCreateFromMapId(int mapId) = 0;
	virtual char *MapVariantCreateDefault(char *pFileBuffer) = 0;
	virtual char *GameVariantCreateFromFile(char *pFileBuffer, size_t fileSize) = 0;
	virtual char *GameVariantCreateDefault(int engineIndex) = 0;
	virtual bool LoadMapFromVariants(char *pGameVariant, char *pMapVariant) = 0;
	virtual char *SaveFilmMetadataCreateFromFile(char *pFileBuffer, size_t fileSize) = 0;

private:
	void *m_HeapAllocation;
	void *m_function0;
	void *m_HeapAllocationSize;
	void *m_function1;
};

// ====================================================================
//							Engine Interface
// ====================================================================

class c_engine_interface
{
public:
	c_engine_interface(LPCSTR);
	~c_engine_interface();

	c_engine *GetEngine();
	c_engine_data *GetEngineData();

private:
	static char s_modulePath[MAX_PATH];
	static HMODULE s_hLibModule;

	c_engine *m_pEngine = nullptr;
	c_engine_data *m_pEngineData = nullptr;
};

char c_engine_interface::s_modulePath[MAX_PATH] = {};
HMODULE c_engine_interface::s_hLibModule = nullptr;

c_engine_interface::c_engine_interface(LPCSTR pModulePath)
{
	strcpy(s_modulePath, pModulePath);

	if (!s_hLibModule)
	{
		s_hLibModule = LoadLibraryA(s_modulePath);
		//printf("%p [%s]\n", s_hLibModule, s_modulePath);
	}

	if (s_hLibModule)
	{
		if (!m_pEngine)
		{
			auto pCreateGameEngine = (int(*)(c_engine **))GetProcAddress(s_hLibModule, "CreateGameEngine");
			pCreateGameEngine(&m_pEngine);
		}
		if (!m_pEngineData)
		{
			auto pCreateDataAccess = (int(*)(c_engine_data **))GetProcAddress(s_hLibModule, "CreateDataAccess");
			pCreateDataAccess(&m_pEngineData);
		}
		// auto pSetLibrarySettings = (int(*)(wchar_t *))GetProcAddress(s_hLibModule, "SetLibrarySettings");
	}
}

c_engine_interface::~c_engine_interface()
{
	if (s_hLibModule)
	{
		FreeLibrary(s_hLibModule);
	}
	strcpy(s_modulePath, "");
}

c_engine *c_engine_interface::GetEngine()
{
	return m_pEngine;
}

c_engine_data *c_engine_interface::GetEngineData()
{
	return m_pEngineData;
}
