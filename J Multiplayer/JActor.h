#pragma once

#include "Utility.h"

using namespace Utility;

class JActor {
public:
	JActor() {}

	virtual void SetPosition(float InDeltaMove);
	virtual void SetRotation(float InDeltaDir);

protected:
	FVector3 Position;
	FVector3 Rotation;
};