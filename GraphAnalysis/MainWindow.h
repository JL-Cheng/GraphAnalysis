//主窗口

#pragma once

#include <QtWidgets/QMainWindow>
#include<QStackedWidget>
#include "ui_MainWindow.h"

#include"SelectWindow.h"
#include"ShortestPathWindow.h"
#include"PrimWindow.h"
#include"betweennessWindow.h"
#include"LoadWindow.h"
#include"ShortestPath.h"
#include"prim.h"
#include"Connected_componentWindow.h"
#include"WorkerThread.h"

class SelectWindow;
class WorkerThread;
class searchShortestPath;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

	private slots:
	inline void changeToShortestPathWindow()//切换到最短路径界面
	{
		backgroundController->setCurrentIndex(2);
	}
	inline void changeToPrimWindow()//切换到最小生成树界面
	{
		backgroundController->setCurrentIndex(3);
	}
	inline void changeToConnected_componentWindow()//切换到连通分支界面
	{
		backgroundController->setCurrentIndex(4);
	}
	inline void changeToBetweennessWindow()//切换到介数中心度界面
	{
		backgroundController->setCurrentIndex(5);
	}
	inline void changeToSelectWindow()//切换到选择界面
	{
		backgroundController->setCurrentIndex(1);
	}

	void startSearchShortestPathThread(int startPoint,int endPoint);//开启搜寻最短路径的线程
	void startPrimThread();//开启最小生成树生成线程
	void startBetweennessThread();//开启介数中心度生成线程
	void startConnected_componentThread(int threshold);//开启连通分支生成线程
	void startExtractInformationThread();//开启信息提取的线程

private:
	Ui::MainWindowClass ui;

	void init();//主界面初始化函数。

	QStackedWidget *backgroundController;//控制界面的转换（加载界面编号为0，选择界面编号为1，最短路径界面编号为2，最小生成树界面为3，连通分支界面为4）
	
	LoadWindow *loadWindow;//加载界面
	SelectWindow *selectWindow;//选择界面
	ShortestPathWindow *shortestPathWindow;//最短路径界面
	PrimWindow *primWindow;//最小生成树界面
	Connected_componentWindow *connected_componentWindow;//连通分支界面
	betweennessWindow *degreeCentralityWindow;//介数中心度界面

};
