//选择不同的图
#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_SelectWindow.h"

#include<QPushButton>
#include<QResizeEvent>

class SelectWindow : public QWidget
{
	Q_OBJECT

public:
	SelectWindow(QWidget *parent = Q_NULLPTR);
	~SelectWindow();

	QPushButton *shortestPathButton;//选择最短路径
	QPushButton *minimumSpanningTreeButton;//选择最小生成树
	QPushButton *degreeCentralityButton;//选择中心度
	QPushButton *connectedComponentButton;//选择连通分量
private:
	Ui::SelectWindow ui;
	void init();//初始化界面
	void resizeEvent(QResizeEvent*event);

};
