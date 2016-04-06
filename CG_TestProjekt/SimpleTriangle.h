#include "GL/glew.h"

class SimpleTriangle
{
private:
	GLuint vbo;

public:
	SimpleTriangle();
	~SimpleTriangle();

	void Draw();

};