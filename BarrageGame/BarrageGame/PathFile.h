#pragma once
#include "Path.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <list>

#define space setw(20)
constexpr auto NEWLINE = "\r\n";

using namespace std;

class PathFile
{
public:
	PathFile();
	~PathFile();
	static void ReadPaths();
	//void DelPath(int pos);
	//void AddPath(list<Point*>*listpoints);
	static Path* GetPath(int pos);

	static list<Path*> paths;
	static int pathnum;
};
