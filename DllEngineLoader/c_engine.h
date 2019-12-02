#pragma once

// ====================================================================
//							Engine Stub
// ====================================================================

class c_engine
{
public:
	virtual int InitGraphics(ID3D11Device *pDevice, ID3D11DeviceContext *pDeviceContext, IDXGISwapChain *pSwapchain, IDXGISwapChain *pFallbackSwapchain) = 0;
	virtual HANDLE InitThread(class IGameEngineHost *pGameEngineHost, class IGameContext *pGameContext) = 0;
	virtual int UpdateEngineState(int state, LPVOID unknown = nullptr) = 0;
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
//							Engine DataAccess
// ====================================================================

class IMapVariant
{
public:
	// IVariantAccessorBase
	virtual void Free() = 0;
	virtual wchar_t *GetName() = 0;
	virtual wchar_t *GetDescription() = 0;
	virtual wchar_t *SetName(LPCWSTR pName) = 0;
	virtual wchar_t *SetDescription(LPCWSTR pDescription) = 0;
	virtual void Function5() = 0;
	virtual void Function6() = 0;
	virtual void Function7() = 0;
	virtual bool CreateFileFromBuffer(LPVOID pBuffer, size_t *pSize) = 0;

	virtual INT32 GetID() = 0;
	virtual bool Function10() = 0;
	virtual bool Function11() = 0;

	LPVOID GetData();
	size_t GetDataSize();

private:
	char m_data[0x14CD8];
};

LPVOID IMapVariant::GetData()
{
	return &m_data;
}

size_t IMapVariant::GetDataSize()
{
	return sizeof(m_data);
}

class IGameVariant
{
public:
	// IVariantAccessorBase
	virtual void Free() = 0;
	virtual wchar_t *GetName() = 0;
	virtual wchar_t *GetDescription() = 0;
	virtual wchar_t *SetName(LPCWSTR pName) = 0;
	virtual wchar_t *SetDescription(LPCWSTR pDescription) = 0;
	virtual void Function5() = 0;
	virtual void Function6() = 0;
	virtual void Function7() = 0;
	virtual bool CreateFileFromBuffer(LPVOID pBuffer, size_t *pSize) = 0;

	virtual bool Function9() = 0;
	virtual INT32 GetID() = 0;
	virtual bool Function11() = 0;
	virtual UINT8 Function12() = 0;
	virtual UINT32 Function13() = 0;
	virtual IGameVariant *Reset() = 0;
	virtual INT32 Function15(LPVOID, LPVOID) = 0;
	virtual UINT32 Function16(LPVOID, LPVOID) = 0;
	virtual bool Function17(LPVOID, LPVOID) = 0;
	virtual bool Function18(LPVOID, LPVOID) = 0;
	virtual bool Function19(LPVOID, LPVOID) = 0;
	virtual INT32 Function20() = 0;
	virtual bool Function21(INT32) = 0;

	LPVOID GetData();
	size_t GetDataSize();

private:
	char m_data[0x15230];
};

LPVOID IGameVariant::GetData()
{
	return &m_data;
}

size_t IGameVariant::GetDataSize()
{
	return sizeof(m_data);
}

class ISaveFilmMetadata
{
public:
	// IVariantAccessorBase
	virtual void Free() = 0;
	virtual INT32 Function1() = 0;
	virtual UINT32 Function2() = 0;
	virtual INT32 GetID() = 0;
	virtual INT64 GetAuthorXuid() = 0;
	virtual wchar_t *GetName() = 0;
	virtual wchar_t *GetDescription() = 0;

	LPVOID GetData();
	size_t GetDataSize();

private:
	char m_data[0x1F7B0];
};

LPVOID ISaveFilmMetadata::GetData()
{
	return &m_data;
}

size_t ISaveFilmMetadata::GetDataSize()
{
	return sizeof(m_data);
}

class IDataAccess
{
public:
	virtual void Free() = 0;
	virtual IMapVariant *MapVariantCreateFromFile(char *pBuffer, size_t size) = 0;
	virtual IMapVariant *MapVariantCreateFromMapID(int mapID) = 0;
	virtual IMapVariant *MapVariantCreateDefault(char *pBuffer) = 0;
	virtual IGameVariant *GameVariantCreateFromFile(char *pBuffer, size_t size) = 0;
	virtual IGameVariant *GameVariantCreateDefault(int engineIndex) = 0;
	virtual bool LoadMapFromVariants(IGameVariant *pGameVariant, IMapVariant *pMapVariant) = 0;
	virtual ISaveFilmMetadata *SaveFilmMetadataCreateFromFile(char *pBuffer, size_t size) = 0;

	IGameVariant *GetGameVariant(LPCSTR pEngine, LPCSTR pName)
	{
		size_t file_size = {};
		c_file *pFile = new c_file(pathf("%s\\game_variants\\%s.bin", pEngine, pName));
		static IGameVariant *pGameVariant = {};

		if (pFile->FileOpen())
		{
			pGameVariant = GameVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}
		else if (pFile = new c_file(pathf("%s\\hopper_game_variants\\%s.bin", pEngine, pName)), pFile->FileOpen())
		{
			pGameVariant = GameVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}
		else if (pFile = new c_file(pathf("%s\\AppData\\LocalLow\\MCC\\Temporary\\UserContent\\%s\\GameType\\%s.bin", GetUserprofileVariable(), pEngine, pName)), pFile->FileOpen())
		{
			pGameVariant = GameVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}

		return pGameVariant;
	}

