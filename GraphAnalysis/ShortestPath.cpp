#include"ShortestPath.h"
#include<fstream>

#define Max_Int 1000000
#define MIN(a,b) a<b?a:b

searchShortestPath::searchShortestPath()
{
	//information.operate();
	shortestPathList = information.list;
}

void searchShortestPath::search(int startPoint, int endPoint)
{
	int start_ID, end_ID, operate_ID;//开始顶点、结束顶点、正在操作结点
	int min_length = Max_Int;//最短长度
	vector<node> p_node;//未搜索的结点向量
	vector<node> q_node;//已搜索的结点向量
	QString result="";//结果字符串
	node temp_node;//临时结点

	cout << endl << shortestPathList.size();
	start_ID = startPoint;
	end_ID = endPoint;

	//将结点集合添加到未搜索结点
	for (int i = 0; i < shortestPathList.size(); i++)
	{
		temp_node.path.clear();
		temp_node.ID = shortestPathList[i].ID;
		temp_node.pre_ID = -1;
		temp_node.min_len = Max_Int;
		temp_node.path.push_back(temp_node.ID);
		temp_node.used = false;
		temp_node.final_length = 0;
		p_node.push_back(temp_node);
	}

	//压入开始结点
	q_node.push_back(p_node[start_ID]);
	p_node[start_ID].used = true;
	operate_ID = start_ID;

	while (true)// Dijkstra 算法
	{
		msleep(5);
		for (int b = 0; b < shortestPathList.size(); b++)
		{
			if (b != operate_ID&&p_node[b].used == false)
			{
				int temp_length = Max_Int;//存放b与operate_ID之间的距离
				for (int j = 0; j < shortestPathList[operate_ID].connectNode.size(); j++)
				{
					if (shortestPathList[operate_ID].connectNode[j].first == b)
						temp_length = shortestPathList[operate_ID].connectNode[j].second;
				}
				if (temp_length < p_node[b].min_len)
				{
					p_node[b].min_len = temp_length;
					p_node[b].pre_ID = operate_ID;
				}

				min_length = MIN(min_length, p_node[b].min_len);
			}//更新每个点的最近节点

		}

		if (min_length == Max_Int)
		{
			result = "NO PATH";
			break;
		}//没有道路
		else
		{
			int b = 0;
			for (b = 0; b < shortestPathList.size(); b++)//找寻下一个最近的节点
			{
				if (p_node[b].min_len == min_length&&p_node[b].used == false)
					break;
			}
			min_length = Max_Int;

			//把这一节点插入q_node中
			q_node.push_back(p_node[b]);
			p_node[b].path = p_node[p_node[b].pre_ID].path;
			p_node[b].path.push_back(p_node[b].ID);
			p_node[b].used = true;
			p_node[b].final_length = p_node[p_node[b].pre_ID].final_length + p_node[b].min_len;
			if (p_node[b].ID == end_ID)
			{
				shortestPath = p_node[b].path;
				result = result + "[" + QString::number(p_node[b].path[0]);
				shortestPathList[p_node[b].path[0]].group = 1;
				for (int i = 1; i < p_node[b].path.size(); i++)
				{
					result = result + " -> " + QString::number(p_node[b].path[i]);
					shortestPathList[p_node[b].path[i]].group = 1;
				}
				result = result + " " + QString::number(p_node[b].final_length) + "]";
				break;
			}
			else
			{
				operate_ID = b;
				continue;
			}
		}
	}

	//进行结点修饰
	int num = 2;
	for (int i = 0; i < shortestPathList.size(); i++)
	{
		if (shortestPathList[i].group == 0)
		{
			shortestPathList[i].group = num;
			num++;
		}
	}

	printShortestPath();

	emit findResult(result);
}

void searchShortestPath::printShortestPath()
{
	string tempLine, text1 = "", text2 = "";

	ifstream infile1("text1.txt");
	if (!infile1.is_open())//打开文件失败，返回
		exit(-1);
	while (getline(infile1, tempLine))
	{
		text1 += tempLine + "\n";
	}

	ifstream infile2("text2.txt");
	if (!infile2.is_open())//打开文件失败，返回
		exit(-1);
	while (getline(infile2, tempLine))
	{
		text2 += tempLine + "\n";
	}

	ofstream outfile("shortestPath.html");
	outfile << text1;
	outfile << "var nodes=[" << endl;
	for (int i = 0; i < shortestPathList.size(); i++)
	{
		if (i != 0)
			outfile << "," << endl;
		outfile << "{\"id\":\"";
		outfile << shortestPathList[i].movieName;
		outfile << "\", \"group\":";
		outfile << shortestPathList[i].group;
		outfile << "}";
	}
	outfile << "];" << endl << "var links =[";
	for (int i = 0; i < shortestPathList.size(); i++)
	{
		for (int j = 0; j < shortestPathList[i].connectNode.size(); j++)
		{
			if (i != 0 || j != 0)
				outfile << "," << endl;
			outfile << "{\"source\":\"";
			outfile << shortestPathList[i].movieName;
			outfile << "\", \"target\": \"";
			outfile << shortestPathList[shortestPathList[i].connectNode[j].first].movieName;
			outfile << "\", \"value\":";
			outfile << shortestPathList[i].connectNode[j].second;
			if (shortestPathList[i].group == 1 && shortestPathList[shortestPathList[i].connectNode[j].first].group == 1)
			{
				for (int k = 0; k < shortestPath.size(); k++)
				{
					if (shortestPath[k] == shortestPathList[i].ID)
					{
						if (k == shortestPath.size() - 1 && shortestPath[k - 1] == shortestPathList[shortestPathList[i].connectNode[j].first].ID)
							outfile << ", \"color\": 2";
						else if (k == 0 && shortestPath[k + 1] == shortestPathList[shortestPathList[i].connectNode[j].first].ID)
							outfile << ", \"color\": 2";
						else if (k > 0 && k<shortestPath.size() - 1 &&
							(shortestPath[k - 1] == shortestPathList[shortestPathList[i].connectNode[j].first].ID ||
								shortestPath[k + 1] == shortestPathList[shortestPathList[i].connectNode[j].first].ID))
							outfile << ", \"color\": 2";
						else
							outfile << ", \"color\": 1";
					}
					else
						continue;
				}
			}
			else
			{
				outfile << ", \"color\": 1";
			}
			outfile << "}";
		}
	}
	outfile << endl << "];";
	outfile << text2;
}