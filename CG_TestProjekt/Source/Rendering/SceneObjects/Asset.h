#pragma once

#include "GL/glew.h"

#include "FancyLib/FancyMath.h"
#include "../Helpers/Colors.h"

#include "../../Buffer/BuffersHeader.h"
#include "../../Shader/ShaderProgram.h"

#include "../Textures/Texture2D.h"

struct VertexData
{
	FancyMath::Vector3f position;
	FancyMath::Vector4f color;
	FancyMath::Vector2f texCoord;
	FancyMath::Vector3f normal;

	VertexData(
		FancyMath::Vector3f inPos = FancyMath::Vector3f(),
		FancyMath::Vector4f inColor = FancyMath::Vector4f(0.5f, 0.5f, 0.5f, 1),
		FancyMath::Vector2f inTexCoord = FancyMath::Vector2f(),
		FancyMath::Vector3f inNormal = FancyMath::Vector3f()
		);
};

struct QuadFace
{
	VertexData vertices[6];

	QuadFace();
	QuadFace(VertexData inCorners[4]);
	QuadFace(
		FancyMath::Vector3f vert1,
		FancyMath::Vector3f vert2,
		FancyMath::Vector3f vert3,
		FancyMath::Vector3f vert4,
		FancyMath::Vector4f faceColor = Color::White);

};

struct ModelAsset
{
	friend class SceneInstance;


public:
	ModelAsset(ShaderProgram* program);
	virtual ~ModelAsset(){};

private:
	ShaderProgram* shaderProgram;

protected:
	VertexArray* vao;
	Buffer* vbo;
	Texture2D* texture;

	GLenum drawType;
	GLuint numVertices;

private:
	const ShaderProgram* GetShader() const;

	virtual void Draw() const = 0;
};