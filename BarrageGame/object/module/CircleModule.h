/***********************************************
���ߣ�����ʤ
ʱ�䣺2021��6��28��22:43:27
�汾��V0.1
��Ҫ�����Բ ��Ķ���
��ע��
************************************************/
#pragma once
#include "Module.h"
class CircleModule:public Module
{
public:
	CircleModule(int x1, int y1, int radius1,const TCHAR *str1 , function< void(void)> cbfunc1);
	~CircleModule();
	void Update();
	void Destroy();
	void Draw();
private:
	int radius;									//����뾶
};
