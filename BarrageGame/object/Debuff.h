/***********************************************
���ߣ�����ʤ
ʱ�䣺2021��6��28��22:44:38
�汾��V0.1
��Ҫ������Ч����Ķ���
��ע��
************************************************/
#pragma once
#include "Object.h"
class Debuff:public Object
{
public:
	Debuff();
	~Debuff();
	virtual void Start();
	virtual void Update();
	virtual void Destroy();
	virtual void Draw();
protected:
	TCHAR *name;	
	DWORD gettime;
	DWORD t1;
	int num;
	int max_num;
};
