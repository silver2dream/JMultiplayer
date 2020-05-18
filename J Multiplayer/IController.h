#pragma once

class IController {
public:
	~IController(){}
	virtual void PressKey(int Key, int x, int y) = 0;
	virtual void ReleaseKey(int Key, int x, int y) = 0;
	virtual void MouseButton(int Button, int state, int x, int y) = 0;
	virtual void MouseMove(int x, int y) = 0;
};