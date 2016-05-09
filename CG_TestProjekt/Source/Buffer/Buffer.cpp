#include "Buffer.h"

Buffer::Buffer(
	void* inBufferData,
	GLsizeiptr inBufferElementsSize,	
	GLenum inBufferType,
	GLenum inMemoryMode)
	: bufferType(inBufferType)
{
	glGenBuffers(1, &vboID);
	glBindBuffer(bufferType, vboID);
	glBufferData(bufferType, inBufferElementsSize, inBufferData, inMemoryMode);

	glBindBuffer(bufferType, 0);
}

Buffer::~Buffer()
{
	glDeleteBuffers(1, &vboID);
}

void Buffer::Enable()
{
	glBindBuffer(bufferType, vboID);
}

void Buffer::Disable()
{
	glBindBuffer(bufferType, 0);
}

