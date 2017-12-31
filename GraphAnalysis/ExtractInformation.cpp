#include"ExtractInformation.h"
#include<fstream>

extractInformation::extractInformation()
{
	fileName = "user.csv";

	operate();
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
	string tempLine;//ÿһ�������ַ���
	string movieName = "";//��Ӱ��
	int ID = -1;//��Ӱ���
	int num = 0;
	vector<string> tempLineData;//ÿһ�е���������

	ifstream infile(fileName);//���ļ�
	if (!infile.is_open())//���ļ�ʧ�ܣ�����
		exit(-1);
	while (getline(infile, tempLine))
	{
		num++;
		cout << num << " ";
		if (tempLine == "")
			continue;
		tempLineData.clear();
		splitString(tempLine, tempLineData, ",");
		if (!tempLineData.size())
			continue;

		if (movieName != tempLineData[0])//�µĵ�Ӱ��
		{
			ID++;
			movieName = tempLineData[0];

			movieData newMovie;
			newMovie.ID = ID;
			newMovie.movieName = movieName;

			hash_map<string, int> newHashMap;
			newHashMap.insert(pair<string, int>(tempLineData[1], ID));
			reviewersList.push_back(newHashMap);

			for (int i = 0; i < reviewersList.size(); i++)
			{
				if (i == ID)//�����Լ�ƥ��
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
				if (i == ID)//�����Լ�ƥ��
					continue;
				if (reviewersList[i].find(tempLineData[1]) != reviewersList[i].end())
				{
					int j;
					for (j = 0; j < list[ID].connectNode.size(); j++)//�����Ƿ�֮ǰ��ýڵ�����
					{
						if (list[ID].connectNode[j].first == i)//�ҵ��ý��
							break;
					}
					if (j >= list[ID].connectNode.size())
					{
						list[ID].connectNode.push_back(pair<int, int>(i, 1));//�����½��
						list[i].connectNode.push_back(pair<int, int>(ID, 1));
					}

					else
					{
						list[ID].connectNode[j].second++;//Ȩֵ����
						for (int k = 0; k < list[i].connectNode.size(); k++)
						{
							if (list[i].connectNode[k].first == ID)//�ҵ��ý��
							{
								list[i].connectNode[k].second++;
							}
						}
					}
				}
			}
		}

	}

	ofstream outfile("test.json");
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