/***********************************************
���ߣ�����ʤ
ʱ�䣺2021��6��28��22:29:59
�汾��V0.1
��Ҫ���ӵ�������Ķ���
��ע��
************************************************/
#pragma once
#include "..\Object.h"
#include "Bullet.h"
#include "..\..\input\MouseInput.h"
#include "..\player\Player.h"

class BleManager:public Object
{
public:
	BleManager();
	~BleManager();
	void Update();
	void Draw();
	void ShootBle();
	void RestoreObject(Bullet* obj1);

	static int movetimer;								//�ƶ��ļ�ʱ��
	static int shoottimer; 								//�����ӵ�ʱ��
private:
	int shoottime;										//�����ӵ�ʱ��

	list<Bullet*> *lbullets;							//���µ��ӵ�
	list<Bullet*> gameobjects;							//������
	list<Bullet*>::iterator objiterator;				//�������ĵ�����
};
