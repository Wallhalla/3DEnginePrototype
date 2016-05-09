#pragma once
#include "FancyLib/FancyMath.h"

namespace Lighting
{

	static FancyMath::Vector3f AmbientLight = FancyMath::Vector3f(0.2f, 0.2f, 0.2f);


	struct DirectionalLight
	{
		FancyMath::Vector3f color;
		FancyMath::Vector3f direction;

		DirectionalLight(FancyMath::Vector3f inDirection, FancyMath::Vector3f inLightColor);
	};
}