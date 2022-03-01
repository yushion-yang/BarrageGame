#pragma once
#include "..\Object.h"
#include "..\..\input\MouseInput.h"
//�������⣺��ν�lambda���ʽ�洢���������������ʹ��
//�Ѿ������  ���ֱ�������ȱ������ ���ģ�庯��Ŀǰ���޷����ļ�ʵ��

class Module:public Object
{
public:
	Module(int x1, int y1, const TCHAR *str1, function< void(void)> cbfunc1);
	virtual ~Module();
	virtual void Start();
	virtual void Update();
	virtual void Destroy();
	virtual void Draw();
protected:
	int x;												//����x
	int y;												//����x
	const TCHAR *str;									//��ʾ���ַ���
	bool ismouseon;										//�Ƿ񱻴���
	function< void(void)> cbfunc;						//�ص�����
};