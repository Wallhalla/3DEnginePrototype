#include "ShaderProgram.h"

#include "FancyLib/FancyUtils.h"

#include <iostream>
#include <vector>

ShaderProgram::ShaderProgram(const char* vertexShaderFilePath, const char* fragmentShaderFilePath)
{
	shaderProgramID = glCreateProgram();

	Init(vertexShaderFilePath, fragmentShaderFilePath);
}

void ShaderProgram::Init(const char* vertexShaderFilePath, const char* fragmentShaderFilePath)
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

	std::string vertexShaderSourceString = FancyUtils::FancyFileManager::ReadFromFile(vertexShaderFilePath);
	const char* vertexShaderSource = vertexShaderSourceString.c_str();	

	glShaderSource(vertexShaderID, 1, &vertexShaderSource, 0);
	glCompileShader(vertexShaderID);

	CheckShaderAnyErrors(vertexShaderID);

	std::string fragmentShaderSourceString = FancyUtils::FancyFileManager::ReadFromFile(fragmentShaderFilePath);
	const char* fragmentShaderSource = fragmentShaderSourceString.c_str();

	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, 0);
	glCompileShader(fragmentShaderID);

	CheckShaderAnyErrors(fragmentShaderID);

	glAttachShader(shaderProgramID, vertexShaderID);
	glAttachShader(shaderProgramID, fragmentShaderID);

	glLinkProgram(shaderProgramID);

	glValidateProgram(shaderProgramID);

	CheckProgramAnyError();

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	
}

void ShaderProgram::CheckProgramAnyError()
{
	GLint validProgram;

	GLchar errorData[1024] = { 0 };

	glGetProgramiv(shaderProgramID, GL_VALIDATE_STATUS, &validProgram);

	if (validProgram == GL_FALSE)
	{
		glGetProgramInfoLog(shaderProgramID, sizeof(errorData), NULL, errorData);
		std::cout << errorData << std::endl;
		glDeleteProgram(shaderProgramID);
	}
}

void ShaderProgram::CheckShaderAnyErrors(GLuint shaderID)
{	
	GLint success = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	
	GLint logSize = 0;
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logSize);

	GLchar errorLog[512] = { 0 };
	glGetShaderInfoLog(shaderID, logSize, &logSize, errorLog);

	if (success == GL_FALSE)
	{
		std::cout << errorLog << std::endl;
		glDeleteShader(shaderID);
	}
}

void ShaderProgram::Enable()
{
	glUseProgram(shaderProgramID);
}

void ShaderProgram::Disable()
{
	glUseProgram(0);
}
