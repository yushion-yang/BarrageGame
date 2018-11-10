#include "pch.h"
#include "CombatScene.h"
#include "GameManager.h"
#include "Player.h"
#pragma comment( lib,"winmm.lib" )
//遇到问题的  不同的char类型之间的转换问题

//遇到问题：2018年10月30日18:03:45 EnemyIncubator的构造函数没有执行
//解决问题：其实是有执行  但敌人孵化器没有先构造 添加玩家时会将场景 敌人孵化器添加给子弹 空指针异常
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
	Resize(NULL, WIDTH, HEIGHT);									//让界面放大
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
	_stprintf_s(musicmp3, _T("%s.mp3"), musicname);			//拼接后缀
	::GetTempPath(_MAX_PATH, sourcebuff);					//获取根路径
	_tcscat_s(sourcebuff, sizeof(musicmp3) + 1, musicmp3);	//拼接完整路径
	ExtractResource(sourcebuff, _T("MP3"), musicname);		//将 MP3 资源提取为临时文件
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
	// 创建文件
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// 查找资源文件中、加载资源到内存、得到资源大小
	HRSRC	hRes = ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem = ::LoadResource(NULL, hRes);
	DWORD	dwSize = ::SizeofResource(NULL, hRes);

	// 写入文件
	DWORD dwWrite = 0;  	// 返回写入字节
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}
