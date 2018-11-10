#pragma once
#include "Object.h"
#include "Timer.h"
#include "ConstValue.h"
#include "EnemyIncubator.h"

class Player;
class Weapon:public Object
{
public:
	Weapon();
	~Weapon();
	virtual void Update();
	virtual void Draw();
	virtual void CrashEnemy();

	static EnemyIncubator *enemyicbt;
	static Player *player;					//玩家
protected:
	double x;								//当前坐标x
	double y;								//当前坐标y
	double mx;								//每次移动的距离x
	double my;								//每次移动的距离y
};
