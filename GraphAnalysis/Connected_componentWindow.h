//连通分量显示界面

#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_Connected_componentWindow.h"

#include<QLabel>
#include<QResizeEvent>
#include<QPushButton>

#include"WebsiteShow.h";

class Connected_componentWindow : public QWidget
{
	Q_OBJECT

public:
	Connected_componentWindow(QWidget *parent = Q_NULLPTR);
	~Connected_componentWindow();

	QPushButton *returnButton;//返回按钮

	public slots:
	void showResult();//结果显示信号

private:
	Ui::Connected_componentWindow ui;
	void init();//界面初始化函数
	void resizeEvent(QResizeEvent*event);

	QLabel *progressLabel;//提示进程控件
	WebsiteShow *websiteShowWindow;//路径图像显示
};
