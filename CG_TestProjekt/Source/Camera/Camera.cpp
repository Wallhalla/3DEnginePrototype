#include "Camera.h"

using namespace FancyMath;

Camera::Camera(Vector3f inEyeVector, Vector3f inViewTarget, Vector3f inUpVector)
{
	eyeVector = inEyeVector;
	viewTarget = inViewTarget;
	upVector = inUpVector;

	globalCamera = this;
}

Camera* Camera::GetSuperCamera()
{
	return globalCamera;
}

Camera::~Camera()
{
}

Matrix4 Camera::GetViewMatrix()
{
	Matrix4 rotation = Matrix4(1);
	Matrix4 translation = Matrix4(1);

	Vector3f viewDirection = Vector3f::Normalize(Camera::eyeVector - Camera::viewTarget);
	Vector3f rightVector = Vector3f::Normalize(Vector3f::CrossProduct(Camera::upVector, viewDirection));
	Vector3f cameraUpVector = Vector3f::CrossProduct(viewDirection, rightVector);
	
	rotation.Elements[0] = rightVector.X;
	rotation.Elements[1] = cameraUpVector.X;
	rotation.Elements[2] = viewDirection.X;

	rotation.Elements[4] = rightVector.Y;
	rotation.Elements[5] = cameraUpVector.Y;
	rotation.Elements[6] = viewDirection.Y;

	rotation.Elements[8] = rightVector.Z;
	rotation.Elements[9] = cameraUpVector.Z;
	rotation.Elements[10] = viewDirection.Z;

	translation.Elements[12] = Camera::eyeVector.X * -1;
	translation.Elements[13] = Camera::eyeVector.Y * -1;
	translation.Elements[14] = Camera::eyeVector.Z * -1;
	
	Matrix4 retVal = rotation * translation;
	
	return retVal;
}