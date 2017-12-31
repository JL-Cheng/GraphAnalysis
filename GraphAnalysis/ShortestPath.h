//用Dijkstra 算法求两点间最短路径

#pragma once
#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include"ExtractInformation.h"

struct node
{
	int ID;//数值
	int pre_ID;//前一个顶点数值
	int min_len;//与前一个点的最短距离
	int final_length;//到达这个点走的长度
	bool used;//是否已走过该店
	vector<int> path;//存储走到该点的路径
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
	vector<movieData> shortestPathList;//存储提取得到的的图的信息
	vector<int> shortestPath;//最短路径存放向量
};

#endif // !SHORTESTPATH_H



