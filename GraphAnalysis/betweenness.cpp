#include "betweenness.h"
#include <fstream>

betweenness::betweenness()
{
	int n = extractInformation::list.size();
	resWayNum = new double[n];
	for(int i = 0; i<n; i++)
	{
		resWayNum[i] = 0.0;
	}
}

int betweenness::indexof(vector<pair<int, int>> x, int y)
{
	int num = -1;
	for(auto it = x.begin(); it != x.end(); it++)
	{
		num ++;
		if((*it).first == y)
		{
			return num;
		}
	}
	return -1;
}

betweenness::~betweenness()
{
	delete []resWayNum;
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
	int **tag = new int*[n];	//	用来统计ij之间条数
	for(int i = 0; i<n; i++)
	{
		tag[i] = new int[n];
		for(int j = 0; j<n; j++)
		{
			tag[i][j] = 0;
		}
	}
	vector<pair<int, int>> **path = new vector<pair<int, int>>*[n]; // 第一个是id，第二个是个数
	for(int i = 0; i<n; i++)
	{
		path[i] = new vector<pair<int, int>>[n];
	}

	for(int i = 0; i<n; i++)
	{
		msleep(1);
		int k = extractInformation::list[i].connectNode.size();
		for(int j = 0; j<k; j++)
		{
			pair<int, int> x;
			x.first = extractInformation::list[i].connectNode[j].first;
			x.second = 1;
			path[i][extractInformation::list[i].connectNode[j].first].push_back(x);
			value[i][extractInformation::list[i].connectNode[j].first] = extractInformation::list[i].connectNode[j].second;
			tag[i][extractInformation::list[i].connectNode[j].first] = 1;
		}
	}
	
	for(int k = 0; k<n; k++)
	{
		msleep(2);
		int k1 = extractInformation::list[k].connectNode.size();
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				if(j != k && i != k && value[i][k] != -1 && value[k][j] != -1 && (value[i][k] + value[k][j] < value[i][j] || value[i][j] == -1))
				{
					tag[i][j] = tag[i][k]*tag[k][j];
					path[i][j].clear();
					value[i][j] = value[i][k] + value[k][j];
						for(auto it = path[i][k].begin(); it != path[i][k].end(); it++)
						{
								path[i][j].push_back(*it);
								path[i][j][path[i][j].size()-1].second *= tag[k][j];
								if((*it).second> 1000 || (*it).second < 0)
								{
									int m = 11;
								}
						}
						
						for(auto it = path[k][j].begin(); it != path[k][j].end(); it++)
						{
							int ks = indexof(path[i][j], (*it).first);
							if(ks == -1)
							{
								
								path[i][j].push_back(*it);
								path[i][j][path[i][j].size()-1].second *= tag[i][k];
																if((*it).second> 1000 || (*it).second < 0)
								{
									int m = 11;
								}
							}
							else
							{
								path[i][j][ks].second = path[i][j][ks].second + (*it).second * tag[i][k];
							}
						}
						
				}
				else if(j != k && i!= k && value[i][k] != -1 && value[k][j] != -1 && (value[i][k] + value[k][j] == value[i][j]))
				{
					tag[i][j] += tag[i][k]*tag[k][j];
					for(auto it = path[i][k].begin(); it != path[i][k].end(); it++)
					{
							int ks = indexof(path[i][j], (*it).first);
							if(ks == -1)
							{
								path[i][j].push_back(*it);
								path[i][j][path[i][j].size()-1].second *= tag[k][j];
								if((*it).second> 1000 || (*it).second < 0)
								{
									int m = 11;
								}
							}
							else
							{
								path[i][j][ks].second = path[i][j][ks].second + (*it).second * tag[k][j];
							}
					}
					for(auto it = path[k][j].begin(); it != path[k][j].end(); it++)
					{
							int ks = indexof(path[i][j], (*it).first);
							if(ks == -1)
							{
								path[i][j].push_back(*it);
								path[i][j][path[i][j].size()-1].second *= tag[i][k];
								if((*it).second> 1000 || (*it).second < 0)
								{
									int m = 11;
								}
							}
							else
							{
								path[i][j][ks].second = path[i][j][ks].second + (*it).second * tag[i][k];
							}
					}
				}
			}
		}
	}
	int sumWay = 0;
	for(int i = 0; i<n; i++)
	{
		msleep(1);
		for(int j = 0; j<n; j++)
		{
			if(path[i][j].size() != 0)
			{

				for(auto it = path[i][j].begin(); it != path[i][j].end(); it++)
				{
					if(tag[i][j] >= 1)
					{
						resWayNum[(*it).first] += ((double)((*it).second))/((double)tag[i][j]);
					}
				}
			}
		}
	}
	for(int i = 0; i<n; i++)
	{
		delete value[i];
		delete tag[i];
	}

	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			path[i][j].swap(vector<pair<int, int>>());
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
		outfile << "{\"id\":\"" << extractInformation::list[i].movieName << "\",\"value\":" << resWayNum[i];
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