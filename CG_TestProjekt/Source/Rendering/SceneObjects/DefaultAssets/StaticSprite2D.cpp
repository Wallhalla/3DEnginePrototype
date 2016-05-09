#include "StaticSprite2D.h"

using namespace FancyMath;

StaticSprite2D::StaticSprite2D(Vector3f position, Vector2f(size))
{
	GLfloat vertices[] =
	{
		-1, -1,  0,		// Bottom Left
		 1,	-1,  0,		// Bottom Right
		 1,	 1,	 0,		// Top Right
		-1,  1,	 0		// Top Left
	};

	GLuint indices[] =
	{
		0, 1, 2, 0, 2, 3
	};

	vao = new VertexArray();
	vao->Enable();

	ibo = new IndexBuffer(indices, sizeof(indices));
	ibo->Enable();

	vao->ConnectBufferToShaderAttribute(
		new Buffer(vertices, sizeof(vertices)),
		3,
		EShaderAttributes::POSITION);

	ibo->Disable();

	vao->Disable();
}

StaticSprite2D::~StaticSprite2D()
{
	delete vao;
	delete ibo;
}

void StaticSprite2D::Draw()
{
	vao->Enable();
	ibo->Enable();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	ibo->Disable();
	vao->Disable();
}