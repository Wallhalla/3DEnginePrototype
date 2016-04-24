#include "FancyLib/FancyMath.h"

#include "GL/glew.h"

#include "../Buffer/Buffer.h"

class Circle2D
{
private:
	GLuint vao;
	Buffer* buffer;
	GLuint numVertices;

public:
	Circle2D(float radius, FancyMath::Vector3f position, unsigned int numTriangles);
	~Circle2D();

	void Draw();
};