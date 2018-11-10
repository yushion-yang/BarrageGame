#pragma once
#include "Scene.h"
#include "GameIntroduction.h"
#include "CombatScene.h"
#include "GameManager.h"	
//遇到问题List的释放	后来发现其实不是不是这个问题  而且切换场景后没有重新调用GameManager的Run方法
//导致了继续执行原来场景的Updatae方法出现错误
class FirstInterface:public Scene
{
public:
	FirstInterface(GameManager *gamemanager1);
	~FirstInterface();
	void Update();
	void Destroy();
	void Draw();
private:
	list<Object*> gameobjects;
};
