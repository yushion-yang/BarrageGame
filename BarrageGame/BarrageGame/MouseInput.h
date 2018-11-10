#pragma once
#include "Object.h"
class MouseInput:public Object
{
public:
	MouseInput();
	~MouseInput();
	void Start();
	void Update();
	void Destroy();
	void Draw();
	static bool RsMosueMove();
	static bool RsLButtonDown();
	static bool RsLButtonDBClick();
	static bool RsLButtonUp();
	static bool RsMButtonDown();
	static bool RsMButtonDBClick();
	static bool RsMButtonUp();
	static bool RsRButtonDown();
	static bool RsRButtonDBClick();
	static bool RsRButtonUp();
	static bool RsOn(int x1, int y1, int radius1);
	static bool RsOn(int x1, int y1, int width1, int height1);
	static void GetMxy(int &x1, int &y1);
private:
	static MOUSEMSG m;
};
