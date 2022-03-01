/***********************************************
作者：杨玉胜
时间：2018年10月28日14:45:55
版本：V0.1
概要：子弹类的实现
备注：
************************************************/
#include "..\..\pch.h"
#include "Bullet.h"
#include "..\player\Player.h"
#include "BleManager.h"
//#include "EnemyIncubator.h"
//更复杂的一个问题：2018年10月31日11:07:42 在一个容器遍历的时候可能删除自身元素 同时遍历的操作过程中
//遍历别的容器的元素并且可能把它删除	寻求解决的方法：如何在遍历时删除元素并确保遍历可以继续进行

//思路：如果没有删除 则一直遍历完成  如果删除了元素  则迭代器需要指向正确位置并判断是否可以进行步进操作
//难点：在遍历过程中是否删除元素无法告知遍历操作
//那么一个方法是可以让遍历中的执行操作返回是否删除元素  另外将遍历处理的工作移交给具备容器迭代器的对象进行
//处理 如此一来  它在处理过程中如果删除了元素  不会出现迭代器的++ --操作异常的情况
//最终选择的做法是将带有可能删除元素遍历操作专业到管理者中进行

const int DAMAGE = 200;
const int MOVESPEED = 50;


double Bullet::interpolation;
BleManager* Bullet::blemanager;
EffectsManager* Bullet::efsmanager;

Bullet::Bullet()
{
	x=-100;								//当前坐标x
	y=-100;								//当前坐标y
	originalx=x;						//原始坐标x
	originaly=y;						//原始坐标y
}

Bullet::Bullet(list<Object*>*lbullet1):Bullet()
{
	lbullet = lbullet1;
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	CrashEnemy();
	Move();
}


void Bullet::Draw()
{
	int x1 = x + BleManager::movetimer * interpolation*mx;
	int y1 = y + BleManager::movetimer * interpolation*my;
	fillcircle(x1, y1, 3);
}

void Bullet::Move()
{
	x += mx;
	y += my;
	if (x > WIDTH)
	{
		x = WIDTH;
		Restore();
		return;
	}
	if (x < 0)
	{
		x = 0;			
		Restore();
		return;
	}
	if (y > HEIGHT)
	{
		y = HEIGHT;
		Restore();
		return;
	}
	if (y < 0)
	{
		y = 0;			
		Restore();
		return;
	}
}

void Bullet::SetDirection(int x1,int y1,int dirx1, int diry1)
{
	x = x1;
	y = y1;
	double dir = sqrt((dirx1 - x)*(dirx1 - x) + (diry1 - y)*(diry1 - y));
	if (dir != 0)
	{
		mx = MOVESPEED * ((dirx1 - x) / dir);
		my = MOVESPEED * ((diry1 - y) / dir);
	}
	else//往上下移动
	{
		mx = 0;
		if (my >= y1)
			my = -MOVESPEED;
		else
			my = MOVESPEED;
	}
}

void Bullet::Restore()
{
	efsmanager->CreateEfs(x, y);
	blemanager->RestoreObject(this);
}

void Bullet::CrashEnemy()
{
	//已将子弹移动速度过大进行考虑
	int mtox = x + mx;
	int mtoy = y + my;
	if (enemyicbt->BulletCrashEnemy(x,y,mtox,mtoy,DAMAGE))
	{
		x = mtox;
		y = mtoy;
		Restore();
	}
}
