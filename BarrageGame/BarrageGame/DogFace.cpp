#include "pch.h"
#include "DogFace.h"

const int NOTHIT = 8;										//µÚÈýºÅÊôÐÔ  µÖÓù¹¥»÷¼ì²â

DogFace::DogFace(int x1, int y1, EnemyIncubator *enemyicbt1,int pathindex1)
	:Enemy(x1,y1,enemyicbt1, pathindex1)
{
	//attributes &= ~NOTHIT;			//¿ªÆô¹¦ÄÜ
	attributes |=  NOTHIT;		//¹Ø±Õ¹¦ÄÜ
}

DogFace::~DogFace()
{

}

//bool DogFace::RsHit(int x1, int y1,int mtox1,int mtoy1)
//{
//	if (Enemy::RsHit(x1,y1,mtox1,mtoy1) && (attributes & NOTHIT))			//µÚÈýºÅÊôÐÔ  µÖÓù¹¥»÷¼ì²â
////	if (Enemy::RsHit(x1, y1,mtox1,mtoy1))								//µÚÈýºÅÊôÐÔ  µÖÓù¹¥»÷¼ì²â
//	{
//		return true;
//	}
//	return false;
//}
