#pragma once


#include "WorldObject.h"
#include "Texture.h"


class Ball : public WorldObject {
	

private:
	Texture ballTexture;

public:

	Ball();

	void draw();

};