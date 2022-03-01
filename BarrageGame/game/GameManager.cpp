/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��10��28��14:45:55
�汾��V0.1
��Ҫ����Ϸ�������ʵ��
��ע��
************************************************/
#include "..\pch.h"
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
	settextstyle(FONT_SIZE, 0, _T("����"));
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
		//������ ���̵Ļ���������
		FlushMouseMsgBuffer();
	//	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		fflush(stdin);
	}
}
