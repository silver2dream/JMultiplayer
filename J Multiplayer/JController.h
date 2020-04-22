#pragma once

#include "IController.h"
#include "JPawn.h"

class JController : public IController {
public:
	virtual void PressKey(int Key, int x, int y) override;
	virtual void ReleaseKey(int Key, int x, int y) override;

	void Attach(JActor* InPawn);
	void Update();

private:
	JActor* Pawn;
	float deltaAngle = 0.f;
	float deltaMove = 0.f;
};