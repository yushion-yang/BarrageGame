#pragma once
#include "Point.h"
#include <list>
using namespace std;

class Path
{
public:
//	Path(list<Point*>* pointlist1);
	Path();
	~Path();

	list<Point*> pointlist;
	int pointnum;
};