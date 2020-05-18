#pragma once

#include "IRender.h"
#include "JActor.h"

class JCamera : public JActor {

public:
	JCamera() {
		Position = FVector3(0.f, 1.0f, 0.0f);
	};

	void Update();
	virtual void SetPosition(float InDeltaMove) override;
	virtual void SetRotation(float InDeltaDir) override;

	void SetupAttachment(JActor* InParent);

private:
	void updateLookAt();

	JActor* AttachParent;
	float angle = 0.f;
	float lx = 0.f;
	float lz = -1.f;
};