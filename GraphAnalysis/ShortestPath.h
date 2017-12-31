//��Dijkstra �㷨����������·��

#pragma once
#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include"ExtractInformation.h"

struct node
{
	int ID;//��ֵ
	int pre_ID;//ǰһ��������ֵ
	int min_len;//��ǰһ�������̾���
	int final_length;//����������ߵĳ���
	bool used;//�Ƿ����߹��õ�
	vector<int> path;//�洢�ߵ��õ��·��
};

class searchShortestPath
{
public:
	searchShortestPath();
	~searchShortestPath() {}

	void toFindShortestPath();

private:
	void printShortestPath();
	extractInformation information;
	vector<movieData> shortestPathList;//�洢��ȡ�õ��ĵ�ͼ����Ϣ
	vector<int> shortestPath;//���·���������
};

#endif // !SHORTESTPATH_H



