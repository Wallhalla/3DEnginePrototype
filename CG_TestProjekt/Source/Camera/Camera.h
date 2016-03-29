#pragma once

#include "FancyLib/FancyMath.h"

namespace CG
{

	struct Camera
	{
	private:
		FancyMath::Vector3f location;
		FancyMath::Vector3f lookAt;
		FancyMath::Vector3f upVector;
	

	public:
		Camera(FancyMath::Vector3f inCameraLocation, FancyMath::Vector3f inLookAtLocation, FancyMath::Vector3f inUpVector);
		~Camera();

		FancyMath::Matrix4 GetCameraMatrix() const;
	};

}

