#include "JPlayer.h"
#include <GL/freeglut.h>
#include <iostream>
void JPlayer::Render()
{
	FollowCamera->Update();
	glPushMatrix();
	glColor3f(Color.X, Color.Y, Color.Z);
	glTranslatef(Position.X, Position.Y, Position.Z);
	glutSolidCube(scale);
	glPopMatrix();
}

void JPlayer::SetPosition(float InDeltaMove)
{
	if (InDeltaMove == 0) return;
	
	Position.Z += InDeltaMove * speed;
	FollowCamera->SetPosition(InDeltaMove * speed);
	
	//Position.X += InDeltaMove * speed;
	//Position.Z += deltaMove * lz * 0.1f;
	cout << "Player:" << Position.ToString() << endl;
}

void JPlayer::SetRotation(float InDeltaDir)
{
	FollowCamera->SetRotation(InDeltaDir);
	/*angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);*/
}

