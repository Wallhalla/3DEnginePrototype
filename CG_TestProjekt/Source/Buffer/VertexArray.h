#pragma once

#include "GL/glew.h"
#include <vector>
#include "Buffer.h"

namespace CG
{

	class VertexArray
	{
	private:
		GLuint vaoID;
		std::vector<Buffer*> buffers;

	public:
		VertexArray();
		~VertexArray();

		/* adds a buffer to this array and link the bufferdata to the corresponding shaderlocation*/
		void AddBuffer(Buffer* inBuffer, GLuint shaderLocationIndex);
	
		void Bind() const;
		void Unbind() const;
	};
}