#include "GL/glew.h"
#include "Buffer/Buffer.h"

class SimpleTriangle
{
private:
	Buffer* buffer;
	GLuint ibo;
	GLuint vao;

public:
	SimpleTriangle();
	~SimpleTriangle();

	void Draw();

};