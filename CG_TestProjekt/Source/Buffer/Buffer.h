#pragma once
#include "GL/glew.h"

namespace CG
{
	class Buffer
	{
	private:
		GLuint bufferID;
		// How many elements in Buffer define 1 Component (f.e. Vec2 is defined by 2 elements)
		GLint elementsPerComponent;

	public:
		Buffer(GLfloat* dataArray, GLuint dataSize, GLint countPerComponent);
		~Buffer();

		void Bind() const;
		void Unbind() const;

		GLint GetComponentCount() const;
	};
}