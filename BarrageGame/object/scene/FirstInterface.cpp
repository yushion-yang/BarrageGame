#include "..\..\pch.h"
#include "FirstInterface.h"

FirstInterface::FirstInterface(GameManager *gamemanager1):Scene(gamemanager1)
{
	gameobjects.push_back(new CircleModule(300, 400, 50, _T("��  ��"), []()->void {
		exit(0); 
	}));
	gameobjects.push_back(new RectangleModule(250, 150, 100, 50, _T("��ʼ��Ϸ"), [&]()->void {
		gamemanager->ChangeScene(new CombatScene(gamemanager));
	}));
	gameobjects.push_back(new RectangleModule(250, 250, 100, 50, _T("����˵��"), [&]()->void {
		gamemanager->ChangeScene(new GameIntroduction(gamemanager));
	}));
	settextstyle(16, 0, _T("����"));
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
