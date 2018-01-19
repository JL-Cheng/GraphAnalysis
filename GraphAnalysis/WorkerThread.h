//���߳��࣬��֤���治�Ῠ����ʵ�ֲ����Ѻ���

#pragma once
#pragma execution_character_set("utf-8")

#include <QThread>
#include"ShortestPath.h"
#include"prim.h"
#include"betweenness.h"
#include"connectness.h"
#include"Connected_component.h"

class searchShortestPath;
class extractInformation;

class WorkerThread : public QThread
{
	Q_OBJECT

public:
	WorkerThread(int startPoint, int endPoint,int number, QObject *parent = 0);
	WorkerThread(int number, QObject *parent = 0);
	WorkerThread(int thresholdNum,int number, QObject *parent = 0);
	~WorkerThread();

protected:
	virtual void run() Q_DECL_OVERRIDE;

	private slots:
	void getResult(QString result)
	{
		emit sendResult(result);
	}
	void getRateOfProgress(int number)
	{
		emit sendRateOfProgress(number);
	}

signals:
	void sendResult(QString result);//�������·�����

	void sendRateOfProgress(int number);//��֪����
	void tellTotalNumber(int number);//��֪�ܽ����
	void changeWindow();//�л���ѡ�񴰿�

	void finishPrim();//��С������������

	void finishConnected_component();//��ͨ��֧������

	void finishBetweennessAndConnectness();//���Ķ�������

private:
	int status;//����״̬��0Ϊ��Ϣ��ȡ��1Ϊ���·����Ѱ,2Ϊ��С��������3Ϊ��ͨ��֧��4Ϊ�������Ķȣ�
	int start_ID, end_ID;//���·���п�ʼ��������
	int threshold;//��ֵ
	searchShortestPath *search_shortest_path;//���·��											
	prim newTree; //��С������	
	betweenness newBetweenness;//�������Ķ�
	connectness newConnectness;//�������Ķ�
	connected_component newComponent;//��ͨ��֧

	extractInformation *information;//�洢�����ߵ���Ϣ
};
