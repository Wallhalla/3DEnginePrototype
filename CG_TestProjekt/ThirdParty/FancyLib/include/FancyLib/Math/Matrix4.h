#pragma once
#include "MathExportHeader.h"

#include "Vector3f.h"
#include "Vector4f.h"

namespace FancyMath
{
	FANCYMATH_API float ToRadians(float inDegrees);

	struct FANCYMATH_API Matrix4
	{
		union
		{
			float Elements[4 * 4];
			struct
			{
				Vector4f Collumns[4];
			};
		};

		Matrix4();
		Matrix4(float diagonal);

		Matrix4& Multiply(const Matrix4& other);
		Vector4f Multiply(const Vector4f& vector) const;
		Vector3f Multiply(const Vector3f& vector) const;


		Matrix4& operator*=(const Matrix4& other);
		friend FANCYMATH_API Matrix4 operator*(Matrix4 left, const Matrix4& right);
		friend FANCYMATH_API Vector4f operator*(const Matrix4& left, const Vector4f& right);
		friend FANCYMATH_API Vector3f operator*(const Matrix4& left, const Vector3f& right);


	};

	FANCYMATH_API Matrix4 IdentityMatrix();
	FANCYMATH_API Matrix4 OrthographicMatrix(float left, float right, float bottom, float top, float near, float far);
	FANCYMATH_API Matrix4 PerspectiveMatrix(float fieldOfView, float aspectRatio, float near, float far);

	FANCYMATH_API Matrix4 Translate(const Vector3f& translationVector);
	FANCYMATH_API Matrix4 Rotate(const float angle, const Vector3f& axis);
	FANCYMATH_API Matrix4 Scale(const Vector3f& scaleVector);
}
