#include "pch.h"
#include "SkillManager.h"
#include "Player.h"

SkillManager::SkillManager(Player *player1, EnemyIncubator* enemyicbt1)
{
	player = player1;
	snatch = new Snatch(enemyicbt1);
	skills.push_back(snatch);
}

SkillManager::~SkillManager()
{
	
}

void SkillManager::Update()
{
	for (auto skl = skills.begin(); skl != skills.end(); ++skl)
	{
		(*skl)->Update();
	}
	LiberateSkill();
}

void SkillManager::Draw()
{
	for (auto skl = skills.begin(); skl != skills.end(); ++skl)
	{
		(*skl)->Draw();
	}
}

void SkillManager::LiberateSkill()
{
	if (GetAsyncKeyState('F'))
	{
		if (Timer::GetTimeScale() == 0)
		{
			return;
		}
		double x, y;
		player->GetXy(x, y);
		snatch->ReStart(x, y);
	}
}
