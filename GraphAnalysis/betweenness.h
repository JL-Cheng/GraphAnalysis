//�������Ķ�ʵ����

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

	void sumWayNum(); //	�������Ķ�

private:
	void print();	//	���
	int indexof(vector<pair<int, int>> x, int y);
	double* resWayNum;	//	���ÿһ�����Ķ�
};

#endif