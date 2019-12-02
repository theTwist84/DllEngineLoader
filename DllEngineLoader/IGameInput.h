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

class IGameInput
{
public:
	static void                  SetSensitivity(float horizontalSensitivity, float verticalSensitivity);

	static float                 GetMouseX();
	static float                 GetMouseY();
	static bool                  GetMouseButton(MouseInputButton button);
	static void                  SetMode(MouseMode mode, HWND hWnd);

	static void                  InputWindowMessage(LPARAM lParam);
	static bool                  SetCursorWindowMessage(LPARAM lParam);
private:
	static void                  SetClipMode(MouseMode mode, HWND hWnd);

	static MouseMode             s_currentMode;
	static float                 s_horizontalSensitivity;
	static float                 s_verticalSensitivity;
	static std::atomic<uint32_t> s_xPositionAccumulator;
	static std::atomic<uint32_t> s_yPositionAccumulator;
	static std::atomic<int32_t>  s_wheelAccumulator;
	static bool                  s_leftButtonPressed;
	static bool                  s_rightButtonPressed;
	static bool                  s_middleButtonPressed;
	static bool                  s_button4Pressed;
	static bool                  s_button5Pressed;
};



float                 IGameInput::s_horizontalSensitivity = 1.0f;
float                 IGameInput::s_verticalSensitivity   = 1.0f;
MouseMode             IGameInput::s_currentMode           = MouseMode::None;
std::atomic<uint32_t> IGameInput::s_xPositionAccumulator  = 0;
std::atomic<uint32_t> IGameInput::s_yPositionAccumulator  = 0;
std::atomic<int32_t>  IGameInput::s_wheelAccumulator      = 0;
bool                  IGameInput::s_leftButtonPressed     = false;
bool                  IGameInput::s_rightButtonPressed    = false;
bool                  IGameInput::s_middleButtonPressed   = false;
bool                  IGameInput::s_button4Pressed        = false;
bool                  IGameInput::s_button5Pressed        = false;

void IGameInput::InputWindowMessage(LPARAM lParam)
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
				int xPosRelative        = rRawMouse.lLastX;
				int yPosRelative        = rRawMouse.lLastY;
				s_xPositionAccumulator += xPosRelative;
				s_yPositionAccumulator += yPosRelative;
			}

			if (rRawMouse.usButtonFlags & RI_MOUSE_WHEEL)
			{
				s_wheelAccumulator += static_cast<int32_t>(static_cast<SHORT>(rRawMouse.usButtonData));
			}

			s_leftButtonPressed   = rRawMouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_DOWN   ? true : false;
			s_rightButtonPressed  = rRawMouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_DOWN  ? true : false;
			s_middleButtonPressed = rRawMouse.usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_DOWN ? true : false;
			s_button4Pressed      = rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_4_DOWN      ? true : false;
			s_button5Pressed      = rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_5_DOWN      ? true : false;
		}
	}
	break;
	}
}

bool IGameInput::SetCursorWindowMessage(LPARAM lParam)
{
	if (LOWORD(lParam) == HTCLIENT)
	{
		static HCURSOR hHandCursor = LoadCursorW(NULL, IDC_ARROW);
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

void IGameInput::SetClipMode(MouseMode mode, HWND hWnd)
{
	if (mode == MouseMode::Exclusive)
	{
		RECT rect = {};
		GetClientRect(hWnd, &rect);

		POINT ul = { rect.left, rect.top };
		POINT lr = { rect.right, rect.bottom };

		MapWindowPoints(hWnd, nullptr, &ul, 1);
		MapWindowPoints(hWnd, nullptr, &lr, 1);

		rect.left   = ul.x;
		rect.top    = ul.y;
		rect.right  = lr.x;
		rect.bottom = lr.y;

		ClipCursor(&rect);
	}
	else
	{
		ClipCursor(NULL);
	}
}

void IGameInput::SetMode(MouseMode mode, HWND hWnd)
{
	if (s_currentMode != mode)
	{
		s_currentMode = mode;
		SetClipMode(mode, hWnd);
	}
}

void IGameInput::SetSensitivity(float horizontalSensitivity, float verticalSensitivity)
{
	s_horizontalSensitivity = __max(horizontalSensitivity, 0.0f);
	s_verticalSensitivity   = __max(verticalSensitivity,   0.0f);

	if (s_horizontalSensitivity > 1.0f) s_horizontalSensitivity = 1.0f;
	if (s_verticalSensitivity > 1.0f)   s_verticalSensitivity   = 1.0f;
	if (s_horizontalSensitivity < 0.0f) s_horizontalSensitivity = 0.0f;
	if (s_verticalSensitivity < 0.0f)   s_verticalSensitivity   = 0.0f;
}

float IGameInput::GetMouseX()
{
	int xRelativeTicks = s_xPositionAccumulator.exchange(0);
	return float(xRelativeTicks) * 0.005f * s_horizontalSensitivity;
}

float IGameInput::GetMouseY()
{
	int yRelativeTicks = s_yPositionAccumulator.exchange(0);
	return float(yRelativeTicks) * 0.005f * s_horizontalSensitivity;
}

bool IGameInput::GetMouseButton(MouseInputButton button)
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
