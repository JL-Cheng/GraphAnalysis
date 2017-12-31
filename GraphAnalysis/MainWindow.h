//主窗口

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

	void init();//主界面初始化函数。

	QStackedWidget *backgroundController;//控制界面的转换（显示网页的界面编号为0）
	WebsiteShow *websiteShowWindow;//显示网页的界面
};
