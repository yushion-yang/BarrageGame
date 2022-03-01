#include "..\pch.h"
#include "CollisionDetection.h"

double Distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

bool RsPointOnCircle(int px, int py, int cx, int cy, int cr)
{
	if ((px - cx)*(px - cx) + (py - cy)*(py - cy) < cr*cr)
	{
		return true;
	}
	return false;
}

bool RsPointOnRectangle(int px, int py, int lx, int ly, int width, int height)
{
	if (px > lx&&px<lx + width && py>ly&&py < ly + height)
	{
		return true;
	}
	return false;
}

bool RsLineOnCircle(int px1, int py1, int px2, int py2, int cx, int cy, int cr)
{
	//前置判断  缩减判断时间
	int diss = (abs(px1 - px2) + abs(py1 - py2) + cr);
	if ((cx - px1)*(cx - px1) + (cy - py1)*(cy - py1) > diss*diss)
	{
		return false;
	}
	if (((cx - px1)*(cx - px1) + (cy - py1)*(cy - py1) < cr*cr) ||
		((cx - px2)*(cx - px2) + (cy - py2)*(cy - py2) < cr*cr))
	{
		return true;				//如果线段端点在圆内则相交								
	}
	int a;
	int b;
	int c;
	//ax+by+c=0;			a = y2 - y1;			b = x1 - x2;
	if (px1 == px2)
	{
		a = 1, b = 0, c = -px1;				//特殊情况判断，分母不能为零
	}
	else if (py1 == py2)
	{
		a = 0, b = 1, c = -py1;				//特殊情况判断，分母不能为零
	}
	else
	{
		a = py1 - py2;
		b = px2 - px1;
		c = py2 * px1 - px2 * py1;
	}
	double dis1 = (a * cx + b * cy + c);
	dis1 *= dis1;
	double dis2 = (a*a + b * b)*cr*cr;
	//点到直线的距离
	if (dis1 > dis2)
	{
		return false;
	}
	double angle1 = (cx - px1) * (px2 - px1) + (cy - py1) * (py2 - py1);
	double angle2 = (cx - px2) * (px1 - px2) + (cy - py2) * (py1 - py2);
	if (angle1 > 0 && angle2 > 0)	//余弦都为正，则是锐角
	{
		return true;				
	}
	return false;
}

bool RsRectangleOnCircle(int lx, int ly, int width, int height, int cx, int cy, int cr)
{
	return false;
}
