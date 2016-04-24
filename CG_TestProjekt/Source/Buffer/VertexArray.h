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

	void ConnectBufferToShaderAttribute(Buffer* buffer, EShaderAttributes shaderLocation);

	void Enable();
	void Disable();

};
