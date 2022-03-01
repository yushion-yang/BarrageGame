#include "..\pch.h"
#include "PathFile.h"

const char filepath[] = "Path.txt";
//const char usefilepath[] = "../��Ļ�����Ϸ-����/Path.txt";
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
	ifstream in;				//������	���ļ��л�ȡ����
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
		return;						//û�м�¼
	}
	for (int i = 0; in.peek() != EOF; i++)
	{
		Path *path = new Path();
		ss.clear();
		int pointnum;
		getline(in, line);
		if (line == "") {
			continue;
		}
		ss << line;
		ss >> pointnum;
		path->pointnum = pointnum;
		for (int j = 0; j < pointnum && in.peek() != EOF; )
		{
			getline(in, line);
			if (line == "") {
				continue;
			}
			j++;
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
//	ifstream in;				//������	���ļ��л�ȡ����
//	string line;
//	string temp;
//	in.open(usefilepath, ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		cout << "delete input usefile open error" << endl;
//		return;
//	}
//	//���ļ��м��ټ�¼
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
//	ofstream out;				//�����	д���ݵ��ļ���
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
//void PathFile::DelPath(int pos)				//ɾ�����±��0��ʼ		��ɾ����pos+1����¼
//{
//	if (pathnum <= 0)
//	{
//		cout << "û�м�¼����ɾ��" << endl;
//		return;
//	}
//	if (pos >= pathnum)
//	{
//		cout << "ɾ����ų�����¼��" << endl;
//		return;
//	}
//	stringstream ss;
//	ifstream in;				//������	���ļ��л�ȡ����
//	string line;
//	string temp;
//	in.open(filepath, ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		cout << "delete input file open error" << endl;
//		return;
//	}
//	//�ڶ��������м��ټ�¼
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
//	//���ļ��м��ټ�¼
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
//	ofstream out;				//�����	д���ݵ��ļ���
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
//	ifstream in;									//������ ���ļ��л�ȡ����
//
//	in.open(usefilepath, ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		cout << "input file open error" << endl;
//		ofstream out;								//���ļ�δ�����򴴽��ļ�
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
//	getline(ss, newInfo);							//��ss���ں�������ȡ����
//	if (in.peek() != EOF)
//	{
//		getline(in, line);
//	}
//	temp += newInfo + NEWLINE;
//
//	//���һ����¼
//	int size = listpoints->size();
//	ss.clear();
//	ss.fill(' ');
//	ss.setf(ios::left);
//	ss << space << size;
//	getline(ss, newInfo);//��ss���ں�������ȡ����
//	temp += newInfo + NEWLINE;
//	//�����·���ĵ�
//	auto lipoint = listpoints->begin();
//	int ox = (*lipoint)->x;
//	int oy = (*lipoint)->y;
//	for (; lipoint != listpoints->end(); ++lipoint)
//	{
//		stringstream infoTemp;
//		infoTemp.fill(' ');
//		infoTemp.setf(ios::left);
//		infoTemp << space << (*lipoint)->x - ox << space << (*lipoint)->y - oy;
//		getline(infoTemp, newInfo);		//��infoTemp���ں�������ȡ����
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
//	ofstream out;				//�����	д���ݵ��ļ���
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
//	paths.push_front(path);							//����·����ӵ�������
//
//	stringstream ss;
//	ifstream in;									//������ ���ļ��л�ȡ����
//
//	in.open(filepath, ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		cout << "input file open error" << endl;
//		ofstream out;								//���ļ�δ�����򴴽��ļ�
//		out.open(filepath, ios::out);
//		out.close();
//		cout << "create new file" << endl;
//	}
//
//	string temp;
//	string newInfo;
//	string line;
//	//��¼����������1
//	pathnum += 1;
//	ss.fill(' ');
//	ss.setf(ios::left);
//	ss << space << pathnum;
//	getline(ss, newInfo);	//��ss���ں�������ȡ����
//	if (in.peek() != EOF)
//	{
//		getline(in, line);
//	}
//	temp += newInfo + NEWLINE;
//
//	//���һ����¼
//	int size = listpoints->size();
//	ss.clear();
//	ss.fill(' ');
//	ss.setf(ios::left);
//	ss << space << size;
//	getline(ss, newInfo);//��ss���ں�������ȡ����
//	temp += newInfo + NEWLINE;
//	//�����·���ĵ�
//	for (auto lipoint = listpoints->begin(); lipoint != listpoints->end(); ++lipoint)
//	{
//		stringstream infoTemp;
//		infoTemp.fill(' ');
//		infoTemp.setf(ios::left);
//		infoTemp << space << (*lipoint)->x << space << (*lipoint)->y;
//		getline(infoTemp, newInfo);		//��infoTemp���ں�������ȡ����
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
//	ofstream out;				//�����	д���ݵ��ļ���
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

Path * PathFile::GetPath(int pos)	//��ȡ��¼�±�Ϊpos�ļ�¼  ����pos+1����¼
{
	//���⣺2018��11��3��20:48:37
	//ԭ���ļ���������˾ֲ�������ָ��...
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
