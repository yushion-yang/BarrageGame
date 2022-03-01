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
	static int deltime;								//ÿ֡����ʱ��
	static double timescale;						//��Ϸʱ��߶� Ĭ��Ϊ1
	DWORD currenttime;								//��ǰʱ��
	DWORD oldtime;									//��һ֡����ʱ��
};
