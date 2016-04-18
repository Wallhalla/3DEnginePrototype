#include "SimpleTriangle.h"


SimpleTriangle::SimpleTriangle()
{
	GLfloat vertices[] =
	{
		-1,-1,0,
		1,-1,0,
		0,1,0
	};

	buffer = new Buffer(vertices, sizeof(vertices));

	buffer->Enable();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		0					// array buffer offset
		);

	buffer->Disable();
}

SimpleTriangle::~SimpleTriangle()
{
	delete buffer;
}

void SimpleTriangle::Draw()
{
	buffer->Enable();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	buffer->Disable();
}