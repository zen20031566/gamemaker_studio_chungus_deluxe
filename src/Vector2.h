#pragma once
#include "Mathf.h"
#include <string>

namespace GameMakerStudioChungusDeluxe
{
	struct Vector2
	{
		float x;
		float y;

		Vector2();
		Vector2(float x, float y);

		float magnitude() const;
		Vector2 normalized() const;
		float sqrMagnitude() const;

		static Vector2 down;
		static Vector2 left;
		static Vector2 one;
		static Vector2 right;
		static Vector2 up;
		static Vector2 zero;
		static Vector2 negativeInfinity;
		static Vector2 positiveInfinity;

		bool equals(const Vector2& other) const;
		void normalize();
		void scale(const Vector2& scale);
		void set(float newX, float newY);
		std::string toString() const;

		static float angle(const Vector2& from, const Vector2& to);
		static Vector2 clampMagnitude(const Vector2& vector, float maxLength);
		static float distance(const Vector2& a, const Vector2& b);
		static float dot(const Vector2& lhs, const Vector2& rhs);
		static Vector2 lerp(const Vector2& a, const Vector2& b, float t);
		static Vector2 lerpUnclamped(const Vector2& a, const Vector2& b, float t);
		static Vector2 max(const Vector2& lhs, const Vector2& rhs);
		static Vector2 min(const Vector2& lhs, const Vector2& rhs);
		static Vector2 normalize(const Vector2& value);
		static Vector2 perpendicular(const Vector2& inDirection);
		static Vector2 reflect(const Vector2& inDirection, const Vector2& inNormal);
		static Vector2 scale(const Vector2& a, const Vector2& b);
		static float signedAngle(const Vector2& from, const Vector2& to);
	};
	 
	Vector2 operator+(const Vector2& a, const Vector2& b);
	Vector2 operator-(const Vector2& a, const Vector2& b);
	Vector2 operator-(const Vector2& a);
	Vector2 operator*(const Vector2& a, const Vector2& b);
	Vector2 operator*(const Vector2& a, float d);
	Vector2 operator*(float d, const Vector2& a);
	Vector2 operator/(const Vector2& a, const Vector2& b);
	Vector2 operator/(const Vector2& a, float d);
	bool operator==(const Vector2& lhs, const Vector2& rhs);
	bool operator!=(const Vector2& lhs, const Vector2& rhs);
}
