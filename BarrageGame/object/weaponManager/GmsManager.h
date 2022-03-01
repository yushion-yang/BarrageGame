#pragma once
#include "..\Object.h"
#include "GuidedMissile.h"
#include "..\player\Player.h"

class GmsManager:public Object
{
public:
	GmsManager();
	~GmsManager();
	void Update();
	void Draw();
	void ShootGms();
	void RestoreObject(GuidedMissile* obj);
	static int movetimer;
private:
	int shoottime;										//发射导弹时间
	list<GuidedMissile*> *lguidemissiles;				//留下的导弹
	list<GuidedMissile*> gameobjects;					//子物体
	list<GuidedMissile*>::iterator objiterator;			//对象链的迭代器
};