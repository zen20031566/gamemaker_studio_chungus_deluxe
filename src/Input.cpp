#include "Input.h"
#include "AppWindow.h"                  
#include "Application.h"
#include <glfw/glfw3.h>

namespace GameMakerStudioChungusDeluxe
{
	static GLFWwindow* window_Impl;

	// define the unordered_maps 
	std::unordered_map<KeyCode, bool> Input::key_states_current;
	std::unordered_map<KeyCode, bool> Input::key_states_previous;
	std::unordered_map<MouseButtonCode, bool> Input::mouse_states_current;
	std::unordered_map<MouseButtonCode, bool> Input::mouse_states_previous;

	Vector2 Input::mouse_pos_current;
	Vector2 Input::mouse_pos_previous;

	void Input::init(void* procAddress)
	{
		AppWindow* appWindow = static_cast<AppWindow*>(procAddress);
		void* nativeWindow = appWindow->getNativeWindow();
		window_Impl = static_cast<GLFWwindow*>(nativeWindow);

		// set sticky 
		glfwSetInputMode(window_Impl, GLFW_STICKY_KEYS, GLFW_TRUE);
		glfwSetInputMode(window_Impl, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);

		// init defaults 
		// key states 
		key_states_current = {
			// Printable keys
			{ KeyCode::SPACE, false },
			{ KeyCode::APOSTROPHE, false },
			{ KeyCode::COMMA, false },
			{ KeyCode::MINUS, false },
			{ KeyCode::PERIOD, false },
			{ KeyCode::SLASH, false },

			// Number row
			{ KeyCode::ALPHA0, false },
			{ KeyCode::ALPHA1, false },
			{ KeyCode::ALPHA2, false },
			{ KeyCode::ALPHA3, false },
			{ KeyCode::ALPHA4, false },
			{ KeyCode::ALPHA5, false },
			{ KeyCode::ALPHA6, false },
			{ KeyCode::ALPHA7, false },
			{ KeyCode::ALPHA8, false },
			{ KeyCode::ALPHA9, false },

			{ KeyCode::SEMICOLON, false },
			{ KeyCode::EQUAL, false },

			// Letters
			{ KeyCode::A, false },
			{ KeyCode::B, false },
			{ KeyCode::C, false },
			{ KeyCode::D, false },
			{ KeyCode::E, false },
			{ KeyCode::F, false },
			{ KeyCode::G, false },
			{ KeyCode::H, false },
			{ KeyCode::I, false },
			{ KeyCode::J, false },
			{ KeyCode::K, false },
			{ KeyCode::L, false },
			{ KeyCode::M, false },
			{ KeyCode::N, false },
			{ KeyCode::O, false },
			{ KeyCode::P, false },
			{ KeyCode::Q, false },
			{ KeyCode::R, false },
			{ KeyCode::S, false },
			{ KeyCode::T, false },
			{ KeyCode::U, false },
			{ KeyCode::V, false },
			{ KeyCode::W, false },
			{ KeyCode::X, false },
			{ KeyCode::Y, false },
			{ KeyCode::Z, false },

			{ KeyCode::LEFTBRACKET, false },
			{ KeyCode::BACKSLASH, false },
			{ KeyCode::RIGHTBRACKET, false },
			{ KeyCode::GRAVEACCENT, false },

			{ KeyCode::WORLD1, false },
			{ KeyCode::WORLD2, false },

			// Function / navigation keys
			{ KeyCode::ESCAPE, false },
			{ KeyCode::ENTER, false },
			{ KeyCode::TAB, false },
			{ KeyCode::BACKSPACE, false },
			{ KeyCode::INSERT, false },
			{ KeyCode::DELETE, false },

			{ KeyCode::RIGHT, false },
			{ KeyCode::LEFT, false },
			{ KeyCode::DOWN, false },
			{ KeyCode::UP, false },

			{ KeyCode::PAGEUP, false },
			{ KeyCode::PAGEDOWN, false },
			{ KeyCode::HOME, false },
			{ KeyCode::END, false },

			{ KeyCode::CAPSLOCK, false },
			{ KeyCode::SCROLLLOCK, false },
			{ KeyCode::NUMLOCK, false },
			{ KeyCode::PRINTSCREEN, false },
			{ KeyCode::PAUSE, false },

			// Function keys
			{ KeyCode::F1, false },
			{ KeyCode::F2, false },
			{ KeyCode::F3, false },
			{ KeyCode::F4, false },
			{ KeyCode::F5, false },
			{ KeyCode::F6, false },
			{ KeyCode::F7, false },
			{ KeyCode::F8, false },
			{ KeyCode::F9, false },
			{ KeyCode::F10, false },
			{ KeyCode::F11, false },
			{ KeyCode::F12, false },
			{ KeyCode::F13, false },
			{ KeyCode::F14, false },
			{ KeyCode::F15, false },
			{ KeyCode::F16, false },
			{ KeyCode::F17, false },
			{ KeyCode::F18, false },
			{ KeyCode::F19, false },
			{ KeyCode::F20, false },
			{ KeyCode::F21, false },
			{ KeyCode::F22, false },
			{ KeyCode::F23, false },
			{ KeyCode::F24, false },
			{ KeyCode::F25, false },

			// Keypad
			{ KeyCode::KEYPAD0, false },
			{ KeyCode::KEYPAD1, false },
			{ KeyCode::KEYPAD2, false },
			{ KeyCode::KEYPAD3, false },
			{ KeyCode::KEYPAD4, false },
			{ KeyCode::KEYPAD5, false },
			{ KeyCode::KEYPAD6, false },
			{ KeyCode::KEYPAD7, false },
			{ KeyCode::KEYPAD8, false },
			{ KeyCode::KEYPAD9, false },

			{ KeyCode::KEYPADDECIMAL, false },
			{ KeyCode::KEYPADDIVIDE, false },
			{ KeyCode::KEYPADMULTIPLY, false },
			{ KeyCode::KEYPADSUBTRACT, false },
			{ KeyCode::KEYPADADD, false },
			{ KeyCode::KEYPADENTER, false },
			{ KeyCode::KEYPADEQUAL, false },

			// Modifiers
			{ KeyCode::LEFTSHIFT, false },
			{ KeyCode::LEFTCONTROL, false },
			{ KeyCode::LEFTALT, false },
			{ KeyCode::LEFTSUPER, false },

			{ KeyCode::RIGHTSHIFT, false },
			{ KeyCode::RIGHTCONTROL, false },
			{ KeyCode::RIGHTALT, false },
			{ KeyCode::RIGHTSUPER, false },

			{ KeyCode::MENU, false },
		};

		// In C++, doing this makes a copy of the unordered_map.
		// This works in our favour, reducing boilerplate codes. 
		key_states_previous = key_states_current;

		// mouse states
		mouse_states_current = {
			{ MouseButtonCode::LEFT, false },
			{ MouseButtonCode::RIGHT, false },
			{ MouseButtonCode::MIDDLE, false },
			{ MouseButtonCode::BUTTON4, false },
			{ MouseButtonCode::BUTTON5, false },
			{ MouseButtonCode::BUTTON6, false },
			{ MouseButtonCode::BUTTON7, false },
			{ MouseButtonCode::BUTTON8, false },
		};

		mouse_states_previous = mouse_states_current;

		mouse_pos_current = getMousePosition();
		mouse_pos_previous = mouse_pos_current;
	}

