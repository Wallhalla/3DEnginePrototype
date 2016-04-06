#include "Window/Window.h"
using namespace CG;

#include "Shader/Shader.h"

#include "FancyLib/FancyMath.h"
#include "FancyLib/Math/Vector3f.h"
using namespace FancyMath;

#include "Rendering/SimpleRenderable2D.h"
#include "Rendering/SimpleCube.h"

#include "Camera/Camera.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"


#include "../SimpleTriangle.h"

#include "FancyLib/FancyUtils.h"

int main()
{
	Window window("Einfuehrung Computergrafik", 800, 600);	


	//FancyUtils::FancyFileManager::ReadFromFile

	/*const char* vertexShaderSource = 
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

	glUseProgram(shaderProgram);*/

	//Shader shader("Source/Shader/ShaderFiles/BasicShader.vertexshader", "Source/Shader/ShaderFiles/BasicShader.fragmentshader");
	//shader.Enable();	
	//
	//// 3D World Projection
	//Matrix4 persp = PerspectiveMatrix(45.0f, (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);

	//// 2D World Projection
	//Matrix4 ortho = OrthographicMatrix(-1, 1, -1, 1, -1, 1);

	//Matrix4 view = Camera(Vector3f(0,0,1), Vector3f(0, 0, 0), Vector3f(0, 1, 0)).GetCameraMatrix();		
	//	
	//SimpleCube cube = SimpleCube();
	//Matrix4 model = Translate(Vector3f(0, 0, 0));
	//Matrix4 MV = persp * view;	
	
	//// Enable depth test
	//glEnable(GL_DEPTH_TEST);
	//// Accept fragment if it closer to the camera than the former one
	//glDepthFunc(GL_LESS);

	/*GLfloat vertices[] =
	{
		-1,-1,0,
		1,-1,0,
		0,1,0
	};*/

	/*GLuint vbo;
	glCreateBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);*/


	SimpleTriangle triangle = SimpleTriangle();
	
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(
	//	0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	//	3,                  // size
	//	GL_FLOAT,           // type
	//	GL_FALSE,           // normalized?
	//	0,                  // stride
	//	0           // array buffer offset
	//	);

	
	while (!window.WasWindowClosed())
	{
		window.Clear();
		
		triangle.Draw();

		window.Update();
	}

	return 1;
}