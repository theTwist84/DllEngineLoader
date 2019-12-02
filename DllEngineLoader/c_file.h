#pragma once
#pragma warning(disable:4996)

class c_file
{
public:
	c_file(LPCSTR);
	~c_file();

	static bool FileOpen();
	static void FileClose();

	static char *GetBuffer(size_t &);

private:
	static char s_filePath[MAX_PATH];
	static FILE *s_pFile;

	static char *s_pBuffer;
	static size_t s_bufferSize;
};

char c_file::s_filePath[MAX_PATH] = {};
FILE *c_file::s_pFile = nullptr;

char *c_file::s_pBuffer = nullptr;
size_t c_file::s_bufferSize = -1;


c_file::c_file(LPCSTR pFilePath)
{
	strcpy(s_filePath, pFilePath);
}

c_file::~c_file()
{
	strcpy(s_filePath, "");
}

bool c_file::FileOpen()
{
	if (s_pFile = fopen(s_filePath, "rb"))
	{
		fseek(s_pFile, 0, SEEK_END);
		s_bufferSize = ftell(s_pFile);
		fseek(s_pFile, 0L, SEEK_SET);
		s_pBuffer = new char[s_bufferSize];
		memset(s_pBuffer, 0x00, s_bufferSize);

		fseek(s_pFile, 0L, SEEK_SET);
		size_t totalBytesRead = 0;
		do
		{
			size_t bytesToRead = s_bufferSize - totalBytesRead;
			fseek(s_pFile, static_cast<long>(totalBytesRead), SEEK_SET);
			size_t bytesRead = fread(s_pBuffer + totalBytesRead, 1, bytesToRead, s_pFile);
			totalBytesRead += bytesRead;
		} while (totalBytesRead < s_bufferSize);

		return true;
	}

	return false;
}

void c_file::FileClose()
{
	if (s_pFile)
	{
		if (s_pBuffer)
		{
			free(s_pBuffer);
			s_bufferSize = 0;
		}
		fclose(s_pFile);
	}
}

char *c_file::GetBuffer(size_t &rBufferSize)
{
	rBufferSize = s_bufferSize;
	return s_pBuffer;
}
