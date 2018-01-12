//������

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
	inline void changeToShortestPathWindow()//�л������·������
	{
		backgroundController->setCurrentIndex(2);
	}
	inline void changeToPrimWindow()//�л�����С����������
	{
		backgroundController->setCurrentIndex(3);
	}
	inline void changeToConnected_componentWindow()//�л�����ͨ��֧����
	{
		backgroundController->setCurrentIndex(4);
	}
	inline void changeToBetweennessWindow()//�л����������ĶȽ���
	{
		backgroundController->setCurrentIndex(5);
	}
	inline void changeToSelectWindow()//�л���ѡ�����
	{
		backgroundController->setCurrentIndex(1);
	}

	void startSearchShortestPathThread(int startPoint,int endPoint);//������Ѱ���·�����߳�
	void startPrimThread();//������С�����������߳�
	void startBetweennessThread();//�����������Ķ������߳�
	void startConnected_componentThread(int threshold);//������ͨ��֧�����߳�
	void startExtractInformationThread();//������Ϣ��ȡ���߳�

private:
	Ui::MainWindowClass ui;

	void init();//�������ʼ��������

	QStackedWidget *backgroundController;//���ƽ����ת�������ؽ�����Ϊ0��ѡ�������Ϊ1�����·��������Ϊ2����С����������Ϊ3����ͨ��֧����Ϊ4��
	
	LoadWindow *loadWindow;//���ؽ���
	SelectWindow *selectWindow;//ѡ�����
	ShortestPathWindow *shortestPathWindow;//���·������
	PrimWindow *primWindow;//��С����������
	Connected_componentWindow *connected_componentWindow;//��ͨ��֧����
	betweennessWindow *degreeCentralityWindow;//�������ĶȽ���

};
