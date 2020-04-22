#pragma once

#include "IRender.h"
#include "JActor.h"

class JCamera : public JActor, public IRender {

public:
	static JCamera* GetInstance();

	virtual void Render() override;
	virtual void SetPosition(float InDeltaMove) override;
	virtual void SetRotation(float InDeltaDir) override;

private:
	JCamera() {
		Position = FVector3(0.f, 1.f, 5.0f);
	};

	void updateLookAt();

	static JCamera* instance;
	float deltaAngle = 0.f;
	float deltaMove = 0.f;
	float angle = 1.f;
	float lx = 0.f;
	float lz = -1.f;
};