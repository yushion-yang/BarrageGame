#include "..\..\pch.h"
#include "EffectsManager.h"
#include "ExplodeCircle.h"
//�������⣺2018��10��31��10:36:18 ����STL�����ĵ�����β++ ͷ-- ���������� 
//��ô����ڱ����Ĺ����н�������ɾ����

//������������ת�Ƶ���������ͳһ��������Ϊ������ӵ�е�������Ա������¼�����������ͨ������������ɾ��
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
