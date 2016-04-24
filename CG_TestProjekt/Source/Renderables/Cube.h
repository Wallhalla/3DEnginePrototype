#pragma once

#include "GL/glew.h"
#include "../Buffer/Buffer.h"

class Cube
{

private:
	GLuint vao;
	Buffer* buffer;
	GLuint numVertices;
public:
	Cube();
	~Cube();

	void Draw();
};