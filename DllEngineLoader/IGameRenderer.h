#pragma once

class IGameRenderer
{
private:
	static HICON s_hIcon;
	static HWND s_hWnd;
	static HWND s_hFocusWnd;
	static HWND s_hForegroundWnd;
	static HINSTANCE s_hInstance;
	static HANDLE s_hPostMessageThread;
	static DWORD s_hPostMessageThreadId;

	static ID3D11Device *s_pDevice;
	static ID3D11DeviceContext *s_pDeviceContext;
	static IDXGISwapChain *s_pSwapChain;

	static int s_Width;
	static int s_Height;
	static bool s_Windowed;

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void CreateEngineWindow();
	static void CreateRenderContext();
public:
	IGameRenderer(int width, int height, bool windowed);
	~IGameRenderer();

	static HWND GetWindowHandle();
	static bool IsWindowFocused();

	static HICON GetIcon();

	static void SetIcon(HICON hIcon);

	static ID3D11Device *GetDevice();
	static ID3D11DeviceContext *GetDeviceContext();
	static IDXGISwapChain *GetSwapChain();

	static void Deinit();
	static void Update();
};

HICON IGameRenderer::s_hIcon = NULL;
HWND IGameRenderer::s_hWnd = NULL;
HWND IGameRenderer::s_hFocusWnd = NULL;
HWND IGameRenderer::s_hForegroundWnd = NULL;
HINSTANCE IGameRenderer::s_hInstance = NULL;
HANDLE IGameRenderer::s_hPostMessageThread = NULL;
DWORD IGameRenderer::s_hPostMessageThreadId = NULL;

ID3D11Device *IGameRenderer::s_pDevice = nullptr;
ID3D11DeviceContext *IGameRenderer::s_pDeviceContext = nullptr;
IDXGISwapChain *IGameRenderer::s_pSwapChain = nullptr;

int IGameRenderer::s_Width = 1280;
int IGameRenderer::s_Height = 720;
bool IGameRenderer::s_Windowed = true;


inline IGameRenderer::IGameRenderer(int width, int height, bool windowed)
{
	s_Width = width;
	s_Height = height;
	s_Windowed = windowed;

	CreateEngineWindow();
	CreateRenderContext();
}

inline IGameRenderer::~IGameRenderer()
{
}

inline HWND IGameRenderer::GetWindowHandle()
{
	return s_hWnd;
}

bool IGameRenderer::IsWindowFocused()
{
	return s_hWnd == s_hFocusWnd;
}

HICON IGameRenderer::GetIcon()
{
	return s_hIcon;
}

void IGameRenderer::SetIcon(HICON hIcon)
{
	s_hIcon = hIcon;
}

inline ID3D11Device *IGameRenderer::GetDevice()
{
	return s_pDevice;
}

inline ID3D11DeviceContext *IGameRenderer::GetDeviceContext()
{
	return s_pDeviceContext;
}

inline IDXGISwapChain *IGameRenderer::GetSwapChain()
{
	return s_pSwapChain;
}

LRESULT CALLBACK IGameRenderer::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
		s_hFocusWnd = GetFocus();
		s_hForegroundWnd = GetForegroundWindow();
		break;
	case WM_INPUT:
		MouseInput::InputWindowMessage(lParam);
		break;
	case WM_SETCURSOR:
		if (MouseInput::SetCursorWindowMessage(lParam))
		{
			return TRUE;
		}
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void IGameRenderer::CreateEngineWindow()
{
	SetProcessDPIAware();

	s_hInstance = GetModuleHandle(NULL);

	// Register the window class.

	WNDCLASSEX windowClass = { };
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = s_hInstance;
	windowClass.hIcon = NULL;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = L"dll_engine_loader_window_class";
	windowClass.hCursor = NULL;
	ATOM registerClassExResult = RegisterClassEx(&windowClass);
	if (registerClassExResult == NULL)
	{
		int err = GetLastError();
		printf("Failed to create window [%i]\n", err);
	}

	// Create the window.
	s_hWnd = CreateWindowEx(0, L"dll_engine_loader_window_class", L"DllEngineLoader", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, s_Width, s_Height, NULL, NULL, s_hInstance, NULL);

	if (s_hWnd == NULL)
	{
		int err = GetLastError();
		printf("Failed to create window [%i]\n", err);
	}

	ShowWindow(s_hWnd, SW_SHOW);
	SetFocus(s_hWnd);

	static RAWINPUTDEVICE mouseInputDevice = {};
	mouseInputDevice.usUsagePage = HID_USAGE_PAGE_GENERIC;
	mouseInputDevice.usUsage = HID_USAGE_GENERIC_MOUSE;
	mouseInputDevice.dwFlags = RIDEV_INPUTSINK;
	mouseInputDevice.hwndTarget = s_hWnd;
	static RAWINPUTDEVICE rawInputDevices[] = { mouseInputDevice };
	RegisterRawInputDevices(rawInputDevices, _countof(rawInputDevices), sizeof(rawInputDevices));
}

void IGameRenderer::Deinit()
{
	CloseWindow(s_hWnd);
	UnregisterClassA("dll_engine_loader_window_class", s_hInstance);
}

void IGameRenderer::Update()
{
	MSG msg = {};

	while (PeekMessage(&msg, s_hWnd, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


void IGameRenderer::CreateRenderContext()
{
	assert(s_pDevice == nullptr);
	assert(s_pDeviceContext == nullptr);
	assert(s_pSwapChain == nullptr);

	static DXGI_SWAP_CHAIN_DESC s_SwapchainDescription = {};
	static IDXGIFactory1 *s_pFactory = nullptr;
	static DEVMODE s_deviceMode = {};

	EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &s_deviceMode);

	D3D_FEATURE_LEVEL pFeatureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_0,
	};

	D3D_FEATURE_LEVEL FeatureLevel = {};

	bool createSwapchain = true;

	HRESULT CreateDXGIFactory1Result = CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void **)&s_pFactory);
	assert(CreateDXGIFactory1Result == S_OK);
	assert(s_pFactory != nullptr);

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	HRESULT D3D11CreateDeviceResult = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, pFeatureLevels, _countof(pFeatureLevels), D3D11_SDK_VERSION, &s_pDevice, &FeatureLevel, &s_pDeviceContext);
	assert(D3D11CreateDeviceResult == S_OK);
	assert(s_pDevice != nullptr);
	assert(s_pDeviceContext != nullptr);

	if (createSwapchain)
	{
		s_SwapchainDescription = {};

		s_SwapchainDescription.BufferDesc.Width = s_Width;
		s_SwapchainDescription.BufferDesc.Height = s_Height;
		s_SwapchainDescription.BufferDesc.RefreshRate.Numerator = 0;
		s_SwapchainDescription.BufferDesc.RefreshRate.Denominator = 0;
		s_SwapchainDescription.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		s_SwapchainDescription.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		s_SwapchainDescription.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		s_SwapchainDescription.SampleDesc.Count = 1;
		s_SwapchainDescription.SampleDesc.Quality = 0;
		s_SwapchainDescription.BufferUsage = DXGI_USAGE_SHADER_INPUT | DXGI_USAGE_RENDER_TARGET_OUTPUT;
		s_SwapchainDescription.BufferCount = 1;
		s_SwapchainDescription.OutputWindow = s_hWnd;
		s_SwapchainDescription.Windowed = s_Windowed;
		s_SwapchainDescription.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		s_SwapchainDescription.Flags = 0;

		s_pFactory->CreateSwapChain(s_pDevice, &s_SwapchainDescription, &s_pSwapChain);
		assert(s_pSwapChain != nullptr);
	}
}