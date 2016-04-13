#pragma once

#include "GL/glew.h"

class ShaderProgram
{
private:
	GLuint shaderProgramID;

public:
	ShaderProgram(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);
	~ShaderProgram();

	void Enable();
	void Disable();

private:
	void Init(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);

	/** 
	 * Creates a shader by the given type and filepath
	 * Fills outID with the generated ShaderID
	 * Returns GL_NO_ERRORS in when the shader compilation succeeded
	 */
	GLint CreateShader(GLenum shaderType, const char* shaderFilePath, GLuint& outID);
	void CreateProgram(GLuint shaders[]);

	/**
	 * Checks Compile Status of the given ShaderID
	 * Returns true in case of errors and prints to Console
	 */
	bool CheckShaderAnyErrors(GLuint shaderID);

	/**
	* Checks Validation Status of the ShaderProgram
	* Returns true in case of errors and prints to Console
	*/
	bool CheckProgramAnyError();
};