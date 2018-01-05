//最初的的加载界面

#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_LoadWindow.h"
#include<QResizeEvent>
#include<QLabel>
#include<QProgressBar>

class LoadWindow : public QWidget
{
	Q_OBJECT

public:
	LoadWindow(QWidget *parent = Q_NULLPTR);
	~LoadWindow();

	public slots:
	void getRateOfProgress(int num);//获取进度

private:
	Ui::LoadWindow ui;
	void resizeEvent(QResizeEvent *event);//填充背景
	void init();//初始化界面

	QLabel *showLabel;//显示提示语
	QProgressBar *showProgressBar;//显示信息提取进程
	int number;//正在操作的信息数
	int total;//总操作信息数

};
