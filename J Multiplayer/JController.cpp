#include "JController.h"
#include "IRender.h"
#include <GL/freeglut.h>

using namespace std;

void JController::PressKey(int Key, int x, int y)
{
	switch (Key) {
	case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
	case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
	case GLUT_KEY_UP: deltaMove = -0.5f; break;
	case GLUT_KEY_DOWN: deltaMove = 0.5f; break;
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

void JController::MouseButton(int Button, int state, int x, int y)
{
	if (Button == GLUT_LEFT_BUTTON) {
		if (state != GLUT_UP) {
			xOrigin = x;
			return;
		}
		deltaAngle = 0.f;
		xOrigin = -1.f;
	}
}

void JController::MouseMove(int x, int y)
{
	if (xOrigin >= 0) {
		deltaAngle = (x - xOrigin) * 0.001f;
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
