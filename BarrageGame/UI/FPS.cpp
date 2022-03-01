#include "..\pch.h"
#include "FPS.h"

FPS::FPS()
{
	rectmodule = new RectangleModule(0.93*WIDTH, 0.01*HEIGHT, 80, 40, _T("FPS: 0"), []()->void {});
	framerate=0;					//帧率 每秒帧数	
	clktime=0;						//计时器
	calnum=0;						//统计量
}

FPS::~FPS()
{

}

void FPS::Start()
{

}

void FPS::Update()
{
	if (Timer::GetTimeScale() == 0)
	{
		return;
	}
	clktime += Timer::Deltime();
	if (clktime > 1000)
	{
		clktime = 0;
		framerate = calnum;
		_stprintf_s(cfps, _T("FPS:%2d"), framerate);
		rectmodule->SetStr(cfps);
		calnum = 0;
	}
	calnum++;
}


void FPS::Destroy()
{

}

void FPS::Draw()
{
	rectmodule->Draw();
}
