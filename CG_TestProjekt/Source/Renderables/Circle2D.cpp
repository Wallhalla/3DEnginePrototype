#include "Circle2D.h"

#include <math.h>
#define PI 3.14159265359

#include <vector>

using namespace FancyMath;

Circle2D::Circle2D(float radius, FancyMath::Vector3f position, unsigned int numTriangles)
{
	std::vector<Vector3f> vertices;

	vertices.push_back(Vector3f());
	
		
	for (unsigned int i = 0; i <= numTriangles; i++)
	{
		vertices.push_back(
			Vector3f(
			radius * (float)cos(i * 2 * PI / numTriangles),
			radius * (float)sin(i * 2 * PI / numTriangles),
			0)
			);	
	}		

	numVertices = vertices.size();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vector3f) * vertices.size(), vertices.data(), GL_STATIC_DRAW);	

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
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void Circle2D::Draw()
{
	glBindVertexArray(vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Malen
	glDrawArrays(GL_TRIANGLE_FAN, 0, numVertices);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);
}