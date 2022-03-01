#pragma once
#include "Scene.h"
#include "..\..\UI\FPS.h"
#include "..\effectsManager\EffectsManager.h"
#include "..\enemyIncubator\EnemyIncubator.h"

class GameManager;

bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);
void SolveMusicFile(TCHAR *sourcebuff, const TCHAR *musicname);

class CombatScene:public Scene
{
public:
	CombatScene(GameManager *gamemanager1);
	~CombatScene();
	void Update();
	void Destroy();
	void Draw();
	void InitMusic();
	void PlayMusic();
	EffectsManager* GetEfsManager();
	EnemyIncubator* GetEnemyIncubator();
private:
	list<Object*> gameobjects;
	IMAGE bkpicture;
	EffectsManager *efsmanager;
	EnemyIncubator *enemyicbt;						//���˷�����
};
