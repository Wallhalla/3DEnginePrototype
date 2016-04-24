#include "Window/Window.h"
using namespace CG;

#include "Shader/ShaderProgram.h"
#include "StaticSprite2D.h"

#include "Renderables/Circle2D.h"
#include "Renderables/Cube.h"


#include "FancyLib/FancyMath.h"
using namespace FancyMath;

#define WINDOWSIZE_X 800
#define WINDOWSIZE_Y 600

int main()
{
	Window window("Einfuehrung Computergrafik", WINDOWSIZE_Y, WINDOWSIZE_Y);	
	
	Matrix4 ortho = FancyMath::OrthographicMatrix(0, 10, 0, 10, 0.1f, 10);

	Matrix4 translation = Translate(Vector3f(5, 5, -1));
	Matrix4 rotation = Rotate(45.0f, Vector3f(0, 0, 1));
		
	ShaderProgram shader = ShaderProgram(
		"Source/Shader/ShaderFiles/BasicShader.vertexShader",
		"Source/Shader/ShaderFiles/BasicShader.fragmentShader");
	shader.Enable();	
				
	StaticSprite2D sprite1 = StaticSprite2D(Vector3f(0,0,0), Vector2f(2, 2));
		
	while (!window.WasWindowClosed())
	{
		window.Clear();	
		
		sprite1.Draw();

		window.Update();
	}

	return 1;
}