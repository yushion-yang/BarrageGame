#include "..\..\pch.h"
#include "CombatScene.h"
#include "..\..\game\GameManager.h"
#include "..\player\Player.h"
#pragma comment( lib,"winmm.lib" )
//���������  ��ͬ��char����֮���ת������

//�������⣺2018��10��30��18:03:45 EnemyIncubator�Ĺ��캯��û��ִ��
//������⣺��ʵ����ִ��  �����˷�����û���ȹ��� ������ʱ�Ὣ���� ���˷�������Ӹ��ӵ� ��ָ���쳣
TCHAR bkmusic[_MAX_PATH];
TCHAR bomb	 [_MAX_PATH];
TCHAR shoot	 [_MAX_PATH];

CombatScene::CombatScene(GameManager *gamemanager1) :Scene(gamemanager1)
{
	efsmanager = new EffectsManager();
	gameobjects.push_back(efsmanager);
	enemyicbt = new EnemyIncubator();
	gameobjects.push_back(enemyicbt);
	gameobjects.push_back(new Player(this));
	gameobjects.push_back(new FPS());

	InitMusic();
	PlayMusic();
	loadimage(&bkpicture, _T("IMAGE"), _T("bk"), WIDTH, HEIGHT);
	Resize(NULL, WIDTH, HEIGHT);									//�ý���Ŵ�
}

CombatScene::~CombatScene()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); )
	{
		delete (*obj);
		obj = gameobjects.erase(obj);
	}
}

void CombatScene::Update()
{
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Update();
	}
}

void CombatScene::Destroy()
{

}

void CombatScene::Draw()
{
//	putimage(0, 0, &bkpicture, SRCINVERT);
	for (auto obj = gameobjects.begin(); obj != gameobjects.end(); ++obj)
	{
		(*obj)->Draw();
	}
}

void CombatScene::InitMusic()
{
	SolveMusicFile(bkmusic,_T("bkmusic"));
	SolveMusicFile(bomb, _T("bomb"));
	SolveMusicFile(shoot, _T("shoot"));
}

void SolveMusicFile(TCHAR *sourcebuff, const TCHAR *musicname)
{
	TCHAR musicmp3[70];
	_stprintf_s(musicmp3, _T("%s.mp3"), musicname);			//ƴ�Ӻ�׺
	::GetTempPath(_MAX_PATH, sourcebuff);					//��ȡ��·��
	_tcscat_s(sourcebuff, sizeof(musicmp3) + 1, musicmp3);	//ƴ������·��
	ExtractResource(sourcebuff, _T("MP3"), musicname);		//�� MP3 ��Դ��ȡΪ��ʱ�ļ�
}

void CombatScene::PlayMusic()
{
	TCHAR mcicmd[70];
	_stprintf_s(mcicmd, _T("open \"%s\" alias mymusic"), bkmusic);
	mciSendString(mcicmd, NULL, 0, NULL);
	mciSendString(_T("play mymusic repeat"), NULL, 0, NULL);
}

EffectsManager * CombatScene::GetEfsManager()
{
	return efsmanager;
}

EnemyIncubator * CombatScene::GetEnemyIncubator()
{
	return enemyicbt;
}

bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	// �����ļ�
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// ������Դ�ļ��С�������Դ���ڴ桢�õ���Դ��С
	HRSRC	hRes = ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem = ::LoadResource(NULL, hRes);
	DWORD	dwSize = ::SizeofResource(NULL, hRes);

	// д���ļ�
	DWORD dwWrite = 0;  	// ����д���ֽ�
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}
