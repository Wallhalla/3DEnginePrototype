#include "Camera.h"

#include "GLFW/glfw3.h"

using namespace CG;
using namespace FancyMath;

Camera::Camera(FancyMath::Vector3f inCameraLocation, FancyMath::Vector3f inLookAtLocation, FancyMath::Vector3f inUpVector)
	:eye(inCameraLocation), center(inLookAtLocation), upVector(inUpVector)
{

}

Camera::~Camera()
{

}

Matrix4 Camera::GetCameraMatrix() const
{
	// Kameramatrix => M = R * T		

	/**
	 * Berechnung des Kamera KOS -> u,v,n Komponenten
	 */
	// Berechnung der "N" Komponente aka Blickrichtung entlang der Z-Achse
	// N = -(Center - Eye) N zeigt entgegen der Blickrichtung
	Vector3f N = -1*Vector3f::Normalize(center - eye);	

	// Berechnung der "U" Komponente, aka Vektor der Senkrecht zur Ebene zwischen n und dem upVector steht
	// U = N x Up
	Vector3f U = Vector3f::Normalize(Vector3f::CrossProduct(N, upVector));	

	// Berechnung der "V" Komponente, aka Vektor der Senkrecht zu U und N steht
	// U = N x Up
	Vector3f V = Vector3f::CrossProduct(N, U);

	// Translationsmatrix (T) bestimmt Kamera Position (Pos = eye Vector)
	Matrix4 Translation(1);

	Translation.Elements[12] = -eye.X;
	Translation.Elements[13] = -eye.Y;
	Translation.Elements[14] = -eye.Z;

	Matrix4 Rotation(1);
	// 1. Spalte
	Rotation.Elements[0] = U.X;
	Rotation.Elements[1] = V.X;
	Rotation.Elements[2] = N.X;
	Rotation.Elements[3] = 0;

	// 2. Spalte
	Rotation.Elements[4] = U.Y;
	Rotation.Elements[5] = V.Y;
	Rotation.Elements[6] = N.Y;
	Rotation.Elements[7] = 0;

	// 3. Spalte
	Rotation.Elements[8] = U.Z;
	Rotation.Elements[9] = V.Z;
	Rotation.Elements[10] = N.Z;
	Rotation.Elements[11] = 0;
		
	return Rotation * Translation;
}