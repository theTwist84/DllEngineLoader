#pragma once

enum class MouseInputButton
{
	Left,
	Right,
	Middle,
};

enum class MouseMode
{
	None,
	UI,
	Exclusive
};

class MouseInput
{
public:
	static void SetSensitivity(float horizontalSensitivity, float verticalSensitivity);

	static float GetMouseX();
	static float GetMouseY();
	static bool GetMouseButton(MouseInputButton button);
	static void SetMode(MouseMode mode, HWND hWnd);
	static void Init();

	static void InputWindowMessage(LPARAM lParam);
	static bool SetCursorWindowMessage(LPARAM lParam);
private:
	static void setClipMode(MouseMode mode, HWND hWnd);

	static MouseMode s_currentMode;
	static float s_horizontalSensitivity;
	static float s_verticalSensitivity;
	static std::atomic<uint32_t> s_xPositionAccumulator;
	static std::atomic<uint32_t> s_yPositionAccumulator;
	static std::atomic<int32_t> s_wheelAccumulator;
	static bool s_leftButtonPressed;
	static bool s_rightButtonPressed;
	static bool s_middleButtonPressed;
	static bool s_button4Pressed;
	static bool s_button5Pressed;
};



float MouseInput::s_horizontalSensitivity = 1.0f;
float MouseInput::s_verticalSensitivity = 1.0f;
MouseMode MouseInput::s_currentMode;
std::atomic<uint32_t> MouseInput::s_xPositionAccumulator = 0;
std::atomic<uint32_t> MouseInput::s_yPositionAccumulator = 0;
std::atomic<int32_t> MouseInput::s_wheelAccumulator = 0;
bool MouseInput::s_leftButtonPressed = false;
bool MouseInput::s_rightButtonPressed = false;
bool MouseInput::s_middleButtonPressed = false;
bool MouseInput::s_button4Pressed = false;
bool MouseInput::s_button5Pressed = false;

void MouseInput::InputWindowMessage(LPARAM lParam)
{
	RAWINPUT rawInput = {};
	UINT dwSize = sizeof(rawInput);
	GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, &rawInput, &dwSize, sizeof(RAWINPUTHEADER));

	switch (rawInput.header.dwType)
	{
	case RIM_TYPEMOUSE:
	{
		RAWMOUSE &rRawMouse = rawInput.data.mouse;
		if (s_currentMode == MouseMode::Exclusive)
		{
			if (rRawMouse.usFlags == MOUSE_MOVE_RELATIVE)
			{
				int xPosRelative = rRawMouse.lLastX;
				int yPosRelative = rRawMouse.lLastY;
				s_xPositionAccumulator += xPosRelative;
				s_yPositionAccumulator += yPosRelative;
			}

			if (rRawMouse.usButtonFlags & RI_MOUSE_WHEEL)
			{
				SHORT wheelDelta = static_cast<SHORT>(rRawMouse.usButtonData);
				s_wheelAccumulator += static_cast<int32_t>(wheelDelta);
			}

			if (rRawMouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_DOWN)
			{
				s_leftButtonPressed = true;
			}
			if (rRawMouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_UP)
			{
				s_leftButtonPressed = false;
			}
			if (rRawMouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_DOWN)
			{
				s_rightButtonPressed = true;
			}
			if (rRawMouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_UP)
			{
				s_rightButtonPressed = false;
			}
			if (rRawMouse.usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_DOWN)
			{
				s_middleButtonPressed = true;
			}
			if (rRawMouse.usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_UP)
			{
				s_middleButtonPressed = false;
			}
			if (rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_4_DOWN)
			{
				s_button4Pressed = true;
			}
			if (rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_4_UP)
			{
				s_button4Pressed = false;
			}
			if (rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_5_DOWN)
			{
				s_button5Pressed = true;
			}
			if (rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_5_UP)
			{
				s_button5Pressed = false;
			}
		}
	}
	break;
	}
}

bool MouseInput::SetCursorWindowMessage(LPARAM lParam)
{
	if (LOWORD(lParam) == HTCLIENT)
	{
		static HCURSOR hHandCursor = LoadCursor(NULL, IDC_ARROW);
		switch (s_currentMode)
		{
		case MouseMode::Exclusive:
			SetCursor(NULL);
			break;
		default:
			SetCursor(hHandCursor);
			break;
		}
		return true;
	}
	return false;
}

void MouseInput::setClipMode(MouseMode mode, HWND hWnd)
{
	if (mode == MouseMode::Exclusive)
	{
		RECT rect = {};
		GetClientRect(hWnd, &rect);
		POINT ul;
		ul.x = rect.left;
		ul.y = rect.top;
		POINT lr;
		lr.x = rect.right;
		lr.y = rect.bottom;
		MapWindowPoints(hWnd, nullptr, &ul, 1);
		MapWindowPoints(hWnd, nullptr, &lr, 1);
		rect.left = ul.x;
		rect.top = ul.y;
		rect.right = lr.x;
		rect.bottom = lr.y;
		ClipCursor(&rect);
	}
	else
	{
		ClipCursor(NULL);
	}
}

void MouseInput::SetMode(MouseMode mode, HWND hWnd)
{
	if (s_currentMode != mode)
	{
		s_currentMode = mode;
		setClipMode(mode, hWnd);
	}
}

void MouseInput::SetSensitivity(float horizontalSensitivity, float verticalSensitivity)
{
	s_horizontalSensitivity = __max(horizontalSensitivity, 0.0f);
	s_verticalSensitivity = __max(verticalSensitivity, 0.0f);

	if (s_horizontalSensitivity > 1.0f) s_horizontalSensitivity = 1.0f;
	if (s_verticalSensitivity > 1.0f) s_verticalSensitivity = 1.0f;
	if (s_horizontalSensitivity < 0.0f) s_horizontalSensitivity = 0.0f;
	if (s_verticalSensitivity < 0.0f) s_verticalSensitivity = 0.0f;
}

float MouseInput::GetMouseX()
{
	int xRelativeTicks = s_xPositionAccumulator.exchange(0);
	return float(xRelativeTicks) * 0.005f * s_horizontalSensitivity;
}

float MouseInput::GetMouseY()
{
	int yRelativeTicks = s_yPositionAccumulator.exchange(0);
	return float(yRelativeTicks) * 0.005f * s_horizontalSensitivity;
}

bool MouseInput::GetMouseButton(MouseInputButton button)
{
	switch (button)
	{
	case MouseInputButton::Left:
		return s_leftButtonPressed;
	case MouseInputButton::Right:
		return s_rightButtonPressed;
	case MouseInputButton::Middle:
		return s_middleButtonPressed;
	}
	return false;
}
