#ifndef CONNECTED_COMPONENT_H
#define CONNECTED_COMPONENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include<QObject>
#include <QThread>
#include "ExtractInformation.h"
using namespace std;

class connected_component:public QThread
{
public:
	int threshold;		//	阈值
	vector<pair<int, int>*> tree;	//	最小生成树

public:
	connected_component();
	~connected_component();
	void changeThreshold(int threshold);	//	使用此函数来改变联通分量***************

private:
	int length;														//	路径总长度
	
	void findST();													//	将最小生成树存在tree里面，主函数
	void find(int* feature, int* last, int start, int num, int n);	//	递归操作
	void print();													//	输出到json
};

#endif