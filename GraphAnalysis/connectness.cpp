#include "connectness.h"
#include <fstream>

connectness::connectness()
{
	int n = extractInformation::list.size();
	resWayNum = new int[n];
	for(int i = 0; i<n; i++)
	{
		resWayNum[i] = 0;
	}
}

connectness::~connectness()
{
	delete []resWayNum;
}

void connectness::sumWayNum()
{
	int n = extractInformation::list.size();
	int **value = new int*[n];
	for(int i = 0; i<n; i++)
	{
		value[i] = new int[n];
		for(int j = 0; j<n; j++)
		{
			value[i][j] = 0;
		}
	}
	for(int i = 0; i<n; i++)
	{
		int k = extractInformation::list[i].connectNode.size();
		for(int j = 0; j<k; j++)
		{
			value[i][extractInformation::list[i].connectNode[j].first] = extractInformation::list[i].connectNode[j].second;
		}
	}
	
	for(int k = 0; k<n; k++)
	{
		msleep(1);
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				if(j != k && i != k && value[i][k] != 0 && value[k][j] != 0 && (value[i][k] + value[k][j] < value[i][j] || value[i][j] == 0))
				{
					value[i][j] = value[i][k] + value[k][j];
				}
			}
		}
	}
	int sumWay = 0;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			resWayNum[i] += value[i][j];
		}
	}

	for(int i = 0; i<n; i++)
	{
		delete value[i];
	}

	print();
}

void connectness::print()
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
	ofstream outfile("connectness.html");
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