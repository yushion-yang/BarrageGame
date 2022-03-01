#include "..\pch.h"
#include "FPS.h"

FPS::FPS()
{
	rectmodule = new RectangleModule(0.93*WIDTH, 0.01*HEIGHT, 80, 40, _T("FPS: 0"), []()->void {});
	framerate=0;					//֡�� ÿ��֡��	
	clktime=0;						//��ʱ��
	calnum=0;						//ͳ����
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
