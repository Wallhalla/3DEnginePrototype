#include "GL/glew.h"
#include "Buffer/BuffersHeader.h"

#include "FancyLib/FancyMath.h"

class StaticSprite2D
{
private:
	VertexArray* vao;
	IndexBuffer* ibo;
	
public:
	/**
	 * Defines a new Sprite 
	 * @param1: Position defines the Pivot point position of the Sprite
	 * @param2: Size defines the scale around the pivot point
	 */
	StaticSprite2D(FancyMath::Vector3f position = FancyMath::Vector3f(0, 0, 0), FancyMath::Vector2f(size) = FancyMath::Vector2f(1, 1));
	~StaticSprite2D();

	void Draw();

};