#include "pch.h"
#include "FirstInterface.h"

FirstInterface::FirstInterface(GameManager *gamemanager1):Scene(gamemanager1)
{
	gameobjects.push_back(new CircleModule(300, 400, 50, _T("退  出"), []()->void {
		exit(0); 
	}));
	gameobjects.push_back(new RectangleModule(250, 150, 100, 50, _T("开始游戏"), [&]()->void {
		gamemanager->ChangeScene(new CombatScene(gamemanager));
	}));
	gameobjects.push_back(new RectangleModule(250, 250, 100, 50, _T("操作说明"), [&]()->void {
		gamemanager->ChangeScene(new GameIntroduction(gamemanager));
	}));
	settextstyle(16, 0, _T("宋体"));
}

FirstInterface::~FirstInterface()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); )
	{
		delete (*obj);
		obj = gameobjects.erase(obj);
	}
}

void FirstInterface::Update()
{
	for(auto obj=gameobjects.begin();obj!=gameobjects.end();++obj)
	{
		(*obj)->Update();
	}
}

void FirstInterface::Destroy()
{

}

void FirstInterface::Draw()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Draw();
	}
}
