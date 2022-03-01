#include "..\pch.h"
#include "GameIntroduction.h"

const int TIPSLEN = 9;

const TCHAR *tips[TIPSLEN] = {
		_T("A  �����ƶ�"),
		_T("S  �����ƶ�"),
		_T("D  �����ƶ�"),
		_T("W  �����ƶ�"),
		_T("F  �ͷŵ�һ����"),
		_T("P  ��ͣ��Ϸ"),
		_T("L  ������Ϸ"),
		_T("���  �����ӵ�����"),
		//_T("ESC ������ʾ��"),
		_T("�ո� �����������")
};

GameIntroduction::GameIntroduction(GameManager * gamemanager1):Scene(gamemanager1)
{
	gameobjects.push_back(new CircleModule(600, 700, 50, _T("����"), [&]()->void{
		gamemanager->ChangeScene(new FirstInterface(gamemanager));
	}));
	settextstyle(25, 0, _T("����"));						//ʮ����Ĭ��
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
