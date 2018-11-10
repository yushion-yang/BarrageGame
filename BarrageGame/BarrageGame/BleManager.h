#pragma once
#include "Object.h"
#include "Bullet.h"
#include "MouseInput.h"
#include "Player.h"

class BleManager:public Object
{
public:
	BleManager();
	~BleManager();
	void Update();
	void Draw();
	void ShootBle();
	void RestoreObject(Bullet* obj1);

	static int movetime;
private:
	int shoottime;										//发射子弹时间

	list<Bullet*> *lbullets;							//留下的子弹
	list<Bullet*> gameobjects;							//子物体
	list<Bullet*>::iterator objiterator;				//对象链的迭代器
};
