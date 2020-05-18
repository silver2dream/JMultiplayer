
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <GL/freeglut.h>

#include "IRender.h"
#include "JController.h"
#include "JCamera.h"
#include "JPlayer.h"
#include "JPawn.h"
#include "JCube.h"
#include "JPlane.h"

using namespace std;

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

#define  WINDOW_POSITION_X 100
#define  WINDOW_POSITION_Y 100

vector<IRender*> ObjectConatiner;

JController* PlayerController = nullptr;

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	PlayerController->Update();
	for (auto object : ObjectConatiner) {
		if (object != nullptr) {
			object->Render();
		}
	}

	glutSwapBuffers();
}

void onWindowChange(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;

	GLfloat ratio = w * 1.0f / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 100);
	glMatrixMode(GL_MODELVIEW);
}

void init() {
	srand(time(NULL));

	JPlayer* Player = new JPlayer();
	ObjectConatiner.push_back(dynamic_cast<IRender*>(Player));

	auto Plane = new JPlane(100.f);
	ObjectConatiner.push_back(dynamic_cast<IRender*>(Plane));

	for (int i = -3; i < 3; i++)
		for (int j = -3; j < 3; j++) {
			auto Cube = new JCube(FVector3(i * 10.f, 1.f, j * 10.f));
			ObjectConatiner.push_back(dynamic_cast<IRender*>(Cube));
		}

	PlayerController = new JController();
	PlayerController->Attach(dynamic_cast<JActor*>(Player));
}

void OnPressKey(int key, int x, int y) {
	PlayerController->PressKey(key, x, y);
}

void OnReleaseKey(int key, int x, int y) {
	PlayerController->ReleaseKey(key, x, y);
}

void OnPressMouseButton(int ButtonId, int State, int x, int y) {
	PlayerController->MouseButton(ButtonId, State, x, y);
}

void OnMouseMotion(int x, int y) {
	PlayerController->MouseMove(x, y);
}

#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4

void processMenuEvents(int option) {
	/*switch (option) {
	case RED:
		red = 1.0f;
		green = 0.0f;
		blue = 0.0f; break;
	case GREEN:
		red = 0.0f;
		green = 1.0f;
		blue = 0.0f; break;
	case BLUE:
		red = 0.0f;
		green = 0.0f;
		blue = 1.0f; break;
	case ORANGE:
		red = 1.0f;
		green = 0.5f;
		blue = 0.5f; break;
	}*/
}

void CreateGLUTMenus() {
	int menu;
	menu = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Red", RED);
	glutAddMenuEntry("Blue", BLUE);
	glutAddMenuEntry("Green", GREEN);
	glutAddMenuEntry("Orange", ORANGE);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char *argv[])
{
	init();

	glutInit(&argc, argv);

#ifdef _MSC_VER
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
#else
	glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
#endif

	glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("OpenGL Application");

	glutMouseFunc(OnPressMouseButton);
	glutMotionFunc(OnMouseMotion);
	glutSpecialFunc(OnPressKey);
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(OnReleaseKey);
	
	glutDisplayFunc(&renderScene);
	glutReshapeFunc(&onWindowChange);
	glutIdleFunc(&renderScene);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 1;
}

