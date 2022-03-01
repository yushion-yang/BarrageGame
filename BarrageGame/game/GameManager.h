/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��10��28��14:45:55
�汾��V0.1
��Ҫ����Ϸ��Ķ���
��ע��
************************************************/
#pragma once
#include <time.h>
#include "..\object\scene\FirstInterface.h"
#include "..\core\ConstValue.h"
#include "..\core\MMTimer.h"
#include "..\input\MouseInput.h"
#include "..\core\Timer.h"
class Scene;
class GameManager
{
public:
	GameManager();
	~GameManager();
	void Run();
	void InitGame();
	void ChangeScene(Scene *newscene);
	void ControllGame();
private:
	Scene *mainscene;
	MMTimer mmtimer;
	MouseInput mouseinput;
	Timer timer;
};
