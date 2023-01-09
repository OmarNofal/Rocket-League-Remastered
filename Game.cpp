#include "Game.h"



Game::Game(): 
	carTexture(Texture::loadTexture("res/RCCar/10600_RC_Car_SG_v1_diffuse.jpg")),
	groundTexture(Texture::loadTexture("res/textures/field3.jpg")),
	ballTexture(Texture::loadTexture("res/textures/soccer.jpg"))
{
	camera.activateCamera();

	player = new Player(&carTexture);
	ground = new Ground(&groundTexture);
}

void Game::processFrame(float ds) {
	
	moveCamera(ds);
	movePlayer(ds);
	glutPostRedisplay();
}


void Game::draw() {
	player->draw();
	ground->draw();
}


void Game::moveCamera(float ds) {


	if (isKeyPressed('d'))
		camera.ProcessKeyboard(Camera_Movement::RIGHT, ds);

	if (isKeyPressed('a'))
		camera.ProcessKeyboard(Camera_Movement::LEFT, ds);

	if (isKeyPressed('w'))
		camera.ProcessKeyboard(Camera_Movement::FORWARD, ds);

	if (isKeyPressed('s'))
		camera.ProcessKeyboard(Camera_Movement::BACKWARD, ds);

	camera.activateCamera();
}


void Game::movePlayer(float ds) {
	if (isKeyPressed('i'))
		player->move(ds);
}


void Game::onKeyPressed(unsigned char c) {
	keyMap.insert(c);
}


void Game::onKeyReleased(unsigned char c) {
	keyMap.erase(c);
}


bool Game::isKeyPressed(unsigned char c) {
	if (keyMap.find(c) != keyMap.end())
		return true;
	else
		return false;
}


void Game::onMouseMoved(float dx, float dy) {
	camera.ProcessMouseMovement(dx, dy);
	camera.activateCamera();
}