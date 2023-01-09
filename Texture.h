#pragma once

#include <string>
#include "stb_image.h"
#include "glut.h"

class Texture {

private:
	GLuint textureId;



public:

	Texture();
	Texture(GLuint textureId);
	static Texture loadTexture(std::string path);

	GLuint getTextureId();

	void activate();

};