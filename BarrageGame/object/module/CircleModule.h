/***********************************************
作者：杨玉胜
时间：2021年6月28日22:43:27
版本：V0.1
概要：组件圆 类的定义
备注：
************************************************/
#pragma once
#include "Module.h"
class CircleModule:public Module
{
public:
	CircleModule(int x1, int y1, int radius1,const TCHAR *str1 , function< void(void)> cbfunc1);
	~CircleModule();
	void Update();
	void Destroy();
	void Draw();
private:
	int radius;									//组件半径
};
