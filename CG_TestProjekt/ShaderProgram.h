#pragma once

#include "GL/glew.h"
#include <string>

class ShaderProgram
{
private:
	GLuint shaderProgramID;

public:
	ShaderProgram(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);

	void Enable();
	void Disable();

private:
	void Init(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);

	void CheckShaderAnyErrors();
	void CheckProgramAnyError();
};