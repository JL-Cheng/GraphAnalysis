#ifndef BETWEEN_NESS_H
#define BETWEEN_NESS_H

#include "ExtractInformation.h"
#include "ShortestPath.h"

class betweenness
{
public:
	betweenness();
	~betweenness();
	double sumWayNum(int start, int end); //	�����A��B�ĵ�·����
	double sumWayPro(int start, int end, int target); //	�������
	double calBetweenness(int target);	//	����target�����Ķ�
	void print();	//	�����json��

public:
	double* resMap;//	ÿһ����Ľ������Ķ�
	int* resWayNum;	//	���ÿһ��������������·���еĴ���
	int sumWay;		//	����̵�·��Ŀ
};

#endif