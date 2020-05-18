#include "JCamera.h"
#include <cmath>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void JCamera::SetPosition(float InDeltaMove)
{
	if (AttachParent != nullptr) {
		Position.Z += InDeltaMove;
		return;
	}

	if (InDeltaMove == 0) return;

	Position.X += InDeltaMove * lx * 0.1f;
	Position.Z -= InDeltaMove * lz * 0.1f;
}

void JCamera::SetRotation(float InDeltaDir)
{
	if (InDeltaDir == 0) return;

	angle += InDeltaDir;
	lx = sin(angle);
	lz = -cos(angle);
}

void JCamera::SetupAttachment(JActor* InParent)
{
	AttachParent = InParent;
}

void JCamera::Update()
{
	this->updateLookAt();
}

void JCamera::updateLookAt()
{
	gluLookAt(
		Position.X, Position.Y, Position.Z,
		Position.X + lx, 1.f, Position.Z + lz,
		0.0f, 1.0f, 0.0f
	);
}