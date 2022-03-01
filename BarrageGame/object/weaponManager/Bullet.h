/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��10��28��14:45:55
�汾��V0.1
��Ҫ���ӵ���Ķ���
��ע��
************************************************/
#pragma once
#include "..\Object.h"
#include "..\effectsManager\EffectsManager.h"
#include "Weapon.h"


class CombatScene;
class BleManager;
class Bullet:public Weapon
{
public:
	Bullet();
	Bullet( list<Object*>*lbullet1);
	~Bullet();

	void Update();

	void Draw();
	void Move();
	void SetDirection(int x1,int y1,int dirx1,int diry1);
	void Restore();
	void CrashEnemy();

	static double interpolation;
	static BleManager* blemanager;			//�ӵ�������
	static EffectsManager* efsmanager;		//��Ч������
private:
	double originalx;						//ԭʼ����x
	double originaly;						//ԭʼ����y

	list<Object*> *lbullet;					//������
};

