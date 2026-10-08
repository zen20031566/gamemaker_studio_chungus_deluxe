#include "Vector2.h"

namespace GameMakerStudioChungusDeluxe
{
	const Vector2 Vector2::down = Vector2(0.0f, -1.0f);
	const Vector2 Vector2::left = Vector2(-1.0f, 0.0f);
	const Vector2 Vector2::one = Vector2(1.0f, 1.0f);
	const Vector2 Vector2::right = Vector2(1.0f, 0.0f);
	const Vector2 Vector2::up = Vector2(0.0f, 1.0f);
	const Vector2 Vector2::zero = Vector2(0.0f, 0.0f);
	const Vector2 Vector2::positiveInfinity = Vector2(Mathf::Infinity, Mathf::Infinity);

	Vector2::Vector2() : x(0.0f), y(0.0f) {}
	Vector2::Vector2(float x, float y) : x(x), y(y) {}

	Vector2::Vector2(const Vector3& v) : x(v.x), y(v.y) {}
	Vector2::operator Vector3() const { return Vector3(x, y, 0.0f); }

	float Vector2::magnitude() const
	{
		return Mathf::sqrt(x * x + y * y);
	}

	Vector2 Vector2::normalized() const
	{
		return Vector2::normalize(*this);
	}

	float Vector2::sqrMagnitude() const
	{
		return x * x + y * y;
	}

	std::string Vector2::toString() const
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}

	float Vector2::angle(const Vector2& from, const Vector2& to)
	{
		float denominator = Mathf::sqrt(from.sqrMagnitude() * to.sqrMagnitude());

		if (denominator < Mathf::EpsilonNormalSqrt)
		{
			return 0.0f;
		}

		float d = Mathf::clamp(dot(from, to) / denominator, -1.0f, 1.0f);

		return Mathf::acos(d) * Mathf::RadToDeg;
	}

	Vector2 Vector2::clampMagnitude(const Vector2& vector, float maxLength)
	{
		float sqrMag = vector.sqrMagnitude();
		if (sqrMag > maxLength * maxLength)
		{
			float mag = Mathf::sqrt(sqrMag);
			return Vector2(vector.x / mag * maxLength, vector.y / mag * maxLength);
		}
		return vector;
	}

	float Vector2::distance(const Vector2& a, const Vector2& b)
	{
		return (a - b).magnitude();
	}

	float Vector2::dot(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	Vector2 Vector2::lerp(const Vector2& a, const Vector2& b, float t)
	{
		t = Mathf::clamp01(t);

		Vector2 v;
		v.x = a.x + (b.x - a.x) * t;
		v.y = a.y + (b.y - a.y) * t;
		return v;
	}

	Vector2 Vector2::lerpUnclamped(const Vector2& a, const Vector2& b, float t)
	{
		Vector2 v;
		v.x = a.x + (b.x - a.x) * t;
		v.y = a.y + (b.y - a.y) * t;
		return v;
	}

	Vector2 Vector2::max(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(Mathf::max(lhs.x, rhs.x), Mathf::max(lhs.y, rhs.y));
	}

	Vector2 Vector2::min(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(Mathf::min(lhs.x, rhs.x), Mathf::min(lhs.y, rhs.y));
	}

	Vector2 Vector2::normalize(const Vector2& value)
	{
		float mag = value.magnitude();
		if (mag > Mathf::Epsilon)
		{
			return Vector2(value.x / mag, value.y / mag);
		}
		return Vector2::zero;
	}

	Vector2 Vector2::perpendicular(const Vector2& inDirection)
	{
		return Vector2(-inDirection.y, inDirection.x);
	}

	Vector2 Vector2::reflect(const Vector2& inDirection, const Vector2& inNormal)
	{
		float factor = -2.0f * dot(inNormal, inDirection);
		return Vector2(factor * inNormal.x + inDirection.x, factor * inNormal.y + inDirection.y);
	}

	Vector2 Vector2::scale(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x * b.x, a.y * b.y);
	}

	float Vector2::signedAngle(const Vector2& from, const Vector2& to)
	{
		float unsignedAngle = angle(from, to);
		float sign = Mathf::sign(from.x * to.y - from.y * to.x);
		return unsignedAngle * sign;
	}

	Vector2 operator+(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x + b.x, a.y + b.y);
	}

	Vector2 operator-(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x - b.x, a.y - b.y);
	}

	Vector2 operator-(const Vector2& a)
	{
		return Vector2(-a.x, -a.y);
	}

	Vector2 operator*(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x * b.x, a.y * b.y);
	}

	Vector2 operator*(const Vector2& a, float d)
	{
		return Vector2(a.x * d, a.y * d);
	}

	Vector2 operator*(float d, const Vector2& a)
	{
		return Vector2(a.x * d, a.y * d);
	}

	Vector2 operator/(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x / b.x, a.y / b.y);
	}

	Vector2 operator/(const Vector2& a, float d)
	{
		return Vector2(a.x / d, a.y / d	);
	}

	bool operator==(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	bool operator!=(const Vector2& lhs, const Vector2& rhs)
	{
		return !(lhs == rhs);
	}
}