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
	int threshold;		//	��ֵ
	vector<pair<int, int>*> tree;	//	��С������

public:
	connected_component();
	~connected_component();
	void changeThreshold(int threshold);	//	ʹ�ô˺������ı���ͨ����***************

private:
	int length;														//	·���ܳ���
	
	void findST();													//	����С����������tree���棬������
	void find(int* feature, int* last, int start, int num, int n);	//	�ݹ����
	void print();													//	�����json
};

#endif