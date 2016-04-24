#include "IndexBuffer.h"


IndexBuffer::IndexBuffer(GLuint* indicesArray, GLsizeiptr arrayByteSize)
{
	glGenBuffers(1, &iboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, arrayByteSize, indicesArray, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &iboID);
}

void IndexBuffer::Enable()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
}

void IndexBuffer::Disable()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
