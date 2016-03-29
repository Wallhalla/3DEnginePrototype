#pragma once
#include "MathExportHeader.h"

namespace FancyMath
{
	struct FANCYMATH_API Vector4f
	{
	public:
		float X, Y, Z, W;

		Vector4f() = default;
		Vector4f(const float& x, const float& y, const float& z, const float& w);

		Vector4f& Add(const Vector4f& other);
		Vector4f& Subtract(const Vector4f& other);
		Vector4f& Multiply(const float factor);

		float DotProduct(const Vector4f& other);

		friend Vector4f operator+(Vector4f left, const Vector4f& right);
		friend Vector4f operator-(Vector4f left, const Vector4f& right);
		friend Vector4f operator*(Vector4f left, const float factor);
		friend float operator*(Vector4f left, const Vector4f& right);

		Vector4f operator+=(const Vector4f& other);
		Vector4f operator-=(const Vector4f& other);
		Vector4f operator*=(const float factor);

		bool operator==(const Vector4f& other);
		bool operator!=(const Vector4f& other);
		
	};
}
