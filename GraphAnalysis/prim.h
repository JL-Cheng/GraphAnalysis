#ifndef PRIM_H
#define PRIM_H
#include <iostream>
#include <vector>
#include <fstream>
#include "ExtractInformation.h"
using namespace std;

class prim
{
public:
	prim();
	~prim();

	vector<pair<int, int>*> tree;	//	��С������������Ϊ�ߵ�id
	int length; //	·���ܳ���

	void findST();	//	����С����������tree���棬������
	void find(int* feature, int* last, int start, int num, int n);	//	�ݹ����
	void print();	//	�����json
};


#endif