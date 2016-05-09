#include "Window/Window.h"
using namespace CG;

#include "Shader/ShaderProgram.h"

#include "Rendering/SceneObjects/SceneInstance.h"

#include "Camera/Camera.h"


#include "FancyLib/FancyMath.h"
using namespace FancyMath;

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
				
	shader.SetUniformMatrix4("projection_matrix", perspective);
	//shader->Disable();
	
	SceneInstance* cubeMesh = new SceneInstance(&shader, std::string("Cube"));

	cubeMesh->SetLocation(Vector3f(0, 0, -10));

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

		cubeMesh->Draw();

		window.Update();
	}

	return 1;
}