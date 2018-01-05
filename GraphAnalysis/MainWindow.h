//主窗口

#pragma once

#include <QtWidgets/QMainWindow>
#include<QStackedWidget>
#include "ui_MainWindow.h"

#include"SelectWindow.h"
#include"ShortestPathWindow.h"
#include"LoadWindow.h"
#include"ShortestPath.h"
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
	inline void changeToSelectWindow()//切换到选择界面
	{
		backgroundController->setCurrentIndex(1);
	}

	void startSearchShortestPathThread(int startPoint,int endPoint);//开启搜寻最短路径的线程
	void startExtractInformationThread();//开启信息提取的线程

private:
	Ui::MainWindowClass ui;

	void init();//主界面初始化函数。

	QStackedWidget *backgroundController;//控制界面的转换（加载界面编号为0，选择界面编号为1，最短路径界面编号为2）
	
	LoadWindow *loadWindow;//加载界面
	SelectWindow *selectWindow;//选择界面
	ShortestPathWindow *shortestPathWindow;//最短路径界面

};
