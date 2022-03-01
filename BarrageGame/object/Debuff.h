/***********************************************
作者：杨玉胜
时间：2021年6月28日22:44:38
版本：V0.1
概要：减益效果类的定义
备注：
************************************************/
#pragma once
#include "Object.h"
class Debuff:public Object
{
public:
	Debuff();
	~Debuff();
	virtual void Start();
	virtual void Update();
	virtual void Destroy();
	virtual void Draw();
protected:
	TCHAR *name;	
	DWORD gettime;
	DWORD t1;
	int num;
	int max_num;
};
