#pragma once

#include "JObject.h"
#include "Utility.h"

using namespace Utility;

class JActor : public JObject{
public:
	JActor() {}

	JActor(FVector3 InPos)
	:Position(InPos)
	{}

	virtual void SetPosition(float InDeltaMove);
	virtual void SetRotation(float InDeltaDir);

	FVector3 GetPosition();

protected:
	FVector3 Position;
	FVector3 Rotation;
};