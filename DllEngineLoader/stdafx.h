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
#include <D3Dcompiler.h>
#include <dxgi.h>
#include <d3d11.h>
#include <d3d11_4.h>
#include <Xinput.h>

const char *pathf(LPCSTR fmt, ...)
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
	static char szBuf[MAX_PATH] = { 0 };
	GetEnvironmentVariableA("USERPROFILE", szBuf, MAX_PATH);
	return szBuf;
};

bool g_running = false;

#include "MouseInput.h"
#include "IGameRenderer.h"

#include "c_file.h"
#include "c_engine.h"

#include "IGameContext.h"

#include "IGameEvents.h"
#include "IGameEngineHost.h"