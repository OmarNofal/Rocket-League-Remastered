#include <stdio.h>
#include <chrono>
#include "glut.h"


#define WIDTH 1400
#define HEIGHT 787


long long previousTimeMillis;

bool firstFrame = true;

long long lastFrameTime;

long long getCurrentTimeMillis() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
		).count();
}


void keyboardDown(unsigned char key, int mouseX, int mouseY) {

}

void keyboardUp(unsigned char key, int x, int y) {

}

void mouseFunc(int x, int y) {

	

}

void timerFunc(int _) {

	if (firstFrame) {
		firstFrame = false;
		lastFrameTime = getCurrentTimeMillis();
		glutTimerFunc(0, timerFunc, 0);
		return;
	}

	auto currentTimeMillis = getCurrentTimeMillis();

	lastFrameTime = currentTimeMillis;

	glutTimerFunc(0, timerFunc, 0);
}



void display(void) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(.2f, 0.3f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(1.0f, 64, 64);
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
	
	glutTimerFunc(60, timerFunc, 0);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glEnable(GL_DEPTH_TEST);
	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float) WIDTH / HEIGHT, 0.1f, 600.0f);
	gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glMatrixMode(GL_MODELVIEW);

	
	glutMainLoop();
}