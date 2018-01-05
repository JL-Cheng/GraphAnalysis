#include "betweenness.h"
#include <fstream>

betweenness::betweenness()
{
	int n = extractInformation::list.size();
	resWayNum = new int[n];
	resMap = new double[n];
	for (int i = 0; i<n; i++)
	{
		resWayNum[i] = 0;
		resMap[i] = 0.5;
	}
	sumWay = 0;
	calMapBetweenness();
	print();
}

betweenness::~betweenness()
{
	delete[]resMap;
	delete[]resWayNum;
	sumWay = 0;
}

double betweenness::sumWayNum(int start_ID, int end_ID)
{
	int operate_ID;//��ʼ���㡢�������㡢���ڲ������
	int min_length = INT_MAX;
	vector<node> p_node;//δ�����Ľ������
	vector<node> q_node;//�������Ľ������
	node temp_node;//��ʱ���
	double res = 0.0;	//	�洢���	
	int n = extractInformation::list.size();
	//����㼯����ӵ�δ�������
	for (int i = 0; i < n; i++)
	{
		temp_node.ID = extractInformation::list[i].ID;
		temp_node.pre_ID = -1;
		temp_node.min_len = INT_MAX;
		temp_node.path.push_back(temp_node.ID);
		temp_node.used = false;
		temp_node.final_length = 0;
		p_node.push_back(temp_node);
	}

	//ѹ�뿪ʼ���
	q_node.push_back(p_node[start_ID]);
	p_node[start_ID].used = true;
	operate_ID = start_ID;

	while (true)// Dijkstra �㷨
	{
		for (int b = 0; b < n; b++)
		{
			if (b != operate_ID&&p_node[b].used == false)
			{
				int temp_length = INT_MAX;//���b��operate_ID֮��ľ���
				for (int j = 0; j < extractInformation::list[operate_ID].connectNode.size(); j++)
				{
					if (extractInformation::list[operate_ID].connectNode[j].first == b)
						temp_length = extractInformation::list[operate_ID].connectNode[j].second;
				}
				if (temp_length < p_node[b].min_len)
				{
					p_node[b].min_len = temp_length;
					p_node[b].pre_ID = operate_ID;
				}

				min_length = min_length > p_node[b].min_len ? p_node[b].min_len : min_length;
			}//����ÿ���������ڵ�

		}

		if (min_length == INT_MAX)
		{
			cout << "NO PATH";
			break;
		}//û�е�·
		else
		{
			int b = 0;
			for (b = 0; b < n; b++)//��Ѱ��һ������Ľڵ�
			{
				if (p_node[b].min_len == min_length&&p_node[b].used == false)
					break;
			}
			min_length = INT_MAX;

			//����һ�ڵ����q_node��
			q_node.push_back(p_node[b]);
			p_node[b].path = p_node[p_node[b].pre_ID].path;
			p_node[b].path.push_back(p_node[b].ID);
			p_node[b].used = true;
			p_node[b].final_length = p_node[p_node[b].pre_ID].final_length + p_node[b].min_len;
			if (p_node[b].ID == end_ID)
			{
				for (int i = 0; i < p_node[b].path.size(); i++)
				{
					resWayNum[p_node[b].path[i]] += 1.0; //	ͳ��ÿ�����ֵĴ���
				}
				res += 1.0;
			}
			else
			{
				operate_ID = b;
				continue;
			}
		}
	}
	sumWay += res;	//	ͳ���ܸ���
	return res;
}

double betweenness::sumWayPro(int start_ID, int end_ID, int target)
{
	int operate_ID;//��ʼ���㡢�������㡢���ڲ������
	int min_length = INT_MAX;
	vector<node> p_node;//δ�����Ľ������
	vector<node> q_node;//�������Ľ������
	node temp_node;//��ʱ���
	double res = 0.0;	//	�洢���	
	double resTarget = 0.0;
	int n = extractInformation::list.size();
	//����㼯����ӵ�δ�������
	for (int i = 0; i < n; i++)
	{
		temp_node.ID = extractInformation::list[i].ID;
		temp_node.pre_ID = -1;
		temp_node.min_len = INT_MAX;
		temp_node.path.push_back(temp_node.ID);
		temp_node.used = false;
		temp_node.final_length = 0;
		p_node.push_back(temp_node);
	}

	//ѹ�뿪ʼ���
	q_node.push_back(p_node[start_ID]);
	p_node[start_ID].used = true;
	operate_ID = start_ID;

	while (true)// Dijkstra �㷨
	{
		for (int b = 0; b < n; b++)
		{
			if (b != operate_ID&&p_node[b].used == false)
			{
				int temp_length = INT_MAX;//���b��operate_ID֮��ľ���
				for (int j = 0; j < extractInformation::list[operate_ID].connectNode.size(); j++)
				{
					if (extractInformation::list[operate_ID].connectNode[j].first == b)
						temp_length = extractInformation::list[operate_ID].connectNode[j].second;

				}
				if (temp_length < p_node[b].min_len)
				{
					p_node[b].min_len = temp_length;
					p_node[b].pre_ID = operate_ID;
				}

				min_length = min_length > p_node[b].min_len ? p_node[b].min_len : min_length;
			}//����ÿ���������ڵ�

		}

		if (min_length == INT_MAX)
		{
			break;
		}//û�е�·
		else
		{

			int b = 0;
			for (b = 0; b < n; b++)//��Ѱ��һ������Ľڵ�
			{
				if (p_node[b].min_len == min_length&&p_node[b].used == false)
					break;
			}
			min_length = INT_MAX;

			//����һ�ڵ����q_node��
			q_node.push_back(p_node[b]);
			p_node[b].path = p_node[p_node[b].pre_ID].path;
			p_node[b].path.push_back(p_node[b].ID);
			p_node[b].used = true;
			p_node[b].final_length = p_node[p_node[b].pre_ID].final_length + p_node[b].min_len;
			if (p_node[b].ID == end_ID)
			{

				for (int i = 0; i < p_node[b].path.size(); i++)
				{
					if (p_node[b].path[i] == target)
					{
						resTarget += 1.0;
						continue;
					}
					resWayNum[p_node[b].path[i]] += 1.0; //	ͳ��ÿ�����ֵĴ���
				}
				res += 1.0;

			}
			else
			{
				operate_ID = b;
				continue;
			}
		}
	}

	if (res != 0)
	{
		sumWay += res;	//	ͳ���ܸ���
		return (resTarget / res);
	}
	else
	{
		return 0;
	}

}

double betweenness::calBetweenness(int target)
{
	double res = 0;
	int n = extractInformation::list.size();
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			res += sumWayPro(i, j, target);
		}
	}

	for (int i = 0; i<n; i++)
	{
		resMap[i] = ((double)resWayNum[i]) / ((double)sumWay);
	}

	for (int i = 0; i<n; i++)
	{
		resWayNum[i] = 0;
	}
	sumWay = 0;
	return res;
}

void betweenness::calMapBetweenness()
{
	int n = extractInformation::list.size();
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			sumWayPro(i, j, 0);
		}
	}

	for (int i = 0; i<n; i++)
	{
		resMap[i] += ((double)resWayNum[i]) / ((double)sumWay);
	}
}

void betweenness::print()
{
	ofstream outfile("movie.csv");
	outfile << "id,value\n";
	outfile << "movie,\n";
	for (int i = 0; i<extractInformation::list.size(); i++)
	{
		outfile << "movie." << extractInformation::list[i].movieName << "," << 1000 * resMap[i];
		if (i != extractInformation::list.size() - 1)
		{
			outfile << endl;
		}
	}
	outfile.close();
}