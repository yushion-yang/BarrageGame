/***********************************************
作者：杨玉胜
时间：2018年10月28日14:45:55
版本：V0.1
概要：游戏管理类的实现
备注：
************************************************/
#include "pch.h"
#include "GameManager.h"

GameManager::GameManager()
{
	InitGame();
	PathFile::ReadPaths();
	mainscene = new FirstInterface(this);
//	mainscene = new CombatScene(this);
}

GameManager::~GameManager()
{
	delete(mainscene);
}

void GameManager::Run()
{
	while (true)
	{
		mouseinput.Update();
		mainscene->Update();
		mainscene->Draw();
		timer.Update();
		mmtimer.Update();
		FlushBatchDraw();
		cleardevice();
		ControllGame();
	}
}

void GameManager::InitGame()
{
	initgraph(WIDTH * 0.5f, HEIGHT);
	setbkmode(TRANSPARENT);
	settextstyle(FONT_SIZE, 0, _T("宋体"));
	srand((unsigned)time(0));
	BeginBatchDraw();
}

void GameManager::ChangeScene(Scene * newscene)
{
	delete(mainscene);
	mainscene = newscene;
	Run();
}

void GameManager::ControllGame()
{
	if (GetAsyncKeyState('P'))
	{
		Timer::SetTimeScale(0);
	}
	if (GetAsyncKeyState('L'))
	{
		Timer::SetTimeScale(1);
		//清除鼠标 键盘的缓冲区输入
		FlushMouseMsgBuffer();
	//	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		fflush(stdin);
	}
}
