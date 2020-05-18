#pragma once

#include "JCamera.h"
#include "JPawn.h"
#include "IRender.h"

class JPlayer : public JPawn, public IRender {

public:
	JPlayer() {
		Position.X = 0.f;
		Position.Y = 1.f;
		Position.Z = -4.f;
		Color.Z = 1.f;
		scale = 1.f;
		speed = 0.05f;

		FollowCamera = new JCamera();
		FollowCamera->SetupAttachment(this);
	};

	virtual void Render() override;
	virtual void SetPosition(float InDeltaMove) override;
	virtual void SetRotation(float InDeltaDir) override;

	void Update();

	float BaseTurnRate;
	float BaseLookUpRate;
private:

	JCamera* FollowCamera;

	float scale;
	float speed;
};