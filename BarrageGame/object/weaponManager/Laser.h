#pragma once
#include "..\Object.h"
#include "Weapon.h"
#include "..\..\algorithm\CollisionDetection.h"

class Laser:public Weapon
{
public:
	Laser();
	~Laser();
	void Update();
	void Draw();
	void CrashEnemy();
private:
	int laserlength;							//���ⳤ��
	int fadetime;								//����ʱ��
	int addlengthtime;							//���������ʱ��
	int harmtime;								//����˺�ʱ��
};