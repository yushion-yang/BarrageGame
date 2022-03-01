#include "..\..\pch.h"
#include "GuidedMissile.h"
#include "..\player\Player.h"
#include "GmsManager.h"

const int DAMAGE = 128;
const int MOVE_SPEED = 40;
const double CHANGE_CTA = 0.10;


double GuidedMissile::interpolation;
GmsManager* GuidedMissile::gmsmanager;

GuidedMissile::GuidedMissile()
{
	x = -100;							//当前坐标x
	y = -100;							//当前坐标y
	mx = 0;
	my = 0;
	emytarget = NULL;					//没有敌人目标
	rschangedir = true;					//是否需要改变方向
}

GuidedMissile::~GuidedMissile()
{

}

void GuidedMissile::Update()
{
	FindTarget();
	CrashEnemy();
	Move();
	ChangeDir();
}

void GuidedMissile::Draw()
{
	int x1 = x + GmsManager::movetimer * interpolation*mx;
	int y1 = y + GmsManager::movetimer * interpolation*my;
	fillcircle(x1, y1, 5);
	line(x1 - 5, y1, x1 + 5, y1);
	line(x1, y1 - 5, x1, y1 + 5);
}

void GuidedMissile::Move()
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

void GuidedMissile::SetDirection(double dirx1, double diry1)
{
	mx = MOVE_SPEED * dirx1;
	my = MOVE_SPEED * diry1;
}
void GuidedMissile::SetXy(double x1, double y1)
{
	x = x1;
	y = y1;
	emytarget = NULL;
	rschangedir = true;
}

void GuidedMissile::Restore()
{
	gmsmanager->RestoreObject(this);
}

void GuidedMissile::CrashEnemy()
{
	int mtox = x + mx;
	int mtoy = y + my;
	if (enemyicbt->BulletCrashEnemy(x, y, mtox, mtoy, DAMAGE))
	{
		gmsmanager->RestoreObject(this);
	}
}

void GuidedMissile::FindTarget()
{
	if (emytarget && !emytarget->IsSurvival())
	{
		emytarget = NULL;
	}
	if (emytarget)
	{
		return;
	}
	list<Enemy*> *uenemys = enemyicbt->GetEnemys();
	int len = uenemys->size();
	if (len == 0)
	{
		return;
	}
	int randn = rand() % len;
	auto emy = uenemys->begin();
	//攻击最低生命
	//int minhp = 100000000;
	//for (int i=0; i< len;++i, ++emy)
	//{
	//	int hp = (*emy)->enemy->GetHp();
	//	if (hp < minhp)
	//	{
	//		minhp = hp;
	//		emytarget = (*emy)->enemy;
	//	}
	//}
	//随机策略   这个比较好   在游戏体验上
	for (int i = 0; i < randn; ++i, ++emy)
	{
	}
	emytarget = *emy;
}

void GuidedMissile::ChangeDir()
{
	if (!emytarget)
	{
		return;
	}
	double x2, y2;
	int r;
	emytarget->GetXyr(x2, y2, r);
	double dis = sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y));
	double dis1 = sqrt(mx*mx + my * my);
	double dis2 = 100;
	if (dis < dis2)												//当距离目标较近的时候不使用转向
	{
		mx = dis1 / dis * (x2 - x);
		my = dis1 / dis * (y2 - y);
		return;
	}
	x2 = x2 - x;
	y2 = y2 - y;
	double dirx, diry;
	GetDir(mx, my, x2, y2, dirx, diry);
	SetDirection(dirx, diry);
}

void  GuidedMissile::GetDir(double x1, double y1, double x2, double y2, double &dirx, double &diry)
{
	double cta1 = atan2(x1, y1);
	double cta2 = atan2(x2, y2);
	double cta = GetCta(cta1, cta2);

	if (cta >= PI * CHANGE_CTA)
	{
		SetCat(cta1, PI * CHANGE_CTA);
	}
	else if (cta <= -PI * CHANGE_CTA)
	{
		SetCat(cta1, -PI * CHANGE_CTA);
	}
	else
	{
		cta1 = cta2;
		rschangedir = false;
	}
	dirx = sin(cta1);
	diry = cos(cta1);
}

double  GuidedMissile::GetCta(double cta1, double cta2)
{
	double cta = cta2 - cta1;
	if (cta > PI)
	{
		cta -= 2 * PI;
	}
	else if (cta < -PI)
	{
		cta += 2 * PI;
	}
	return cta;
}

void  GuidedMissile::SetCat(double & cta, double n)
{
	cta += n;
	if (cta > PI)
	{
		cta -= 2 * PI;
	}
	else if (cta < -PI)
	{
		cta += 2 * PI;
	}
}