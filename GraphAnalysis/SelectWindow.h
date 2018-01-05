//ѡ��ͬ��ͼ
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

	QPushButton *shortestPathButton;//ѡ�����·��
	QPushButton *minimumSpanningTreeButton;//ѡ����С������
	QPushButton *degreeCentralityButton;//ѡ�����Ķ�
	QPushButton *connectedComponentButton;//ѡ����ͨ����
private:
	Ui::SelectWindow ui;
	void init();//��ʼ������
	void resizeEvent(QResizeEvent*event);

};
