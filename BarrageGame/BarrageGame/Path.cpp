#include "pch.h"
#include "Path.h"

//Path::Path(list<Point*>* pointlist1)
//{
//	for (auto ptl = pointlist1->begin(); ptl != pointlist1->end(); ++ptl)
//	{
//		pointlist.push_back(*ptl);
//	}
//	pointnum = pointlist1->size();
//}

Path::Path()
{

}

Path::~Path()
{
	pointlist.clear();
}
