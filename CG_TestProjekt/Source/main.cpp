#include "Window/Window.h"
using namespace CG;

#include "Shader/Shader.h"

#include "FancyLib/FancyMath.h"
using namespace FancyMath;

#include "Rendering/Renderable2D.h"

#include "Camera/Camera.h"

void SimpleBufferPrep();

int main()
{
	Window window("Einfuehrung Computergrafik", 800, 600);	
	
	Matrix4 persp = PerspectiveMatrix(ToRadians(45.0f), (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);
	Matrix4 ortho = OrthographicMatrix(0,16,0,16,-1,1);

	Shader shader("Source/Shader/ShaderFiles/BasicShader.vertexshader", "Source/Shader/ShaderFiles/BasicShader.fragmentshader");
	shader.Enable();

	shader.SetUniform_Matrix4("projection", persp);

	Camera camera = Camera(Vector3f(8, 4, 3), Vector3f(0, 0, 0), Vector3f(0, 1, 0));
	shader.SetUniform_Matrix4("view", camera.GetCameraMatrix());	

	
	
	Renderable2D renderable = Renderable2D(Vector3f(0,0,0), Vector2f(1, 1));
	//shader.SetUniform_Matrix4("modelview", renderable.GetModelView());

	shader.SetUniform_Vector4f("triangleColor", Vector4f(1.0f, 0.0f, 0.0f, 1.0f));

	while (!window.WasWindowClosed())
	{
		window.Clear();

		renderable.Draw();

		window.Update();
	}

	return 1;
}


void SimpleBufferPrep()
{
	GLfloat vertices[] =
	{
		4, 4, 0.0f, // bottom left
		12, 4, 0.0f,	// bottom right
		8, 12, 0.0f	// top
	};

	// 1. Step = prepare vertex data

	// Create Buffer ID for a Drawable
	GLuint vbo;
	glGenBuffers(1, &vbo);

	// Bind this buffer as an Array_Buffer type in OpenGL
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Bind the actual Buffer Data to the current bound Buffer (= vbo)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Now its stored on the gpu

	// 2. Step = tell shaders which data to use

	/*
	param1: the index location within the shader
	param2: the number of elements which define 1 vertex (here 3 for VertexXYZ)
	param3: the type of the vertexData (here floats)
	param4:
	*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);
}