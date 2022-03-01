#include "..\..\pch.h"
#include "Player.h"
//遇到的问题  从一个正在遍历的链表中转移一个元素到另外一个链表导致的链表遍历出错
//解决方法	类定义一个迭代器进行遍历操作 当回收时使迭代器--

//遇到问题 2018年10月30日20:46:33 将指向容器头的迭代器做减操作时发生错误
//包括子弹的回收 特效的回收 怪物的回收
//解决方法：添加一个迭代器成员变量，在做减操作前进行判断。

const int PLAYER_MOVE_TIME = 20;

Player::Player(CombatScene *scene1)
{
	gameobjects.push_back(new SkillManager(this, scene1->GetEnemyIncubator()));
	gameobjects.push_back(new WeaponManager(this, scene1));

	x = 200;
	y = 200;
	radius = 20;
	horizontalx = 8;
	verticalx = 8;
	movetime = 0;
}

Player::~Player()
{

}

void Player::Move()
{
	if (GetAsyncKeyState('A'))
	{
		x -= horizontalx;
	}
	if (GetAsyncKeyState('D'))
	{
		x += horizontalx;
	}
	if (GetAsyncKeyState('W'))
	{
		y -= horizontalx;
	}
	if (GetAsyncKeyState('S'))
	{
		y += horizontalx;
	}
	if (x < 0)
	{
		x = 0;
	}
	if (x > WIDTH)
	{
		x = WIDTH;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (y > HEIGHT)
	{
		y = HEIGHT;
	}
}


void Player::Update()
{
	movetime += Timer::Deltime();
	if (movetime > PLAYER_MOVE_TIME)
	{
		movetime = 0;
		Move();
	}
	
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Update();
	}
}

void Player::Draw()
{
	circle(x, y, radius);

	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Draw();
	}
}

void Player::GetXy(double & x1, double & y1)
{
	x1 = x;
	y1 = y;
}
