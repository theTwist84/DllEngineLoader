#pragma once

class IModuleInterface
{
	struct s_module
	{
		char   m_path[MAX_PATH];
		size_t m_addr;
		size_t m_base;
		size_t m_size;

		// TODO: add file version
		//size_t m_ver
	};

public:
	IModuleInterface();
	~IModuleInterface();

	static bool IsValidModule(int index);
	static bool IsInModule(int index, size_t addr, bool isFile = false);

	static int GetCount();
	static int GetIndex(LPCSTR pModule);

	static LPCSTR GetPath(int index);
	static LPCSTR GetPath(LPCSTR pModule);

	static size_t GetBase(int index, bool isFile = false);
	static size_t GetBase(LPCSTR pModule, bool isFile = false);

	static size_t GetTop(int index, bool isFile = false);
	static size_t GetTop(LPCSTR pModule, bool isFile = false);

	static size_t GetSize(int index);
	static size_t GetSize(LPCSTR pModule);

	static size_t GetOffset(int index, size_t addr, bool isFile = false);
	static size_t GetOffset(LPCSTR pModule, size_t addr, bool isFile);

	template<typename T>
	static T GetAddress(int index, size_t offset);
	template<typename T>
	static T GetAddress(LPCSTR pModule, size_t offset);

	template<typename T>
	static T &Read(int index, size_t offset);
	template<typename T>
	static T &Read(LPCSTR pModule, size_t offset);

	template<typename T>
	static void Write(int index, size_t offset, T data);
	template<typename T>
	static void Write(LPCSTR pModule, size_t offset, T data);

	static void Update();

private:
	static s_module m_modules[1024];
};

IModuleInterface::s_module IModuleInterface::m_modules[1024] = {};

IModuleInterface::IModuleInterface()
{
	for (size_t i = 0; i < 1024; i++)
	{
		memset(m_modules[i].m_path, 0, MAX_PATH);
		m_modules[i].m_addr = 0;
		m_modules[i].m_base = 0;
		m_modules[i].m_size = 0;
	}
}

IModuleInterface::~IModuleInterface()
{
}

bool IModuleInterface::IsValidModule(int index)
{
	bool result = GetPath(index)[0] && GetBase(index) && GetBase(index, true) && GetSize(index);
	return result;
}

bool IModuleInterface::IsInModule(int index, size_t addr, bool isFile)
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

int IModuleInterface::GetIndex(LPCSTR pModule)
{
	int result = int();
	for (int i = 0; i < GetCount(); i++)
	{
		if (strstr(GetPath(i), pModule) != 0)
		{
			result = i;
		}
	}
	return result;
}

LPCSTR IModuleInterface::GetPath(int index)
{
	LPCSTR result = m_modules[index].m_path;
	return result;
}

LPCSTR IModuleInterface::GetPath(LPCSTR pModule)
{
	auto index = GetIndex(pModule);
	LPCSTR result = m_modules[index].m_path;
	return result;
}

size_t IModuleInterface::GetBase(int index, bool isFile)
{
	size_t result = isFile ? m_modules[index].m_base : m_modules[index].m_addr;
	return result;
}

size_t IModuleInterface::GetBase(LPCSTR pModule, bool isFile)
{
	auto index = GetIndex(pModule);
	size_t result = isFile ? m_modules[index].m_base : m_modules[index].m_addr;
	return result;
}

size_t IModuleInterface::GetTop(int index, bool isFile)
{
	size_t result = GetBase(index, isFile) + GetSize(index);
	return result;
}

size_t IModuleInterface::GetTop(LPCSTR pModule, bool isFile)
{
	auto index = GetIndex(pModule);
	size_t result = GetBase(index, isFile) + GetSize(index);
	return result;
}

size_t IModuleInterface::GetSize(int index)
{
	size_t result = m_modules[index].m_size;
	return result;
}

size_t IModuleInterface::GetSize(LPCSTR pModule)
{
	auto index = GetIndex(pModule);
	size_t result = m_modules[index].m_size;
	return result;
}

size_t IModuleInterface::GetOffset(int index, size_t addr, bool isFile)
{
	size_t result = size_t();
	if (IsInModule(index, addr, isFile))
	{
		result = addr - GetBase(index, isFile);
	}
	return result;
}

size_t IModuleInterface::GetOffset(LPCSTR pModule, size_t addr, bool isFile)
{
	size_t result = size_t();
	auto index = GetIndex(pModule);
	if (IsInModule(index, addr, isFile))
	{
		result = addr - GetBase(index, isFile);
	}
	return result;
}

