#pragma once
#include "Object.h"
#include "Timer.h"
//特效的管理  无论是玩家管理还是场景特效管理者管理  都需要让特效获取指针执行管理
//为了让职责划分更清晰 所以才有场景特效管理者管理

//另一种思考：将子弹和特效绑定在一起管理	不过这种的话职责不清晰  而且管理不方便
//比如在特效产生前特效该干什么  子弹消除后子弹该干什么  假如什么都不干是否需要清除出队列 
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
	int x;									//坐标x
	int y;									//坐标y
	int mradius;							//最大半径
	int lasttime;							//已持续时间
	EffectsManager *efsmanager;				//特效管理者
};
