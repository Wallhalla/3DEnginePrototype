#pragma once

#include "GL/glew.h"
class Cube
{

private:
	GLuint vbo;
public:
	Cube();
	~Cube();

	void Draw();
};