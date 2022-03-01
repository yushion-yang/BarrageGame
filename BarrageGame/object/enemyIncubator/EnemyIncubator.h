/***********************************************
���ߣ�����ʤ
ʱ�䣺2021��6��28��22:47:29
�汾��V0.1
��Ҫ������������
��ע��
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
	int createtime;										//����ʱ��
	list<Enemy*> *uenemys;
	list<Enemy*> *lenemys;
	list<Enemy*>::iterator emyiterator;
};
