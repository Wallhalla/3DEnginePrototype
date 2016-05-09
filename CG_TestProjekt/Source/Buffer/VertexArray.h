#pragma once

#include "GL/glew.h"

#include "Buffer.h"
#include "../Shader/ShaderHeader.h"

#include <vector>

class VertexArray
{
private:
	GLuint vaoID;	

public:
	VertexArray();
	~VertexArray();

	void ConnectBufferToShaderAttribute(Buffer* buffer, GLuint componentCount, EShaderAttributes shaderLocation, GLsizei sizeOfDatatype = 0, GLvoid* attributeOffset = 0 );

	void Enable();
	void Disable();

};
