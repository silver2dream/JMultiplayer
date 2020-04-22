
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

using namespace std;

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

#define  WINDOW_POSITION_X 100
#define  WINDOW_POSITION_Y 100

vector<IRender*> ObjectConatiner;

JController* PlayerController = nullptr;

void MouseHandle(int ButtonId, int State, int x, int y) {
	if (ButtonId == GLUT_LEFT_BUTTON)
	{
		cout <<"Position: "<< x << "," << y << endl;
	}
}

void DrawCube() {
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 1.f, 0.0f);
	glutSolidCube(1.f);
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	PlayerController->Update();

	for (auto object : ObjectConatiner) {
		if (object != nullptr) {
			object->Render();
		}
	}

	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	glColor3f(0.f, 0.f, 1.f);
	glTranslatef(0.f, 0.f, 0.0f);
	glutSolidCube(1.f);

	glTranslatef(0.f, 1.f, 0.0f);
	for (int i = -3; i < 3; i++)
		for (int j = -3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i * 10.0f, 0, j * 10.0f);
			DrawCube();
			glPopMatrix();
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

	//JPlayer* Player = new JPlayer();
	JCamera* Camera = JCamera::GetInstance();
	//ObjectConatiner.push_back(dynamic_cast<IRender*>(Player));
	ObjectConatiner.push_back(dynamic_cast<IRender*>(Camera));

	PlayerController = new JController();
	PlayerController->Attach(dynamic_cast<JActor*>(Camera));
}

void OnPressKey(int key, int x, int y) {
	PlayerController->PressKey(key, x, y);
}

void OnReleaseKey(int key, int x, int y) {
	PlayerController->ReleaseKey(key, x, y);
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

	glutMouseFunc(&MouseHandle);
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

