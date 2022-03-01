#pragma once
#include "..\Object.h"
#include "..\scene\CombatScene.h"
#include "..\skillManager\SkillManager.h"
#include "..\weaponManager\WeaponManager.h"
//�ֲ����˺�Bullet���໥����
//���г��ԣ�2018��11��1��11:11:54 ����׷�ٵ��ӵ���ӵ���Ϸ��
//�Ȳ�����ѧ����ģ��

class Player:public Object
{
public:
	Player(CombatScene *scene1);
	~Player();
	void Move();
	void Update();
	void Draw();
	void GetXy(double &x1, double &y1);

private:
	double x;											//����
	double y;
	int radius;											//�뾶

	double horizontalx;									//ÿ���ƶ��ľ���
	double verticalx;									//��ֱ�ƶ��ٶ�
	int movetime;										//�����ƶ�ʱ��

	list<Object*> gameobjects;							//������
};
