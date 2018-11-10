#include "pch.h"
#include "Enemy.h"
#include "EnemyIncubator.h"


const int MAXHP = 1000;
const int MOVESPEED = 2;

//遇到问题：2018年10月31日15:25:58  线段和圆的相交  感觉网上给出的方法是错误的

EnemyIncubator*	Enemy::enemyicbt;		//敌人孵化器
double	Enemy::interpolation;		
int Enemy::radius;

Enemy::Enemy(int x1, int y1,EnemyIncubator *enemyicbt1,int pathindex1)
{
	x = x1;								//当前坐标x
	y = y1;								//当前坐标y
	ox = x;								//初始的x
	oy = y;								//初始的y
	hp = MAXHP;							//敌人当前hp
	maxhp = hp;							//敌人最大hp
	mx = MOVESPEED;						//移动速度x
	my = 0;								//移动速度y
	attributes = 0;						//属性
	path = PathFile::GetPath(pathindex1);
	poiiterator = path->pointlist.begin();
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	Move();
}

void Enemy::Draw()
{
	if (hp > 0)
	{
		int x1 = x + interpolation * EnemyIncubator::movetime*mx;
		int y1 = y + interpolation * EnemyIncubator::movetime*my;
		TCHAR tips[10];
		_stprintf_s(tips, _T("%d"), hp);

		outtextxy(x1 - 10, y1 - radius - 30, tips);
		//显示敌人的名字
	//	outtextxy(x1 - 10, y1 - radius - 50, _T("小兵"));
		rectangle(x1 - radius, y1 - radius - 10, x1 + radius, y1 - radius);
		int lenth = (int)(2.0*radius*hp / maxhp);
		setfillcolor(RED);
		fillrectangle(x1 - radius, y1 - radius - 10, x1 - radius + lenth, y1 - radius);
		//敌人的绘制方式
		setfillcolor(0xdd4499);
		fillcircle(x1, y1, radius);
	}
}

void Enemy::Move()
{
	x =ox+ (*poiiterator)->x;
	y =oy+ (*poiiterator)->y;
	int x1= (*poiiterator)->x;
	int y1 = (*poiiterator)->y;
	if (poiiterator != path->pointlist.end())
	{
		++poiiterator;
		if (poiiterator == path->pointlist.end())
		{
			poiiterator = path->pointlist.begin();
		}
	}
	mx = (*poiiterator)->x-x1;
	my = (*poiiterator)->y-y1;

	if (x > WIDTH||x<0||y>HEIGHT||y<0)
	{
		hp = -1;
		enemyicbt->RestoreEmy(this);
		return;
	}
}

bool Enemy::RsSurvival()
{
	return hp > 0;
}

bool Enemy::RsHit(int x1, int y1,int x2, int y2)
{
	x2 += mx;
	y2 += my;
	if (RsLineOnCircle(x1, y1, x2, y2, x, y, radius))
	{
		return true;
	}
	return false;
}

void Enemy::TakeDamage(int damage)
{
	hp -= damage;
	if (hp <= 0)
	{
		enemyicbt->RestoreEmy(this);
	}
}

void Enemy::GetXyr(double & x1, double & y1, int & r1)
{
	x1 = x;
	y1 = y;
	r1 = radius;
}

int Enemy::GetHp()
{
	return hp;
}

void Enemy::GetMxy(double &x1, double &y1, double &mx1, double &my1, int &radius1)
{
	x1 = x;
	y1 = y;
	radius1 = radius;
	mx1 = mx;
	my1 = my;
}



