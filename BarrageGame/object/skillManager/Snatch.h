#pragma once
#include "Skill.h"
#include "..\..\algorithm\CollisionDetection.h"

class Snatch:public Skill
{
public:
	Snatch(EnemyIncubator* enemyicbt11);
	~Snatch();
	void Update();
	void Draw();
	void ReStart(int x1,int y1);
	void CrashEnemy();

private:

};
