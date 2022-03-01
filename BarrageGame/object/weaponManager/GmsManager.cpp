#include "..\..\pch.h"
#include "GmsManager.h"

int directions[2][8] = { {-1,-1,-1,0,0,1,1,1} ,{-1,0,1,-1,1,-1,0,1} };
const int SHOOT_TIME = 2000;
const int TEST_NUM = 1;			//≤‚ ‘ ˝¡ø

const int MOVE_TIME = 40;
const int BULLET_NUM = 2000;

int GmsManager::movetimer;

GmsManager::GmsManager()
{
	lguidemissiles = new list<GuidedMissile*>(BULLET_NUM);
	for (auto gms = (*lguidemissiles).begin(); gms != (*lguidemissiles).end(); ++gms)
	{
		*gms = new GuidedMissile();
	}
	GuidedMissile::interpolation = 1.0 / MOVE_TIME;
	GuidedMissile::gmsmanager = this;
}

GmsManager::~GmsManager()
{

}

void GmsManager::Update()
{
	shoottime += Timer::Deltime();
	if (shoottime > SHOOT_TIME)
	{
		shoottime = 0;
		for (int i = 0; i < TEST_NUM; i++)
			ShootGms();
	}

	movetimer += Timer::Deltime();
	if (movetimer > MOVE_TIME)
	{
		movetimer = 0;
		for (objiterator = gameobjects.begin(); objiterator != gameobjects.end();)
		{
			(*objiterator)->Update();
			if (objiterator != gameobjects.end())
			{
				++objiterator;
			}
		}
	}
}

void GmsManager::Draw()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Draw();
	}
}

void GmsManager::ShootGms()
{
	for (int i = 0; i < 8; i++)
	{
		if (!lguidemissiles->empty())
		{
			GuidedMissile* gms = lguidemissiles->front();
			gms->SetDirection(directions[0][i], directions[1][i]);
			double x, y;
			GuidedMissile::player->GetXy(x, y);
			gms->SetXy(x, y);
			gameobjects.push_back(gms);
			lguidemissiles->pop_front();
		}
	}
}

void GmsManager::RestoreObject(GuidedMissile * obj1)
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		if (*obj == obj1)
		{
			lguidemissiles->push_back(obj1);
			objiterator = gameobjects.erase(obj);
			break;
		}
	}
}
