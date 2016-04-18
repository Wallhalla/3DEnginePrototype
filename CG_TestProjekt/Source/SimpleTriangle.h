#include "GL/glew.h"
#include "Buffer/Buffer.h"

class SimpleTriangle
{
private:
	Buffer* buffer;

public:
	SimpleTriangle();
	~SimpleTriangle();

	void Draw();

};