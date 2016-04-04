#pragma once

#include "FancyLib/FancyMath.h"

namespace CG
{

	struct Camera
	{
	private:
		FancyMath::Vector3f eye; // location origin of camera
		FancyMath::Vector3f center; // where the eye is looking at
		FancyMath::Vector3f upVector; // which way is "Up"
	

	public:
		Camera(FancyMath::Vector3f inCameraLocation, FancyMath::Vector3f inLookAtLocation, FancyMath::Vector3f inUpVector);
		~Camera();

		FancyMath::Matrix4 GetCameraMatrix() const;
	};

}

