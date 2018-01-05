//���߳��࣬��֤���治�Ῠ����ʵ�ֲ����Ѻ���

#pragma once
#pragma execution_character_set("utf-8")

#include <QThread>
#include"ShortestPath.h"

class searchShortestPath;
class extractInformation;

class WorkerThread : public QThread
{
	Q_OBJECT

public:
	WorkerThread(int startPoint, int endPoint, QObject *parent = 0);
	WorkerThread(int number, QObject *parent = 0);
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
	void changeWindow();//�л�����һ����

private:
	int status;//����״̬��0Ϊ��Ϣ��ȡ��1Ϊ���·����Ѱ��
	int start_ID, end_ID;//���·���п�ʼ��������
	searchShortestPath *search_shortest_path;//���·��

	extractInformation *information;//�洢�����ߵ���Ϣ
};
