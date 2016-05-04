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

	VAO = new VertexArray();
	VAO->Enable();

	VAO->ConnectBufferToShaderAttribute(new Buffer(vertices.data(), sizeof(Vector3f) * vertices.size(), 3), EShaderAttributes::POSITION);
	
	VAO->Disable();
}

Circle2D::~Circle2D()
{	
	delete VAO;
}

void Circle2D::Draw()
{
	VAO->Enable();	

	// Malen
	glDrawArrays(GL_TRIANGLE_FAN, 0, numVertices);	

	VAO->Disable();
}