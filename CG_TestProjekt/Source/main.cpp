#include "Window/Window.h"
using namespace CG;

#include "Shader/ShaderProgram.h"
#include "Rendering/DefaultRenderables/StaticSprite2D.h"

#include "Rendering/DefaultRenderables/Circle2D.h"
#include "Rendering/DefaultRenderables/Cube.h"

#include "Camera/Camera.h"


#include "FancyLib/FancyMath.h"
using namespace FancyMath;

#define WINDOWSIZE_X 800
#define WINDOWSIZE_Y 600
#define ASPECT_RATIO (float)(WINDOWSIZE_X / WINDOWSIZE_Y)

int main()
{
	Window window("Einfuehrung Computergrafik", WINDOWSIZE_Y, WINDOWSIZE_Y);	
	
	Matrix4 perspective = FancyMath::PerspectiveMatrix(45, ASPECT_RATIO, 1, 10);
	//perspective.Collumns[1].Y = 0.75f;
	Camera camera = Camera(Vector3f(0, 0,3), Vector3f(0, 0, 0), Vector3f(0, 1, 0));

	ShaderProgram shader = ShaderProgram(
		"Source/Shader/ShaderFiles/BasicShader.vertexShader",
		"Source/Shader/ShaderFiles/BasicShader.fragmentShader");
	shader.Enable();	
				
	StaticSprite2D sprite = StaticSprite2D(Vector3f(0,0,0), Vector2f(1, 1));
	Matrix4 spriteModel = Translate(Vector3f(-4, -4, -3.5));

	Circle2D circle = Circle2D(2, Vector3f(), 50);	
		
	shader.SetUniformMatrix4("projection_matrix", perspective);
	shader.SetUniformMatrix4("view_matrix", camera.GetViewMatrix());

	
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

		//Matrix4 modelMatrix = Rotate(i, Vector3f(0, 0, 1)) * Translate(Vector3f(5, 5, -1.5f));
		Matrix4 modelMatrix = Translate(Vector3f(0, 0, -3.5f)) * Rotate(i,Vector3f(0,1,0));
		shader.SetUniformMatrix4("model_matrix", modelMatrix);
		circle.Draw();

		shader.SetUniformMatrix4("model_matrix", spriteModel);
		sprite.Draw();
		

		window.Update();
	}

	return 1;
}