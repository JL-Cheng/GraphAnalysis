//��ͨ���Ķ�ʵ����

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
	void sumWayNum(); //	�������Ķ�

private:
	void print();	//	���
	int* resWayNum;	//	�ܳ���
};

#endif