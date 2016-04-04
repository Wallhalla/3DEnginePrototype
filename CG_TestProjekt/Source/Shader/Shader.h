#pragma once
#include "GL/glew.h"

#include "FancyLib/FancyMath.h"


namespace CG
{
	class Shader
	{
	private:
		GLuint shaderProgramID;

	public:
		Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
		~Shader();

	public:
		void Enable() const;
		void Disable() const;

		GLuint GetProgramID() const
		{
			return shaderProgramID;
		}

	public:		
		void SetUniform_Vector2f(const GLchar* uniformName, const FancyMath::Vector2f& inVector);
		void SetUniform_Vector3f(const GLchar* uniformName, const FancyMath::Vector3f& inVector);
		void SetUniform_Vector4f(const GLchar* uniformName, const FancyMath::Vector4f& inVector);
		void SetUniform_Matrix4(const GLchar* uniformName, const FancyMath::Matrix4& inMatrix);

	private:
		GLuint CompileShader(const GLchar* vShaderSource, const char* fShaderSource);
		bool AnyCompileError(GLuint shaderID);

		/* Returns the Uniform ID of the given Uniformname in the current Shader Program */
		GLint GetUniformLocation(const GLchar* uniformName);
	};
}