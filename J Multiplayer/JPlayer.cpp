#include "JPlayer.h"
#include <GL/freeglut.h>

void JPlayer::Render()
{
	glColor3f(Color.X, Color.Y, Color.Z);
	glTranslatef(0.0f, 1.f, 0.0f);
	glutSolidCube(scale);
}

void JPlayer::SetPosition(float InDeltaMove)
{
	if (InDeltaMove == 0) return;

	/*Position.X += deltaMove * lx * 0.1f;
	Position.Z += deltaMove * lz * 0.1f;*/
}

void JPlayer::SetRotation(float InDeltaDir)
{
	/*angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);*/
}

