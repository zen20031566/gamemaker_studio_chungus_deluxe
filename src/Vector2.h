#pragma once
#include "Mathf.h"
#include "Vector3.h"
#include <string>

namespace GMSCD
{
	class Vector2
	{
	public:
		float x;
		float y;

		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector3& v);  
		operator Vector3() const;

		float magnitude() const;
		Vector2 normalized() const;
		float sqrMagnitude() const;

		const static Vector2 down;
		const static Vector2 left;
		const static Vector2 one;
		const static Vector2 right;
		const static Vector2 up;
		const static Vector2 zero;
		const static Vector2 positiveInfinity;

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
	Vector2& operator+=(Vector2& a, const Vector2& b);
	Vector2& operator-=(Vector2& a, const Vector2& b);
	Vector2& operator*=(Vector2& a, float d);
	Vector2& operator/=(Vector2& a, float d);
}
