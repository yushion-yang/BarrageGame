#pragma once
#include "..\Object.h"
#include "..\..\input\MouseInput.h"
//遇到问题：如何将lambda表达式存储起来，供后面调用使用
//已经解决：  发现编译器的缺陷问题 类的模板函数目前还无法分文件实现

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
	int x;												//坐标x
	int y;												//坐标x
	const TCHAR *str;									//显示的字符串
	bool ismouseon;										//是否被触及
	function< void(void)> cbfunc;						//回调方法
};