//������

#pragma once

#include <QtWidgets/QMainWindow>
#include<QStackedWidget>
#include "ui_MainWindow.h"

#include"WebsiteShow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;

	void init();//�������ʼ��������

	QStackedWidget *backgroundController;//���ƽ����ת������ʾ��ҳ�Ľ�����Ϊ0��
	WebsiteShow *websiteShowWindow;//��ʾ��ҳ�Ľ���
};
