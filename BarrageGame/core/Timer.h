#pragma once
#include <graphics.h>	
#pragma comment( lib,"winmm.lib" )

class Timer
{
public:
	Timer();
	~Timer();
	void Update();
	static int Deltime();
	static void SetTimeScale(double timescale1);
	static double GetTimeScale();
private:
	static int deltime;								//每帧经过时间
	static double timescale;						//游戏时间尺度 默认为1
	DWORD currenttime;								//当前时间
	DWORD oldtime;									//上一帧调用时间
};
