/***********************************************
作者：杨玉胜
时间：2018年10月28日14:45:55
版本：V0.1
概要：子弹类的定义
备注：
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
	static BleManager* blemanager;			//子弹管理者
	static EffectsManager* efsmanager;		//特效管理者
private:
	double originalx;						//原始坐标x
	double originaly;						//原始坐标y

	list<Object*> *lbullet;					//回收链
};

