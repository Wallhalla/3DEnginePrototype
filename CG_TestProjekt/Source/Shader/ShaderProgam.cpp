#include "ShaderProgram.h"

#include "FancyLib/FancyUtils.h"

#include <iostream>
#include <vector>

ShaderProgram::ShaderProgram(const char* vertexShaderFilePath, const char* fragmentShaderFilePath)
{
	Init(vertexShaderFilePath, fragmentShaderFilePath);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(shaderProgramID);
}

void ShaderProgram::Init(const char* vertexShaderFilePath, const char* fragmentShaderFilePath)
{
	GLuint vertexShaderID = 0;
	
	if (CreateShader(GL_VERTEX_SHADER, vertexShaderFilePath, vertexShaderID) != GL_NO_ERROR)
	{
		std::cout << "Could not compile VertexShader - abort!" << std::endl;
		return;
	}

	GLuint fragmentShaderID = 0;

	if (CreateShader(GL_FRAGMENT_SHADER, fragmentShaderFilePath, fragmentShaderID) != GL_NO_ERROR)
	{
		std::cout << "Could not compile FragmentShader - abort!" << std::endl;
		return;
	}

	GLuint shaders[] = { vertexShaderID, fragmentShaderID };
	CreateProgram(shaders);
}

GLint ShaderProgram::CreateShader(GLenum shaderType, const char* shaderFilePath, GLuint& outID)
{
	outID = glCreateShader(shaderType);

	std::string shaderSourceString = FancyUtils::FancyFileManager::ReadFromFile(shaderFilePath);
	const char* shaderSource = shaderSourceString.c_str();

	glShaderSource(outID, 1, &shaderSource, 0);
	glCompileShader(outID);

	if (CheckShaderAnyErrors(outID))
	{
		outID = 0;
		return true;
	}

	return GL_NO_ERROR;
}

void ShaderProgram::CreateProgram(GLuint shaders[])
{
	shaderProgramID = glCreateProgram();

	for (int i = 0; i < sizeof(shaders); i++)
	{
		glAttachShader(shaderProgramID, shaders[i]);
	}	

	glLinkProgram(shaderProgramID);

	glValidateProgram(shaderProgramID);

	if(CheckProgramAnyError())
	{
		glDeleteProgram(shaderProgramID);
	}

	for (int i = 0; i < sizeof(shaders); i++)
	{
		glDeleteShader(shaders[i]);
	}	
}

bool ShaderProgram::CheckShaderAnyErrors(GLuint shaderID)
{
	GLint validShader = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &validShader);

	GLint logSize = 0;
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logSize);
	
	if (validShader == GL_FALSE)
	{
		std::vector<GLchar> errorLog(logSize);
		glGetShaderInfoLog(shaderID, logSize, &logSize, &errorLog[0]);

		for (auto i = errorLog.begin(); i != errorLog.end(); ++i)
		{
			std::cout << *i;
		}
		std::cout << std::endl;
		glDeleteShader(shaderID);
		return true;
	}

	return false;
}

bool ShaderProgram::CheckProgramAnyError()
{
	GLint validProgram = 0;
	glGetProgramiv(shaderProgramID, GL_VALIDATE_STATUS, &validProgram);

	GLint logSize = 0;
	glGetProgramiv(shaderProgramID, GL_INFO_LOG_LENGTH, &logSize);
		
	if (validProgram == GL_FALSE)
	{
		std::vector<GLchar> errorLog(logSize);
		glGetProgramInfoLog(shaderProgramID, errorLog.size(), NULL, &errorLog[0]);
		for (auto i = errorLog.begin(); i != errorLog.end(); ++i)
		{
			std::cout << *i;
		}
		std::cout << std::endl;		
		return true;
	}

	return false;
}

void ShaderProgram::Enable()
{
	glUseProgram(shaderProgramID);
}

void ShaderProgram::Disable()
{
	glUseProgram(0);
}
