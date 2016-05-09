#include "ShaderProgram.h"
#include "ShaderHeader.h"


#include "FancyLib/FancyUtils.h"
using namespace FancyMath;

#include <iostream>
#include <string>
#include <vector>

ShaderProgram::ShaderProgram(const char* shaderFileName)
{
	Init(shaderFileName);

	for (unsigned short i = 0; i < EShaderAttributes::MAX_ATTRIBUTES; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(shaderProgramID);
}

void ShaderProgram::Init(const char* shaderFileName)
{
	GLuint vertexShaderID = 0;
	std::string vs = std::string(shaderFileName).append(".vertexshader");
	const char* vertexShaderFilePath = vs.c_str();

	if (CreateShader(GL_VERTEX_SHADER, vertexShaderFilePath, vertexShaderID) != GL_NO_ERROR)
	{
		std::cout << "Could not compile VertexShader - abort!" << std::endl;
		return;
	}

	GLuint fragmentShaderID = 0;

	std::string fs = std::string(shaderFileName).append(".fragmentshader");
	const char* fragmentShaderFilePath = fs.c_str();

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

void ShaderProgram::Enable() const
{
	glUseProgram(shaderProgramID);	
}

void ShaderProgram::Disable() const
{
	glUseProgram(0);
}

void ShaderProgram::SetUniformMatrix4(GLchar* uniformName, Matrix4 inMatrix) const
{
	GLint handle = GetUniformLocation(uniformName);

	glUniformMatrix4fv(handle, 1, GL_FALSE, inMatrix.Elements);
}

void ShaderProgram::SetUniformVector3(GLchar* uniformName, FancyMath::Vector3f inVector) const
{
	GLint handle = GetUniformLocation(uniformName);

	glUniform3f(handle, inVector.X, inVector.Y, inVector.Z);
}

void ShaderProgram::SetUniformVector4(GLchar* uniformName, FancyMath::Vector4f inVector) const
{
	GLint handle = GetUniformLocation(uniformName);

	glUniform4f(handle, inVector.X, inVector.Y, inVector.Z, inVector.W);
}

GLint ShaderProgram::GetUniformLocation(GLchar* uniformName) const
{
	GLint handle = glGetUniformLocation(shaderProgramID, uniformName);

	if (handle < 0)
	{
		std::cout << "Couldnt find uniform in Shader: " << uniformName << std::endl;
	}

	return handle;
}

