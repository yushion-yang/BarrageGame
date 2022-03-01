#include "..\pch.h"
#include "MMTimer.h"

const int FRAME_INTERVAL = 17;
MMTimer::MMTimer()
{
	 QueryPerformanceFrequency(&mclk);
	 mfreq = (int)mclk.QuadPart / 1000;		// 获得计数器的时钟频率
											// 开始计时
	 QueryPerformanceCounter(&mclk);
	 moldclk = mclk.QuadPart;				// 获得开始时钟
	 ms = FRAME_INTERVAL * mfreq;
}

MMTimer::~MMTimer()
{

}

void MMTimer::Start()
{

}

void MMTimer::Update()
{
	moldclk += ms;

	QueryPerformanceCounter(&mclk);

	if (mclk.QuadPart > moldclk)
	{
		moldclk = mclk.QuadPart;
	}
	else
	{
		do
		{
			Sleep(1);
			QueryPerformanceCounter(&mclk);	// 获得终止时钟
		} while (mclk.QuadPart < moldclk);
	}
}

void MMTimer::Destroy()
{

}

void MMTimer::Draw()
{

}
