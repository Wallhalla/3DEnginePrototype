#pragma once
#include "FancyLib\FancyMath.h"

class Camera
{

private:
	FancyMath::Vector3f eyeVector;
	FancyMath::Vector3f viewTarget;
	FancyMath::Vector3f upVector;
	
public:
	Camera(FancyMath::Vector3f inEyeVector, FancyMath::Vector3f inViewTarget, FancyMath::Vector3f inUpVector = FancyMath::Vector3f(0, 1, 0));	
	~Camera();

public:
	FancyMath::Matrix4 GetViewMatrix();

	static Camera* GetSuperCamera();

private:
	static Camera* globalCamera;
};

