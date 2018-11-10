#pragma once
#include "Object.h"
#include "ConstValue.h"
class MMTimer
{
public:
	MMTimer();
	~MMTimer();
	void Start();
	void Update();
	void Destroy();
	void Draw();
private:
	LARGE_INTEGER mclk;					// 保存时钟信息
	LONGLONG moldclk;					// 保存开始时钟和结束时钟
	int mfreq;							// 时钟频率(时钟时间换算率)，时间差
	int ms;								// 延迟毫秒数
};
