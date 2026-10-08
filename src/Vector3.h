#pragma once
#include "Mathf.h"
#include <string>

namespace GameMakerStudioChungusDeluxe
{
	class Vector3
	{
	public:
		float x;
		float y;
		float z;

		Vector3();
		Vector3(float x, float y, float z);

		float magnitude() const;
		Vector3 normalized() const;
		float sqrMagnitude() const;

		const static Vector3 down;
		const static Vector3 left;
		const static Vector3 one;
		const static Vector3 right;
		const static Vector3 up;
		const static Vector3 zero;
		const static Vector3 positiveInfinity;

		std::string toString() const;

		static float angle(const Vector3& from, const Vector3& to);
		static Vector3 clampMagnitude(const Vector3& vector, float maxLength);
		static Vector3 cross(const Vector3& lhs, const Vector3& rhs);
		static float distance(const Vector3& a, const Vector3& b);
		static float dot(const Vector3& lhs, const Vector3& rhs);
		static Vector3 lerp(const Vector3& a, const Vector3& b, float t);
		static Vector3 lerpUnclamped(const Vector3& a, const Vector3& b, float t);
		static Vector3 max(const Vector3& lhs, const Vector3& rhs);
		static Vector3 min(const Vector3& lhs, const Vector3& rhs);
		static Vector3 normalize(const Vector3& value);
		static Vector3 perpendicular(const Vector3& inDirection);
		static Vector3 reflect(const Vector3& inDirection, const Vector3& inNormal);
		static Vector3 scale(const Vector3& a, const Vector3& b);
		static float signedAngle(const Vector3& from, const Vector3& to, const Vector3& axis);
		static Vector3 project(const Vector3& vector, const Vector3& onNormal);
		static Vector3 projectOnPlane(const Vector3& vector, const Vector3& planeNormal);
	};

	Vector3 operator+(const Vector3& a, const Vector3& b);
	Vector3 operator-(const Vector3& a, const Vector3& b);
	Vector3 operator-(const Vector3& a);
	Vector3 operator*(const Vector3& a, const Vector3& b);
	Vector3 operator*(const Vector3& a, float d);
	Vector3 operator*(float d, const Vector3& a);
	Vector3 operator/(const Vector3& a, const Vector3& b);
	Vector3 operator/(const Vector3& a, float d);
	bool operator==(const Vector3& lhs, const Vector3& rhs);
	bool operator!=(const Vector3& lhs, const Vector3& rhs);

}
