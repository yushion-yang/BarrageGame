#pragma once
#include "..\Object.h"
#include "Snatch.h"
#include "..\..\core\Timer.h"

class Player;
class SkillManager:public Object
{
public:
	SkillManager(Player *player1, EnemyIncubator* enemyicbt1);
	~SkillManager();
	void Update();
	void Draw();
	void LiberateSkill();

private:
	Player *player;								//���
	Snatch *snatch;								//���ܹ⵶
	list<Skill*> skills;						//������
};
