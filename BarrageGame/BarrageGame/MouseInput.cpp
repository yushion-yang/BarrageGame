#include "pch.h"
#include "MouseInput.h"

MOUSEMSG MouseInput::m;										//为何要进行声明

MouseInput::MouseInput()
{

}

MouseInput::~MouseInput()
{

}

void MouseInput::Start()
{

}

void MouseInput::Update()
{
	while (MouseHit())	//获取更新鼠标信息
	{
		m = GetMouseMsg();
	}
}

void MouseInput::Destroy()
{
}

void MouseInput::Draw()
{

}

bool MouseInput::RsMosueMove()
{
	if (m.uMsg == WM_MOUSEMOVE)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsLButtonDown()
{
	if (m.uMsg == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsLButtonDBClick()
{
	if (m.uMsg == WM_LBUTTONDBLCLK)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsLButtonUp()
{
	if (m.uMsg == WM_LBUTTONUP)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsMButtonDown()
{
	if (m.uMsg == WM_MBUTTONDOWN)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsMButtonDBClick()
{
	if (m.uMsg == WM_MBUTTONDBLCLK)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsMButtonUp()
{
	if (m.uMsg == WM_MBUTTONUP)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsRButtonDown()
{
	if (m.uMsg == WM_RBUTTONDOWN)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsRButtonDBClick()
{
	if (m.uMsg == WM_RBUTTONDBLCLK)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsRButtonUp()
{
	if (m.uMsg == WM_RBUTTONUP)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsOn(int x1, int y1, int radius1)
{
	if ((m.x - x1)*(m.x - x1) + (m.y - y1)*(m.y - y1) < radius1*radius1)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsOn(int x1, int y1, int width1, int height1)
{
	if (m.x > x1&&m.x<x1 + width1 && m.y>y1&&m.y < y1 + height1)
	{
		return true;
	}
	return false;
}

void MouseInput::GetMxy(int & x1, int & y1)
{
	x1 = m.x;
	y1 = m.y;
}
