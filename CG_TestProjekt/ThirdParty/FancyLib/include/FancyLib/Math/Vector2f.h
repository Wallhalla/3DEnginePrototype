#pragma once
#include "MathExportHeader.h"

namespace FancyMath
{

	struct FANCYMATH_API Vector2f
	{
	public:
		float X, Y;

		Vector2f();

		Vector2f(const float& x, const float& y);

		Vector2f& Add(const Vector2f& other);
		Vector2f& Subtract(const Vector2f& other);
		Vector2f& Multiply(const float factor);

		float DotProduct(const Vector2f& other);

		friend Vector2f operator+(Vector2f left, const Vector2f& right);
		friend Vector2f operator-(Vector2f left, const Vector2f& right);
		friend Vector2f operator*(Vector2f left, const float factor);
		friend float operator*(Vector2f left, const Vector2f& right);

		Vector2f operator+=(const Vector2f& other);
		Vector2f operator-=(const Vector2f& other);
		Vector2f operator*=(const float factor);

		bool operator==(const Vector2f& other);
		bool operator!=(const Vector2f& other);


	};
}

