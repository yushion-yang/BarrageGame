/***********************************************
作者：杨玉胜
时间：2021年6月28日22:47:29
版本：V0.1
概要：敌人生产器
备注：
************************************************/
#pragma once
#include "..\Object.h"
#include "..\..\core\ConstValue.h"
#include "..\..\Path\PathFile.h"
#include "Enemy.h"

class EnemyIncubator:public Object
{
public:
	EnemyIncubator();
	~EnemyIncubator();
	void Update();
	void Draw();
	void CreateEmy();
	void RestoreEmy(Enemy *emy);
	list<Enemy*>* GetEnemys();					
	bool BulletCrashEnemy(int x1, int y1, int &mtox1, int &mtoy1, int damage1);
	void CrashEnemy(function<int(double x1, double y1, int r1)> cbfunc);
	static int movetimer;
private:
	int createtime;										//产生时间
	list<Enemy*> *uenemys;
	list<Enemy*> *lenemys;
	list<Enemy*>::iterator emyiterator;
};
