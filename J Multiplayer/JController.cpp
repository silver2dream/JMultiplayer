#include "JController.h"
#include <iostream>
#include <GL/freeglut.h>

using namespace std;

void JController::PressKey(int Key, int x, int y)
{
	switch (Key) {
	case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
	case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
	case GLUT_KEY_UP: deltaMove = 0.5f; break;
	case GLUT_KEY_DOWN: deltaMove = -0.5f; break;
	}
}

void JController::ReleaseKey(int Key, int x, int y)
{
	switch (Key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT: deltaAngle = 0.0f; break;
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN: deltaMove = 0; break;
	}
}

void JController::Attach(JActor* InPawn)
{
	Pawn = InPawn;
}

void JController::Update()
{
	Pawn->SetPosition(deltaMove);
	Pawn->SetRotation(deltaAngle);
}
