#pragma once
#include "Object.h"
#include "Timer.h"
#include "CollisionDetection.h"
#include "Path.h"
#include "PathFile.h"

class EnemyIncubator;
class Enemy:public Object
{
public:
	Enemy(int x1, int y1,EnemyIncubator *enemyicbt1, int pathindex1);
	~Enemy();
	virtual void Update();
	virtual void Draw();
	virtual void Move();
	virtual bool RsSurvival();
	virtual bool RsHit(int x1, int y1, int mtox1, int mtoy1);
	virtual void TakeDamage(int damage);
	void GetXyr(double &x1, double &y1, int &r1);
	int GetHp();
	void GetMxy(double &x1, double &y1, double &mx1, double &my1, int &radius1);

	static EnemyIncubator	*enemyicbt;		//敌人孵化器
	static double interpolation;
	static int radius;				 		//敌人半径
protected:
	double x;								//当前坐标x
	double y;								//当前坐标y
	double ox;								//初始的x
	double oy;								//初始的y
	int hp;									//敌人当前hp
	int maxhp;								//敌人最大hp
	double mx;								//移动速度x
	double my;								//移动速度y
	int  attributes;						//属性

	Path *path;								//行走路径
	list<Point*>::iterator poiiterator;		//行走的路径点


};
