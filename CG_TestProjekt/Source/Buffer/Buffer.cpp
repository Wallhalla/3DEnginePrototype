#include "Buffer.h"



Buffer::Buffer(
	GLfloat* inBufferData,
	GLfloat inBufferElementsSize,
	GLenum inBufferType,
	GLenum inMemoryMode)
	: bufferType(inBufferType)
{
	glGenBuffers(1, &vboID);
	glBindBuffer(bufferType, vboID);
	glBufferData(bufferType, inBufferElementsSize, inBufferData, inMemoryMode);

	glBindBuffer(bufferType, 0);
}

void Buffer::Enable()
{
	glBindBuffer(bufferType, vboID);
}

void Buffer::Disable()
{
	glBindBuffer(bufferType, 0);
}