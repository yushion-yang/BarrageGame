/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��10��28��14:45:55
�汾��V0.1
��Ҫ���������Ķ���
��ע��
************************************************/
#pragma once
#include <graphics.h>
#include <functional>
#include <vector>
#include <list>

using namespace std;

class Object
{
public:
	Object();
	~Object();
	virtual void Start();
	virtual void Update();
	virtual void Destroy();
	virtual void Draw();
protected:

};