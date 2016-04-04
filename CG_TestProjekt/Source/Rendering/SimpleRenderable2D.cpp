#include "SimpleRenderable2D.h"

using namespace CG;
using namespace FancyMath;

SimpleRenderable2D::SimpleRenderable2D(FancyMath::Vector3f inLocation, FancyMath::Vector2f inSize)
	:position(inLocation), size(inSize)
{

	float xPos = position.X;
	float yPos = position.Y;
	float zPos = position.Z;

	GLfloat vertices[] =
	{
		xPos,			yPos,	zPos,
		xPos + size.X,	yPos,	zPos,
		xPos,	yPos + size.Y,	zPos,
		xPos + size.X, yPos + size.Y, zPos
	};

	GLushort indices[] =
	{
		0,1,2,2,1,3
	};

	vao = new VertexArray();
	vao->AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	ibo = new IndexBuffer(indices, 6);
}

SimpleRenderable2D::~SimpleRenderable2D()
{
	delete vao;
	delete ibo;
}

void SimpleRenderable2D::Draw() const
{
	vao->Bind();
	ibo->Bind();

	glDrawElements(GL_TRIANGLES, ibo->GetCount(), GL_UNSIGNED_SHORT, 0);

	ibo->Unbind();
	vao->Unbind();
}

Matrix4 SimpleRenderable2D::GetModelView() const
{
	Matrix4 result = IdentityMatrix();

	result = result * Translate(position);

	return result;

}