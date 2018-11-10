#include "pch.h"
#include "PathFile.h"

const char filepath[] = "Path.txt";
//const char usefilepath[] = "../弹幕射击游戏-重做/Path.txt";
int PathFile::pathnum;
list<Path*> PathFile::paths;

PathFile::PathFile()
{
	ReadPaths();
}

PathFile::~PathFile()
{
	paths.clear();
}

void PathFile::ReadPaths()
{
	stringstream ss;
	ifstream in;				//输入流	从文件中获取数据
	string line;
	in.open(filepath, ios::in | ios::binary);
	if (!in.is_open())
	{
		cout << "read input file open error" << endl;
		return;
	}
	if (in.peek() != EOF)
	{
		getline(in, line);
		ss << line;
		ss >> pathnum;
	}
	else
	{
		pathnum = 0;
		return;						//没有记录
	}
	for (int i = 0; in.peek() != EOF; i++)
	{
		Path *path = new Path();
		ss.clear();
		int pointnum;
		getline(in, line);
		ss << line;
		ss >> pointnum;
		path->pointnum = pointnum;
		for (int j = 0; j < pointnum; j++)
		{
			getline(in, line);
			ss << line;
			int x, y;
			ss >> x >> y;
			path->pointlist.push_back(new Point(x, y));
		}
		paths.push_back(path);
	}
}