	void Input::process()
	{
		for (auto& kvp : key_states_previous)
		{
			kvp.second = key_states_current[kvp.first];
		}

		for (auto& kvp : key_states_current)
		{
			kvp.second = glfwGetKey(window_Impl, (int)kvp.first);
		}

		for (auto& kvp : mouse_states_previous)
		{
			kvp.second = mouse_states_current[kvp.first];
		}

		for (auto& kvp : mouse_states_current)
		{
			kvp.second = glfwGetMouseButton(window_Impl, (int)kvp.first);
		}

		mouse_pos_previous = mouse_pos_current; //copy first
		mouse_pos_current = getMousePosition();
	}

	bool Input::getKey(const KeyCode keyCode)
	{
		auto it = key_states_current.find(keyCode);
		bool foundKey = it != key_states_current.end();

		if (foundKey)
		{
			return it->second;
		}

		return false;
	}

	bool Input::getKeyDown(const KeyCode keyCode)
	{
		auto it = key_states_current.find(keyCode);
		bool foundKey = it != key_states_current.end();

		if (foundKey)
		{
			bool currValue = it->second;
			bool oldValue = key_states_previous[it->first];

			return currValue && !oldValue;
		}

		return false;
	}

	bool Input::getKeyUp(const KeyCode keyCode)
	{
		auto it = key_states_current.find(keyCode);
		bool foundKey = it != key_states_current.end();

		if (foundKey)
		{
			bool currValue = it->second;
			bool oldValue = key_states_previous[it->first];

			return !currValue && oldValue;
		}

		return false;
	}

	bool Input::getMouseButton(const MouseButtonCode button)
	{
		auto it = mouse_states_current.find(button);
		bool foundButton = it != mouse_states_current.end();

		if (foundButton)
		{
			return it->second;
		}

		return false;
	}

	bool Input::getMouseButtonDown(const MouseButtonCode button)
	{
		auto it = mouse_states_current.find(button);
		bool foundButton = it != mouse_states_current.end();

		if (foundButton)
		{
			bool currValue = it->second;
			bool oldValue = mouse_states_previous[it->first];

			return currValue && !oldValue;
		}

		return false;
	}

	bool Input::getMouseButtonUp(const MouseButtonCode button)
	{
		auto it = mouse_states_current.find(button);
		bool foundButton = it != mouse_states_current.end();

		if (foundButton)
		{
			bool currValue = it->second;
			bool oldValue = mouse_states_previous[it->first];

			return !currValue && oldValue;
		}

		return false;
	}

	Vector2 Input::getMousePosition()
	{
		double x = 0.0;
		double y = 0.0;
		glfwGetCursorPos(window_Impl, &x, &y);
		return Vector2((float)x, (float)y);
	}

	Vector2 Input::getMouseDelta()
	{
		return mouse_pos_current - mouse_pos_previous;
	}
}