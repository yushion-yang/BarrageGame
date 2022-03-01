#pragma once
#include "..\Object.h"
#include "..\..\core\ConstValue.h"

class ExplodeCircle;
class EffectsManager:public Object
{
public:
	EffectsManager();
	~EffectsManager();
	void Update();
	void Draw();
	void CreateEfs(int x1, int y1);
	void RestoreEfs(ExplodeCircle *obj);
private:
	list<ExplodeCircle*> *ueffects;
	list<ExplodeCircle*> *leffects;
	list<ExplodeCircle*>::iterator efsiterator;
};
