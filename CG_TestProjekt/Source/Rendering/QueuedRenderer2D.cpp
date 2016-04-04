#include "QueuedRenderer2D.h"

using namespace CG;

QueuedRenderer2D::QueuedRenderer2D()
{
}

QueuedRenderer2D::~QueuedRenderer2D()
{
	
}



void QueuedRenderer2D::Submit(const SimpleRenderable2D* renderable)
{
	renderables.push_back(renderable);
}

void QueuedRenderer2D::Flush()
{
	for (const SimpleRenderable2D* renderable : renderables)
	{
		renderable->Draw();
	}
}