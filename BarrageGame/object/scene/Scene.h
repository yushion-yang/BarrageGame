#pragma once
#include "..\Object.h"
#include "..\module\CircleModule.h"
#include "..\module\RectangleModule.h"
//���⣺��д�ó���ת��֮��������Scene���޷�ʶ������⣬����gamemanagerҲ���ֱ���
//A B�໥����  C�̳�B  Ȼ����C�б���  Cû�ж������
//��� ʹ��ָ��  ����Ҫ����GameManager�෽����Դ�ļ������GameManager��ͷ�ļ�
class GameManager;
class Scene:public Object
{
public:
	Scene(GameManager *gamemanager1);
	virtual ~Scene();
	virtual void Start();
	virtual void Update();
	virtual void Destroy();
	virtual void Draw();
protected:
	GameManager *gamemanager;
};
