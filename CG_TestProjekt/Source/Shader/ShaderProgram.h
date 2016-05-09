#pragma once

#include "GL/glew.h"
#include "FancyLib/FancyMath.h"

#include "../Rendering/Textures/Texture2D.h"

class ShaderProgram
{
	/* =================================
	 * Member 
	 * =================================
	 */
private:
	GLuint shaderProgramID;

	/* =================================
	 * Initialization 
	 * =================================
	 */
public:
	ShaderProgram(const char* shaderFileName);
	~ShaderProgram();
	
private:
	void Init(const char* shaderFileName);

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


	/*=================================
	* Methods
	* =================================
	*/
public:
	void Enable() const;
	void Disable() const;

	void SetUniformMatrix4(GLchar* uniformName, FancyMath::Matrix4 inMatrix) const;
	void SetUniformSampler2D(GLchar* uniformName, Texture2D* texture) const;
private:
	GLint GetUniformLocation(GLchar* uniformName) const;

};