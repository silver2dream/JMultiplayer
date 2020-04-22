#pragma once

#include "JPawn.h"
#include "IRender.h"

class JPlayer : public JPawn, public IRender {

public:
	JPlayer() {
		Color.Z = 1.f;
		scale = 1.f;
	};

	virtual void Render() override;
	virtual void SetPosition(float InDeltaMove) override;
	virtual void SetRotation(float InDeltaDir) override;

private:
	float scale;
};