#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &vaoID);	
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &vaoID);
}

void VertexArray::ConnectBufferToShaderAttribute(Buffer* buffer, EShaderAttributes shaderLocation)
{
	Enable();

	buffer->Enable();	
	
	glEnableVertexAttribArray(shaderLocation);
	
	glVertexAttribPointer(
		shaderLocation,								// shader location
		buffer->GetComponentSize(),                 // size
		GL_FLOAT,									// type
		GL_FALSE,									// normalized?
		0,											// stride
		0											// array buffer offset
		);

	glDisableVertexAttribArray(shaderLocation);

	buffer->Disable();	

	Disable();
}

void VertexArray::Enable()
{
	glBindVertexArray(vaoID);

	// TODO: too heavy, move inside Renderer if any
	for (unsigned short i = 0; i < EShaderAttributes::MAX_ATTRIBUTES; i++)
	{
		glEnableVertexAttribArray(i);
	}	
}

void VertexArray::Disable()
{
	glBindVertexArray(0);

	// TODO: too heavy, move inside Renderer if any
	for (unsigned short i = 0; i < EShaderAttributes::MAX_ATTRIBUTES; i++)
	{
		glDisableVertexAttribArray(i);
	}
}