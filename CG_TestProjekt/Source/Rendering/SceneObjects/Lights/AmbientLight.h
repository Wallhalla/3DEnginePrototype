#pragma once

#include "FancyLib/FancyMath.h"
#include "../../Helpers/Colors.h"

struct AmbientLight
{
	float Intensity = 1.0f;
	FancyMath::Vector4f color = Color::White;

	FancyMath::Vector4f GetLight();
};