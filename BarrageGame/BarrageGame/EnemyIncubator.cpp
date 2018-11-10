#include "pch.h"
#include "EnemyIncubator.h"
#include "DogFace.h"
#include <assert.h>
//遇到问题的思考  对象池  先生成一定数量的某一类对象  但是我想生成一个敌人的内存池  敌人有不同种类
//即很多敌人类型是基础敌人基类的  该如何分配内存		

//以下是解决方法：使用对象池 加定位new的方式分配对象空间 然后在使用到具体对象时在空间内创建类对象
//使用定位new在buff创建A类的对象a后会使用A类大小等同的字节来保存对象a的数据（包括虚基表）
//如果调用了显式析构函数 则虚基表会被释放 而其他的数据如果没有释放则不变 
//即调用派生类的函数会调用到基类的函数 调用类成员变量则值不变
class DogFace;
int enemynum = 0;

const int MAX_ENEMY_NUM = 5000;
const int ENEMY_CREATE_TIME = 1000;
const int TEST_NUM = 50;			//测试数量

const int MOVE_TIME_INTERVAL = 200;
const int RADIUS = 10;
int EnemyIncubator::movetime;

EnemyIncubator::EnemyIncubator()
{
	movetime = 0;
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
	movetime += Timer::Deltime();
	if (movetime > MOVE_TIME_INTERVAL)
	{
		movetime = 0;
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
	//显示敌人数量
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

		//基类定义统一接口则无需进行向下转型，而且运行时转型是比较耗费时间的操作 
		//哦对了  记得显示调用析构（这里就没有必要）
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
		//if (e->RsHit(x1, y1,mtox1,mtoy1))
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