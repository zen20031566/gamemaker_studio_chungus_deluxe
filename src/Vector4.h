#pragma once
#include "Mathf.h"
#include <string>

namespace GameMakerStudioChungusDeluxe
{
	class Vector4
	{
	public:
		float x;
		float y;
		float z;
		float w;

		Vector4();
		Vector4(float x, float y, float z, float w);

		float magnitude() const;
		Vector4 normalized() const;
		float sqrMagnitude() const;

		const static Vector4 one;
		const static Vector4 zero;
		const static Vector4 positiveInfinity;

		bool equals(const Vector4& other) const;
		void set(float newX, float newY, float newZ, float newW);
		std::string toString() const;

		static float distance(const Vector4& a, const Vector4& b);
		static float dot(const Vector4& lhs, const Vector4& rhs);
		static Vector4 lerp(const Vector4& a, const Vector4& b, float t);
		static Vector4 lerpUnclamped(const Vector4& a, const Vector4& b, float t);
		static Vector4 max(const Vector4& lhs, const Vector4& rhs);
		static Vector4 min(const Vector4& lhs, const Vector4& rhs);
		static Vector4 normalize(const Vector4& value);
		static Vector4 scale(const Vector4& a, const Vector4& b);
	};

	Vector4 operator+(const Vector4& a, const Vector4& b);
	Vector4 operator-(const Vector4& a, const Vector4& b);
	Vector4 operator-(const Vector4& a);
	Vector4 operator*(const Vector4& a, float d);
	Vector4 operator*(float d, const Vector4& a);
	Vector4 operator/(const Vector4& a, float d);
	bool operator==(const Vector4& lhs, const Vector4& rhs);
	bool operator!=(const Vector4& lhs, const Vector4& rhs);

}
