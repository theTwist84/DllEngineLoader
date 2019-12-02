#pragma once

#define DIRECTINPUT_VERSION 0x0800
#include <hidusage.h>
#include <dinput.h>
#include <D3Dcompiler.h>
#include <dxgi.h>
#include <d3d11.h>
#include <d3d11_4.h>
#include <Xinput.h>

class IGameRasterizer
{
private:
	static int                  s_Width;
	static int                  s_Height;
	static bool                 s_Windowed;

	static HWND                 s_hWnd;
	static HWND                 s_hFocusWnd;
	static HWND                 s_hForegroundWnd;
	static HINSTANCE            s_hInstance;

	static ID3D11Device        *s_pDevice;
	static ID3D11DeviceContext *s_pContext;
	static IDXGISwapChain      *s_pSwapChain;

	static LRESULT CALLBACK     WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void                 InitializeWindow();
	static void                 InitializeDevice(bool createSwapchain);

public:
	IGameRasterizer();
	~IGameRasterizer();

	IGameRasterizer(int width, int height, bool windowed);

	static HWND                 GetWindowHandle();
	static bool                 IsWindowFocused();

	static ID3D11Device        *GetDevice();
	static ID3D11DeviceContext *GetContext();
	static IDXGISwapChain      *GetSwapChain();

	static void                 DisposeWindow();
	static void                 Update();
};

int                  IGameRasterizer::s_Width          = 1280;
int                  IGameRasterizer::s_Height         = 720;
bool                 IGameRasterizer::s_Windowed       = true;

HWND                 IGameRasterizer::s_hWnd           = 0;
HWND                 IGameRasterizer::s_hFocusWnd      = 0;
HWND                 IGameRasterizer::s_hForegroundWnd = 0;
HINSTANCE            IGameRasterizer::s_hInstance      = 0;

ID3D11Device        *IGameRasterizer::s_pDevice        = 0;
ID3D11DeviceContext *IGameRasterizer::s_pContext       = 0;
IDXGISwapChain      *IGameRasterizer::s_pSwapChain     = 0;

IGameRasterizer::IGameRasterizer(int width, int height, bool windowed)
{
	printf("IGameRasterizer(%i, %i, %s);\n", width, height, windowed ? "true" : "false");

	s_Width    = width;
	s_Height   = height;
	s_Windowed = windowed;

	InitializeDevice(true);
}

IGameRasterizer::~IGameRasterizer()
{
}

HWND IGameRasterizer::GetWindowHandle()
{
	return s_hWnd;
}

bool IGameRasterizer::IsWindowFocused()
{
	return s_hWnd == s_hFocusWnd;
}

ID3D11Device *IGameRasterizer::GetDevice()
{
	return s_pDevice;
}

ID3D11DeviceContext *IGameRasterizer::GetContext()
{
	return s_pContext;
}

IDXGISwapChain *IGameRasterizer::GetSwapChain()
{
	return s_pSwapChain;
}

