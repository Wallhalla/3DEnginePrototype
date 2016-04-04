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

int main()
{
	Window window("Einfuehrung Computergrafik", 800, 600);	

	Shader shader("Source/Shader/ShaderFiles/BasicShader.vertexshader", "Source/Shader/ShaderFiles/BasicShader.fragmentshader");
	shader.Enable();	
	
	// 3D World Projection
	Matrix4 persp = PerspectiveMatrix(45.0f, (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);

	// 2D World Projection
	Matrix4 ortho = OrthographicMatrix(-1, 1, -1, 1, -1, 1);

	Matrix4 view = Camera(Vector3f(0,0,1), Vector3f(0, 0, 0), Vector3f(0, 1, 0)).GetCameraMatrix();		
		
	SimpleCube cube = SimpleCube();
	Matrix4 model = Translate(Vector3f(0, 0, 0));
	Matrix4 MV = persp * view;	
	
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	int max = 10;
	Matrix4 MVP(1);
	float x = 0.0f;
	bool forward = true;
	while (!window.WasWindowClosed())
	{
		window.Clear();
		
		model = Translate(Vector3f(0, 0, 0));
		MVP = MV * model;
		shader.SetUniform_Matrix4("mvp_matrix", MVP);
		cube.Draw();

		window.Update();
	}

	return 1;
}