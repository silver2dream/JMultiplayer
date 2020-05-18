#pragma once

#include "JActor.h"
#include "IRender.h"

class JPlane : public JActor, public IRender {
public:
	JPlane(){}

	JPlane(float InScale)
		:Scale(InScale)
	{}

	JPlane(FVector3 InPos)
		:JActor(InPos)
	{}

	virtual void Render() override;

private:
	float Scale;

};