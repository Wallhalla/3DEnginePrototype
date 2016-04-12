#pragma once

#include "GL/glew.h"
#include "../Buffer/Buffer.h"

class Cube
{

private:
	Buffer* buffer;
	GLuint numVertices;
public:
	Cube();
	~Cube();

	void Draw();
};