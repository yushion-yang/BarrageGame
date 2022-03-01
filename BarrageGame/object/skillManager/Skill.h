#pragma once
#include "..\Object.h"
#include "..\..\core\Timer.h"
#include "..\..\core\ConstValue.h"
#include "..\enemyIncubator\EnemyIncubator.h"

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
	double x;											//����x
	double y;											//����y
	double movex;										//�ƶ��ٶ�x
	double movey;										//�ƶ��ٶ�y
	int radius;											//�뾶	
	int  damage;										//�˺�ֵ
	bool enable;										//�Ƿ���Ч
	int lasttime;										//����ʱ���ʱ��
	int updatetime;										//����ʱ���ʱ��
	EnemyIncubator* enemyicbt;
};
