#include "Cube.h"

#include <iostream>
Cube::Cube()
{
	GLfloat vertices[] =
	{
		// Front Face
		0, 0, 0,
		1, 0, 0,
		1, 1, 0,
		1, 1, 0,
		0, 1, 0,
		0, 0, 0,
		// Back Face
		0, 0, -1,
		1, 0, -1,
		1, 1, -1,
		1, 1, -1,
		0, 1, -1,
		0, 0, -1,
		// Top Face
		0, 1, 0,
		1, 1, 0,
		1, 1, -1,
		1, 1, -1,
		0, 1, -1,
		0, 1, 0,
		// Bottom Face
		0, 0, 0,
		1, 0, 0,
		1, 0, -1,
		1, 0, -1,
		0, 0, -1,
		0, 0, 0,
		// Left Face
		0, 0, 0,
		0, 0, -1,
		0, 1, -1,
		0, 1, -1,
		0, 1, 0,
		0, 0, 0,
		// Right Face
		1, 0, 0,
		1, 0, -1,
		1, 1, -1,
		1, 1, -1,
		1, 1, 0,
		1, 0, 0
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

Cube::~Cube()
{

}

void Cube::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Malen
	glDrawArrays(GL_TRIANGLES, 0, 12);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}