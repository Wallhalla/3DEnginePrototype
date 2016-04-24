#include "SimpleTriangle.h"


SimpleTriangle::SimpleTriangle()
{
	GLfloat vertices[] =
	{
		-1,-1,0,
		1,-1,0,
		1,1,0,
		-1,1,0
	};

	GLuint indices[] =
	{
		0,1,2,0,2,3
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,	GL_STATIC_DRAW);


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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

SimpleTriangle::~SimpleTriangle()
{
	delete buffer;
}

void SimpleTriangle::Draw()
{
	glBindVertexArray(vao);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	/*buffer->Enable();*/

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//buffer->Disable();
	glBindVertexArray(0);
}