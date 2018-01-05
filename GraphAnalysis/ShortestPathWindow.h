//最短路径显示界面
#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_ShortestPathWindow.h"

#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QResizeEvent>

#include"WebsiteShow.h";

class ShortestPathWindow : public QWidget
{
	Q_OBJECT

public:
	ShortestPathWindow(QWidget *parent = Q_NULLPTR);
	~ShortestPathWindow();

signals:
	void searchShortestPath(int startPoint, int endPoint);

	public slots:
	void showResult(QString result);
	void getTotalNumber(int number);

	private slots:
	void sendSearchSignal();

private:
	Ui::ShortestPathWindow ui;
	void init();//界面初始化函数
	void resizeEvent(QResizeEvent*event);

	QLineEdit *startPointLabel;//输入出发点的控件
	QLineEdit *endPointLabel;//输入结束点的控件
	QLabel *resultLabel;//结果显示控件
	QPushButton *searchButton;//搜索按钮

	int totalNumber;//总结点数

	WebsiteShow *websiteShowWindow;//路径图像显示
};