	IMapVariant *GetMapVariant(LPCSTR pEngine, LPCSTR pName)
	{
		size_t file_size = {};
		c_file *pFile = new c_file(pathf("%s\\map_variants\\%s.mvar", pEngine, pName));
		static IMapVariant *pMapVariant = {};

		if (pFile->FileOpen())
		{
			pMapVariant = MapVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}
		else
		{
			if (pFile = new c_file(pathf("%s\\hopper_map_variants\\%s.mvar", pEngine, pName)), pFile->FileOpen())
			{
				pMapVariant = MapVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
				pFile->FileClose();
			}
			else
			{
				if (pFile = new c_file(pathf("%s\\AppData\\LocalLow\\MCC\\Temporary\\UserContent\\%s\\Map\\%s.bin", GetUserprofileVariable(), pEngine, pName)), pFile->FileOpen())
				{
					pMapVariant = MapVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
					pFile->FileClose();
				}
			}
		}

		return pMapVariant;
	}

	ISaveFilmMetadata *GetSaveFilmMetadata(LPCSTR pEngine, LPCSTR &rpName)
	{
		static LPCSTR pPath = pathf("%s\\Temporary\\autosave\\%s.film", pEngine, rpName);

		size_t file_size = {};
		c_file *pFile = new c_file(pPath);
		static ISaveFilmMetadata *pSaveFilmMetadata = {};

		if (pFile->FileOpen())
		{
			pSaveFilmMetadata = SaveFilmMetadataCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}
		else
		{
			pPath = pathf("%s\\AppData\\LocalLow\\MCC\\Temporary\\%s\\autosave\\%s.film", GetUserprofileVariable(), pEngine, rpName);
			if (pFile = new c_file(pPath), pFile->FileOpen())
			{
				pSaveFilmMetadata = SaveFilmMetadataCreateFromFile(pFile->GetBuffer(file_size), file_size);
				pFile->FileClose();
			}
			else
			{
				pPath = pathf("%s\\AppData\\LocalLow\\MCC\\Temporary\\UserContent\\%s\\Movie\\%s.mov", GetUserprofileVariable(), pEngine, rpName);
				if (pFile = new c_file(pPath), pFile->FileOpen())
				{
					pSaveFilmMetadata = SaveFilmMetadataCreateFromFile(pFile->GetBuffer(file_size), file_size);
					pFile->FileClose();
				}
			}
		}

		rpName = pPath;

		return pSaveFilmMetadata;
	}
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

	static c_engine *GetEngine();
	static IDataAccess *GetDataAccess();

	static void LaunchTitle(class IGameRenderer &rGameRenderer, class IGameEngineHost &rGameEngineHost, class IGameContext &rGameContext, bool &rRunning, void(*cb)());

private:
	static char s_modulePath[MAX_PATH];
	static HMODULE s_hLibModule;

	static c_engine *s_pEngine;
	static IDataAccess *s_pDataAccess;
};

char c_engine_interface::s_modulePath[MAX_PATH] = {};
HMODULE c_engine_interface::s_hLibModule = nullptr;
c_engine *c_engine_interface::s_pEngine = nullptr;
IDataAccess *c_engine_interface::s_pDataAccess = nullptr;

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
		if (!s_pEngine)
		{
			auto pCreateGameEngine = (int(*)(c_engine **))GetProcAddress(s_hLibModule, "CreateGameEngine");
			pCreateGameEngine(&s_pEngine);
		}
		if (!s_pDataAccess)
		{
			auto pCreateDataAccess = (int(*)(IDataAccess **))GetProcAddress(s_hLibModule, "CreateDataAccess");
			pCreateDataAccess(&s_pDataAccess);
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
	return s_pEngine;
}

IDataAccess *c_engine_interface::GetDataAccess()
{
	return s_pDataAccess;
}

void c_engine_interface::LaunchTitle(class IGameRenderer &rGameRenderer, class IGameEngineHost &rGameEngineHost, class IGameContext &rGameContext, bool &rRunning, void(*pCallback)() = nullptr)
{
	if (!LoadLibraryA("MCC\\Binaries\\Win64\\bink2w64.dll"))
	{
		printf("unable to load bink\n");
		return;
	}

	auto pEngine = GetEngine();
	auto pDataAccess = GetDataAccess();

	pEngine->InitGraphics(rGameRenderer.GetDevice(), rGameRenderer.GetDeviceContext(), rGameRenderer.GetSwapChain(), 0);
	HANDLE hMainGameThread = pEngine->InitThread(&rGameEngineHost, &rGameContext);

	if (rRunning = hMainGameThread ? true : false)
	{
		while (rRunning)
		{
			rGameRenderer.Update();

			if (pCallback)
			{
				pCallback();
			}
		}

		WaitForSingleObject(hMainGameThread, INFINITE);
	}

	pDataAccess->Free();
	pEngine->Free();
}
