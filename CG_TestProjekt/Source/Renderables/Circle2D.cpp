#include "Circle2D.h"

#include <math.h>
#define PI 3.14159265359

#include <vector>

using namespace FancyMath;

Circle2D::Circle2D(float radius, FancyMath::Vector3f position, unsigned int numTriangles)
{
	std::vector<GLfloat> vertices;

	vertices.push_back(position.X);
	vertices.push_back(position.Y);
	vertices.push_back(position.Z);	
		
	for (unsigned int i = 0; i <= 1; ++i)
	{
		Vector3f vec(
			position.X + (radius * (float)cos(i * 2 * PI / numTriangles)),
			position.Y + (radius * (float)sin(i * 2 * PI / numTriangles)),
			position.Z);	

		vertices.push_back(vec.X);
		vertices.push_back(vec.Y);
		vertices.push_back(vec.Z);
	}	

	numVertices = vertices.size();

	GLfloat* vertArray = &vertices[0];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	buffer = new Buffer(vertArray, sizeof(GLfloat) * vertices.size());

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

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
	
}

Circle2D::~Circle2D()
{
	delete buffer;
}

void Circle2D::Draw()
{
	glBindVertexArray(vao);
	buffer->Enable();

	// Malen
	glDrawArrays(GL_TRIANGLE_FAN, 0, numVertices);

	buffer->Disable();

	glBindVertexArray(0);
}