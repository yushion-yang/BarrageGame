#pragma once
#include "..\Object.h"
#include "..\..\core\Timer.h"
//��Ч�Ĺ���  ��������ҹ����ǳ�����Ч�����߹���  ����Ҫ����Ч��ȡָ��ִ�й���
//Ϊ����ְ�𻮷ָ����� ���Բ��г�����Ч�����߹���

//��һ��˼�������ӵ�����Ч����һ�����	�������ֵĻ�ְ������  ���ҹ�������
//��������Ч����ǰ��Ч�ø�ʲô  �ӵ��������ӵ��ø�ʲô  ����ʲô�������Ƿ���Ҫ��������� 
class EffectsManager;
class ExplodeCircle:public Object
{
public:
	ExplodeCircle(EffectsManager *efsmanger1);
	~ExplodeCircle();
	void Update();
	void Draw();
	void ReStart(int x1, int y1);
private:
	int x;									//����x
	int y;									//����y
	int mradius;							//���뾶
	int lasttime;							//�ѳ���ʱ��
	EffectsManager *efsmanager;				//��Ч������
};
