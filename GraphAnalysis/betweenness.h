#ifndef BETWEEN_NESS_H
#define BETWEEN_NESS_H

#include<QObject>
#include <QThread>
#include "ExtractInformation.h"
#include "ShortestPath.h"

class betweenness:public QThread
{
public:
	betweenness();
	~betweenness();
	void sumWayNum(); //	计算中心度

private:
	void print();	//	输出

	double* resMap;//	每一个点的介数中心度
	int* resWayNum;	//	存放每一点出现在所有最短路径中的次数
	int sumWay;		//	总最短道路数目
};

#endif