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

};