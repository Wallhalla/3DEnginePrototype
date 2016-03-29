#pragma once
#include "GL/glew.h"

namespace CG
{
	class IndexBuffer
	{
	private:
		GLuint bufferID;		
		GLsizei elementCount;

	public:
		IndexBuffer(GLushort* dataArray, GLsizei dataSize);
		~IndexBuffer();

		GLsizei GetCount();
		void Bind() const;
		void Unbind() const;
	};
}