LRESULT CALLBACK IGameRasterizer::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
		{
			return 0;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	case WM_SIZE:
		// #TODO: tell game to resize
		break;
	case WM_KILLFOCUS:
	case WM_SETFOCUS:
		s_hFocusWnd      = GetFocus();
		s_hForegroundWnd = GetForegroundWindow();
		break;
	case WM_INPUT:
		IGameInput::InputWindowMessage(lParam);
		break;
	case WM_SETCURSOR:
		if (IGameInput::SetCursorWindowMessage(lParam))
		{
			return TRUE;
		}
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void IGameRasterizer::InitializeWindow()
{
	printf("IGameRasterizer::InitializeWindow();\n");

	SetProcessDPIAware();

	s_hInstance = GetModuleHandleA(NULL);

	// Register the window class.

	WNDCLASSEX windowClass   = {};
	windowClass.cbSize        = sizeof(WNDCLASSEX);
	windowClass.style         = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc   = WndProc;
	windowClass.cbClsExtra    = 0;
	windowClass.cbWndExtra    = 0;
	windowClass.hInstance     = s_hInstance;
	windowClass.hIcon         = NULL;
	windowClass.hCursor       = LoadCursorW(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	windowClass.lpszMenuName  = NULL;
	windowClass.lpszClassName = L"#dll_engine_loader";
	windowClass.hCursor       = NULL;

	if (RegisterClassEx(&windowClass) == NULL)
	{
		int err = GetLastError();
		printf("Failed to create window [%i]\n", err);
	}

	s_hWnd = CreateWindowEx(
		0, 
		L"#dll_engine_loader", 
		L"DllEngineLoader", 
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		s_Width, 
		s_Height, 
		NULL, 
		NULL, 
		s_hInstance, 
		NULL
	);

	if (s_hWnd == NULL)
	{
		int err = GetLastError();
		printf("Failed to create window [%i]\n", err);
	}
	else
	{
		ShowWindow(s_hWnd, SW_SHOW);
		SetFocus(s_hWnd);
	}

	static RAWINPUTDEVICE mouseInputDevice = {};
	mouseInputDevice.usUsagePage = HID_USAGE_PAGE_GENERIC;
	mouseInputDevice.usUsage     = HID_USAGE_GENERIC_MOUSE;
	mouseInputDevice.dwFlags     = RIDEV_INPUTSINK;
	mouseInputDevice.hwndTarget  = s_hWnd;

	static RAWINPUTDEVICE rawInputDevices[] = { mouseInputDevice };
	RegisterRawInputDevices(rawInputDevices, _countof(rawInputDevices), sizeof(rawInputDevices));
}

void IGameRasterizer::DisposeWindow()
{
	CloseWindow(s_hWnd);
	UnregisterClass(L"#dll_engine_loader", s_hInstance);
}

void IGameRasterizer::Update()
{
	MSG msg = {};

	while (PeekMessageW(&msg, s_hWnd, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}


void IGameRasterizer::InitializeDevice(bool createSwapchain)
{
	printf("IGameRasterizer::InitializeDevice(%s);\n", createSwapchain ? "true" : "false");

	InitializeWindow();

	assert(s_pDevice    == nullptr);
	assert(s_pContext   == nullptr);
	assert(s_pSwapChain == nullptr);

	static DXGI_SWAP_CHAIN_DESC s_SwapchainDesc = {};
	static IDXGIFactory1       *s_pFactory      = 0;
	static DEVMODE              s_deviceMode    = {};

	D3D_FEATURE_LEVEL pFeatureLevels[] = { D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	D3D_FEATURE_LEVEL FeatureLevel = {};

	EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &s_deviceMode);
	
	assert(CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void **)&s_pFactory) == S_OK);
	assert(s_pFactory != nullptr);

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	assert(D3D11CreateDevice(
		NULL, 
		D3D_DRIVER_TYPE_HARDWARE, 
		NULL, 
		createDeviceFlags, 
		pFeatureLevels, 
		_countof(pFeatureLevels), 
		D3D11_SDK_VERSION, 
		&s_pDevice, 
		&FeatureLevel, 
		&s_pContext
	) == S_OK);
	
	assert(s_pDevice  != nullptr);
	assert(s_pContext != nullptr);

	if (createSwapchain)
	{
		s_SwapchainDesc.BufferDesc.Width                   = s_Width;
		s_SwapchainDesc.BufferDesc.Height                  = s_Height;
		s_SwapchainDesc.BufferDesc.RefreshRate.Numerator   = 0;
		s_SwapchainDesc.BufferDesc.RefreshRate.Denominator = 0;
		s_SwapchainDesc.BufferDesc.Format                  = DXGI_FORMAT_R8G8B8A8_UNORM;
		s_SwapchainDesc.BufferDesc.ScanlineOrdering        = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		s_SwapchainDesc.BufferDesc.Scaling                 = DXGI_MODE_SCALING_UNSPECIFIED;
		s_SwapchainDesc.SampleDesc.Count                   = 1;
		s_SwapchainDesc.SampleDesc.Quality                 = 0;
		s_SwapchainDesc.BufferUsage                        = DXGI_USAGE_SHADER_INPUT | DXGI_USAGE_RENDER_TARGET_OUTPUT;
		s_SwapchainDesc.BufferCount                        = 1;
		s_SwapchainDesc.OutputWindow                       = s_hWnd;
		s_SwapchainDesc.Windowed                           = s_Windowed;
		s_SwapchainDesc.SwapEffect                         = DXGI_SWAP_EFFECT_DISCARD;
		s_SwapchainDesc.Flags                              = 0;

		s_pFactory->CreateSwapChain(s_pDevice, &s_SwapchainDesc, &s_pSwapChain);

		assert(s_pSwapChain != nullptr);
	}
}