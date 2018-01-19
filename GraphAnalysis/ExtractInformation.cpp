#include"ExtractInformation.h"
#include<fstream>

vector<movieData> extractInformation::list;

extractInformation::extractInformation()
{
	fileName = "user.csv";
}

void extractInformation::splitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

void extractInformation::operate()
{
	string tempLine;//每一行数据字符串
	string movieName = "";//电影名
	int ID = -1;//电影编号
	int num = 0;
	vector<string> tempLineData;//每一行的两个数据
	vector<string> movieNameFound;//已经找过的电影名，用于去重

	ifstream infile(fileName);//打开文件
	if (!infile.is_open())//打开文件失败，返回
		exit(-1);
	while (getline(infile, tempLine))
	{
		msleep(5);
		num++;
		emit sendRateOfProgress(num);
		if (tempLine == "")
			continue;
		tempLineData.clear();
		splitString(tempLine, tempLineData, ",");
		if (!tempLineData.size())
			continue;

		if (movieName != tempLineData[0])//新的电影名
		{
			if (find(movieNameFound.begin(), movieNameFound.end(), tempLineData[0]) != movieNameFound.end())
				continue;
			ID++;
			movieName = tempLineData[0];
			movieNameFound.push_back(movieName);

			movieData newMovie;
			newMovie.ID = ID;
			newMovie.movieName = movieName;
			newMovie.group = 0;

			hash_map<string, int> newHashMap;
			newHashMap.insert(pair<string, int>(tempLineData[1], ID));
			reviewersList.push_back(newHashMap);

			for (int i = 0; i < reviewersList.size(); i++)
			{
				if (i == ID)//不与自己匹配
					continue;
				if (reviewersList[i].find(tempLineData[1]) != reviewersList[i].end())
				{
					newMovie.connectNode.push_back(pair<int, int>(i, 1));
					list[i].connectNode.push_back(pair<int, int>(ID, 1));
				}

			}
			list.push_back(newMovie);
		}

		else
		{
			reviewersList[ID].insert(pair<string, int>(tempLineData[1], ID));
			for (int i = 0; i < reviewersList.size(); i++)
			{
				if (i == ID)//不与自己匹配
					continue;
				if (reviewersList[i].find(tempLineData[1]) != reviewersList[i].end())
				{
					int j;
					for (j = 0; j < list[ID].connectNode.size(); j++)//查找是否之前与该节点相连
					{
						if (list[ID].connectNode[j].first == i)//找到该结点
							break;
					}
					if (j >= list[ID].connectNode.size())
					{
						list[ID].connectNode.push_back(pair<int, int>(i, 1));//插入新结点
						list[i].connectNode.push_back(pair<int, int>(ID, 1));
					}

					else
					{
						list[ID].connectNode[j].second++;//权值增加
						for (int k = 0; k < list[i].connectNode.size(); k++)
						{
							if (list[i].connectNode[k].first == ID)//找到该结点
							{
								list[i].connectNode[k].second++;
							}
						}
					}
				}
			}
		}

	}

	for (int i = 0; i < list.size(); i++)
	{
		vector<pair<int, int>>::iterator it1,it2;
		if (list[i].connectNode.size() >=10 )
		{
			for (it1 = list[i].connectNode.begin()+3; it1 != list[i].connectNode.end();)
			{
				for (it2 = list[it1->first].connectNode.begin(); it2 != list[it1->first].connectNode.end()&&it2->first != i; it2++);
					it2 = list[it1->first].connectNode.erase(it2);
				it1 = list[i].connectNode.erase(it1);

			}
		}
	}

	print();
}

void extractInformation::print()
{
	ofstream outfile("GraphData.json");
	outfile << "{" << endl << "\"nodes\":[" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		if (i != 0)
			outfile << "," << endl;
		outfile << "{\"id\":\"";
		outfile << list[i].movieName;
		outfile << "\", \"group\":";
		outfile << list[i].ID % 10;
		outfile << "}";
	}
	outfile << "]," << endl << "\"links\":[";
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 0; j < list[i].connectNode.size(); j++)
		{
			if (i != 0 || j != 0)
				outfile << "," << endl;
			outfile << "{\"source\":\"";
			outfile << list[i].movieName;
			outfile << "\", \"target\": \"";
			outfile << list[list[i].connectNode[j].first].movieName;
			outfile << "\", \"value\":";
			outfile << list[i].connectNode[j].second;
			outfile << "}";
		}
	}
	outfile << endl << "]" << endl << "}";
}