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

#include "MouseInput.h"
#include "IGameRenderer.h"

extern IGameRenderer GameRenderer;

#include "IGameEvents.h"
#include "IGameEngineHost.h"

#include "c_file.h"
#include "c_engine.h"