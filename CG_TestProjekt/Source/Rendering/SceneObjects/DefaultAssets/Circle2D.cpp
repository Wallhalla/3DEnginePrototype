#include "Circle2D.h"

#include <math.h>
#define PI 3.14159265359

#include <vector>

using namespace FancyMath;

Circle2D::Circle2D(float radius, FancyMath::Vector3f position, unsigned int numTriangles)
	: ModelAsset(nullptr)
{
	std::vector<VertexData> vertices;

	vertices.push_back(VertexData());	
		
	for (unsigned int i = 0; i <= numTriangles; i++)
	{
		VertexData vertex = VertexData();

		vertex.position = Vector3f(
			radius * (float)cos(i * 2 * PI / numTriangles),
			radius * (float)sin(i * 2 * PI / numTriangles),
			0);

		vertices.push_back(vertex);
	}		

	numVertices = vertices.size();
	drawType = GL_TRIANGLE_FAN;

	vao = new VertexArray();
	vao->Enable();

	vbo = new Buffer(vertices.data(), sizeof(VertexData) * vertices.size());

	vao->ConnectBufferToShaderAttribute(
		vbo,
		sizeof(Vector3f) / sizeof(GLfloat),
		EShaderAttributes::POSITION,
		sizeof(VertexData),
		(GLvoid*)(0));
	
	
	vao->ConnectBufferToShaderAttribute(
		vbo,
		sizeof(Vector4f) / sizeof(GLfloat),
		EShaderAttributes::COLOR,
		sizeof(VertexData),
		(GLvoid*)offsetof(VertexData, VertexData::position));
	
	vao->Disable();
}

Circle2D::~Circle2D()
{	
	delete vao;
	delete vbo;
}

void Circle2D::Draw()
{
	vao->Enable();	

	// Malen
	glDrawArrays(drawType, 0, numVertices);	

	vao->Disable();
}