#pragma once

#include "JActor.h"
#include "IRender.h"

class JCube :public JActor, public IRender {

public:
	JCube(){
		Scale = 1.f;
	}

	JCube(FVector3 InPos)
		:JActor(InPos)
	{
		Scale = 1.f;
		Color = FVector3(0.5f);
	}

	virtual void Render() override;

private:
	FVector3 Color;
	float Scale;

};