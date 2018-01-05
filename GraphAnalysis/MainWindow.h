//������

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
	inline void changeToShortestPathWindow()//�л������·������
	{
		backgroundController->setCurrentIndex(2);
	}
	inline void changeToSelectWindow()//�л���ѡ�����
	{
		backgroundController->setCurrentIndex(1);
	}

	void startSearchShortestPathThread(int startPoint,int endPoint);//������Ѱ���·�����߳�
	void startExtractInformationThread();//������Ϣ��ȡ���߳�

private:
	Ui::MainWindowClass ui;

	void init();//�������ʼ��������

	QStackedWidget *backgroundController;//���ƽ����ת�������ؽ�����Ϊ0��ѡ�������Ϊ1�����·��������Ϊ2��
	
	LoadWindow *loadWindow;//���ؽ���
	SelectWindow *selectWindow;//ѡ�����
	ShortestPathWindow *shortestPathWindow;//���·������

};
