#include "Lights.h"

using namespace Lighting;
using namespace FancyMath;


DirectionalLight::DirectionalLight(Vector3f inDirection, Vector3f inLightColor)
	:direction(inDirection), color(inLightColor)
{
	
}