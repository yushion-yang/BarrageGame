#pragma once
#include "..\object\Object.h"
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
	LARGE_INTEGER mclk;					// ����ʱ����Ϣ
	LONGLONG moldclk;					// ���濪ʼʱ�Ӻͽ���ʱ��
	int mfreq;							// ʱ��Ƶ��(ʱ��ʱ�任����)��ʱ���
	int ms;								// �ӳٺ�����
};
