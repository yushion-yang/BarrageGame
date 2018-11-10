#include "pch.h"
#include "BleManager.h"

const int SHOOT_TIME = 200;
const int TEST_NUM = 1;			//≤‚ ‘ ˝¡ø
const int MOVE_TIME = 40;
const int BULLET_NUM = 2000;

int BleManager::movetime;

BleManager::BleManager()
{
	lbullets = new list<Bullet*>(BULLET_NUM);
	for (auto ble = (*lbullets).begin(); ble != (*lbullets).end(); ++ble)
	{
		*ble = new Bullet();
	}
	Bullet::interpolation = 1.0 / MOVE_TIME;
	Bullet::blemanager = this;
}

BleManager::~BleManager()
{
}

void BleManager::Update()
{
	shoottime += Timer::Deltime();
	if (shoottime > SHOOT_TIME)
	{
		shoottime = 0;
		for (int i = 0; i < TEST_NUM; i++)
			ShootBle();
	}
	movetime += Timer::Deltime();
	if (movetime > MOVE_TIME)
	{
		movetime = 0;
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

void BleManager::Draw()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Draw();
	}
}

void BleManager::ShootBle()
{
	if (!lbullets->empty())
	{
		int mx, my;
		MouseInput::GetMxy(mx, my);
		Bullet* ble = dynamic_cast<Bullet*>(lbullets->front());

		double x, y;
		Bullet::player->GetXy(x, y);
		ble->SetDirection(x, y, mx, my);
		gameobjects.push_back(ble);
		lbullets->pop_front();
	}
}

void BleManager::RestoreObject(Bullet * obj1)
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		if (*obj == obj1)
		{
			lbullets->push_back(obj1);
			objiterator = gameobjects.erase(obj);
			break;
		}
	}
}
