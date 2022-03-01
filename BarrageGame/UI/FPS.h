#pragma once
#include "..\object\Object.h"
#include "..\object\module\RectangleModule.h"
#include "..\core\Timer.h"
#include "..\core\ConstValue.h"

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
	int framerate;					//帧率

	int clktime;					//计时器
	TCHAR cfps[10];					//显示的字符
	int calnum;						//统计量
};
