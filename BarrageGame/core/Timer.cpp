#include "..\pch.h"
#include "Timer.h"

int Timer::deltime=0;
double Timer::timescale = 1;

Timer::Timer()
{
	timescale=1;											//游戏时间尺度 默认为1
	currenttime =timeGetTime();								//当前时间
	oldtime = currenttime;									//上一帧调用时间
}

Timer::~Timer()
{
}

void Timer::Update()
{
	currenttime = timeGetTime();
	deltime = (currenttime - oldtime)*timescale;
	oldtime = currenttime;
}

int Timer::Deltime()
{
	return deltime;
}

void Timer::SetTimeScale(double timescale1)
{
	timescale = timescale1;
}

double Timer::GetTimeScale()
{
	return timescale;
}
