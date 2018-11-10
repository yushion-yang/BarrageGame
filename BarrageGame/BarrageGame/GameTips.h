#pragma once
#include "Object.h"
#include "RectangleModule.h"
class GameTips:public Object
{
public:
	GameTips();
	~GameTips();
	void Start();
	void Update();
	void Destroy();
	void Draw();
private:
	RectangleModule *rectmodule;
	bool value;
};
