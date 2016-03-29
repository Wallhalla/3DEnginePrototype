#pragma once
#include "MathExportHeader.h"

namespace FancyMath
{
	struct FANCYMATH_API Vector3f
	{
	public:
		float X, Y, Z;

		Vector3f();

		Vector3f(const float& x, const float& y, const float& z);

		Vector3f& Add(const Vector3f& other);
		Vector3f& Subtract(const Vector3f& other);
		Vector3f& Multiply(const float factor);

		static float DotProduct(const Vector3f& vector1, const Vector3f& vector2);
		static Vector3f CrossProduct(const Vector3f& vector1, const Vector3f& vector2);

		friend FANCYMATH_API Vector3f operator+(Vector3f left, const Vector3f& right);
		friend FANCYMATH_API Vector3f operator-(Vector3f left, const Vector3f& right);
		friend FANCYMATH_API Vector3f operator*(Vector3f left, const float factor);
		//friend float operator*(Vector3f left, const Vector3f& right);

		Vector3f operator+=(const Vector3f& other);
		Vector3f operator-=(const Vector3f& other);
		Vector3f operator*=(const float factor);

		bool operator==(const Vector3f& other);
		bool operator!=(const Vector3f& other);

		float GetLength() const;

		void Normalize();
	};

	
}
