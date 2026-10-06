#pragma once
#include "Vector4.h"

namespace GameMakerStudioChungusDeluxe
{
	struct Matrix4x4
	{
		float m00, m01, m02, m03;
		float m10, m11, m12, m13;
		float m20, m21, m22, m23;
		float m30, m31, m32, m33;

		Matrix4x4();
		Matrix4x4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);

		Matrix4x4(const Vector4& column0, const Vector4& column1,
			const Vector4& column2, const Vector4& column3);


	};
}