#include "Window/Window.h"
using namespace CG;

#include "Shader/ShaderProgram.h"
#include "SimpleTriangle.h"

int main()
{
	Window window("Einfuehrung Computergrafik", 800, 600);	
		
	ShaderProgram shader = ShaderProgram(
		"Source/Shader/ShaderFiles/BasicShader.vertexShader",
		"Source/Shader/ShaderFiles/BasicShader.fragmentShader");
	shader.Enable();
	SimpleTriangle triangle = SimpleTriangle();

	
	
	while (!window.WasWindowClosed())
	{
		window.Clear();
		
		triangle.Draw();

		window.Update();
	}

	return 1;
}