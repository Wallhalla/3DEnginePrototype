#pragma once
#include "FancyLib/FancyMath.h"

namespace Color
{
	static FancyMath::Vector4f White = FancyMath::Vector4f(1, 1, 1, 1);
	static FancyMath::Vector4f Black = FancyMath::Vector4f(0, 0, 0, 1);

	static FancyMath::Vector4f Grey = FancyMath::Vector4f(0.5f, 0.5f, 0.5f, 1);
	static FancyMath::Vector4f LightGrey = FancyMath::Vector4f(0.75f, 0.75f, 0.75f, 1);
	static FancyMath::Vector4f DarkGrey = FancyMath::Vector4f(0.25f, 0.25f, 0.25f, 1);

	static FancyMath::Vector4f Red = FancyMath::Vector4f(1, 0, 0, 1);
	static FancyMath::Vector4f Green = FancyMath::Vector4f(0, 1, 0, 1);
	static FancyMath::Vector4f Blue = FancyMath::Vector4f(0, 0, 1, 1);

	static FancyMath::Vector4f Yellow = FancyMath::Vector4f(1, 1, 0, 1);
	static FancyMath::Vector4f Magenta = FancyMath::Vector4f(1, 0, 1, 1);
	static FancyMath::Vector4f Cyan = FancyMath::Vector4f(0, 1, 1, 1);
}