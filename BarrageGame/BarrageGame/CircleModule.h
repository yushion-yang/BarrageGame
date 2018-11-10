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
	int radius;									//×é¼þ°ë¾¶
};
