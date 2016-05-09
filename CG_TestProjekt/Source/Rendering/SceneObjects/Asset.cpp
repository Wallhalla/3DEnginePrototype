#include "Asset.h"
using namespace FancyMath;


VertexData::VertexData(
	Vector3f inPos,
	Vector4f inColor,
	Vector2f inTexCoord,
	Vector3f inNormal)
	: position(inPos), color(inColor), texCoord(inTexCoord), normal(inNormal)
{
}

QuadFace::QuadFace()
{

}

QuadFace::QuadFace(VertexData invertices[4])
{
	vertices[0] = invertices[0];
	vertices[1] = invertices[1];
	vertices[2] = invertices[2];
	vertices[3] = invertices[3];
}

QuadFace::QuadFace(
	Vector3f vert1,
	Vector3f vert2,
	Vector3f vert3,
	Vector3f vert4,
	Vector4f faceColor)
{
	
	vertices[0] = VertexData(vert1, faceColor, Vector2f(0,0));
	vertices[1] = VertexData(vert2, faceColor, Vector2f(1,0));
	vertices[2] = VertexData(vert3, faceColor, Vector2f(1,1));
	vertices[3] = VertexData(vert3, faceColor, Vector2f(1,1));
	vertices[4] = VertexData(vert4, faceColor, Vector2f(0,1));
	vertices[5] = VertexData(vert1, faceColor, Vector2f(0,0));
}

ModelAsset::ModelAsset(ShaderProgram* program)
{
	shaderProgram = program;
}

const ShaderProgram* ModelAsset::GetShader() const
{
	return shaderProgram;
}