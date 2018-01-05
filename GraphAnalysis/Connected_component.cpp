#include "Connected_component.h"


connected_component::connected_component()
{
	int n = extractInformation::list.size();
	for(int i = 0; i<n; i++)
	{
		extractInformation::list[i].group = 0;
		extractInformation::list[i].betweenness = 0;
	}
	threshold = 0;
	length = 0;
	findST();
	print();
}

connected_component::~connected_component()
{

}

void connected_component::changeThreshold(int thre)
{
	int n = extractInformation::list.size();
	for(int i = 0; i<n; i++)
	{
		extractInformation::list[i].group = 0;
		extractInformation::list[i].betweenness = 0;
	}
	threshold = thre;
	length = 0;
	findST();
	print();
}

void connected_component::findST()
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
	delete[] feature;
	delete[] last;
}

void connected_component::find(int* feature, int* last, int start, int num, int n)
{
	if(num == n-1)
	{
		cout << length << endl;
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
					if(extractInformation::list[extractInformation::list[i].connectNode[j].first].ID ==  start && extractInformation::list[i].connectNode[j].second > threshold && feature[i] >= extractInformation::list[i].connectNode[j].second)
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
		extractInformation::list[x->first].group = 1;
		extractInformation::list[x->second].group = 1;
		tree.push_back(x);
		num ++;
		length += min;
		feature[end] = -1;
		find(feature, last, end, num, n);
	}
	
}

void connected_component::print()
{
	ofstream outfile("connected_component.json");
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
			if(extractInformation::list[i].connectNode[j].second > threshold)
			{
				if (i != 0 || j != 0)
					outfile << "," << endl;
				outfile << "{\"source\":\"";
				outfile << extractInformation::list[i].movieName;
				outfile << "\", \"target\": \"";
				outfile << extractInformation::list[extractInformation::list[i].connectNode[j].first].movieName;
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
	}
	outfile << endl << "]" << endl << "}";
}