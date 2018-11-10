#pragma once
#include "Object.h"
#include "Snatch.h"
#include "Timer.h"

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
	Player *player;								//玩家
	Snatch *snatch;								//技能光刀
	list<Skill*> skills;						//技能链
};
