//������ȡ���ݼ����ݵ���

#pragma once
#ifndef EXTRACTINFORMATION_H
#define EXTRACTINFORMATION_H
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1

#include<string>
#include<iostream>
#include<vector>
#include<hash_map>
#include<QObject>
#include <QThread>
using namespace std;
using namespace stdext;

//ÿ�����ݽ���Ӧ�ṹ��
typedef struct movieData
{
	int ID;//���
	string movieName;//��Ӱ��
	vector<pair<int, int>> connectNode;//��ý�������ӵĽ�㣬pair�ĵ�һ��ֵΪ���ӽ���ID���ڶ���ֵΪȨֵ
	int group;
	int betweenness;	//�������Ķ�
};

class extractInformation:public QThread
{
	Q_OBJECT

public:
	extractInformation();
	~extractInformation() {}

	void operate();//������Ϣ����ȡ
	static vector<movieData> list;//�洢��ȡ�õ��ĵ�ͼ����Ϣ

signals:
	void sendRateOfProgress(int number);//��֪����

private:
	void splitString(const string& s, vector<string>& v, const string& c);//�ָ��ַ���
	void print();//����ȡ���������ļ���

	vector<hash_map<string, int>> reviewersList;//ÿ����Ӱ��Ӧ��Ӱ��������

	string fileName;//��Ϣ�洢���ļ���
};

#endif // !EXTRACTINFORMATION_H
