#include "Buffer.h"

Buffer::Buffer(
	void* inBufferData,
	GLsizeiptr inBufferElementsSize,
	GLushort inBufferComponentElementsCount,
	GLenum inBufferType,
	GLenum inMemoryMode)
	: bufferType(inBufferType), componentSize(inBufferComponentElementsCount)
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

GLushort Buffer::GetComponentSize() const
{
	return componentSize;
}