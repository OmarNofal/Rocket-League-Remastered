#pragma once

#include "Camera.h"
#include "Player.h"
#include "Texture.h"

#include <set>

class Game {

private:

	// which keys are pressed
	std::set<unsigned char> keyMap;

	bool isKeyPressed(unsigned char);
	
	void moveCamera(float);

	Texture carTexture;
	
public:
	
	Game();

	Camera camera;
	Player* player;

	/*Processes a new frame
	ds is the time since last frame in seconds
	*/
	void processFrame(float ds);

	void draw();

	void onKeyPressed(unsigned char);
	void onKeyReleased(unsigned char);
	void onMouseMoved(float dx, float dy);

};