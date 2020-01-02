#pragma once
#pragma warning(disable:4996)

enum class FileAccessType
{
	Read,
	Write,

	kCount
};

class IFileAccess
{
public:
	IFileAccess(LPCSTR, ...);
	~IFileAccess();

	bool   FileOpen(FileAccessType);
	void   FileClose();

	template<typename T>
	T     &FileRead(size_t &, size_t offset = 0);

	void   FileWrite(char *, size_t);

	LPCSTR GetFilePath();

private:
	char   s_filePath[MAX_PATH] = {};
	FILE  *s_pFile              = 0;

	char  *s_pBuffer            = 0;
	size_t s_size               = 0;
};

IFileAccess::IFileAccess(LPCSTR pFormat, ...)
{
	va_list args;
	va_start(args, pFormat);

	int result = vsnprintf_s(s_filePath, MAX_PATH, _TRUNCATE, pFormat, args);
	va_end(args);
}

IFileAccess::~IFileAccess()
{
	strcpy(s_filePath, "");
}

bool IFileAccess::FileOpen(FileAccessType accessType)
{
	switch (accessType)
	{
	case FileAccessType::Read:
		if (s_pFile = fopen(s_filePath, "rb"))
		{
			fseek(s_pFile, 0, SEEK_END);
			s_size = ftell(s_pFile);
			fseek(s_pFile, 0L, SEEK_SET);
			s_pBuffer = new char[s_size];
			memset(s_pBuffer, 0x00, s_size);

			return true;
		}
		break;
	case FileAccessType::Write:
		if (s_pFile = fopen(s_filePath, "wb"))
		{
			return true;
		}
		break;
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
	memset(s_filePath, 0, sizeof(s_filePath));
}

template<typename T>
T &IFileAccess::FileRead(size_t &rBufferSize, size_t offset)
{
	if (s_pFile)
	{
		fseek(s_pFile, 0L, SEEK_SET);
		size_t totalBytesRead = 0;
		do
		{
			size_t bytesToRead = s_size - totalBytesRead;
			fseek(s_pFile, static_cast<long>(totalBytesRead), SEEK_SET);
			size_t bytesRead = fread(s_pBuffer + totalBytesRead, 1, bytesToRead, s_pFile);
			totalBytesRead += bytesRead;
		} while (totalBytesRead < s_size);
	}

	rBufferSize = s_size;
	if (offset > 0)
		return *reinterpret_cast<T *>(&s_pBuffer[offset]);
	return *reinterpret_cast<T *>(&s_pBuffer);
}

void IFileAccess::FileWrite(char *buffer, size_t size)
{
	if (s_pFile)
	{
		fseek(s_pFile, 0L, SEEK_SET);
		size_t totalBytesRead = 0;
		do
		{
			size_t bytesToRead = size - totalBytesRead;
			fseek(s_pFile, static_cast<long>(totalBytesRead), SEEK_SET);
			size_t bytesRead = fwrite(buffer + totalBytesRead, 1, bytesToRead, s_pFile);
			totalBytesRead += bytesRead;
		} while (totalBytesRead < size);
	}
}

LPCSTR IFileAccess::GetFilePath()
{
	return s_filePath;
}