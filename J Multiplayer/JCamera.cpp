#include "JCamera.h"
#include <cmath>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

JCamera* JCamera::instance = nullptr;

void JCamera::updateLookAt()
{
	gluLookAt(Position.X, 1.0f, Position.Z,
		Position.X + lx, 1.0f, Position.Z + lz,
		0.0f, 1.0f, 0.0f);
}

void JCamera::Render()
{
	this->updateLookAt();
}

void JCamera::SetPosition(float InDeltaMove)
{
	if (InDeltaMove == 0) return;

	cout << InDeltaMove << endl;

	Position.X += InDeltaMove * lx * 0.1f;
	Position.Z += InDeltaMove * lz * 0.1f;
	cout << Position.X << endl;
}

void JCamera::SetRotation(float InDeltaDir)
{
	if (InDeltaDir == 0) return;

	angle += InDeltaDir;
	lx = sin(angle);
	lz = -cos(angle);
}

JCamera* JCamera::GetInstance()
{
	if (instance == nullptr) {
		instance = new JCamera();
	}
	return instance;
}