//void DelUseFilePath(int pos)
//{
//	stringstream ss;
//	ifstream in;				//输入流	从文件中获取数据
//	string line;
//	string temp;
//	in.open(usefilepath, ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		cout << "delete input usefile open error" << endl;
//		return;
//	}
//	//在文件中减少记录
//	if (in.peek() != EOF)
//	{
//		getline(in, line);
//	}
//	temp += line + NEWLINE;
//	for (int i = 0; in.peek() != EOF; i++)
//	{
//		ss.clear();
//		int size;
//		getline(in, line);
//		ss << line;
//		ss >> size;
//		if (i != pos)
//		{
//			temp += line + NEWLINE;
//		}
//		for (int j = 0; j < size; j++)
//		{
//			getline(in, line);
//			if (i != pos)
//			{
//				temp += line + NEWLINE;
//			}
//		}
//	}
//	ofstream out;				//输出流	写数据到文件中
//	out.open(usefilepath, ios::out);
//	if (!out.is_open())
//	{
//		cout << "output file open error" << endl;
//		return;
//	}
//	out << temp;
//	out.close();
//}
//
//void PathFile::DelPath(int pos)				//删除的下标从0开始		即删除第pos+1条记录
//{
//	if (pathnum <= 0)
//	{
//		cout << "没有记录可以删除" << endl;
//		return;
//	}
//	if (pos >= pathnum)
//	{
//		cout << "删除编号超过记录数" << endl;
//		return;
//	}
//	stringstream ss;
//	ifstream in;				//输入流	从文件中获取数据
//	string line;
//	string temp;
//	in.open(filepath, ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		cout << "delete input file open error" << endl;
//		return;
//	}
//	//在对象链表中减少记录
//	pathnum--;
//	auto pat = paths.begin();
//	for (int i = 0; pat != paths.end(); ++i, ++pat)
//	{
//		if (i == pos)
//		{
//			paths.erase(pat);
//			break;
//		}
//	}
//	//在文件中减少记录
//	if (in.peek() != EOF)
//	{
//		getline(in, line);
//	}
//	temp += line + NEWLINE;
//	for (int i = 0; in.peek() != EOF; i++)
//	{
//		ss.clear();
//		int size;
//		getline(in, line);
//		ss << line;
//		ss >> size;
//		if (i != pos)
//		{
//			temp += line + NEWLINE;
//		}
//		for (int j = 0; j < size; j++)
//		{
//			getline(in, line);
//			if (i != pos)
//			{
//				temp += line + NEWLINE;
//			}
//		}
//	}
//	ofstream out;				//输出流	写数据到文件中
//	out.open(filepath, ios::out);
//	if (!out.is_open())
//	{
//		cout << "output file open error" << endl;
//		return;
//	}
//	out << temp;
//	out.close();
//	DelUseFilePath(pos);
//}
//
//void AddUseFilePath(list <Point*>* listpoints, int pathnum)
//{
//	Path *path = new Path(listpoints);
//
//	stringstream ss;
//	ifstream in;									//输入流 从文件中获取数据
//
//	in.open(usefilepath, ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		cout << "input file open error" << endl;
//		ofstream out;								//若文件未创建则创建文件
//		out.open(usefilepath, ios::out);
//		out.close();
//		cout << "create new file" << endl;
//	}
//
//	string temp;
//	string newInfo;
//	string line;
//
//	ss.fill(' ');
//	ss.setf(ios::left);
//	ss << space << pathnum;
//	getline(ss, newInfo);							//从ss（内核流）获取内容
//	if (in.peek() != EOF)
//	{
//		getline(in, line);
//	}
//	temp += newInfo + NEWLINE;
//
//	//添加一条记录
//	int size = listpoints->size();
//	ss.clear();
//	ss.fill(' ');
//	ss.setf(ios::left);
//	ss << space << size;
//	getline(ss, newInfo);//从ss（内核流）获取内容
//	temp += newInfo + NEWLINE;
//	//添加新路径的点
//	auto lipoint = listpoints->begin();
//	int ox = (*lipoint)->x;
//	int oy = (*lipoint)->y;
//	for (; lipoint != listpoints->end(); ++lipoint)
//	{
//		stringstream infoTemp;
//		infoTemp.fill(' ');
//		infoTemp.setf(ios::left);
//		infoTemp << space << (*lipoint)->x - ox << space << (*lipoint)->y - oy;
//		getline(infoTemp, newInfo);		//从infoTemp（内核流）获取内容
//		temp += newInfo + NEWLINE;
//	}
//
//	while (in.peek() != EOF)
//	{
//		string line;
//		getline(in, line);
//		temp += line + NEWLINE;
//	}
//	in.close();
//
//	ofstream out;				//输出流	写数据到文件中
//	out.open(usefilepath, ios::out);
//	if (!out.is_open())
//	{
//		cout << "output file open error" << endl;
//		return;
//	}
//	out << temp;
//	out.close();
//}
//
//void PathFile::AddPath(list<Point*>* listpoints)
//{
//	Path *path = new Path(listpoints);
//	paths.push_front(path);							//将新路径添加到链表中
//
//	stringstream ss;
//	ifstream in;									//输入流 从文件中获取数据
//
//	in.open(filepath, ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		cout << "input file open error" << endl;
//		ofstream out;								//若文件未创建则创建文件
//		out.open(filepath, ios::out);
//		out.close();
//		cout << "create new file" << endl;
//	}
//
//	string temp;
//	string newInfo;
//	string line;
//	//记录的数据量加1
//	pathnum += 1;
//	ss.fill(' ');
//	ss.setf(ios::left);
//	ss << space << pathnum;
//	getline(ss, newInfo);	//从ss（内核流）获取内容
//	if (in.peek() != EOF)
//	{
//		getline(in, line);
//	}
//	temp += newInfo + NEWLINE;
//
//	//添加一条记录
//	int size = listpoints->size();
//	ss.clear();
//	ss.fill(' ');
//	ss.setf(ios::left);
//	ss << space << size;
//	getline(ss, newInfo);//从ss（内核流）获取内容
//	temp += newInfo + NEWLINE;
//	//添加新路径的点
//	for (auto lipoint = listpoints->begin(); lipoint != listpoints->end(); ++lipoint)
//	{
//		stringstream infoTemp;
//		infoTemp.fill(' ');
//		infoTemp.setf(ios::left);
//		infoTemp << space << (*lipoint)->x << space << (*lipoint)->y;
//		getline(infoTemp, newInfo);		//从infoTemp（内核流）获取内容
//		temp += newInfo + NEWLINE;
//	}
//
//	while (in.peek() != EOF)
//	{
//		string line;
//		getline(in, line);
//		temp += line + NEWLINE;
//	}
//	in.close();
//
//	ofstream out;				//输出流	写数据到文件中
//	out.open(filepath, ios::out);
//	if (!out.is_open())
//	{
//		cout << "output file open error" << endl;
//		return;
//	}
//	out << temp;
//	out.close();
//	AddUseFilePath(listpoints, pathnum);
//}

Path * PathFile::GetPath(int pos)	//获取记录下标为pos的记录  即第pos+1条记录
{
	//问题：2018年11月3日20:48:37
	//原因：文件链表添加了局部变量的指针...
	if (pos >= pathnum || pos < 0)
	{
		return nullptr;
	}
	auto pat = paths.begin();
	for (int i = 0; pat != paths.end() && i < pos; ++i, ++pat)
	{

	}
	return *pat;
}
