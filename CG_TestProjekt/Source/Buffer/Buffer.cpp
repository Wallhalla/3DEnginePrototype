#include "Buffer.h"

using namespace CG;


Buffer::Buffer(GLfloat* dataArray, GLuint dataSize, GLint countPerComponent)
	: elementsPerComponent(countPerComponent)
{
	glGenBuffers(1, &bufferID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, dataSize * sizeof(GL_FLOAT), dataArray, GL_DYNAMIC_DRAW);
	Unbind();
}

Buffer::~Buffer()
{
	glDeleteBuffers(1, &bufferID);
}

void Buffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

void Buffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLint Buffer::GetComponentCount() const
{
	return elementsPerComponent;
}
