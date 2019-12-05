#pragma once

#include <windows.h>
#include <atomic>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <psapi.h>
#include <stdio.h>
#include <string>

#define DIRECTINPUT_VERSION 0x0800
#include <hidusage.h>
#include <dinput.h>
#include <Xinput.h>

#include <D3Dcompiler.h>
#include <dxgi.h>
#include <d3d11.h>
#include <d3d11_4.h>

struct s_mod_infos
{
	char   m_path[1024][MAX_PATH];
	size_t m_addr[1024];
	size_t m_base[1024];
	size_t m_size[1024];

	s_mod_infos()
	{
		for (size_t i = 0; i < 1024; i++)
		{
			memset(this->m_path[i], 0, MAX_PATH);
			this->m_addr[i] = 0;
			this->m_base[i] = 0;
			this->m_size[i] = 0;
		}

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

						HANDLE hFile = INVALID_HANDLE_VALUE;
						if (hFile = CreateFileA(m_path[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0), hFile != INVALID_HANDLE_VALUE)
						{
							HANDLE hFileMapping = INVALID_HANDLE_VALUE;
							if (hFileMapping = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL), hFileMapping != INVALID_HANDLE_VALUE)
							{
								LPVOID lpFileBase = 0;
								if (lpFileBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0), lpFileBase != 0)
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
};

LPCSTR GetUserprofileVariable()
{
	static char szBuf[MAX_PATH] = {};
	if (!szBuf[0])
	{
		memset(szBuf, 0, sizeof(szBuf));
		GetEnvironmentVariableA("USERPROFILE", szBuf, MAX_PATH);
	}

	return szBuf;
};

LPCSTR GetCommandLineArg(int index)
{
	static int     nArgs = 0;
	static LPWSTR *szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	static char    szBuf[4096] = {};

	memset(szBuf, 0, sizeof(szBuf));
	if (index < nArgs)
	{
		sprintf_s(szBuf, "%S", szArglist[index]);
	}
	return szBuf;
}

std::string GetFilePath(LPCSTR pStr)
{
	return std::string(pStr).erase(std::string(pStr).find_last_of("/\\") + 1, std::string::npos);
}

std::string GetFileName(LPCSTR pStr)
{
	return std::string(pStr).substr(std::string(pStr).find_last_of("/\\") + 1);
}

void EnsureModuleIsLoaded(LPCSTR pLibPath)
{
#ifdef _DEBUG
	printf("EnsureModuleIsLoaded(\"%s\");\n", pLibPath);
#endif

	HMODULE hModule = GetModuleHandleA(pLibPath);
	if (!hModule)
	{
		if (hModule = LoadLibraryA(pLibPath), !hModule)
		{
			MessageBoxA(NULL, pLibPath, "failed to load library", MB_ICONERROR);
		}
		else
		{
			FreeLibrary(hModule);
		}
	}
}

auto WriteStackTrace = [=](LPCSTR pCallingFunction)
{
	static s_mod_infos moduleInfos;

	printf("TRACE(%s)\n", pCallingFunction);
	printf("{\n");

	size_t traces[1024];
	for (int traceIndex = 0; traceIndex < CaptureStackBackTrace(0, 1024, (LPVOID*)traces, NULL); traceIndex++)
	{
		for (size_t i = 0; i < 1024; i++)
		{
			if (traces[traceIndex] >= moduleInfos.m_addr[i] && traces[traceIndex] < (moduleInfos.m_addr[i] + moduleInfos.m_size[i]))
			{
				auto offset = traces[traceIndex] - moduleInfos.m_addr[i];
				printf("\t%s+0x%08llX, 0x%016llX\n", GetFileName(moduleInfos.m_path[i]).c_str(), offset, (moduleInfos.m_base[i] + offset));
			}
		}
	}

	printf("}\n");
};

bool g_running = false;

#include "IFileAccess.h"

#include "IGameInput.h"
#include "IGameRasterizer.h"

#include "IGameEngine.h"
#include "IDataAccess.h"
#include "IVariantAccessorBase.h"
#include "IGameVariant.h"
#include "IMapVariant.h"
#include "ISaveFilmMetadata.h"

#include "IGameInterface.h"
#include "IGameContext.h"
#include "IGameEvents.h"
#include "IGameEngineHost.h"

#include "IConsoleAccess.h"
