#include "Texture2D.h"
#include "SOIL.h"

Texture2D::Texture2D(const char* texturePath)
{
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);

	int width, height;
	soilImage = SOIL_load_image(texturePath, &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, soilImage);
	

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glGenerateMipmap(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::~Texture2D()
{
	SOIL_free_image_data(soilImage);
	glDeleteTextures(1, &textureID);
}

void Texture2D::Enable()
{	
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture2D::Disable()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

