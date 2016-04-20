#include "Window/Window.h"
using namespace CG;

#include "Shader/ShaderProgram.h"
#include "SimpleTriangle.h"

#include "Renderables/Circle2D.h"
#include "Renderables/Cube.h"


#include "FancyLib/FancyMath.h"
using namespace FancyMath;


int main()
{
	Window window("Einfuehrung Computergrafik", 800, 600);	
		
	ShaderProgram shader = ShaderProgram(
		"Source/Shader/ShaderFiles/BasicShader.vertexShader",
		"Source/Shader/ShaderFiles/BasicShader.fragmentShader");
	shader.Enable();
	SimpleTriangle triangle = SimpleTriangle();

	Circle2D circle = Circle2D(1, Vector3f(0, 0, 0), 20);

	Cube cube;
	
	while (!window.WasWindowClosed())
	{
		window.Clear();
		
		circle.Draw();		

		window.Update();
	}

	return 1;
}