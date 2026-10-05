#pragma once
#include <limits>

namespace GameMakerStudioChungusDeluxe
{
	struct Mathf
	{
		Mathf() = delete;

		static constexpr float PI = 3.1415927f;
		static constexpr float Epsilon = 1e-5f;
		static constexpr float Infinity = std::numeric_limits<float>::infinity();
		static constexpr float DegToRad = 0.017453292f; // pi/180
		static constexpr float RadToDeg = 57.29578f; // 180/pi

		static float sin(float f);
		static float cos(float f);
		static float tan(float f);
		static float asin(float f);
		static float acos(float f);
		static float atan(float f);
		static float atan2(float y, float x);

		static float abs(float f);
		static float sign(float f);
		static float sqrt(float f);
		static float pow(float f, float p);
		static float exp(float power);
		static float log(float f);
		static float log10(float f);

		static float min(float a, float b);
		static int min(int a, int b);
		static float max(float a, float b);
		static int max(int a, int b);
		static float clamp(float value, float min, float max);
		static float clamp01(float value);

		static float floor(float f);
		static float ceil(float f);
		static float round(float f);
		static int floorToInt(float f);
		static int ceilToInt(float f);
		static int roundToInt(float f);

		static float lerp(float a, float b, float t);
		static float lerpUnclamped(float a, float b, float t);
		static float inverseLerp(float a, float b, float value);
		static float smoothStep(float from, float to, float t);
	};
}



