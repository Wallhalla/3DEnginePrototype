#pragma once
#include "Renderable2D.h"

#include <vector>


namespace CG
{
	class QueuedRenderer2D
	{
	private:
		std::vector<const Renderable2D*> renderables;

	public:
		QueuedRenderer2D();
		~QueuedRenderer2D();

		void Submit(const Renderable2D* renderable);
		void Flush();
	};
}