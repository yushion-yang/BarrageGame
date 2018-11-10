#pragma once
#include "Object.h"
#include "Timer.h"
#include "ConstValue.h"
#include "EnemyIncubator.h"

class Skill:public Object
{
public:
	Skill(EnemyIncubator* enemyicbt1);
	~Skill();
	virtual void Update();
	virtual void Draw();
	virtual void ReStart(int x1, int y1);
	virtual void CrashEnemy();

protected:
	double x;											//坐标x
	double y;											//坐标y
	double movex;										//移动速度x
	double movey;										//移动速度y
	int radius;											//半径	
	int  damage;										//伤害值
	bool enable;										//是否有效
	int lasttime;										//持续时间计时器
	int updatetime;										//更新时间计时器
	EnemyIncubator* enemyicbt;
};
