#include "IndexBuffer.h"
using namespace CG;

IndexBuffer::IndexBuffer(GLushort* dataArray, GLsizei dataSize)
	:elementCount(dataSize)
{
	glGenBuffers(1, &bufferID);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize * sizeof(GL_UNSIGNED_SHORT), dataArray, GL_DYNAMIC_DRAW);
	Unbind();
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &bufferID);
}

GLsizei IndexBuffer::GetCount()
{
	return elementCount;
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}