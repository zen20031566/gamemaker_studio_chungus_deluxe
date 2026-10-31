#include "Vector3.h"

namespace GMSCD
{
	const Vector3 Vector3::down = Vector3(0.0f, -1.0f, 0.0f);
	const Vector3 Vector3::left = Vector3(-1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::one = Vector3(1.0f, 1.0f, 1.0f);
	const Vector3 Vector3::right = Vector3(1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::up = Vector3(0.0f, 1.0f, 0.0f);
	const Vector3 Vector3::zero = Vector3(0.0f, 0.0f, 0.0f);
	const Vector3 Vector3::positiveInfinity = Vector3(Mathf::Infinity, Mathf::Infinity, Mathf::Infinity);

	Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	float Vector3::magnitude() const
	{
		return Mathf::sqrt(x * x + y * y + z * z);
	}

	Vector3 Vector3::normalized() const
	{
		return Vector3::normalize(*this);
	}

	float Vector3::sqrMagnitude() const
	{
		return x * x + y * y + z * z;
	}

	std::string Vector3::toString() const
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	}

	float Vector3::angle(const Vector3& from, const Vector3& to)
	{
		float denominator = Mathf::sqrt(from.sqrMagnitude() * to.sqrMagnitude());

		if (denominator < Mathf::EpsilonNormalSqrt)
		{
			return 0.0f;
		}

		float d = Mathf::clamp(dot(from, to) / denominator, -1.0f, 1.0f);

		return Mathf::acos(d) * Mathf::RadToDeg;
	}

	Vector3 Vector3::clampMagnitude(const Vector3& vector, float maxLength)
	{
		float sqrMag = vector.sqrMagnitude();
		if (sqrMag > maxLength * maxLength)
		{
			float mag = Mathf::sqrt(sqrMag);
			return Vector3(vector.x / mag * maxLength, vector.y / mag * maxLength, vector.z / mag * maxLength);
		}
		return vector;
	}

	Vector3 Vector3::cross(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x);
	}

	float Vector3::distance(const Vector3& a, const Vector3& b)
	{
		return (a - b).magnitude();
	}

	float Vector3::dot(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	Vector3 Vector3::lerp(const Vector3& a, const Vector3& b, float t)
	{
		t = Mathf::clamp01(t);

		Vector3 v;
		v.x = a.x + (b.x - a.x) * t;
		v.y = a.y + (b.y - a.y) * t;
		v.z = a.z + (b.z - a.z) * t;
		return v;
	}

	Vector3 Vector3::lerpUnclamped(const Vector3& a, const Vector3& b, float t)
	{
		Vector3 v;
		v.x = a.x + (b.x - a.x) * t;
		v.y = a.y + (b.y - a.y) * t;
		v.z = a.z + (b.z - a.z) * t;
		return v;
	}

	Vector3 Vector3::max(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(Mathf::max(lhs.x, rhs.x), Mathf::max(lhs.y, rhs.y), Mathf::max(lhs.z, rhs.z));
	}

	Vector3 Vector3::min(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(Mathf::min(lhs.x, rhs.x), Mathf::min(lhs.y, rhs.y), Mathf::min(lhs.z, rhs.z));
	}

	Vector3 Vector3::normalize(const Vector3& value)
	{
		float mag = value.magnitude();
		if (mag > Mathf::Epsilon)
		{
			return Vector3(value.x / mag, value.y / mag, value.z / mag);
		}
		return Vector3::zero;
	}

	Vector3 Vector3::perpendicular(const Vector3& inDirection)
	{
		float ax = Mathf::abs(inDirection.x);
		float ay = Mathf::abs(inDirection.y);
		float az = Mathf::abs(inDirection.z);

		Vector3 axis = Vector3(0.0f, 0.0f, 1.0f);
		if (ax <= ay && ax <= az)
		{
			axis = Vector3::right;
		}
		else if (ay <= az)
		{
			axis = Vector3::up;
		}

		return cross(inDirection, axis);
	}

	Vector3 Vector3::reflect(const Vector3& inDirection, const Vector3& inNormal)
	{
		float factor = -2.0f * dot(inNormal, inDirection);
		return Vector3(
			factor * inNormal.x + inDirection.x,
			factor * inNormal.y + inDirection.y,
			factor * inNormal.z + inDirection.z);
	}

	Vector3 Vector3::scale(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
	}

	float Vector3::signedAngle(const Vector3& from, const Vector3& to, const Vector3& axis)
	{
		float unsignedAngle = angle(from, to);

		float crossX = from.y * to.z - from.z * to.y;
		float crossY = from.z * to.x - from.x * to.z;
		float crossZ = from.x * to.y - from.y * to.x;
		float sign = Mathf::sign(axis.x * crossX + axis.y * crossY + axis.z * crossZ);
		return unsignedAngle * sign;
	}

	Vector3 Vector3::project(const Vector3& vector, const Vector3& onNormal)
	{
		float sqrMag = dot(onNormal, onNormal);
		if (sqrMag < Mathf::Epsilon)
		{
			return zero;
		}

		float d = dot(vector, onNormal);
		return onNormal * (d / sqrMag);
	}

	Vector3 Vector3::projectOnPlane(const Vector3& vector, const Vector3& planeNormal)
	{
		float sqrMag = dot(planeNormal, planeNormal);
		if (sqrMag < Mathf::Epsilon)
		{
			return vector;
		}

		float d = dot(vector, planeNormal);
		return vector - planeNormal * (d / sqrMag);
	}

	Vector3 operator+(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	Vector3 operator-(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
	}

	Vector3 operator-(const Vector3& a)
	{
		return Vector3(-a.x, -a.y, -a.z);
	}

	Vector3 operator*(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
	}

	Vector3 operator*(const Vector3& a, float d)
	{
		return Vector3(a.x * d, a.y * d, a.z * d);
	}

	Vector3 operator*(float d, const Vector3& a)
	{
		return Vector3(a.x * d, a.y * d, a.z * d);
	}

	Vector3 operator/(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.x / b.x, a.y / b.y, a.z / b.z);
	}

	Vector3 operator/(const Vector3& a, float d)
	{
		return Vector3(a.x / d, a.y / d, a.z / d);
	}

	bool operator==(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	bool operator!=(const Vector3& lhs, const Vector3& rhs)
	{
		return !(lhs == rhs);
	}

	Vector3& operator+=(Vector3& a, const Vector3& b)
	{
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		return a;
	}

	Vector3& operator-=(Vector3& a, const Vector3& b)
	{
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		return a;
	}

	Vector3& operator*=(Vector3& a, float d)
	{
		a.x *= d;
		a.y *= d;
		a.z *= d;
		return a;
	}

	Vector3& operator/=(Vector3& a, float d)
	{
		a.x /= d;
		a.y /= d;
		a.z /= d;
		return a;
	}
}