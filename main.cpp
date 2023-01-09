#define TINYOBJLOADER_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <chrono>
#include "glut.h"
#include "Game.h"


#define WIDTH 1400
#define HEIGHT 787


Game* game;

int lastMouseX = WIDTH / 2;
int lastMouseY = HEIGHT / 2;

long long previousTimeMillis;

long framesCount = 0;

bool firstFrame = true;

long long lastFrameTime;

long long getCurrentTimeMillis() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
		).count();
}


void keyboardDown(unsigned char key, int mouseX, int mouseY) {
	game->onKeyPressed(key);
}

void keyboardUp(unsigned char key, int x, int y) {
	game->onKeyReleased(key);
}

void passiveMouseFunc(int x, int y) {

	int dx = x - lastMouseX;
	int dy = y - lastMouseY;

	game->onMouseMoved(dx, dy);
	
	lastMouseX = x;
	lastMouseY = y;

}

void timerFunc() {

	if (firstFrame) {
		firstFrame = false;
		lastFrameTime = getCurrentTimeMillis();
		return;
	}
	framesCount++;
	auto currentTimeMillis = getCurrentTimeMillis();
	game->processFrame( (currentTimeMillis - lastFrameTime) / 1000.0f);

	lastFrameTime = currentTimeMillis;
}



void display(void) {
	glClearColor(.2f, 0.3f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	game->draw();
	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("RL");
	glutDisplayFunc(display);


	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutPassiveMotionFunc(passiveMouseFunc);
	
	glutIdleFunc(timerFunc);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	


	glEnable(GL_DEPTH_TEST);
	
	game = new Game();
	
	glutMainLoop();
}