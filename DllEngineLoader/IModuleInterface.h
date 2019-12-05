#pragma once

class IModuleInterface
{
public:
	IModuleInterface();
	~IModuleInterface();

	static bool IsValidModule(int index);
	static bool IsInModule(size_t addr, int index, bool isFile = false);

	static int GetCount();

	static LPCSTR GetPath(int index);
	static size_t GetBase(int index, bool isFile = false);
	static size_t GetTop(int index, bool isFile = false);
	static size_t GetSize(int index);
	static size_t GetOffset(size_t addr, int index, bool isFile = false);

	template<typename T>
	static T GetAddess(size_t offset, LPCSTR pModule);
	template<typename T>
	static T &GetReference(size_t offset, LPCSTR pModule);
	template<typename T>
	static void Write(size_t offset, T data, LPCSTR pModule);

	static void Update();

private:
	static char   m_path[1024][MAX_PATH];
	static size_t m_addr[1024];
	static size_t m_base[1024];
	static size_t m_size[1024];
};

char   IModuleInterface::m_path[1024][MAX_PATH] = {};
size_t IModuleInterface::m_addr[1024] = {};
size_t IModuleInterface::m_base[1024] = {};
size_t IModuleInterface::m_size[1024] = {};

IModuleInterface::IModuleInterface()
{
	for (size_t i = 0; i < 1024; i++)
	{
		memset(m_path[i], 0, MAX_PATH);
		m_addr[i] = 0;
		m_base[i] = 0;
		m_size[i] = 0;
	}
}

IModuleInterface::~IModuleInterface()
{
}

bool IModuleInterface::IsValidModule(int index)
{
	bool result = m_path[index][0] && m_addr[index] && m_base[index] && m_size[index];
	return result;
}

bool IModuleInterface::IsInModule(size_t addr, int index, bool isFile)
{
	bool result = IsValidModule(index) && addr >= GetBase(index, isFile) && addr < GetTop(index, isFile);
	return result;
}

int IModuleInterface::GetCount()
{
	int index = 0;
	while (IsValidModule(index))
	{
		index++;
	}

	return index;
}

LPCSTR IModuleInterface::GetPath(int index)
{
	LPCSTR result = m_path[index];
	return result;
}

size_t IModuleInterface::GetBase(int index, bool isFile)
{
	size_t result = isFile ? m_base[index] : m_addr[index];
	return result;
}

size_t IModuleInterface::GetTop(int index, bool isFile)
{
	size_t result = m_size[index] + GetBase(index, isFile);
	return result;
}

size_t IModuleInterface::GetSize(int index)
{
	size_t result = m_size[index];
	return result;
}

size_t IModuleInterface::GetOffset(size_t addr, int index, bool isFile)
{
	size_t result = size_t();
	if (IsInModule(addr, index, isFile))
	{
		result = addr - GetBase(index, isFile);
	}

	return result;
}

template<typename T>
T IModuleInterface::GetAddess(size_t offset, LPCSTR pModule)
{
	size_t result = size_t();
	for (int i = 0; i < GetCount(); i++)
	{
		if (strstr(GetPath(i), pModule) != 0)
		{
			if (IsInModule(GetBase(i, true) + GetOffset(offset, i, true), i, true))
			{
				result = GetBase(i) + GetOffset(offset, i, true);
			}
		}
	}

	return (T)result;
}

template<typename T>
T &IModuleInterface::GetReference(size_t offset, LPCSTR pModule)
{
	return *GetAddess<T *>(offset, pModule);
}

template<typename T>
void IModuleInterface::Write(size_t offset, T data, LPCSTR pModule)
{
	auto addr = IModuleInterface::GetAddess<LPVOID>(offset, IGameInterface::s_modulePath);
	DWORD old;
	VirtualProtect(addr, sizeof(T), PAGE_READWRITE, &old);
	memcpy(addr, data, sizeof(T));
	VirtualProtect(addr, sizeof(T), old, &old);
}

void IModuleInterface::Update()
{
	auto hProcess = GetCurrentProcess();
	HMODULE m_hModules[1024]; DWORD cbNeeded;
	if (EnumProcessModules(hProcess, m_hModules, sizeof(m_hModules), &cbNeeded))
	{
		for (unsigned int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			MODULEINFO moduleInformation;
			if (GetModuleInformation(hProcess, m_hModules[i], &moduleInformation, sizeof(moduleInformation)))
			{
				if (GetModuleFileNameExA(hProcess, m_hModules[i], m_path[i], sizeof(m_path[i]) / sizeof(char)))
				{
					m_addr[i] = (size_t)moduleInformation.lpBaseOfDll;
					m_size[i] = (size_t)moduleInformation.SizeOfImage;

					HANDLE hFile = CreateFileA(m_path[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
					if (hFile != INVALID_HANDLE_VALUE)
					{
						HANDLE hFileMapping = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
						if (hFileMapping != INVALID_HANDLE_VALUE)
						{
							LPVOID lpFileBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
							if (lpFileBase != 0)
							{
								auto dosHeader = (PIMAGE_DOS_HEADER)lpFileBase;
								if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE)
								{
									m_base[i] = ((PIMAGE_NT_HEADERS)((UINT64)dosHeader + (UINT64)dosHeader->e_lfanew))->OptionalHeader.ImageBase;
								}
								UnmapViewOfFile(lpFileBase);
							}
							CloseHandle(hFileMapping);
						}
						CloseHandle(hFile);
					}
				}
			}
		}
	}
}

auto WriteStackTrace = [=](LPCSTR pCallingFunction = "")
{
	IModuleInterface::Update();

	printf("TRACE(%s)\n", pCallingFunction);
	printf("{\n");

	size_t traces[1024];
	for (int traceIndex = 0; traceIndex < CaptureStackBackTrace(0, 1024, (LPVOID *)traces, NULL); traceIndex++)
	{
		for (int i = 0; i < 1024; i++)
		{
			if (IModuleInterface::IsInModule(traces[traceIndex], i))
			{
				auto offset = IModuleInterface::GetOffset(traces[traceIndex], i);
				printf("\t0x%016llX, %s+0x%08llX\n", IModuleInterface::GetOffset(traces[traceIndex], i, true), GetFileName(IModuleInterface::GetPath(i)).c_str(), offset);
			}
		}
	}

	printf("}\n");
};