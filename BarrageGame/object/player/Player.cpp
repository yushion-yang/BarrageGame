#include "..\..\pch.h"
#include "Player.h"
//����������  ��һ�����ڱ�����������ת��һ��Ԫ�ص�����һ�������µ������������
//�������	�ඨ��һ�����������б������� ������ʱʹ������--

//�������� 2018��10��30��20:46:33 ��ָ������ͷ�ĵ�������������ʱ��������
//�����ӵ��Ļ��� ��Ч�Ļ��� ����Ļ���
//������������һ����������Ա����������������ǰ�����жϡ�

const int PLAYER_MOVE_TIME = 20;

Player::Player(CombatScene *scene1)
{
	gameobjects.push_back(new SkillManager(this, scene1->GetEnemyIncubator()));
	gameobjects.push_back(new WeaponManager(this, scene1));

	x = 200;
	y = 200;
	radius = 20;
	horizontalx = 8;
	verticalx = 8;
	movetime = 0;
}

Player::~Player()
{

}

void Player::Move()
{
	if (GetAsyncKeyState('A'))
	{
		x -= horizontalx;
	}
	if (GetAsyncKeyState('D'))
	{
		x += horizontalx;
	}
	if (GetAsyncKeyState('W'))
	{
		y -= horizontalx;
	}
	if (GetAsyncKeyState('S'))
	{
		y += horizontalx;
	}
	if (x < 0)
	{
		x = 0;
	}
	if (x > WIDTH)
	{
		x = WIDTH;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (y > HEIGHT)
	{
		y = HEIGHT;
	}
}


void Player::Update()
{
	movetime += Timer::Deltime();
	if (movetime > PLAYER_MOVE_TIME)
	{
		movetime = 0;
		Move();
	}
	
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Update();
	}
}

void Player::Draw()
{
	circle(x, y, radius);

	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Draw();
	}
}

void Player::GetXy(double & x1, double & y1)
{
	x1 = x;
	y1 = y;
}
