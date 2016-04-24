#pragma once

#include "GL/glew.h"

class IndexBuffer
{
private:
	GLuint iboID;

public:
	IndexBuffer(GLuint* indicesArray, GLsizeiptr arrayByteSize);
	~IndexBuffer();

	void Enable();
	void Disable();

};

