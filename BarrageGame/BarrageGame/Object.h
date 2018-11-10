/***********************************************
作者：杨玉胜
时间：2018年10月28日14:45:55
版本：V0.1
概要：对象基类的定义
备注：
************************************************/
#pragma once
#include <graphics.h>
#include <functional>
#include <vector>
#include <list>

using namespace std;

class Object
{
public:
	Object();
	~Object();
	virtual void Start();
	virtual void Update();
	virtual void Destroy();
	virtual void Draw();
protected:

};