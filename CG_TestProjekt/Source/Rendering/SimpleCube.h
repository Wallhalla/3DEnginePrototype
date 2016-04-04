#pragma once
#include "GL/glew.h"
#include "../Buffer/BufferHeader.h"

namespace CG
{

	class SimpleCube
	{

	private:
		VertexArray* vao;		

	public:
		SimpleCube();
		~SimpleCube();


		void Draw();
	};

}