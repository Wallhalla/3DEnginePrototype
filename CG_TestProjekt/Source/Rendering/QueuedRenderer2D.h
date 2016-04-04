#pragma once
#include "SimpleRenderable2D.h"

#include <vector>


namespace CG
{
	class QueuedRenderer2D
	{
	private:
		std::vector<const SimpleRenderable2D*> renderables;

	public:
		QueuedRenderer2D();
		~QueuedRenderer2D();

		void Submit(const SimpleRenderable2D* renderable);
		void Flush();
	};
}