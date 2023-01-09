#pragma once


#include "WorldObject.h"
#include "Texture.h"


class Ball : public WorldObject {
	

private:
	Texture* ballTexture;

public:

	Ball(Texture* texture);

	void draw();

};