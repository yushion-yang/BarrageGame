#include "..\..\pch.h"
#include "EnemyIncubator.h"
#include "DogFace.h"
#include <assert.h>
//���������˼��  �����  ������һ��������ĳһ�����  ������������һ�����˵��ڴ��  �����в�ͬ����
//���ܶ���������ǻ������˻����  ����η����ڴ�		

//�����ǽ��������ʹ�ö���� �Ӷ�λnew�ķ�ʽ�������ռ� Ȼ����ʹ�õ��������ʱ�ڿռ��ڴ��������
//ʹ�ö�λnew��buff����A��Ķ���a���ʹ��A���С��ͬ���ֽ����������a�����ݣ����������
//�����������ʽ�������� �������ᱻ�ͷ� ���������������û���ͷ��򲻱� 
//������������ĺ�������õ�����ĺ��� �������Ա������ֵ����
class DogFace;
int enemynum = 0;

const int MAX_ENEMY_NUM = 1;		//����������
const int ENEMY_CREATE_TIME = 1000;	//���˲�����ʱ����
const int TEST_NUM = 50;			//��������

const int MOVE_TIME_INTERVAL = 200;	//���˵��ƶ����
const int RADIUS = 10;				//�������Ĵ�С?
int EnemyIncubator::movetimer;		//�ƶ��ļ�ʱ��	

EnemyIncubator::EnemyIncubator()
{
	movetimer = 0;
	int dogfacesize = sizeof(DogFace);
	uenemys = new list<Enemy*>();
	lenemys = new list<Enemy*>(MAX_ENEMY_NUM);
	for (auto emy = (*lenemys).begin(); emy != (*lenemys).end(); ++emy)
	{
		char *buff = new char[dogfacesize];
		*emy = new(buff) DogFace(0, 0, this, rand() % PathFile::pathnum);
	}
	Enemy::enemyicbt = this;
	Enemy::interpolation = 1.0 / MOVE_TIME_INTERVAL;
	Enemy::radius = RADIUS;
}

EnemyIncubator::~EnemyIncubator()
{

}

void EnemyIncubator::Update()
{
	movetimer += Timer::Deltime();
	if (movetimer > MOVE_TIME_INTERVAL)
	{
		movetimer = 0;
		for (emyiterator = uenemys->begin(); emyiterator != uenemys->end();)
		{
			(*emyiterator)->Update();
			if (emyiterator != uenemys->end())
			{
				++emyiterator;
			}
		}
	}
	createtime += Timer::Deltime();
	if (createtime > ENEMY_CREATE_TIME)
	{
		createtime = 0;
		for (int i = 0; i < TEST_NUM; i++)
		CreateEmy();
	}
}

void EnemyIncubator::Draw()
{
	for (emyiterator = uenemys->begin(); emyiterator != uenemys->end(); ++emyiterator)
	{
		(*emyiterator)->Draw();
	}
	//��ʾ��������
	TCHAR tips[10];
	_stprintf_s(tips, _T("%d"), enemynum);
	outtextxy(WIDTH - 40, HEIGHT - 30, tips);

}

void EnemyIncubator::CreateEmy()
{
	if (!lenemys->empty())
	{
		enemynum++;
		int x = rand() % (WIDTH >> 1) + WIDTH >> 1;
		int y = rand() % (HEIGHT >> 1);

		//���ඨ��ͳһ�ӿ��������������ת�ͣ���������ʱת���ǱȽϺķ�ʱ��Ĳ��� 
		//Ŷ����  �ǵ���ʾ���������������û�б�Ҫ��
		lenemys->front() = new(lenemys->front()) DogFace(x, y, this,rand()%PathFile::pathnum);
		//lenemys->front()->enemy = new(lenemys->front()->buff) DogFace(x, y, this, 0);
		//lenemys->front() = dynamic_cast<DogFace*>(lenemys->front());
		uenemys->push_back(lenemys->front());
		lenemys->pop_front();
	}
}

void EnemyIncubator::RestoreEmy(Enemy * emy1)
{
	enemynum--;
	for (auto emy = uenemys->begin(); emy != uenemys->end(); ++emy)
	{
		if (*emy == emy1)
		{
			lenemys->push_back(*emy);
			emyiterator = uenemys->erase(emy);
			break;
		}
	}
}

list<Enemy*>* EnemyIncubator::GetEnemys()
{
	return uenemys;
}

bool EnemyIncubator::BulletCrashEnemy(int x1, int y1,int &mtox1,int &mtoy1,int damage1)
{
	for (emyiterator = uenemys->begin(); emyiterator != uenemys->end();)
	{
		Enemy *e = *emyiterator;
		//e->GetMxy();
		double ex, ey, emx, emy;
		int eradius;
		e->GetMxy(ex,ey,emx,emy,eradius);
		if(RsLineOnCircle(x1, y1, mtox1+emx, mtoy1+emy, ex, ey, eradius))
		//if (e->IsHit(x1, y1,mtox1,mtoy1))
		{
			e->TakeDamage(damage1);
			mtox1 = ex;
			mtoy1 = ey;
			return true;
		}
		if (emyiterator != uenemys->end())
		{
			++emyiterator;
		}
	}
	return false;
}

void EnemyIncubator::CrashEnemy(function<int(double x1, double y1, int r1)> cbfunc)
{
	for (emyiterator = uenemys->begin(); emyiterator != uenemys->end();)
	{
		Enemy *e = *emyiterator;
		double x, y;
		int r;
		e->GetXyr(x, y, r);
		int damage = cbfunc(x, y, r);
		if (damage>0)
		{
			e->TakeDamage(damage);
		}
		if (emyiterator != uenemys->end())
		{
			++emyiterator;
		}
	}
}