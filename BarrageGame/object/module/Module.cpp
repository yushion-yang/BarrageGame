#include "..\..\pch.h"
#include "Module.h"

Module::Module(int x1, int y1, const TCHAR * str1, function<void(void)> cbfunc1)
{
	x = x1;
	y = y1;
	str = str1;
	ismouseon = false;
	cbfunc = cbfunc1;
}

Module::~Module()
{
	Destroy();
}

void Module::Start()
{

}

void Module::Update()
{

}

void Module::Destroy()
{

}

void Module::Draw()
{

}
