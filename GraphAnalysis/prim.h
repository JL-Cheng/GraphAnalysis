//最小生成树实现的prim算法类

#ifndef PRIM_H
#define PRIM_H
#include <iostream>
#include <vector>
#include <fstream>
#include<QObject>
#include <QThread>
#include "ExtractInformation.h"
using namespace std;

class prim :public QThread
{
public:
	prim();
	~prim();

	vector<pair<int, int>*> tree;	//	最小生成树，内容为边的id
	int length; //	路径总长度

	void findST();	//	将最小生成树存在tree里面，主函数

private:
	void find(int* feature, int* last, int start, int num, int n);	//	递归操作
	void print();	//	输出到html
};


#endif