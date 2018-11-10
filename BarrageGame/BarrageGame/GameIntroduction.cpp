#include "pch.h"
#include "GameIntroduction.h"
const int TIPSLEN = 9;
const TCHAR *tips[TIPSLEN] = {
		_T("A  向左移动"),
		_T("S  向下移动"),
		_T("D  向右移动"),
		_T("W  向上移动"),
		_T("F  释放第一技能"),
		_T("P  暂停游戏"),
		_T("L  继续游戏"),
		_T("鼠标  控制子弹方向"),
		//_T("ESC 调出提示框"),
		_T("空格 增长激光射程")
};

GameIntroduction::GameIntroduction(GameManager * gamemanager1):Scene(gamemanager1)
{
	gameobjects.push_back(new CircleModule(600, 700, 50, _T("返回"), [&]()->void{
		gamemanager->ChangeScene(new FirstInterface(gamemanager));
	}));
	settextstyle(25, 0, _T("宋体"));						//十六是默认
}

GameIntroduction::~GameIntroduction()
{

}

void GameIntroduction::Start()
{
}

void GameIntroduction::Update()
{
	for (int i = 0; i < TIPSLEN; i++)
	{
		outtextxy(100, 20 + i * 60, tips[i]);
	}
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Update();
	}
}

void GameIntroduction::Destroy()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		delete (*obj);
	}
}

void GameIntroduction::Draw()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Draw();
	}
}
