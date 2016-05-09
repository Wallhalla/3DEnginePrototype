#include "Cube.h"

#include "../../Helpers/Colors.h"
#include "FancyLib/FancyMath.h"
using namespace FancyMath;

#include <iostream>
Cube::Cube(ShaderProgram* inShaderProgram)
	:ModelAsset(inShaderProgram)
{
	texture = new Texture2D("Content/Images/Koala.jpg");

	Vector3f vertexPositions[] =
	{
		Vector3f(-1, -1, 1),	// 0 - Front, Bot-Left
		Vector3f(1, -1, 1),		// 1 - Front, Bot-Right
		Vector3f(1, 1, 1),		// 2 - Front, Top-Right
		Vector3f(-1, 1, 1),		// 3 - Front, Top-Left
		Vector3f(1, -1, -1),	// 4 - Back, Bot-Right
		Vector3f(-1, -1, -1),	// 5 - Back, Bot-Left
		Vector3f(-1, 1, -1),	// 6 - Back, Top-Left
		Vector3f(1, 1, -1)		// 7 - Back, Top-Right
	};

	GLushort indices[] =
	{
		// Frontface
		0, 1, 2, 2, 3, 0,
		// Backface
		4, 5, 6, 6, 7, 4,
		// Topface
		3, 2, 7, 7, 6, 3,
		// Botface
		5, 4, 1, 1, 0, 5,
		// Leftface
		5, 0, 3, 3, 6, 5,
		// Rightface
		1, 4, 7, 7, 2, 1
	};

	Vector4f faceColors[] =
	{
		Color::Grey,
		Color::Blue,
		Color::Green,
		Color::Yellow,
		Color::Cyan,
		Color::Magenta
	};

	numVertices = 36;

	QuadFace faces[6];

	int colorIndex = 0;
	int faceIndex = 0;
	for (int i = 0; i < numVertices; i += 6)
	{
		faces[faceIndex] = QuadFace(
			vertexPositions[indices[i]],
			vertexPositions[indices[i + 1]],
			vertexPositions[indices[i + 2]],
			vertexPositions[indices[i + 4]],
			faceColors[colorIndex]);

		colorIndex++;
		faceIndex++;
	}

	vbo = new Buffer(faces, sizeof(QuadFace) * 6);

	vao = new VertexArray();
	vao->Enable();

	// Create GPU Buffer Positions
	vao->ConnectBufferToShaderAttribute(
		vbo,
		3,
		EShaderAttributes::POSITION,
		sizeof(VertexData),
		(GLvoid*)(0)
		);

	vao->ConnectBufferToShaderAttribute(
		vbo,
		4,
		EShaderAttributes::COLOR,
		sizeof(VertexData),
		(GLvoid*)(offsetof(VertexData, VertexData::color))
		);

	vao->ConnectBufferToShaderAttribute(
		vbo,
		4,
		EShaderAttributes::TEXCOORD,
		sizeof(VertexData),
		(GLvoid*)(offsetof(VertexData, VertexData::texCoord))
		);

	vao->Disable();
}

Cube::~Cube()
{
	delete vao;
	delete vbo;
}

void Cube::Draw() const
{
	texture->Enable();
	vao->Enable();

	// Malen
	glDrawArrays(GL_TRIANGLES, 0, numVertices);

	vao->Disable();
	texture->Disable();
}