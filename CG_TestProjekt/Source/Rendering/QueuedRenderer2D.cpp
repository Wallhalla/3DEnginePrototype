#include "QueuedRenderer2D.h"

using namespace CG;

QueuedRenderer2D::QueuedRenderer2D()
{
}

QueuedRenderer2D::~QueuedRenderer2D()
{
	
}



void QueuedRenderer2D::Submit(const Renderable2D* renderable)
{
	renderables.push_back(renderable);
}

void QueuedRenderer2D::Flush()
{
	for (const Renderable2D* renderable : renderables)
	{
		renderable->Draw();
	}
}