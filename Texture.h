#pragma once

#include "glut.h"
#include <string>
#include "stb_image.h"

class Texture {

private:
	GLuint textureId;



public:

	Texture(GLuint textureId);
	static Texture loadTexture(std::string path);

	void activate();

};