//多线程类，保证界面不会卡死，实现操作友好性

#pragma once
#pragma execution_character_set("utf-8")

#include <QThread>
#include"ShortestPath.h"
#include"prim.h"
#include"Connected_component.h"

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
	void sendResult(QString result);//返回最短路径结果

	void sendRateOfProgress(int number);//告知进程
	void tellTotalNumber(int number);//告知总结点数
	void changeWindow();//切换到选择窗口

	void finishPrim();//最小生成树已生成

	void finishConnected_component();//连通分支已生成

private:
	int status;//进程状态（0为信息提取，1为最短路径搜寻,2为最小生成树，3为连通分支）
	int start_ID, end_ID;//最短路径中开始与结束结点
	searchShortestPath *search_shortest_path;//最短路径											
	prim newTree; //最小生成树			  
	connected_component newComponent;//连通分支

	extractInformation *information;//存储结点与边的信息
};
