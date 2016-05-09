#pragma once
#include "GL/glew.h"


struct Texture2D
{
private:
	GLuint textureID;
	GLubyte* soilImage;

public:
	Texture2D(const char* texturePath);
	~Texture2D();

	void Enable();
	void Disable();



};