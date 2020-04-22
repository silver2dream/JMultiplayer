#pragma once

namespace Utility {

	struct FVector3
	{
		FVector3(){}
		FVector3(float InX, float InY, float inZ)
			:X(InX)
			,Y(InY)
			,Z(inZ)
		{}

		float X{};
		float Y{};
		float Z{};
	};
}