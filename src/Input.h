#pragma once
#include <unordered_map>
#include "GMSCDMath.h"

namespace GMSCD
{
	// declare key & button codes
	enum class KeyCode
	{
		// Printable keys
		SPACE = 32,
		APOSTROPHE = 39,
		COMMA = 44,
		MINUS = 45,
		PERIOD = 46,
		SLASH = 47,

		// Number row
		ALPHA0 = 48,
		ALPHA1 = 49,
		ALPHA2 = 50,
		ALPHA3 = 51,
		ALPHA4 = 52,
		ALPHA5 = 53,
		ALPHA6 = 54,
		ALPHA7 = 55,
		ALPHA8 = 56,
		ALPHA9 = 57,

		SEMICOLON = 59,
		EQUAL = 61,

		// Letters
		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LEFTBRACKET = 91,
		BACKSLASH = 92,
		RIGHTBRACKET = 93,
		GRAVEACCENT = 96,

		WORLD1 = 161,
		WORLD2 = 162,

		// Function / navigation keys
		ESCAPE = 256,
		ENTER = 257,
		TAB = 258,
		BACKSPACE = 259,
		INSERT = 260,
		DELETE = 261,

		RIGHT = 262,
		LEFT = 263,
		DOWN = 264,
		UP = 265,

		PAGEUP = 266,
		PAGEDOWN = 267,
		HOME = 268,
		END = 269,

		CAPSLOCK = 280,
		SCROLLLOCK = 281,
		NUMLOCK = 282,
		PRINTSCREEN = 283,
		PAUSE = 284,

		// Function keys
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		// Keypad
		KEYPAD0 = 320,
		KEYPAD1 = 321,
		KEYPAD2 = 322,
		KEYPAD3 = 323,
		KEYPAD4 = 324,
		KEYPAD5 = 325,
		KEYPAD6 = 326,
		KEYPAD7 = 327,
		KEYPAD8 = 328,
		KEYPAD9 = 329,

		KEYPADDECIMAL = 330,
		KEYPADDIVIDE = 331,
		KEYPADMULTIPLY = 332,
		KEYPADSUBTRACT = 333,
		KEYPADADD = 334,
		KEYPADENTER = 335,
		KEYPADEQUAL = 336,

		// Modifiers
		LEFTSHIFT = 340,
		LEFTCONTROL = 341,
		LEFTALT = 342,
		LEFTSUPER = 343,

		RIGHTSHIFT = 344,
		RIGHTCONTROL = 345,
		RIGHTALT = 346,
		RIGHTSUPER = 347,

		MENU = 348,

		LAST = MENU
	};

	enum class MouseButtonCode
	{
		LEFT = 0,
		RIGHT = 1,
		MIDDLE = 2,

		BUTTON4 = 3,
		BUTTON5 = 4,
		BUTTON6 = 5,
		BUTTON7 = 6,
		BUTTON8 = 7,

		LAST = BUTTON8
	};

	class Input
	{
	private:
		friend class Application;

		Input() = delete;

		static void init(void* procAddress);
		static void process();

		// declare static unordered_maps 
		static std::unordered_map<KeyCode, bool> key_states_current;
		static std::unordered_map<KeyCode, bool> key_states_previous;
		static std::unordered_map<MouseButtonCode, bool> mouse_states_current;
		static std::unordered_map<MouseButtonCode, bool> mouse_states_previous;

		static Vector2 mouse_pos_current;
		static Vector2 mouse_pos_previous;

	public:
		static bool getKey(const KeyCode keyCode);
		static bool getKeyDown(const KeyCode keyCode);
		static bool getKeyUp(const KeyCode keyCode);
		static bool getMouseButton(const MouseButtonCode buttonCode);
		static bool getMouseButtonDown(const MouseButtonCode buttonCode);
		static bool getMouseButtonUp(const MouseButtonCode buttonCode);
		static Vector2 getMousePosition();
		static Vector2 getMouseDelta();
	};
}
