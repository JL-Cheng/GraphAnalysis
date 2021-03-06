//中心度显示界面
#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_betweennessWindow.h"

#include<QLabel>
#include<QPushButton>
#include<QResizeEvent>

#include"WebsiteShow.h";

class betweennessWindow : public QWidget
{
	Q_OBJECT

public:
	betweennessWindow(QWidget *parent = Q_NULLPTR);
	~betweennessWindow();

	QPushButton *returnButton;//返回按钮

	public slots:
	void showResult();//结果显示信号

	private slots:
	inline void showBetweenness()
	{
		websiteShowWindow->showWeb("file:///betweenness.html");
		websiteShowWindow->show();
	}
	inline void showConnectness()
	{
		websiteShowWindow->showWeb("file:///connectness.html");
		websiteShowWindow->show();
	}

private:
	Ui::betweennessWindow ui;
	void init();//界面初始化函数
	void resizeEvent(QResizeEvent*event);

	QLabel *progressLabel;//提示进程控件
	QPushButton *betweennessButton;//介数中心度
	QPushButton *connectnessButton;//连通中心度
	WebsiteShow *websiteShowWindow;//路径图像显示
};
