#pragma once

#include <windows.h>
#include <atomic>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <psapi.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

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

std::vector<std::string> SplitString(std::string phrase, LPCSTR delimiter)
{
	std::vector<std::string> list;
	std::string s = phrase;
	size_t pos = 0;
	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		list.push_back(s.substr(0, pos));
		s.erase(0, pos + strlen(delimiter));
	}
	list.push_back(s.c_str());
	return list;
}

bool g_running = false;

#include "ICommand.h"

#include "IModuleInterface.h"

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

#include "ITagInterface.h"

#include "IConsoleAccess.h"

void print_internal_enum(size_t offset, LPCSTR pName, std::vector<LPCSTR> pNames)
{
	static int _previous = -1;
	int &_current = IModuleInterface::Read<int>(IGameInterface::s_modulePath, offset);
	if (_current != _previous)
	{
		_previous = _current;

		if (_current >= 0 && _current < pNames.size() - 1)
		{
			printf("%s(%s)\n", pName, pNames[_current]);
		}
	}
};

void print_insecure_ip_at(size_t offset)
{
	UINT8(&addr)[4] = IModuleInterface::Read<UINT8[4]>(IGameInterface::s_modulePath, offset);
	printf("%hd.%hd.%hd.%hd\n", addr[3], addr[2], addr[1], addr[0]);
};

void print_secure_ip_at(size_t offset)
{
	UINT8 (&addr)[8] = IModuleInterface::Read<UINT8[8]>(IGameInterface::s_modulePath, offset);
	printf("%02X%02X:%02X%02X:%02X%02X:%02X%02X\n", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], addr[6], addr[7]);
};