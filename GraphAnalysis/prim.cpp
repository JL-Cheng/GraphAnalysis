#include "prim.h"

prim::prim()
{
	length = 0;
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
	delete[] feature;
	delete[] last;
}


void prim::find(int* feature, int* last, int start, int num, int n)
{
	if(num == n-1)
	{
		return ;
	}
	else
	{
		int min = INT_MAX;
		int end = INT_MAX;
		for(int i = 0; i<n; i++)
		{
			if(feature[i] != -1)
			{
				int len = extractInformation::list[i].connectNode.size();
				for(int j = 0; j<len; j++)
				{
					if(extractInformation::list[i].connectNode[j].first == start && feature[i] >= extractInformation::list[i].connectNode[j].second)
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
		pair<int, int>* x = new pair<int, int>;
		x->first = last[end];
		x->second = end;
		extractInformation::list[x->first].group = 1;
		extractInformation::list[x->second].group = 1;
		tree.push_back(x);
		num ++;
		length += min;
		feature[end] = -1;
		find(feature, last, end, num, n);
	}
	
}

void prim::print()
{
	ofstream outfile("prim.json");
	outfile << "{" << endl << "\"nodes\":[" << endl;
	int num = extractInformation::list.size();
	for (int i = 0; i < num; i++)
	{
		if (i != 0)
			outfile << "," << endl;
		outfile << "{\"id\":\"";
		outfile << extractInformation::list[i].movieName;
		outfile << "\", \"group\":";
		outfile << extractInformation::list[i].group;
		outfile << "}";
	}
	outfile << "]," << endl << "\"links\":[";
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < extractInformation::list[i].connectNode.size(); j++)
		{
			if (i != 0 || j != 0)
				outfile << "," << endl;
			outfile << "{\"source\":\"";
			outfile << extractInformation::list[i].movieName;
			outfile << "\", \"target\": \"";
			outfile << extractInformation::list[extractInformation::list[i].connectNode[j].first].movieName;
			outfile << "\", \"value\":";
			outfile << extractInformation::list[i].connectNode[j].second;
			if (extractInformation::list[i].group == 1 && extractInformation::list[extractInformation::list[i].connectNode[j].first].group == 1)
			{
				outfile << ", \"color\": 2";
			}
			else
			{
				outfile << ", \"color\": 1";
			}
			outfile << "}";
		}
	}
	outfile << endl << "]" << endl << "}";
}