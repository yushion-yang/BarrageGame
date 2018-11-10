#pragma once
#include "Object.h"
#include "RectangleModule.h"
#include "Timer.h"
#include "ConstValue.h"

class FPS:public Object
{
public:
	FPS();
	~FPS();
	void Start();
	void Update();
	void Destroy();
	void Draw();
private:
	RectangleModule *rectmodule;
	int framerate;

	int clktime;					//计时器
	TCHAR cfps[10];					//显示的字符
	int calnum;						//统计量
};
