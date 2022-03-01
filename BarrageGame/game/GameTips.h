#pragma once
#include "..\object\Object.h"
#include "..\object\module\RectangleModule.h"
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
