#pragma once

#include "GL/glew.h"

class Buffer
{
private:
	GLuint vboID;
	GLuint bufferType;

public:
	/*
	 * @param1: array of buffer elements
	 * @param2: size of array in BYTES! not in Elements
	 * 
	 * @param3 (optional): the type of this buffer, default is GL_ARRAY_BUFFER
	 *
	 * @param4 (optional): 
	 * define the memory storage type of the buffered data
	 * GL_STATIC_DRAW (default) -> for data which rarely changes
	 * GL_DYNAMIC_DRAW -> for data which changes more often
	 * GL_STREAM_DRAW -> for data which probably changes fast (f.e. every frame)
	 */
	Buffer(
		GLfloat* inBufferData, 
		GLsizeiptr inBufferElementsSize,
		GLenum inBufferType = GL_ARRAY_BUFFER, 
		GLenum inMemoryMode = GL_STATIC_DRAW);

	~Buffer();

	/* Enable this Buffer and Type to the current used on the GPU */
	void Enable();
	/* Disable this Buffer to free the type on GPU */
	void Disable();
};