template<typename T>
T IModuleInterface::GetAddress(int index, size_t offset)
{
	size_t result = size_t();
	if (IsInModule(index, GetBase(index, true) + GetOffset(index, offset, true), true))
	{
		result = GetBase(index) + GetOffset(index, offset, true);
	}
	return (T)result;
}

template<typename T>
T IModuleInterface::GetAddress(LPCSTR pModule, size_t offset)
{
	size_t result = size_t();
	auto index = GetIndex(pModule);
	if (IsInModule(index, GetBase(index, true) + GetOffset(index, offset, true), true))
	{
		result = GetBase(index) + GetOffset(index, offset, true);
	}
	return (T)result;
}

template<typename T>
T &IModuleInterface::Read(int index, size_t offset)
{
	return *GetAddress<T *>(index, offset);
}

template<typename T>
T &IModuleInterface::Read(LPCSTR pModule, size_t offset)
{
	return *GetAddress<T *>(pModule, offset);
}

template<typename T>
void IModuleInterface::Write(int index, size_t offset, T data)
{
	auto addr = IModuleInterface::GetAddress<LPVOID>(index, offset);
	DWORD old;
	VirtualProtect(addr, sizeof(T), PAGE_READWRITE, &old);
	memcpy(addr, data, sizeof(T));
	VirtualProtect(addr, sizeof(T), old, &old);
}

template<typename T>
void IModuleInterface::Write(LPCSTR pModule, size_t offset, T data)
{
	auto index = GetIndex(pModule);
	auto addr = IModuleInterface::GetAddress<LPVOID>(index, offset);
	DWORD old;
	VirtualProtect(addr, sizeof(T), PAGE_READWRITE, &old);
	memcpy(addr, &data, sizeof(T));
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
				if (GetModuleFileNameExA(hProcess, m_hModules[i], m_modules[i].m_path, sizeof(m_modules[i].m_path) / sizeof(char)))
				{
					m_modules[i].m_addr = (size_t)moduleInformation.lpBaseOfDll;
					m_modules[i].m_size = (size_t)moduleInformation.SizeOfImage;

					HANDLE hFile = CreateFileA(m_modules[i].m_path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
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
									m_modules[i].m_base = ((PIMAGE_NT_HEADERS)((UINT64)dosHeader + (UINT64)dosHeader->e_lfanew))->OptionalHeader.ImageBase;
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
			if (IModuleInterface::IsInModule(i, traces[traceIndex]))
			{
				auto offset = IModuleInterface::GetOffset(i, traces[traceIndex]);
				printf("\t0x%016llX, %s+0x%08llX\n", IModuleInterface::GetOffset(i, traces[traceIndex], true), GetFileName(IModuleInterface::GetPath(i)).c_str(), offset);
			}
		}
	}

	printf("}\n");
};


class IPatch
{
public:
	IPatch(LPCSTR pModule, size_t offset, std::initializer_list<UINT8> patchBytes);
	~IPatch();

	void Apply(bool revert = false);

private:
	LPCSTR                       Module;
	size_t                       Offset;
	std::initializer_list<UINT8> PatchBytes;
	std::vector<UINT8>           OrigBytes;
};

class IPatchInterface
{
public:
	IPatchInterface(IPatch &rPatch);
	~IPatchInterface();

	static std::vector<IPatch> Get();

private:
	static std::vector<IPatch> s_Patches;
};

std::vector<IPatch> IPatchInterface::s_Patches;

IPatch::IPatch(LPCSTR pModule, size_t offset, std::initializer_list<UINT8> patchBytes)
	: Module(pModule), Offset(offset), PatchBytes(patchBytes)
{
	for (size_t i = 0; i < PatchBytes.size(); i++)
	{
		OrigBytes.push_back(IModuleInterface::Read<UINT8>(pModule, offset + i));
	}

	IPatchInterface(*this);
}

IPatch::~IPatch()
{
}

void IPatch::Apply(bool revert)
{
	auto bytes = revert ? OrigBytes : PatchBytes;
	for (size_t i = 0; i < PatchBytes.size(); i++)
	{
		IModuleInterface::Write(Module, Offset + i, bytes[i]);
	}
}

IPatchInterface::IPatchInterface(IPatch &rPatch)
{
	s_Patches.push_back(rPatch);
}

IPatchInterface::~IPatchInterface()
{
}

std::vector<IPatch> IPatchInterface::Get()
{
	return s_Patches;
}