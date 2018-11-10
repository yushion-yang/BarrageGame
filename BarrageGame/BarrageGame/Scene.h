#pragma once
#include "Object.h"
#include "CircleModule.h"
#include "RectangleModule.h"
//问题：在写好场景转换之后遇到了Scene类无法识别的问题，导致gamemanager也出现报错
//A B相互包含  C继承B  然后在C中报错  C没有定义基类
//解决 使用指针  在需要调用GameManager类方法的源文件中添加GameManager的头文件
class GameManager;
class Scene:public Object
{
public:
	Scene(GameManager *gamemanager1);
	virtual ~Scene();
	virtual void Start();
	virtual void Update();
	virtual void Destroy();
	virtual void Draw();
protected:
	GameManager *gamemanager;
};
