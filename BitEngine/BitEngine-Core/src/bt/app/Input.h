#pragma once

#include "bt\common.h"
#include "bt\maths\maths.h"
#include "bt\events\Event.h"

namespace bt {
#define MAX_KEYS	1024
#define MAX_BUTTONS 32

	typedef std::function<void(events::Event& event)> WindowEventCallback;

	class Window;

	class BT_API InputManager {
	private:
		friend BT_API Window;
	private:
		bool m_KeyState[MAX_KEYS];
		bool m_LastKeyState[MAX_KEYS];

		bool m_MouseButtons[MAX_KEYS];
		bool m_MouseState[MAX_KEYS];
		bool m_MouseClicked[MAX_KEYS];
		bool m_MouseGrabbed;
		int32 m_KeyModifiers;

		maths::vec2 m_MousePosition;
		WindowEventCallback m_EventCallback;
	public:
		InputManager();

		inline void SetEventCallback(const WindowEventCallback& eventCallback) { m_EventCallback = eventCallback; }

		void Update();
		void PlatformUpdate();

		bool IsKeyPressed(uint keycode) const;
		bool IsMouseButtonPressed(uint button) const;
		bool IsMouseButtonClicked(uint button) const;

		const maths::vec2& GetMousePosition() const;
		void SetMousePosition(const maths::vec2& position);
		const bool IsMouseGrabbed() const;
		void SetMouseGrabbed(bool grabbed);
		void SetMouseCursor(int32 cursor);

		void ClearKeys();
		void ClearMouseButtons();
	private:
		friend void KeyCallback(InputManager* inputManager, int32 flags, int32 key, uint message);
		friend void MouseButtonCallback(InputManager* inputManager, int32 button, int32 x, int32 y);

	};

	class BT_API Input {
	private:
		friend class InputManager;
	private:
		static InputManager* s_InputManager;
	public:
		inline static bool IsKeyPressed(uint keycode) { return s_InputManager->IsKeyPressed(keycode); }
		inline static bool IsMouseButtonPressed(uint button) { return s_InputManager->IsMouseButtonPressed(button); }
		inline static bool IsMouseButtonClicked(uint button) { return s_InputManager->IsMouseButtonClicked(button); }

		inline static const maths::vec2& GetMousePosition() { return s_InputManager->GetMousePosition(); }

		inline static InputManager* GetInputManager() { return s_InputManager; }
	};
}

#define BT_MOUSE_LEFT	  0x00
#define BT_MOUSE_MIDDLE	  0x01
#define BT_MOUSE_RIGHT    0x02

#define BT_NO_CURSOR	  NULL

#define BT_MODIFIER_LEFT_CONTROL	BIT(0)
#define BT_MODIFIER_LEFT_ALT		BIT(1)
#define BT_MODIFIER_LEFT_SHIFT		BIT(2)
#define BT_MODIFIER_RIGHT_CONTROL	BIT(3)
#define BT_MODIFIER_RIGHT_ALT		BIT(4)
#define BT_MODIFIER_RIGHT_SHIFT		BIT(5)

#define BT_KEY_TAB			  0x09

#define BT_KEY_0			  0x30
#define BT_KEY_1			  0x31
#define BT_KEY_2			  0x32
#define BT_KEY_3			  0x33
#define BT_KEY_4			  0x34
#define BT_KEY_5			  0x35
#define BT_KEY_6			  0x36
#define BT_KEY_7			  0x37
#define BT_KEY_8			  0x38
#define BT_KEY_9			  0x39

#define BT_KEY_A			  0x41
#define BT_KEY_B			  0x42
#define BT_KEY_C			  0x43
#define BT_KEY_D			  0x44
#define BT_KEY_E			  0x45
#define BT_KEY_F			  0x46
#define BT_KEY_G			  0x47
#define BT_KEY_H			  0x48
#define BT_KEY_I			  0x49
#define BT_KEY_J			  0x4A
#define BT_KEY_K			  0x4B
#define BT_KEY_L			  0x4C
#define BT_KEY_M			  0x4D
#define BT_KEY_N			  0x4E
#define BT_KEY_O			  0x4F
#define BT_KEY_P			  0x50
#define BT_KEY_Q			  0x51
#define BT_KEY_R			  0x52
#define BT_KEY_S			  0x53
#define BT_KEY_T			  0x54
#define BT_KEY_U			  0x55
#define BT_KEY_V			  0x56
#define BT_KEY_W			  0x57
#define BT_KEY_X			  0x58
#define BT_KEY_Y			  0x59
#define BT_KEY_Z			  0x5A

