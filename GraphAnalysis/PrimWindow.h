//最小生成树显示界面
#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_PrimWindow.h"

#include<QLabel>
#include<QPushButton>
#include<QResizeEvent>

#include"WebsiteShow.h";

class PrimWindow : public QWidget
{
	Q_OBJECT

public:
	PrimWindow(QWidget *parent = Q_NULLPTR);
	~PrimWindow();

	QPushButton *returnButton;//返回按钮

	public slots:
	void showResult();//结果显示信号

private:
	Ui::PrimWindow ui;
	void init();//界面初始化函数
	void resizeEvent(QResizeEvent*event);

	QLabel *progressLabel;//提示进程控件
	WebsiteShow *websiteShowWindow;//路径图像显示
};
