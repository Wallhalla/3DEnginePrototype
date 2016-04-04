#include "SimpleCube.h"

using namespace CG;

	SimpleCube::SimpleCube()
	{
		GLfloat g_vertex_buffer_data[] = {
			// Back Face
			-1.0f, -1.0f, -1.0f, 
			1.0f, -1.0f, -1.0f,
			1.0f, 1.0f, -1.0f, 
			-1.0f, 1.0f, -1.0f, 
			// Front Face
			-1.0f, -1.0f, 1.0f,
			1.0f, -1.0f, 1.0f,
			1.0f, 1.0f, 1.0f,
			-1.0f, 1.0f, 1.0f,
			// Bottom Face
			-1.0f, -1.0f, -1.0f, 
			1.0f, -1.0f, -1.0f, 
			1.0f, -1.0f, 1.0f,
			-1.0f, -1.0f, 1.0f, 
			// Top Face
			-1.0f, 1.0f, -1.0f,
			1.0f, 1.0f, -1.0f,
			1.0f, 1.0f, 1.0f,
			-1.0f, 1.0f, 1.0f,
			// Left Face
			-1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f, 1.0f,		
			-1.0f, 1.0f, 1.0f,
			-1.0f, 1.0f, -1.0f,
			// Right Face
			1.0f, -1.0f, -1.0f,
			1.0f, -1.0f, 1.0f,
			1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, -1.0f,
		};

		GLfloat g_color_buffer_data[] = {
			// Back Red
			1, 0, 0,
			1, 0, 0,
			1, 0, 0,
			1, 0, 0,			
			// Front Blue
			0, 0, 1,
			0, 0, 1,
			0, 0, 1,
			0, 0, 1,			
			// Bottom Green
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,			
			// Top White
			1, 1, 1,
			1, 1, 1,
			1, 1, 1,
			1, 1, 1,
			// Left Purple
			1, 0, 1,
			1, 0, 1,
			1, 0, 1,
			1, 0, 1,
			// Right Yellow
			1, 1, 0,
			1, 1, 0,
			1, 1, 0,
			1, 1, 0
		};

		vao = new VertexArray();
		vao->AddBuffer(new Buffer(g_vertex_buffer_data, 12 * 6, 3), 0);
		vao->AddBuffer(new Buffer(g_color_buffer_data, 12 * 6, 3), 1);
	}

	SimpleCube::~SimpleCube()
	{

	}

	void SimpleCube::Draw()
	{
		vao->Bind();

		glDrawArrays(GL_QUADS, 0, 6*4);

		vao->Unbind();
	}