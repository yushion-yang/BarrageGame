#pragma once
#include "..\object\Object.h"
#include "..\object\module\RectangleModule.h"
#include "..\core\Timer.h"
#include "..\core\ConstValue.h"

class FPS:public Object
{
public:
	FPS();
	~FPS();
	void Start();
	void Update();
	void Destroy();
	void Draw();
private:
	RectangleModule *rectmodule;
	int framerate;					//֡��

	int clktime;					//��ʱ��
	TCHAR cfps[10];					//��ʾ���ַ�
	int calnum;						//ͳ����
};
