#pragma once
#include "..\Object.h"
#include "Weapon.h"

class GmsManager;
class GuidedMissile:public Weapon
{
public:
	GuidedMissile();
	~GuidedMissile();
	void Update();
	void Draw();
	void Move();
	void SetDirection(double dirx1, double diry1);
	void Restore();
	void CrashEnemy();
	void ChangeDir();
	void FindTarget();
	void SetXy(double x1, double y1);
	void SetCat(double & cta, double n);
	double GetCta(double cta1, double cta2);
	void GetDir(double x1, double y1, double x2, double y2, double &dirx, double &diry);

	static GmsManager* gmsmanager;
	static double interpolation;
private:
	bool rschangedir;						//是否需要改变方向
	Enemy *emytarget;						//敌人目标
};