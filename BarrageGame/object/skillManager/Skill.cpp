#include "..\..\pch.h"
#include "Skill.h"

Skill::Skill(EnemyIncubator* enemyicbt1)
{
	x = 0;
	y = 0;
	movex = 0;
	movey = 0;
	radius = 10;
	damage = 100;
	enable = false;
	lasttime = 0;		
	updatetime = 0;
	enemyicbt = enemyicbt1;
}

Skill::~Skill()
{

}

void Skill::Update()
{

}


void Skill::Draw()
{

}

void Skill::ReStart(int x1, int y1)
{
	x = x1;
	y = y1;
}

void Skill::CrashEnemy()
{

}
