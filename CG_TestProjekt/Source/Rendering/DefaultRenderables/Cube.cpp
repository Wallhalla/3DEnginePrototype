#include "Cube.h"

#include "../Helpers/Colors.h"
#include "FancyLib/FancyMath.h"
using namespace FancyMath;

#include <iostream>
Cube::Cube()
{
	Vector3f vertices[] =
	{
		// Front Face
		Vector3f(0, 0, 0),
		Vector3f(1, 0, 0),
		Vector3f(1, 1, 0),
		Vector3f(1, 1, 0),
		Vector3f(0, 1, 0),
		Vector3f(0, 0, 0),
		//// Back Face
		Vector3f(0, 0, -1),
		Vector3f(1, 0, -1),
		Vector3f(1, 1, -1),
		Vector3f(1, 1, -1),
		Vector3f(0, 1, -1),
		Vector3f(0, 0, -1),
		// Top Face
		Vector3f(0, 1, 0),
		Vector3f(1, 1, 0),
		Vector3f(1, 1, -1),
		Vector3f(1, 1, -1),
		Vector3f(0, 1, -1),
		Vector3f(0, 1, 0),
		// Bottom Face
		Vector3f(0, 0, 0),
		Vector3f(1, 0, 0),
		Vector3f(1, 0, -1),
		Vector3f(1, 0, -1),
		Vector3f(0, 0, -1),
		Vector3f(0, 0, 0),
		// Left Face
		Vector3f(0, 0, 0),
		Vector3f(0, 0, -1),
		Vector3f(0, 1, -1),
		Vector3f(0, 1, -1),
		Vector3f(0, 1, 0),
		Vector3f(0, 0, 0),
		// Right Face
		Vector3f(1, 0, 0),
		Vector3f(1, 0, -1),
		Vector3f(1, 1, -1),
		Vector3f(1, 1, -1),
		Vector3f(1, 1, 0),
		Vector3f(1, 0, 0)
	};

	Vector4f colors[] =
	{
		// Front Face
		Color::Red,
		Color::Red,
		Color::Red,
		Color::Red,
		Color::Red,
		Color::Red,
		// Back Face
		Color::White,
		Color::White,
		Color::White,
		Color::White,
		Color::White,
		Color::White,
		// Top Face
		Color::Blue,
		Color::Blue,
		Color::Blue,
		Color::Blue,
		Color::Blue,
		Color::Blue,
		// Bottom Face
		Color::Magenta,
		Color::Magenta,
		Color::Magenta,
		Color::Magenta,
		Color::Magenta,
		Color::Magenta,		
		// Left Face
		Color::Cyan,
		Color::Cyan,
		Color::Cyan,
		Color::Cyan,
		Color::Cyan,
		Color::Cyan,
		// Right Face
		Color::Yellow,
		Color::Yellow,
		Color::Yellow,
		Color::Yellow,
		Color::Yellow,
		Color::Yellow
		
	};


	// Store number of vertices
	numVertices = sizeof(vertices) / sizeof(vertices[0]);

	vao = new VertexArray();
	vao->Enable();

	// Create GPU Buffer Positions
	vao->ConnectBufferToShaderAttribute(
		new Buffer(vertices, sizeof(vertices), 3), 
		EShaderAttributes::POSITION);

	vao->ConnectBufferToShaderAttribute(
		new Buffer(colors, sizeof(colors), 4),
		EShaderAttributes::COLOR);

	vao->Disable();
}

Cube::~Cube()
{
	delete vao;
}

void Cube::Draw()
{
	vao->Enable();

	// Malen
	glDrawArrays(GL_TRIANGLES, 0, numVertices);

	vao->Disable();
}