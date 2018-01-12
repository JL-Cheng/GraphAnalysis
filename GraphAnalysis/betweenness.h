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
	void sumWayNum(); //	�������Ķ�

private:
	void print();	//	���

	double* resMap;//	ÿһ����Ľ������Ķ�
	int* resWayNum;	//	���ÿһ��������������·���еĴ���
	int sumWay;		//	����̵�·��Ŀ
};

#endif