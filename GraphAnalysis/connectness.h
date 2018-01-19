//连通中心度实现类

#ifndef CONNECT_NESS_H
#define CONNECT_NESS_H

#include "ExtractInformation.h"
#include "ShortestPath.h"
#include<QObject>
#include <QThread>

class connectness:public QThread
{
public:
	connectness();
	~connectness();
	void sumWayNum(); //	计算中心度

private:
	void print();	//	输出
	int* resWayNum;	//	总长度
};

#endif