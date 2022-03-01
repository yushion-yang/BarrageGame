/***********************************************
作者：杨玉胜
时间：2018年10月28日14:45:55
版本：V0.1
概要：游戏类的定义
备注：
************************************************/
#pragma once
#include <time.h>
#include "..\object\scene\FirstInterface.h"
#include "..\core\ConstValue.h"
#include "..\core\MMTimer.h"
#include "..\input\MouseInput.h"
#include "..\core\Timer.h"
class Scene;
class GameManager
{
public:
	GameManager();
	~GameManager();
	void Run();
	void InitGame();
	void ChangeScene(Scene *newscene);
	void ControllGame();
private:
	Scene *mainscene;
	MMTimer mmtimer;
	MouseInput mouseinput;
	Timer timer;
};
