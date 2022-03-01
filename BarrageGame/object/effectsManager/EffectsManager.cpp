#include "..\..\pch.h"
#include "EffectsManager.h"
#include "ExplodeCircle.h"
//遇到问题：2018年10月31日10:36:18 关于STL容器的迭代器尾++ 头-- 操作的问题 
//那么如何在遍历的过程中进行增加删除呢

//做法：将操作转移到管理者中统一操作，因为管理者拥有迭代器成员变量记录链表操作对象，通过迭代器进行删除
EffectsManager::EffectsManager()
{
	ueffects = new 	list<ExplodeCircle*>();
	leffects = new 	list<ExplodeCircle*>(OBJECT_NUM);
	for (auto efs = (*leffects).begin(); efs != (*leffects).end(); ++efs)
	{
		*efs = new ExplodeCircle(this);
	}
}

EffectsManager::~EffectsManager()
{
	for (auto efs = (*leffects).begin(); efs != (*leffects).end(); ++efs)
	{
		delete (*efs);
		efs = ueffects->erase(efs);
	}
	for (auto efs = (*leffects).begin(); efs != (*leffects).end(); ++efs)
	{
		delete (*efs);
		efs = ueffects->erase(efs);
	}
}

void EffectsManager::Update()
{
	for (efsiterator = ueffects->begin(); efsiterator != ueffects->end(); )
	{
		(*efsiterator)->Update();
		if (efsiterator != ueffects->end())
		{
			++efsiterator;
		}
	}
}

void EffectsManager::Draw()
{
	for (efsiterator = ueffects->begin(); efsiterator != ueffects->end(); ++efsiterator)
	{
		(*efsiterator)->Draw();
	}
}

void EffectsManager::CreateEfs(int x1,int y1)
{
	if (!leffects->empty())
	{
		leffects->front()->ReStart(x1, y1);
		ueffects->push_back(leffects->front());
		leffects->pop_front();
	}
}

void EffectsManager::RestoreEfs(ExplodeCircle * effects)
{
	for (auto efs = ueffects->begin(); efs != ueffects->end(); ++efs)
	{
		if (*efs == effects)
		{
			leffects->push_back(effects);
			efsiterator = ueffects->erase(efs);
			break;
		}
	}
}
