#pragma once

#include "GL/glew.h"
#include "../../Buffer/BuffersHeader.h"

class Cube
{

private:
	VertexArray* vao;	
	GLuint numVertices;
public:
	Cube();
	~Cube();

	void Draw();
};