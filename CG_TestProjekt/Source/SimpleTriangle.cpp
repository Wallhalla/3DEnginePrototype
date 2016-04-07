#include "SimpleTriangle.h"


SimpleTriangle::SimpleTriangle()
{
	GLfloat vertices[] =
	{
		-1,-1,0,
		1,-1,0,
		0,1,0,
		/*0,-1,0,
		1,-1,0,
		0.5,1,0*/

	};

	glGenBuffers(1, &vbo);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		0					// array buffer offset
		);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

SimpleTriangle::~SimpleTriangle()
{
	glDeleteBuffers(1, &vbo);
}

void SimpleTriangle::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);	

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}