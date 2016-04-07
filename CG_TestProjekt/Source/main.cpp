#include "Window/Window.h"
using namespace CG;

#include "Shader/Shader.h"

#include "FancyLib/FancyMath.h"
#include "FancyLib/Math/Vector3f.h"
using namespace FancyMath;

#include "SimpleTriangle.h"

int main()
{
	Window window("Einfuehrung Computergrafik", 800, 600);	
		
	const char* vertexShaderSource = 
	"#version 330 core\n\
	\
	layout(location = 0) in vec3 vertexPosition;\
	\
	void main()\
	{\
		gl_Position = vec4(vertexPosition, 1);\
	}";

	const char* fragmentShaderSource =
		"#version 330 core\n\
		\
		layout(location = 0) out vec4 color;\
		\
		void main()\
		{\
			color = vec4(1, 0, 1, 1);\
		}";

	GLuint shaderProgram = 0;

	shaderProgram = glCreateProgram();

	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShaderID);
	
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShaderID);

	glAttachShader(shaderProgram, vertexShaderID);
	glAttachShader(shaderProgram, fragmentShaderID);

	glLinkProgram(shaderProgram);

	glValidateProgram(shaderProgram);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	glUseProgram(shaderProgram);
	
	SimpleTriangle triangle = SimpleTriangle();
	
	while (!window.WasWindowClosed())
	{
		window.Clear();
		
		triangle.Draw();

		window.Update();
	}

	return 1;
}