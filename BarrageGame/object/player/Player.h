#pragma once
#include "..\Object.h"
#include "..\scene\CombatScene.h"
#include "..\skillManager\SkillManager.h"
#include "..\weaponManager\WeaponManager.h"
//又产生了和Bullet的相互调用
//进行尝试：2018年11月1日11:11:54 将会追踪的子弹添加到游戏中
//先测试数学几何模型

class Player:public Object
{
public:
	Player(CombatScene *scene1);
	~Player();
	void Move();
	void Update();
	void Draw();
	void GetXy(double &x1, double &y1);

private:
	double x;											//坐标
	double y;
	int radius;											//半径

	double horizontalx;									//每次移动的距离
	double verticalx;									//垂直移动速度
	int movetime;										//控制移动时间

	list<Object*> gameobjects;							//子物体
};
