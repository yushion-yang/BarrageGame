#pragma once
#include "..\Object.h"
#include "Weapon.h"
#include "..\..\algorithm\CollisionDetection.h"

class Laser:public Weapon
{
public:
	Laser();
	~Laser();
	void Update();
	void Draw();
	void CrashEnemy();
private:
	int laserlength;							//激光长度
	int fadetime;								//消退时间
	int addlengthtime;							//增长间隔计时器
	int harmtime;								//造成伤害时间
};