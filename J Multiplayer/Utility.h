#pragma once

#include <string>

using namespace std;

namespace Utility {

	struct FVector3
	{
		FVector3(){}

		FVector3(float InX, float InY, float inZ)
			:X(InX)
			,Y(InY)
			,Z(inZ)
		{}

		FVector3(float InValue)
			:X(InValue)
			,Y(InValue)
			,Z(InValue)
		{}

		float X{};
		float Y{};
		float Z{};

		string ToString() {
			string value;
			value.append(to_string(X)).append(",");
			value.append(to_string(Y)).append(",");
			value.append(to_string(Z)).append(",");
			return  value;
		}
	};
}