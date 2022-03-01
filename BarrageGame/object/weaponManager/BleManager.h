/***********************************************
作者：杨玉胜
时间：2021年6月28日22:29:59
版本：V0.1
概要：子弹管理类的定义
备注：
************************************************/
#pragma once
#include "..\Object.h"
#include "Bullet.h"
#include "..\..\input\MouseInput.h"
#include "..\player\Player.h"

class BleManager:public Object
{
public:
	BleManager();
	~BleManager();
	void Update();
	void Draw();
	void ShootBle();
	void RestoreObject(Bullet* obj1);

	static int movetimer;								//移动的计时器
	static int shoottimer; 								//发射子弹时间
private:
	int shoottime;										//发射子弹时间

	list<Bullet*> *lbullets;							//留下的子弹
	list<Bullet*> gameobjects;							//子物体
	list<Bullet*>::iterator objiterator;				//对象链的迭代器
};
