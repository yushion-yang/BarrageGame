#pragma once
#include "Module.h"

class RectangleModule:public Module
{
public:
	RectangleModule(int x1, int y1, int width1, int height1, const TCHAR *str1, function< void(void)> cbfunc1);
	~RectangleModule();
	void Start();
	void Update();
	void Destroy();
	void Draw();
	void SetStr(TCHAR *str1);
private:
	int width;											//组件宽度
	int height;											//组件高度
};

