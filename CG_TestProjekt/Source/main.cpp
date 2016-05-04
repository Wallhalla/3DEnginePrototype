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
				
	//StaticSprite2D sprite1 = StaticSprite2D(Vector3f(0,0,0), Vector2f(2, 2));

	Circle2D circle = Circle2D(5, Vector3f(), 20);

	GLuint projection = glGetUniformLocation(shader.shaderProgramID, "projectionMatrix");
	glUniformMatrix4fv(projection, 1, GL_FALSE, perspective.Elements);

	GLuint model = glGetUniformLocation(shader.shaderProgramID, "modelMatrix");
	glUniformMatrix4fv(model, 1, GL_FALSE, Translate(Vector3f(5,5,-1.5f)).Elements);
		
	while (!window.WasWindowClosed())
	{
		window.Clear();	
		
		circle.Draw();

		window.Update();
	}

	return 1;
}