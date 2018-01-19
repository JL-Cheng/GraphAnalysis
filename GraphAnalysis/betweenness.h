//介数中心度实现类

#ifndef BETWEEN_NESS_H
#define BETWEEN_NESS_H

#include "ExtractInformation.h"
#include "ShortestPath.h"
#include<QObject>
#include <QThread>

class betweenness:public QThread
{
public:
	betweenness();
	~betweenness();

	void sumWayNum(); //	计算中心度

private:
	void print();	//	输出
	int indexof(vector<pair<int, int>> x, int y);
	double* resWayNum;	//	存放每一点中心度
};

#endif