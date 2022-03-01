#pragma once
#include "..\Object.h"
#include "..\..\core\Timer.h"
#include "..\..\core\ConstValue.h"
#include "..\enemyIncubator\EnemyIncubator.h"

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
	static Player *player;					//���
protected:
	double x;								//��ǰ����x
	double y;								//��ǰ����y
	double mx;								//ÿ���ƶ��ľ���x
	double my;								//ÿ���ƶ��ľ���y
};
