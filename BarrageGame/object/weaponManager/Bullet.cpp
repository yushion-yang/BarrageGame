/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��10��28��14:45:55
�汾��V0.1
��Ҫ���ӵ����ʵ��
��ע��
************************************************/
#include "..\..\pch.h"
#include "Bullet.h"
#include "..\player\Player.h"
#include "BleManager.h"
//#include "EnemyIncubator.h"
//�����ӵ�һ�����⣺2018��10��31��11:07:42 ��һ������������ʱ�����ɾ������Ԫ�� ͬʱ�����Ĳ���������
//�������������Ԫ�ز��ҿ��ܰ���ɾ��	Ѱ�����ķ���������ڱ���ʱɾ��Ԫ�ز�ȷ���������Լ�������

//˼·�����û��ɾ�� ��һֱ�������  ���ɾ����Ԫ��  ���������Ҫָ����ȷλ�ò��ж��Ƿ���Խ��в�������
//�ѵ㣺�ڱ����������Ƿ�ɾ��Ԫ���޷���֪��������
//��ôһ�������ǿ����ñ����е�ִ�в��������Ƿ�ɾ��Ԫ��  ���⽫��������Ĺ����ƽ����߱������������Ķ������
//���� ���һ��  ���ڴ�����������ɾ����Ԫ��  ������ֵ�������++ --�����쳣�����
//����ѡ��������ǽ����п���ɾ��Ԫ�ر�������רҵ���������н���

const int DAMAGE = 200;
const int MOVESPEED = 50;


double Bullet::interpolation;
BleManager* Bullet::blemanager;
EffectsManager* Bullet::efsmanager;

Bullet::Bullet()
{
	x=-100;								//��ǰ����x
	y=-100;								//��ǰ����y
	originalx=x;						//ԭʼ����x
	originaly=y;						//ԭʼ����y
}

Bullet::Bullet(list<Object*>*lbullet1):Bullet()
{
	lbullet = lbullet1;
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	CrashEnemy();
	Move();
}


void Bullet::Draw()
{
	int x1 = x + BleManager::movetimer * interpolation*mx;
	int y1 = y + BleManager::movetimer * interpolation*my;
	fillcircle(x1, y1, 3);
}

void Bullet::Move()
{
	x += mx;
	y += my;
	if (x > WIDTH)
	{
		x = WIDTH;
		Restore();
		return;
	}
	if (x < 0)
	{
		x = 0;			
		Restore();
		return;
	}
	if (y > HEIGHT)
	{
		y = HEIGHT;
		Restore();
		return;
	}
	if (y < 0)
	{
		y = 0;			
		Restore();
		return;
	}
}

void Bullet::SetDirection(int x1,int y1,int dirx1, int diry1)
{
	x = x1;
	y = y1;
	double dir = sqrt((dirx1 - x)*(dirx1 - x) + (diry1 - y)*(diry1 - y));
	if (dir != 0)
	{
		mx = MOVESPEED * ((dirx1 - x) / dir);
		my = MOVESPEED * ((diry1 - y) / dir);
	}
	else//�������ƶ�
	{
		mx = 0;
		if (my >= y1)
			my = -MOVESPEED;
		else
			my = MOVESPEED;
	}
}

void Bullet::Restore()
{
	efsmanager->CreateEfs(x, y);
	blemanager->RestoreObject(this);
}

void Bullet::CrashEnemy()
{
	//�ѽ��ӵ��ƶ��ٶȹ�����п���
	int mtox = x + mx;
	int mtoy = y + my;
	if (enemyicbt->BulletCrashEnemy(x,y,mtox,mtoy,DAMAGE))
	{
		x = mtox;
		y = mtoy;
		Restore();
	}
}