#define BT_KEY_LBUTTON        0x01
#define BT_KEY_RBUTTON        0x02
#define BT_KEY_CANCEL         0x03
#define BT_KEY_MBUTTON        0x04

#define BT_KEY_ESCAPE         0x1B
#define BT_KEY_SHIFT          0x10
#define BT_KEY_CONTROL        0x11
#define BT_KEY_MENU           0x12
#define BT_KEY_ALT	          BT_KEY_MENU
#define BT_KEY_PAUSE          0x13
#define BT_KEY_CAPITAL        0x14

#define BT_KEY_BTACE          0x20
#define BT_KEY_PRIOR          0x21
#define BT_KEY_NEXT           0x22
#define BT_KEY_END            0x23
#define BT_KEY_HOME           0x24
#define BT_KEY_LEFT           0x25
#define BT_KEY_UP             0x26
#define BT_KEY_RIGHT          0x27
#define BT_KEY_DOWN           0x28
#define BT_KEY_SELECT         0x29
#define BT_KEY_PRINT          0x2A
#define BT_KEY_EXECUTE        0x2B
#define BT_KEY_SNAPSHOT       0x2C
#define BT_KEY_INSERT         0x2D
#define BT_KEY_DELETE         0x2E
#define BT_KEY_HELP           0x2F

#define BT_KEY_NUMPAD0        0x60
#define BT_KEY_NUMPAD1        0x61
#define BT_KEY_NUMPAD2        0x62
#define BT_KEY_NUMPAD3        0x63
#define BT_KEY_NUMPAD4        0x64
#define BT_KEY_NUMPAD5        0x65
#define BT_KEY_NUMPAD6        0x66
#define BT_KEY_NUMPAD7        0x67
#define BT_KEY_NUMPAD8        0x68
#define BT_KEY_NUMPAD9        0x69
#define BT_KEY_MULTIPLY       0x6A
#define BT_KEY_ADD            0x6B
#define BT_KEY_SEPARATOR      0x6C
#define BT_KEY_SUBTRACT       0x6D
#define BT_KEY_DECIMAL        0x6E
#define BT_KEY_DIVIDE         0x6F
#define BT_KEY_F1             0x70
#define BT_KEY_F2             0x71
#define BT_KEY_F3             0x72
#define BT_KEY_F4             0x73
#define BT_KEY_F5             0x74
#define BT_KEY_F6             0x75
#define BT_KEY_F7             0x76
#define BT_KEY_F8             0x77
#define BT_KEY_F9             0x78
#define BT_KEY_F10            0x79
#define BT_KEY_F11            0x7A
#define BT_KEY_F12            0x7B
#define BT_KEY_F13            0x7C
#define BT_KEY_F14            0x7D
#define BT_KEY_F15            0x7E
#define BT_KEY_F16            0x7F
#define BT_KEY_F17            0x80
#define BT_KEY_F18            0x81
#define BT_KEY_F19            0x82
#define BT_KEY_F20            0x83
#define BT_KEY_F21            0x84
#define BT_KEY_F22            0x85
#define BT_KEY_F23            0x86
#define BT_KEY_F24            0x87

#define BT_KEY_NUMLOCK        0x90
#define BT_KEY_SCROLL         0x91

#define BT_KEY_LSHIFT         0xA0
#define BT_KEY_RSHIFT         0xA1
#define BT_KEY_LCONTROL       0xA2
#define BT_KEY_RCONTROL       0xA3
#define BT_KEY_LMENU          0xA4
#define BT_KEY_RMENU          0xA5