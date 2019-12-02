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

LPCSTR GetCommandLineToArg(int index)
{
	static int     nArgs = 0;
	static LPWSTR *szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	static char    szBuf[4096] = {};

	if (!szBuf[0])
	{
		memset(szBuf, 0, sizeof(szBuf));
		if (index > nArgs)
		{
			sprintf_s(szBuf, "%S", szArglist[index]);
		}
	}
	return szBuf;
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

auto WriteStackBackTrace = [=](LPCSTR pCallingFunction, DWORD size = 1024)
{
	auto FileGetImageBase = [](LPSTR filename)
	{
		auto result = 0ull;
		auto hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			auto hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
			if (hFileMapping != 0)
			{
				auto lpFileBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
				if (lpFileBase != 0)
				{
					auto dosHeader = (PIMAGE_DOS_HEADER)lpFileBase;
					if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE)
					{
						auto pNTHeader = (PIMAGE_NT_HEADERS)((UINT64)dosHeader + (UINT64)dosHeader->e_lfanew);
						result = pNTHeader->OptionalHeader.ImageBase;
					}
					UnmapViewOfFile(lpFileBase);
				}
				CloseHandle(hFileMapping);
			}
			CloseHandle(hFile);
		}
		return result;
	};

	printf("TRACE(%s)\n", pCallingFunction);
	printf("{\n");

	auto *traces = new LPVOID[size];
	for (int traceIndex = 0; traceIndex < CaptureStackBackTrace(0, size, traces, NULL); traceIndex++)
	{
		auto hProcess = GetCurrentProcess();
		HMODULE hModules[1024]; DWORD cbNeeded;
		if (EnumProcessModules(hProcess, hModules, sizeof(hModules), &cbNeeded))
		{
			for (unsigned int moduleIndex = 0; moduleIndex < (cbNeeded / sizeof(HMODULE)); moduleIndex++)
			{
				MODULEINFO moduleInformation;
				if (GetModuleInformation(hProcess, hModules[moduleIndex], &moduleInformation, sizeof(moduleInformation)))
				{
					auto TopOfDll = (UINT64)moduleInformation.lpBaseOfDll + (UINT64)moduleInformation.SizeOfImage;
					if (traces[traceIndex] >= moduleInformation.lpBaseOfDll && (UINT64)traces[traceIndex] < TopOfDll)
					{
						UINT64 moduleOffset = 0;
						if (moduleOffset = (UINT64)traces[traceIndex] - (UINT64)moduleInformation.lpBaseOfDll)
						{
							char szModName[MAX_PATH];
							if (GetModuleFileNameExA(hProcess, hModules[moduleIndex], szModName, sizeof(szModName) / sizeof(char)))
							{
								auto moduleName = std::string(szModName).substr(std::string(szModName).find_last_of("/\\") + 1);
								auto baseOffset = FileGetImageBase(szModName) + moduleOffset;
								printf("\t% 16s+0x%08llX, 0x%016llX\n", moduleName.c_str(), moduleOffset, baseOffset);
							}
						}
					}
				}
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
