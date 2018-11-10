#include "pch.h"
#include "WeaponManager.h"

WeaponManager::WeaponManager(Player *player1, CombatScene *scene1)
{
	gameobjects.push_back(new GmsManager());
	gameobjects.push_back(new BleManager());
	gameobjects.push_back(new Laser());

	Weapon::player = player1;
	Weapon::enemyicbt = scene1->GetEnemyIncubator();
	Bullet::efsmanager = scene1->GetEfsManager();
}

WeaponManager::~WeaponManager()
{

}

void WeaponManager::Update()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Update();
	}
}

void WeaponManager::Draw()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Draw();
	}
}
