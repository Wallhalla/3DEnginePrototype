#pragma once

#include "GL/glew.h"
#include "../../../Buffer/BuffersHeader.h"

#include "../Asset.h"

struct Cube : public ModelAsset
{
public:
	Cube(ShaderProgram* inShaderProgram);
	~Cube();

	void Draw() const override;

private:
	void SetFaceNormal(QuadFace& face, FancyMath::Vector3f normal);

};