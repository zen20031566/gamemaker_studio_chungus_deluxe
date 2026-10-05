#include "Mathf.h"
#include <cmath>

namespace GameMakerStudioChungusDeluxe
{
	float Mathf::sin(float f) { return std::sin(f); }
	float Mathf::cos(float f) { return std::cos(f); }
	float Mathf::tan(float f) { return std::tan(f); }
	float Mathf::asin(float f) { return std::asin(f); }
	float Mathf::acos(float f) { return std::acos(f); }
	float Mathf::atan(float f) { return std::atan(f); }
	float Mathf::atan2(float y, float x) { return std::atan2(y, x); }

	float Mathf::abs(float f)
	{
		return f < 0.0f ? -f : f;
	}

	float Mathf::sign(float f)
	{
		return f >= 0.0f ? 1.0f : -1.0f;
	}

	float Mathf::sqrt(float f) { return std::sqrt(f); }
	float Mathf::pow(float f, float p) { return std::pow(f, p); }
	float Mathf::exp(float power) { return std::exp(power); }
	float Mathf::log(float f) { return std::log(f); }
	float Mathf::log10(float f) { return std::log10(f); }

	float Mathf::min(float a, float b) { return a < b ? a : b; }
	int Mathf::min(int a, int b) { return a < b ? a : b; }
	float Mathf::max(float a, float b) { return a > b ? a : b; }
	int Mathf::max(int a, int b) { return a > b ? a : b; }

	float Mathf::clamp(float value, float min, float max)
	{
		if (value < min) return min;
		if (value > max) return max;
		return value;
	}

	float Mathf::clamp01(float value)
	{
		if (value < 0.0f) return 0.0f;
		if (value > 1.0f) return 1.0f;
		return value;
	}

	float Mathf::floor(float f) { return std::floor(f); }
	float Mathf::ceil(float f) { return std::ceil(f); }
	float Mathf::round(float f) { return std::round(f); }
	int Mathf::floorToInt(float f) { return static_cast<int>(std::floor(f)); }
	int Mathf::ceilToInt(float f) { return static_cast<int>(std::ceil(f)); }
	int Mathf::roundToInt(float f) { return static_cast<int>(std::round(f)); }

	float Mathf::lerp(float a, float b, float t)
	{
		return a + (b - a) * Mathf::clamp01(t);
	}

	float Mathf::lerpUnclamped(float a, float b, float t)
	{
		return a + (b - a) * t;
	}

	float Mathf::inverseLerp(float a, float b, float value)
	{
		if (a != b)
		{
			return Mathf::clamp01((value - a) / (b - a));
		}
		else
		{
			return 0.0f; 
		}
	}

	float Mathf::smoothStep(float from, float to, float t)
	{
		t = Mathf::clamp01(t);
		t = t * t * (3.0f - 2.0f * t);
		return from + (to - from) * t;
	}
}