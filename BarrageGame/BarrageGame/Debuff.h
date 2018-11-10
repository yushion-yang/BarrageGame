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
