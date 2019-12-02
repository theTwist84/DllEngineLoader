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
#include <stdio.h>

#define DIRECTINPUT_VERSION 0x0800
#include <hidusage.h>
#include <dinput.h>
#include <Xinput.h>

#include <D3Dcompiler.h>
#include <dxgi.h>
#include <d3d11.h>
#include <d3d11_4.h>

// only used for file paths
LPCSTR pathf(LPCSTR fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	static char path[MAX_PATH];
	int result = vsnprintf_s(path, MAX_PATH, _TRUNCATE, fmt, args);
	va_end(args);

	return path;
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

LPCSTR GetCommandLineToArg(int index)
{
	static int     nArgs = 0;
	static LPWSTR *szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	static char    szBuf[1024] = {};

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
		assert(hModule);
	}
}

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
