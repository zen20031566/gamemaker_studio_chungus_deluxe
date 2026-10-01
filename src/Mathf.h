#pragma once
#include <limits>

namespace GameMakerStudioChungusDeluxe
{
	struct Mathf
	{
		Mathf() = delete;
		static constexpr float PI = 3.1415927f;
		static constexpr float Epsilon = std::numeric_limits<float>::min();
		static constexpr float Infinity = std::numeric_limits<float>::infinity();
		static constexpr float NegativeInfinity = -std::numeric_limits<float>::infinity();
		static constexpr float DegToRad = 0.017453292f; // pi/180
		static constexpr float RadToDeg = 57.29578f; // 180/pi

		static float abs(float f);
		static bool approx(float a, float b);
		static float acos(float f);
		static float asin(float f);
		static float atan(float f);
		static float atan2(float y, float x);
		static float ceil(float f);
		static int ceilToInt(float f);
		static float clamp(float value, float min, float max);
		static float clamp01(float value);
		static int closestPowerOfTwo(int value);
		static float cos(float f);
		static float deltaAngle(float current, float target);
		static float exp(float power);
		static float floor(float f);
		static int floorToInt(float f);
		static float inverseLerp(float a, float b, float value);
		static bool isPowerOfTwo(int value);
		static float lerp(float a, float b, float t);
		static float lerpUnclamped(float a, float b, float t);
		static float lerpAngle(float a, float b, float t);
		static float log(float f);
		static float log(float f, float base);
		static float log10(float f);
		static float max(float a, float b);
		static int max(int a, int b);
		static float min(float a, float b);
		static int min(int a, int b);
		static float moveTowards(float current, float target, float maxDelta);
		static float moveTowardsAngle(float current, float target, float maxDelta);
		static int nextPowerOfTwo(int value);
		static float perlinNoise(float x, float y);
		static float pingPong(float t, float length);
		static float pow(float f, float p);
		static float repeat(float t, float length);
		static float round(float f);
		static int roundToInt(float f);
		static float sign(float f);
		static float sin(float f);
		static float smoothDamp(float current, float target, float& currentVelocity,
			float smoothTime, float maxSpeed = Infinity, float deltaTime = 0.0f);
		static float smoothDampAngle(float current, float target, float& currentVelocity,
			float smoothTime, float maxSpeed = Infinity, float deltaTime = 0.0f);
		static float smoothStep(float from, float to, float t);
		static float sqrt(float f);
		static float tan(float f);
	};
}



