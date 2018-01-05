#include "prim.h"

prim::prim()
{
	int n = extractInformation::list.size();
	for(int i = 0; i<n; i++)
	{
		extractInformation::list[i].group = 0;
		extractInformation::list[i].betweenness = 0;
	}
	length = 0;
	findST();
}

prim::~prim()
{
	int n = tree.size();
	for(int i = 0; i<n; i++)
	{
		delete tree[i];
		tree[i] = NULL;
	}
	tree.clear();
}

void prim::findST()
{
	int n = extractInformation::list.size();
	int* feature = new int[n];
	int* last = new int[n];
	for(int i = 0; i<n; i++)
	{
		feature[i] = INT_MAX;
	}
	feature[0] = -1;
	find(feature, last, 0, 0, n);
	for(int i = 0; i<n; i++)
	{
		if(feature[i] != -1)
		{
			feature[i] = -1;
			find(feature, last, i, 0, n);
		}
	}
	print();
	delete[] feature;
	delete[] last;
}

void prim::find(int* feature, int* last, int start, int num, int n)
{
	if(num == n-1)
	{
		cout << length << endl;
		return ;
	}
	else
	{
		msleep(3);
		int min = INT_MAX;
		int end = INT_MAX;
		for(int i = 0; i<n; i++)
		{
			if(feature[i] != -1)
			{
				int len = extractInformation::list[i].connectNode.size();
				for(int j = 0; j<len; j++)
				{
					if(extractInformation::list[extractInformation::list[i].connectNode[j].first].ID ==  start && feature[i] >= extractInformation::list[i].connectNode[j].second)
					{
						feature[i] = extractInformation::list[i].connectNode[j].second;
						last[i] = start;
					}
				}
			}
		}
		for(int i = 0; i<n; i++)
		{
			if(feature[i] != -1 && feature[i] < min)
			{
				min = feature[i];
				end = i;
			}
		}
		if(end == INT_MAX)
		{
			return ;
		}
		pair<int, int>* x = new pair<int, int>;
		x->first = last[end];
		x->second = end;
		cout << "[" << last[end] << "->" << end << "]";
		extractInformation::list[x->first].group = num + 1;
		extractInformation::list[x->second].group = num;
		tree.push_back(x);
		num ++;
		length += min;
		feature[end] = -1;
		find(feature, last, end, num, n);
	}
	
}

void prim::print()
{
	string tempLine, text1 = "", text2 = "";

	ifstream infile1("text1.txt");
	if (!infile1.is_open())//打开文件失败，返回
		exit(-1);
	while (getline(infile1, tempLine))
	{
		text1 += tempLine + "\n";
	}

	ifstream infile2("prim_text2.txt");
	if (!infile2.is_open())//打开文件失败，返回
		exit(-1);
	while (getline(infile2, tempLine))
	{
		text2 += tempLine + "\n";
	}
	ofstream outfile("prim.html");
	outfile << text1;

	outfile << "var nodes=[" << endl;
	int num = extractInformation::list.size();
	for (int i = 0; i < num; i++)
	{
		if (i != 0)
			outfile << "," << endl;
		outfile << "{\"id\":\"";
		outfile << extractInformation::list[i].ID << " " << extractInformation::list[i].movieName;
		outfile << "\", \"group\":";
		outfile << extractInformation::list[i].group;
		outfile << "}";
	}
	outfile << "];" << endl << "var links =[";
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < extractInformation::list[i].connectNode.size(); j++)
		{
			if (i != 0 || j != 0)
				outfile << "," << endl;
			outfile << "{\"source\":\"";
			outfile << extractInformation::list[i].ID << " " << extractInformation::list[i].movieName;
			outfile << "\", \"target\": \"";
			outfile << extractInformation::list[extractInformation::list[i].connectNode[j].first].ID << " " << extractInformation::list[extractInformation::list[i].connectNode[j].first].movieName;
			outfile << "\", \"value\":";
			outfile << extractInformation::list[i].connectNode[j].second;
			int test = 0;
			for(int k = 0; k<tree.size(); k++)
			{
				if(extractInformation::list[i].ID == tree[k]->first && extractInformation::list[extractInformation::list[i].connectNode[j].first].ID == tree[k]->second)
				{
					test = 1;
					outfile << ", \"color\": 2";
					break;
				}
			}
			if(test == 0)
			{
				outfile << ", \"color\": 1";
			}
			outfile << "}";
		}
	}
	outfile << endl << "];";
	outfile << text2;

	outfile.close();
	infile1.close();
	infile2.close();
}