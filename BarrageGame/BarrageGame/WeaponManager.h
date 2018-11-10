#pragma once
#include "Object.h"
#include "Laser.h"
#include "BleManager.h"
#include "GmsManager.h"
#include "CombatScene.h"

class WeaponManager:public Object
{
public:
	WeaponManager(Player *player1, CombatScene *scene1);
	~WeaponManager();
	void Update();
	void Draw();
private:
	list<Object*> gameobjects;							//×ÓÎïÌå
};
