#include "FancyLib/FancyMath.h"

#include "GL/glew.h"
#include "../../Buffer/BuffersHeader.h"

class Circle2D
{
private:
	VertexArray* VAO;

	GLuint numVertices;

public:
	Circle2D(float radius, FancyMath::Vector3f position, unsigned int numTriangles);
	~Circle2D();

	void Draw();
};