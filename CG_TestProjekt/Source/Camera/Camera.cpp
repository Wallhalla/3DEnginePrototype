#include "Camera.h"

#include "GLFW/glfw3.h"

using namespace CG;
using namespace FancyMath;

Camera::Camera(FancyMath::Vector3f inCameraLocation, FancyMath::Vector3f inLookAtLocation, FancyMath::Vector3f inUpVector)
	:location(inCameraLocation), lookAt(inLookAtLocation), upVector(inUpVector)
{

}

Camera::~Camera()
{

}

Matrix4 Camera::GetCameraMatrix() const
{
	Matrix4 result(1);

	/*zaxis = normal(cameraTarget - cameraPosition)
		xaxis = normal(cross(cameraUpVector, zaxis))
		yaxis = cross(zaxis, xaxis)

		xaxis.x           yaxis.x           zaxis.x          0
		xaxis.y           yaxis.y           zaxis.y          0
		xaxis.z           yaxis.z           zaxis.z          0
		- dot(xaxis, cameraPosition) - dot(yaxis, cameraPosition) - dot(zaxis, cameraPosition)  1*/

	Vector3f normZaxis = Vector3f(lookAt - location);
	normZaxis.Normalize();

	Vector3f normXaxis = Vector3f::CrossProduct(upVector, normZaxis);
	normXaxis.Normalize();

	Vector3f normYaxis = Vector3f::CrossProduct(normZaxis, normXaxis); // already normalized no need to call Normalize afterwards

	// First collumn
	result.Collumns[0].X = normXaxis.X; 
	result.Collumns[0].Y = normXaxis.Y; 
	result.Collumns[0].Z = normXaxis.Z; 
	result.Collumns[0].W = Vector3f::DotProduct(normXaxis, location) * -1;
	// Second collumn
	result.Collumns[1].X = normYaxis.X; 
	result.Collumns[1].Y = normYaxis.Y; 
	result.Collumns[1].Z = normYaxis.Z; 
	result.Collumns[1].W = Vector3f::DotProduct(normYaxis, location) * -1;
	// Third collumn
	result.Collumns[2].X = normZaxis.X;
	result.Collumns[2].Y = normZaxis.Y;
	result.Collumns[2].Z = normZaxis.Z;
	result.Collumns[2].W = Vector3f::DotProduct(normZaxis, location) * -1;
	// Fourth collumn
	result.Collumns[3].X = 0;
	result.Collumns[3].Y = 0;
	result.Collumns[3].Z = 0;
	result.Collumns[3].W = 1;

	return result;
}