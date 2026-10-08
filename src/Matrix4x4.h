#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include <string>
//#include "Quaternion.h"

namespace GameMakerStudioChungusDeluxe
{
	class Matrix4x4
	{
	public:
		Vector4 col[4];

		Matrix4x4();
		Matrix4x4(const Vector4& column0, const Vector4& column1,
			const Vector4& column2, const Vector4& column3);

		Vector4& operator[](int c);
		const Vector4& operator[](int c) const;

		const static Matrix4x4 identity;
		const static Matrix4x4 zero;

		//float determinant() const;
		//Matrix4x4 inverse() const;
		//Matrix4x4 transpose() const;

		//Vector3 multiplyPoint(const Vector3& point) const; //w = 1, divides by w
		//Vector3 multiplyVector(const Vector3& vector) const; //w = 0, ignores translation

		static Matrix4x4 translate(const Vector3& v);
		static Matrix4x4 scale(const Vector3& v);
		static Matrix4x4 rotate(float degrees, const Vector3& axis);
		static Matrix4x4 TRS(const Vector3& pos, float degrees, const Vector3& axis, const Vector3& s);

		//static Matrix4x4 rotate(const Quaternion& q);
		//static Matrix4x4 TRS(const Vector3& pos, const Quaternion& q, const Vector3& s);
		//static Matrix4x4 perspective(float fovDegrees, float aspect, float zNear, float zFar);
		//static Matrix4x4 ortho(float left, float right, float bottom, float top, float zNear, float zFar);
		//static Matrix4x4 lookAt(const Vector3& from, const Vector3& to, const Vector3& up);
	};

	Matrix4x4 operator*(const Matrix4x4& a, const Matrix4x4& b);
	Vector4 operator*(const Matrix4x4& m, const Vector4& v);
	bool operator==(const Matrix4x4& a, const Matrix4x4& b);
	bool operator!=(const Matrix4x4& a, const Matrix4x4& b);
}