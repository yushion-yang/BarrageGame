#include "..\..\pch.h"
#include "DogFace.h"

const int NOTHIT = 8;										//����������  �����������

DogFace::DogFace(int x1, int y1, EnemyIncubator *enemyicbt1,int pathindex1)
	:Enemy(x1,y1,enemyicbt1, pathindex1)
{
	//attributes &= ~NOTHIT;			//��������
	attributes |=  NOTHIT;		//�رչ���
}

DogFace::~DogFace()
{

}

//bool DogFace::IsHit(int x1, int y1,int mtox1,int mtoy1)
//{
//	if (Enemy::IsHit(x1,y1,mtox1,mtoy1) && (attributes & NOTHIT))			//����������  �����������
////	if (Enemy::IsHit(x1, y1,mtox1,mtoy1))								//����������  �����������
//	{
//		return true;
//	}
//	return false;
//}
