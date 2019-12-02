#pragma once

class IDataAccess
{
public:
	virtual void                     Free()                                             = 0;
	virtual class IMapVariant       *MapVariantCreateFromFile(char *, size_t)           = 0;
	virtual class IMapVariant       *MapVariantCreateFromMapID(INT32)                   = 0;
	virtual class IMapVariant       *MapVariantCreateDefault(char *)                    = 0;
	virtual class IGameVariant      *GameVariantCreateFromFile(char *, size_t)          = 0;
	virtual class IGameVariant      *GameVariantCreateDefault(int)                      = 0;
	virtual bool                     LoadMapFromVariants(IGameVariant *, IMapVariant *) = 0;
	virtual class ISaveFilmMetadata *SaveFilmMetadataCreateFromFile(char *, size_t)     = 0;

	IGameVariant *GetGameVariant(LPCSTR pEngine, LPCSTR pName)
	{
		size_t file_size = {};
		IFileAccess *pFile = new IFileAccess(pathf("%s\\game_variants\\%s.bin", pEngine, pName));
		static class IGameVariant *pGameVariant = {};

		if (pFile->FileOpen())
		{
			pGameVariant = GameVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}
		else if (pFile = new IFileAccess(pathf("%s\\hopper_game_variants\\%s.bin", pEngine, pName)), pFile->FileOpen())
		{
			pGameVariant = GameVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}
		else if (pFile = new IFileAccess(pathf("%s\\AppData\\LocalLow\\MCC\\Temporary\\UserContent\\%s\\GameType\\%s.bin", GetUserprofileVariable(), pEngine, pName)), pFile->FileOpen())
		{
			pGameVariant = GameVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}

		return pGameVariant;
	}

	class IMapVariant *GetMapVariant(LPCSTR pEngine, LPCSTR pName)
	{
		size_t file_size = {};
		IFileAccess *pFile = new IFileAccess(pathf("%s\\map_variants\\%s.mvar", pEngine, pName));
		static class IMapVariant *pMapVariant = {};

		if (pFile->FileOpen())
		{
			pMapVariant = MapVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}
		else
		{
			if (pFile = new IFileAccess(pathf("%s\\hopper_map_variants\\%s.mvar", pEngine, pName)), pFile->FileOpen())
			{
				pMapVariant = MapVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
				pFile->FileClose();
			}
			else
			{
				if (pFile = new IFileAccess(pathf("%s\\AppData\\LocalLow\\MCC\\Temporary\\UserContent\\%s\\Map\\%s.bin", GetUserprofileVariable(), pEngine, pName)), pFile->FileOpen())
				{
					pMapVariant = MapVariantCreateFromFile(pFile->GetBuffer(file_size), file_size);
					pFile->FileClose();
				}
			}
		}

		return pMapVariant;
	}

	class ISaveFilmMetadata *GetSaveFilmMetadata(LPCSTR pEngine, LPCSTR &rpName)
	{
		static LPCSTR pPath = pathf("%s\\Temporary\\autosave\\%s.film", pEngine, rpName);

		size_t file_size = {};
		IFileAccess *pFile = new IFileAccess(pPath);
		static class ISaveFilmMetadata *pSaveFilmMetadata = {};

		if (pFile->FileOpen())
		{
			pSaveFilmMetadata = SaveFilmMetadataCreateFromFile(pFile->GetBuffer(file_size), file_size);
			pFile->FileClose();
		}
		else
		{
			pPath = pathf("%s\\AppData\\LocalLow\\MCC\\Temporary\\%s\\autosave\\%s.film", GetUserprofileVariable(), pEngine, rpName);
			if (pFile = new IFileAccess(pPath), pFile->FileOpen())
			{
				pSaveFilmMetadata = SaveFilmMetadataCreateFromFile(pFile->GetBuffer(file_size), file_size);
				pFile->FileClose();
			}
			else
			{
				pPath = pathf("%s\\AppData\\LocalLow\\MCC\\Temporary\\UserContent\\%s\\Movie\\%s.mov", GetUserprofileVariable(), pEngine, rpName);
				if (pFile = new IFileAccess(pPath), pFile->FileOpen())
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
