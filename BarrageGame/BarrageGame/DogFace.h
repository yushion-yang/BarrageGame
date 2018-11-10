#pragma once
#include "Enemy.h"

class DogFace:public Enemy
{
public:
	DogFace(int x1, int y1, EnemyIncubator *enemyicbt1, int pathindex1);
	~DogFace();
	//void Update();
	//void Destroy();
//	bool RsHit(int x1, int y1, int mtox1, int mtoy1);
private:

};
