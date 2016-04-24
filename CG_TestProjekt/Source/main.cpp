#include "Window/Window.h"
using namespace CG;

#include "Shader/ShaderProgram.h"
#include "SimpleTriangle.h"

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

	Matrix4 translation = Translate(Vector3f(0,0, 0));
		
	ShaderProgram shader = ShaderProgram(
		"Source/Shader/ShaderFiles/BasicShader.vertexShader",
		"Source/Shader/ShaderFiles/BasicShader.fragmentShader");
	shader.Enable();	

	glUniformMatrix4fv(
		glGetUniformLocation(shader.shaderProgramID,"projectionMatrix"), 
		1,
		GL_FALSE, 
		ortho.Elements);

	/*glUniformMatrix4fv(
		glGetUniformLocation(shader.shaderProgramID, "modelMatrix"),
		1,
		GL_FALSE, 
		translation.Elements);*/

	Circle2D circle = Circle2D(1, Vector3f(2.5f, 7.5f, -1.0f), 20);
	
	while (!window.WasWindowClosed())
	{
		window.Clear();
		
		circle.Draw();

		window.Update();
	}

	return 1;
}