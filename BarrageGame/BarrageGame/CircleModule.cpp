#include "pch.h"
#include "CircleModule.h"

CircleModule::CircleModule(int x1, int y1, int radius1, const TCHAR * str1, function< void(void)> cbfunc1)
	:Module(x1, y1, str1, cbfunc1)
{
	radius = radius1;
}

CircleModule::~CircleModule()
{
}

void CircleModule::Update()
{
	ismouseon = false;
	if (MouseInput::RsOn(x, y, radius))
	{
		ismouseon = true;
	}
	if (MouseInput::RsLButtonDown()&& MouseInput::RsOn(x, y, radius))
	{
		cbfunc();
	}
}

void CircleModule::Destroy()
{
	Destroy();
}

void CircleModule::Draw()
{
	circle(x, y, radius);
	if (ismouseon)
	{
		circle(x, y, radius - 1);
		circle(x, y, radius - 2);
	}
	outtextxy(x - 20, y - 7, str);
}
