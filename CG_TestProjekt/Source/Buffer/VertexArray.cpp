#include "VertexArray.h"
using namespace CG;
VertexArray::VertexArray()
{
	glGenVertexArrays(1, &vaoID);
}

VertexArray::~VertexArray()
{
	for (int i = 0; i < buffers.size(); i++)
	{
		delete buffers[i];
		buffers[i] = nullptr;
	}

	glDeleteVertexArrays(1, &vaoID);
}

void VertexArray::AddBuffer(Buffer* inBuffer, GLuint shaderLocationIndex)
{
	Bind();

	inBuffer->Bind();

	glEnableVertexAttribArray(shaderLocationIndex);
	glVertexAttribPointer(shaderLocationIndex, inBuffer->GetComponentCount(), GL_FLOAT, GL_FALSE, NULL, NULL);


	inBuffer->Unbind();
	Unbind();
}

void VertexArray::Bind() const
{
	glBindVertexArray(vaoID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}