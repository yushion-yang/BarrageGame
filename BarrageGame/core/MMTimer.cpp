#include "..\pch.h"
#include "MMTimer.h"

const int FRAME_INTERVAL = 17;
MMTimer::MMTimer()
{
	 QueryPerformanceFrequency(&mclk);
	 mfreq = (int)mclk.QuadPart / 1000;		// ��ü�������ʱ��Ƶ��
											// ��ʼ��ʱ
	 QueryPerformanceCounter(&mclk);
	 moldclk = mclk.QuadPart;				// ��ÿ�ʼʱ��
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
			QueryPerformanceCounter(&mclk);	// �����ֹʱ��
		} while (mclk.QuadPart < moldclk);
	}
}

void MMTimer::Destroy()
{

}

void MMTimer::Draw()
{

}
