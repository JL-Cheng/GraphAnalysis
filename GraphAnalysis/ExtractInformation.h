//用于提取数据集数据的类

#pragma once
#ifndef EXTRACTINFORMATION_H
#define EXTRACTINFORMATION_H
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1

#include<string>
#include<iostream>
#include<vector>
#include<hash_map>
#include<QObject>
#include <QThread>
using namespace std;
using namespace stdext;

//每个数据结点对应结构体
typedef struct movieData
{
	int ID;//编号
	string movieName;//电影名
	vector<pair<int, int>> connectNode;//与该结点相连接的结点，pair的第一个值为连接结点的ID，第二个值为权值
	int group;
	int betweenness;	//介数中心度
};

class extractInformation:public QThread
{
	Q_OBJECT

public:
	extractInformation();
	~extractInformation() {}

	void operate();//进行信息的提取
	static vector<movieData> list;//存储提取得到的的图的信息

signals:
	void sendRateOfProgress(int number);//告知进程

private:
	void splitString(const string& s, vector<string>& v, const string& c);//分割字符串
	void print();//将提取结果输出到文件中

	vector<hash_map<string, int>> reviewersList;//每个电影对应的影评人名单

	string fileName;//信息存储的文件名
};

#endif // !EXTRACTINFORMATION_H
