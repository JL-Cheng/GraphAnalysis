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
		tree.push_back(x);
		num ++;
		length += min;
		feature[end] = -1;
		find(feature, last, end, num, n);
	}
	
}