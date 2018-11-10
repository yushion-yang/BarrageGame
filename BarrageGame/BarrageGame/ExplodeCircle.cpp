#include "pch.h"
#include "ExplodeCircle.h"
#include "EffectsManager.h"

const int MAXRADIUS = 50;
const int MAXLASTTIME = 500;

ExplodeCircle::ExplodeCircle(EffectsManager *efsmanager1)
{
	efsmanager = efsmanager1;
	mradius = MAXRADIUS;
	lasttime = 0;
}

ExplodeCircle::~ExplodeCircle()
{
}


void ExplodeCircle::Update()
{
	lasttime += Timer::Deltime();
	if (lasttime > MAXLASTTIME)
	{
		efsmanager->RestoreEfs(this);
	}
}

void ExplodeCircle::Draw()
{
	int r = lasttime * 0.005*mradius;
	circle(x, y, r);
}

void ExplodeCircle::ReStart(int x1, int y1)
{
	x = x1;
	y = y1;
	lasttime = 0;
}

