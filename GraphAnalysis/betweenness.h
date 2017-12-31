#ifndef BETWEEN_NESS_H
#define BETWEEN_NESS_H

#include "ExtractInformation.h"
#include "ShortestPath.h"

class betweenness
{
public:
	betweenness();
	~betweenness();
	double sumWayNum(int start, int end); //	计算从A到B的道路个数
	double sumWayPro(int start, int end, int target); //	计算比例
	double calBetweenness(int target);	//	计算target的中心度
	void print();	//	输出到json中

public:
	double* resMap;//	每一个点的介数中心度
	int* resWayNum;	//	存放每一点出现在所有最短路径中的次数
	int sumWay;		//	总最短道路数目
};

#endif