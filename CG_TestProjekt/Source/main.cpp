#include "Window/Window.h"
using namespace CG;

#include "Shader/ShaderProgram.h"
#include "Rendering/DefaultRenderables/StaticSprite2D.h"

#include "Rendering/DefaultRenderables/Circle2D.h"
#include "Rendering/DefaultRenderables/Cube.h"


#include "FancyLib/FancyMath.h"
using namespace FancyMath;

#define WINDOWSIZE_X 800
#define WINDOWSIZE_Y 600
#define ASPECT_RATIO (float)WINDOWSIZE_X / (float)WINDOWSIZE_Y

int main()
{
	Window window("Einfuehrung Computergrafik", WINDOWSIZE_Y, WINDOWSIZE_Y);	
	
	Matrix4 perspective = FancyMath::OrthographicMatrix(0,10,0,10,1,10);

	ShaderProgram shader = ShaderProgram(
		"Source/Shader/ShaderFiles/BasicShader.vertexShader",
		"Source/Shader/ShaderFiles/BasicShader.fragmentShader");
	shader.Enable();	
				
	StaticSprite2D sprite = StaticSprite2D(Vector3f(0,0,0), Vector2f(1, 1));
	//Circle2D circle = Circle2D(5, Vector3f(), 20);	
	
	Matrix4 modelMatrix = Scale(Vector3f(0.5f, 0.5, 0.5f));

	shader.SetUniformMatrix4("modelMatrix", modelMatrix);

	
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
		if (i > 45)
		{
			start = false;
		}
		else if (i < 0)
		{
			start = true;
		}

		window.Clear();	

		//Matrix4 modelMatrix = Rotate(i, Vector3f(0, 0, 1)) * Translate(Vector3f(5, 5, -1.5f));
		
				
		sprite.Draw();
		

		window.Update();
	}

	return 1;
}