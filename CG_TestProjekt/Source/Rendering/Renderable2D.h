#pragma once

#include "FancyLib/FancyMath.h"

#include "../Buffer/BufferHeader.h"

#include "FancyLib/FancyMath.h"

namespace CG
{
	struct VertexData
	{
		FancyMath::Vector3f Position;
		FancyMath::Vector4f Color;
	};

	class Renderable2D
	{

	public:
		Renderable2D(FancyMath::Vector3f inLocation, FancyMath::Vector2f inSize);
		virtual ~Renderable2D();

	public:
		FancyMath::Vector3f position;
		FancyMath::Vector2f size;		
		
		VertexArray* vao;
		IndexBuffer* ibo;

		void Draw() const;

		FancyMath::Matrix4 GetModelView() const;
	};
}