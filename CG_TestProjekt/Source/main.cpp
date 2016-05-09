#include "Window/Window.h"
using namespace CG;

#include "Shader/ShaderProgram.h"

#include "Rendering/SceneObjects/SceneInstance.h"

#include "Camera/Camera.h"


#include "FancyLib/FancyMath.h"
using namespace FancyMath;

#include "Rendering/SceneObjects/Lights/Lights.h"
using namespace Lighting;

#define WINDOWSIZE_X 800
#define WINDOWSIZE_Y 600
#define ASPECT_RATIO (float)(WINDOWSIZE_X / WINDOWSIZE_Y)

int main()
{
	Window window("Einfuehrung Computergrafik", WINDOWSIZE_Y, WINDOWSIZE_Y);	
	
	Matrix4 perspective = FancyMath::PerspectiveMatrix(45, ASPECT_RATIO, 1, 50);
	//perspective.Collumns[1].Y = 0.75f;
	Camera camera = Camera(Vector3f(0, 0, 5), Vector3f(0, 0, 0), Vector3f(0, 1, 0));

	ShaderProgram shader = ShaderProgram(
		"Source/Shader/ShaderFiles/BasicShader");
	shader.Enable();	

	AmbientLight = Vector3f(0.2f, 0.2f, 0.2f);
	shader.SetUniformVector3("ambientLight", AmbientLight);

	// Sonne leuchtet nach unten links mit weißem Licht
	DirectionalLight sun = DirectionalLight(Vector3f(0, 1, 0), Vector3f(1,1,1));
	shader.SetUniformVector3("sunLightDirection", sun.direction);
	shader.SetUniformVector3("sunLightColor", sun.color);

				
	shader.SetUniformMatrix4("projection_matrix", perspective);
	//shader->Disable();
	
	SceneInstance* cubeMesh = new SceneInstance(&shader, std::string("Cube"));

	cubeMesh->SetLocation(Vector3f(0, 0, -5));

	glEnable(GL_DEPTH_TEST);
	
	float i = 0;
	bool start = true;
	while (!window.WasWindowClosed())
	{
		if (start)
		{
			i += 0.005f;
		}
		else
		{
			i -= 0.005f;
		}
		if (i > 180)
		{
			start = false;
		}
		else if (i < 0)
		{
			start = true;
		}

		window.Clear();	

		Matrix4 rot = Rotate(i, Vector3f(1, 0, 0));
		Matrix4 rot1 = Rotate(i, Vector3f(0, 1, 0));
		cubeMesh->SetRotation(rot * rot1);

		cubeMesh->Draw();

		window.Update();
	}

	return 1;
}