#include "betweenness.h"
#include <fstream>

betweenness::betweenness()
{
	int n = extractInformation::list.size();
	resWayNum = new int[n];
	resMap = new double[n];
	for(int i = 0; i<n; i++)
	{
		resWayNum[i] = 0;
		resMap[i] = 0.5;
	}
	sumWay = 0;

}

betweenness::~betweenness()
{
	delete []resMap;
	delete []resWayNum;
	sumWay = 0;
}

void betweenness::sumWayNum()
{
	int n = extractInformation::list.size();
	int **value = new int*[n];
	for(int i = 0; i<n; i++)
	{
		value[i] = new int[n];
		for(int j = 0; j<n; j++)
		{
			value[i][j] = -1;
		}
	}
	vector<int> **path = new vector<int>*[n];
	for(int i = 0; i<n; i++)
	{
		path[i] = new vector<int>[n];
	}
	msleep(3);
	for(int i = 0; i<n; i++)
	{
		int k = extractInformation::list[i].connectNode.size();
		for(int j = 0; j<k; j++)
		{
			path[i][j].push_back(j);
			value[i][j] = extractInformation::list[i].connectNode[j].second;
		}
	}
	
	for(int k = 0; k<n; k++)
	{
		msleep(3);
		int k1 = extractInformation::list[k].connectNode.size();
		for(int i = 0; i<k1; i++)
		{
			for(int j = 0; j<k1; j++)
			{
				if(j != k && (value[i][k] + value[k][j] < value[i][j] || value[i][j] == -1))
				{
					path[i][j].clear();
					value[i][j] = value[i][k] + value[k][j];
					for(auto it = path[i][k].begin(); it != path[i][k].end(); it++)
					{
						path[i][j].push_back(*it);
					}
					for(auto it = path[k][j].begin(); it != path[k][j].end(); it++)
					{
						path[i][j].push_back(*it);
					}
				}
			}
		}
	}
	int sumWay = 0;
	for(int i = 0; i<n; i++)
	{
		msleep(3);
		for(int j = 0; j<n; j++)
		{
			if(path[i][j].size() != 0)
			{
				sumWay ++;
				cout << path[i][j].size();
				for(auto it = path[i][j].begin(); it != path[i][j].end(); it++)
				{
					resWayNum[*it] ++;
				}	
			}
		}
	}
	for(int i = 0; i<n; i++)
	{
		resMap[i] += (((double)resWayNum[i]))/(((double)sumWay)/2000);
	}

	for(int i = 0; i<n; i++)
	{
		delete value[i];
	}

	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			path[i][j].swap(vector<int>());
		}
	}

	print();
}

void betweenness::print()
{
	string tempLine, text1 = "", text2 = "";

	ifstream infile1("text3.txt");
	if (!infile1.is_open())//打开文件失败，返回
		exit(-1);
	while (getline(infile1, tempLine))
	{
		text1 += tempLine + "\n";
	}

	ifstream infile2("text4.txt");
	if (!infile2.is_open())//打开文件失败，返回
		exit(-1);
	while (getline(infile2, tempLine))
	{
		text2 += tempLine + "\n";
	}
	ofstream outfile("betweenness.html");
	outfile << text1;
	outfile << "var nodes=[\n";

	for(int i = 0; i<extractInformation::list.size(); i++)
	{
		outfile << "{\"id\":\"" << extractInformation::list[i].movieName << "\",\"value\":" << resMap[i];
		if(i != extractInformation::list.size()-1)
		{
			outfile << "}," <<endl;
		}
		else
		{
			outfile << "}];\n";
		}
	}
	outfile << text2;
	outfile.close();
	infile1.close();
	infile2.close();
}