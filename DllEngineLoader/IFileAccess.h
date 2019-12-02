#pragma once
#pragma warning(disable:4996)

class IFileAccess
{
public:
	IFileAccess(LPCSTR);
	~IFileAccess();

	bool   FileOpen();
	void   FileClose();

	char  *GetBuffer(size_t &);

private:
	char   s_filePath[MAX_PATH] = {};
	FILE  *s_pFile              = 0;

	char  *s_pBuffer            = 0;
	size_t s_size               = 0;
};


IFileAccess::IFileAccess(LPCSTR pFilePath)
{
	strcpy(s_filePath, pFilePath);
}

IFileAccess::~IFileAccess()
{
	strcpy(s_filePath, "");
}

bool IFileAccess::FileOpen()
{
	if (s_pFile = fopen(s_filePath, "rb"))
	{
		fseek(s_pFile, 0, SEEK_END);
		s_size = ftell(s_pFile);
		fseek(s_pFile, 0L, SEEK_SET);
		s_pBuffer = new char[s_size];
		memset(s_pBuffer, 0x00, s_size);

		fseek(s_pFile, 0L, SEEK_SET);
		size_t totalBytesRead = 0;
		do
		{
			size_t bytesToRead = s_size - totalBytesRead;
			fseek(s_pFile, static_cast<long>(totalBytesRead), SEEK_SET);
			size_t bytesRead = fread(s_pBuffer + totalBytesRead, 1, bytesToRead, s_pFile);
			totalBytesRead += bytesRead;
		} while (totalBytesRead < s_size);

		return true;
	}

	return false;
}

void IFileAccess::FileClose()
{
	if (s_pFile)
	{
		if (s_pBuffer)
		{
			free(s_pBuffer);
			s_size = 0;
		}
		fclose(s_pFile);
	}
}

char *IFileAccess::GetBuffer(size_t &rBufferSize)
{
	rBufferSize = s_size;
	return s_pBuffer;
}
