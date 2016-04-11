#pragma once

#include "GL/glew.h"


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

	void CheckShaderAnyErrors(GLuint shaderID);
	void CheckProgramAnyError();
};