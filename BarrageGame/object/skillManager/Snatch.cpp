#include "..\..\pch.h"
#include "Snatch.h"

const int LASTTIME = 5000;
const int UPDATETIME = 20;
const int  SKILL_W = 125;						//技能宽度
const int  SKILL_H = 50;						//技能高度
const double interpolation = 1.0 / UPDATETIME;

Snatch::Snatch(EnemyIncubator* enemyicbt1):Skill(enemyicbt1)
{
	movex = 10;
	movey = 20;
	damage = 200;
}

Snatch::~Snatch()
{

}

void Snatch::Update()
{
	updatetime += Timer::Deltime();
	if (enable && updatetime > UPDATETIME )
	{
		y -= movey;
		updatetime = 0;
		CrashEnemy();
		if (y <0)
		{
			enable = false;
		}
	}
}

void Snatch::Draw()
{
	if (enable)
	{
		int y1 = y - updatetime * interpolation * movey;
		arc(x - SKILL_W, y1 - 1.8*SKILL_H, x + SKILL_W, y1 +  1.8*SKILL_H, 0 ,PI);
		arc(x - SKILL_W, y1 -  2.2*SKILL_H, x + SKILL_W, y1 +  2.2*SKILL_H, 0 ,PI);
	}
}

void Snatch::ReStart(int x1, int y1)
{
	if (enable)
		return;
	x = x1;
	y = y1;
	updatetime = 0;
	lasttime = 0;
	enable = true;
}

void Snatch::CrashEnemy()
{
	enemyicbt->CrashEnemy(([&](double x1, double y1, int r1)->int {
		if (RsPointOnRectangle(x1, y1, x - SKILL_W, y - SKILL_H * 0.25, 2 * SKILL_W, 0.5*SKILL_H))
		{
			return damage;
		}
		return 0;
	}));
}
