#pragma once
#include "..\object\scene\Scene.h"
#include "..\object\scene\FirstInterface.h"
#include "GameManager.h"

class GameIntroduction:public Scene
{
public:
	GameIntroduction(GameManager *gamemanager1);
	~GameIntroduction();
	void Start();
	void Update();
	void Destroy();
	void Draw();
private:
	list<Object*> gameobjects;
};