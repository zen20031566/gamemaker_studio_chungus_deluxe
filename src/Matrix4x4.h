#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include <string>

namespace GMSCD
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
		Matrix4x4 inverse() const;
		//Matrix4x4 transpose() const;

		static Matrix4x4 translate(const Vector3& v);
		static Matrix4x4 scale(const Vector3& v);
		static Matrix4x4 rotate(float degrees, const Vector3& axis);
		static Matrix4x4 TRS(const Vector3& pos, float degrees, const Vector3& axis, const Vector3& s);
		static Matrix4x4 ortho(float left, float right, float bottom, float top, float zNear, float zFar);
	};

	Matrix4x4 operator*(const Matrix4x4& a, const Matrix4x4& b);
	Vector4 operator*(const Matrix4x4& m, const Vector4& v);
	bool operator==(const Matrix4x4& a, const Matrix4x4& b);
	bool operator!=(const Matrix4x4& a, const Matrix4x4& b);
	Matrix4x4& operator*=(Matrix4x4& a, const Matrix4x4& b);
}