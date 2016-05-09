#include "FancyLib/FancyMath.h"

#include "GL/glew.h"
#include "../../../Buffer/BuffersHeader.h"

#include "../Asset.h"

struct Circle2D : public ModelAsset
{

public:
	Circle2D(float radius, FancyMath::Vector3f position, unsigned int numTriangles);
	~Circle2D();

	void Draw();
};