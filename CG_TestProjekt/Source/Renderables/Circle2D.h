#include "FancyLib/FancyMath.h"

#include "GL/glew.h"

class Circle2D
{
private:
	GLuint vbo;

	GLuint numVertices;

public:
	Circle2D(float radius, FancyMath::Vector3f position, unsigned int numTriangles);
	~Circle2D();

	void Draw();
};