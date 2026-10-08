#include "Vector4.h"

namespace GameMakerStudioChungusDeluxe
{
	const Vector4 Vector4::one = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	const Vector4 Vector4::zero = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4 Vector4::positiveInfinity = Vector4(Mathf::Infinity, Mathf::Infinity, Mathf::Infinity, Mathf::Infinity);

	Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
	Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}

	float& Vector4::operator[](int i)
	{
		return (&x)[i];
	}

	const float& Vector4::operator[](int i) const
	{
		return (&x)[i];
	}

	float Vector4::magnitude() const
	{
		return Mathf::sqrt(x * x + y * y + z * z + w * w);
	}

	Vector4 Vector4::normalized() const
	{
		return Vector4::normalize(*this);
	}

	float Vector4::sqrMagnitude() const
	{
		return x * x + y * y + z * z + w * w;
	}

	std::string Vector4::toString() const
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
	}

	float Vector4::distance(const Vector4& a, const Vector4& b)
	{
		return (a - b).magnitude();
	}

	float Vector4::dot(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	Vector4 Vector4::lerp(const Vector4& a, const Vector4& b, float t)
	{
		t = Mathf::clamp01(t);

		Vector4 v;
		v.x = a.x + (b.x - a.x) * t;
		v.y = a.y + (b.y - a.y) * t;
		v.z = a.z + (b.z - a.z) * t;
		v.w = a.w + (b.w - a.w) * t;
		return v;
	}

	Vector4 Vector4::lerpUnclamped(const Vector4& a, const Vector4& b, float t)
	{
		Vector4 v;
		v.x = a.x + (b.x - a.x) * t;
		v.y = a.y + (b.y - a.y) * t;
		v.z = a.z + (b.z - a.z) * t;
		v.w = a.w + (b.w - a.w) * t;
		return v;
	}

	Vector4 Vector4::max(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(Mathf::max(lhs.x, rhs.x), Mathf::max(lhs.y, rhs.y), Mathf::max(lhs.z, rhs.z), Mathf::max(lhs.w, rhs.w));
	}

	Vector4 Vector4::min(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(Mathf::min(lhs.x, rhs.x), Mathf::min(lhs.y, rhs.y), Mathf::min(lhs.z, rhs.z), Mathf::min(lhs.w, rhs.w));
	}

	Vector4 Vector4::normalize(const Vector4& value)
	{
		float mag = value.magnitude();
		if (mag > Mathf::Epsilon)
		{
			return Vector4(value.x / mag, value.y / mag, value.z / mag, value.w / mag);
		}
		return Vector4::zero;
	}

	Vector4 Vector4::scale(const Vector4& a, const Vector4& b)
	{
		return Vector4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
	}

	Vector4 operator+(const Vector4& a, const Vector4& b)
	{
		return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
	}

	Vector4 operator-(const Vector4& a, const Vector4& b)
	{
		return Vector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
	}

	Vector4 operator-(const Vector4& a)
	{
		return Vector4(-a.x, -a.y, -a.z, -a.w);
	}

	Vector4 operator*(const Vector4& a, float d)
	{
		return Vector4(a.x * d, a.y * d, a.z * d, a.w * d);
	}

	Vector4 operator*(float d, const Vector4& a)
	{
		return Vector4(a.x * d, a.y * d, a.z * d, a.w * d);
	}

	Vector4 operator/(const Vector4& a, float d)
	{
		return Vector4(a.x / d, a.y / d, a.z / d, a.w / d);
	}

	bool operator==(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
	}

	bool operator!=(const Vector4& lhs, const Vector4& rhs)
	{
		return !(lhs == rhs);
	}
}