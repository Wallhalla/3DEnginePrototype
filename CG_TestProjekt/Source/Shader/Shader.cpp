#include "Shader.h"

#include "FancyLib/FancyUtils.h"

#include <iostream>
#include <vector>

#include <string>

using namespace CG;
Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	std::string vShaderSource = FancyUtils::FancyFileManager::ReadFromFile(vertexShaderPath);
	std::string fShaderSource = FancyUtils::FancyFileManager::ReadFromFile(fragmentShaderPath);

	if (vShaderSource.empty() || fShaderSource.empty())
	{
		std::cout << "Failed to read Sourcefiles" << std::endl;
	}
	else
	{
		shaderProgramID = CompileShader(vShaderSource.c_str(), fShaderSource.c_str());
	}
}

Shader::~Shader()
{
	glDeleteProgram(shaderProgramID);
}

GLuint Shader::CompileShader(const char* vShaderSource, const char* fShaderSource)
{
	GLuint tmpProgramID = glCreateProgram();

	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vShaderSource, NULL);
	glCompileShader(vertexShaderID);

	if (!AnyCompileError(vertexShaderID))
	{
		return 0;
	}

	std::cout << "Shader compiled: VertexShader" << std::endl;

	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fShaderSource, NULL);
	glCompileShader(fragmentShaderID);

	if (!AnyCompileError(fragmentShaderID))
	{
		return 0;
	}

	std::cout << "Shader compiled: FragmentShader" << std::endl;
	glAttachShader(tmpProgramID, vertexShaderID);
	glAttachShader(tmpProgramID, fragmentShaderID);

	glLinkProgram(tmpProgramID);

	glValidateProgram(tmpProgramID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return tmpProgramID;

}

bool Shader::AnyCompileError(GLuint shaderID)
{
	GLint compileResult;

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE)
	{
		GLint errorLogLength;

		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &errorLogLength);

		std::vector<char> errorLog(errorLogLength);

		glGetShaderInfoLog(shaderID, errorLogLength, &errorLogLength, &errorLog[0]);

		std::cout << &errorLog[0] << std::endl;

		glDeleteShader(shaderID);

		return false;
	}

	return true;
}

void Shader::Enable() const
{
	glUseProgram(shaderProgramID);
}

void Shader::Disable() const
{
	glUseProgram(0);
}

void Shader::SetUniform_Vector2f(const GLchar* uniformName, const FancyMath::Vector2f& inVector)
{
	GLint uniformID = GetUniformLocation(uniformName);
	glUniform2f(uniformID, inVector.X, inVector.Y);
}

void Shader::SetUniform_Vector3f(const GLchar* uniformName, const FancyMath::Vector3f& inVector)
{
	GLint uniformID = GetUniformLocation(uniformName);
	glUniform3f(uniformID, inVector.X, inVector.Y, inVector.Z);
}

void Shader::SetUniform_Vector4f(const GLchar* uniformName, const FancyMath::Vector4f& inVector)
{
	GLint uniformID = GetUniformLocation(uniformName);
	glUniform4f(uniformID, inVector.X, inVector.Y, inVector.Z, inVector.W);
}

void Shader::SetUniform_Matrix4(const GLchar* uniformName, const FancyMath::Matrix4& inMatrix)
{
	GLint uniformID = GetUniformLocation(uniformName);
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, inMatrix.Elements);
}

GLint Shader::GetUniformLocation(const GLchar* uniformName)
{
	return glGetUniformLocation(shaderProgramID, uniformName);
}