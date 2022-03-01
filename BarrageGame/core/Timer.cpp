#include "..\pch.h"
#include "Timer.h"

int Timer::deltime=0;
double Timer::timescale = 1;

Timer::Timer()
{
	timescale=1;											//��Ϸʱ��߶� Ĭ��Ϊ1
	currenttime =timeGetTime();								//��ǰʱ��
	oldtime = currenttime;									//��һ֡����ʱ��
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
