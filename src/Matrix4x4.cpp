#include "Matrix4x4.h"
#include "Mathf.h"
#include <glm/glm.hpp>

namespace GMSCD
{
	Matrix4x4::Matrix4x4()
	{
		col[0] = Vector4(1, 0, 0, 0);
		col[1] = Vector4(0, 1, 0, 0);
		col[2] = Vector4(0, 0, 1, 0);
		col[3] = Vector4(0, 0, 0, 1);
	}

	Matrix4x4::Matrix4x4(const Vector4& column0, const Vector4& column1,
		const Vector4& column2, const Vector4& column3)
	{
		col[0] = column0;
		col[1] = column1;
		col[2] = column2;
		col[3] = column3;
	}

	Vector4& Matrix4x4::operator[](int c)
	{
		return col[c];
	}

	const Vector4& Matrix4x4::operator[](int c) const
	{
		return col[c];
	}

	const Matrix4x4 Matrix4x4::identity(
		Vector4(1, 0, 0, 0),
		Vector4(0, 1, 0, 0),
		Vector4(0, 0, 1, 0),
		Vector4(0, 0, 0, 1));

	const Matrix4x4 Matrix4x4::zero(
		Vector4(0, 0, 0, 0),
		Vector4(0, 0, 0, 0),
		Vector4(0, 0, 0, 0),
		Vector4(0, 0, 0, 0));

	Matrix4x4 Matrix4x4::inverse() const
	{
		//annoying to do just use glm
		glm::mat4 m;
		for (int i = 0; i < 4; i++)
		{
			m[i] = glm::vec4(col[i].x, col[i].y, col[i].z, col[i].w);
		}

		if (Mathf::abs(glm::determinant(m)) < Mathf::Epsilon)
		{
			return Matrix4x4::zero;
		}

		glm::mat4 inv = glm::inverse(m);
		Matrix4x4 result;
		for (int i = 0; i < 4; i++)
		{
			result[i] = Vector4(inv[i][0], inv[i][1], inv[i][2], inv[i][3]);
		}
		return result;
	}

	Matrix4x4 Matrix4x4::translate(const Vector3& v)
	{
		return Matrix4x4( 
			Vector4(1, 0, 0, 0),         
			Vector4(0, 1, 0, 0),        
			Vector4(0, 0, 1, 0),           
			Vector4(v.x, v.y, v.z, 1));    
	}

	Matrix4x4 Matrix4x4::scale(const Vector3& v)
	{
		return Matrix4x4(
			Vector4(v.x, 0, 0, 0),        
			Vector4(0, v.y, 0, 0),        
			Vector4(0, 0, v.z, 0),       
			Vector4(0, 0, 0, 1));      
	}

	Matrix4x4 Matrix4x4::rotate(float degrees, const Vector3& axis)
	{
		Vector3 a = axis.normalized();
		float rad = degrees * Mathf::DegToRad;
		float cos = Mathf::cos(rad);
		float sin = Mathf::sin(rad);
		float tan = 1.0f - cos;

		return Matrix4x4(
			Vector4(tan * a.x * a.x + cos, 
				tan * a.x * a.y + sin * a.z,
				tan * a.x * a.z - sin * a.y, 0),  

			Vector4(tan * a.x * a.y - sin * a.z, 
				tan * a.y * a.y + cos, 
				tan * a.y * a.z + sin * a.x, 0), 

			Vector4(tan * a.x * a.z + sin * a.y, 
				tan * a.y * a.z - sin * a.x,
				tan * a.z * a.z + cos, 0),  

			Vector4(0, 0, 0, 1));                                                                         
	}

	Matrix4x4 Matrix4x4::TRS(const Vector3& pos, float degrees, const Vector3& axis, const Vector3& s)
	{
		return translate(pos) * rotate(degrees, axis) * scale(s);
	}

	Matrix4x4 Matrix4x4::ortho(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		Matrix4x4 m;

		m[0][0] = 2.0f / (right - left);
		m[1][1] = 2.0f / (top - bottom);
		m[2][2] = -2.0f / (zFar - zNear);

		m[3][0] = -(right + left) / (right - left);
		m[3][1] = -(top + bottom) / (top - bottom);
		m[3][2] = -(zFar + zNear) / (zFar - zNear);

		return m;
	}

	Matrix4x4 operator*(const Matrix4x4& a, const Matrix4x4& b)
	{
		Matrix4x4 r;
		for (int column = 0; column < 4; ++column)
		{
			for (int row = 0; row < 4; ++row)
			{
				float sum = 0.0f;
				for (int i = 0; i < 4; ++i)
				{
					sum += a[i][row] * b[column][i];
				}
				r[column][row] = sum;
			}
		}
		return r;
	}

	Vector4 operator*(const Matrix4x4& m, const Vector4& v)
	{
		Vector4 r;
		for (int row = 0; row < 4; ++row)
		{
			float sum = 0.0f;
			for (int i = 0; i < 4; ++i)
			{
				sum += m[i][row] * v[i];
			}
			r[row] = sum;
		}
		return r;
	}

	bool operator==(const Matrix4x4& a, const Matrix4x4& b)
	{
		return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
	}

	bool operator!=(const Matrix4x4& a, const Matrix4x4& b)
	{
		return !(a == b);
	}

	Matrix4x4& operator*=(Matrix4x4& a, const Matrix4x4& b)
	{
		a = a * b;
		return a;
	}
}