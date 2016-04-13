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
		//// Back Face
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

	// Store number of vertices
	numVertices = sizeof(vertices) / sizeof(vertices[0]);

	// Create GPU Buffer
	buffer = new Buffer(vertices, sizeof(vertices));
	
	// Make it active
	buffer->Enable();

	// Bind it to VertexShader Location 0
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size (how many indices define one component) 3 = Vector3
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		0					// array buffer offset
		);

	buffer->Disable();
}

Cube::~Cube()
{
	delete buffer;
}

void Cube::Draw()
{
	buffer->Enable();

	// Malen
	glDrawArrays(GL_TRIANGLES, 0, numVertices);

	buffer->Disable();
}