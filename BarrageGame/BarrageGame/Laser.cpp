#include "pch.h"
#include "Laser.h"
#include "Player.h"

const int MIN_LASER_LENGTH		 = 100;
const int MAX_LASER_LENGTH		 = 600;
const int FADE_TIME				 = 200;
const int LINE_INTERVAL			 = 200;
const int ADD_LENGTH_TIME		 = 20 ;
const int ATTACK_DAMAGE			 = 40 ;
const int HARM_TIME				 = 100;

Laser::Laser()
{
	laserlength = MIN_LASER_LENGTH;								//激光长度
	fadetime = 0;												//消退时间
	addlengthtime = 0;
	harmtime = 0;
}

Laser::~Laser()
{
}

void Laser::Update()
{
	addlengthtime += Timer::Deltime();
	if (addlengthtime > ADD_LENGTH_TIME&&GetAsyncKeyState(32))
	{
		addlengthtime = 0;
		laserlength += 40;
		laserlength = laserlength > MAX_LASER_LENGTH ? MAX_LASER_LENGTH : laserlength;
		fadetime = 0;
	}
	fadetime += Timer::Deltime();
	if (fadetime > FADE_TIME)
	{
		laserlength -= 100;
		laserlength = laserlength < MIN_LASER_LENGTH ? MIN_LASER_LENGTH : laserlength;
		fadetime = 0;
	}
	player->GetXy(x, y);
	harmtime += Timer::Deltime();
	if (harmtime > HARM_TIME)
	{
		harmtime = 0;
		CrashEnemy();
	}
}

void Laser::Draw()
{
	line(x, y - 20, x, y - 20 - laserlength);
	line(x + LINE_INTERVAL, y, x + LINE_INTERVAL, y - laserlength);
	line(x - LINE_INTERVAL, y, x - LINE_INTERVAL, y - laserlength);
}

void Laser::CrashEnemy()
{
	enemyicbt->CrashEnemy(([&](double x1, double y1, int r1)->int {
		if (RsLineOnCircle(x, y - 20, x, y - 20 - laserlength, x1, y1, r1)
			|| RsLineOnCircle(x + LINE_INTERVAL, y, x + LINE_INTERVAL, y - laserlength, x1, y1, r1)
			|| RsLineOnCircle(x - LINE_INTERVAL, y, x - LINE_INTERVAL, y - laserlength, x1, y1, r1))
		{
			return ATTACK_DAMAGE;
		}
		return 0;
	}));
}