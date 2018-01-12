//�������Ķ���ʾ����
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

	QPushButton *returnButton;//���ذ�ť

	public slots:
	void showResult();//�����ʾ�ź�

private:
	Ui::betweennessWindow ui;
	void init();//�����ʼ������
	void resizeEvent(QResizeEvent*event);

	QLabel *progressLabel;//��ʾ���̿ؼ�
	WebsiteShow *websiteShowWindow;//·��ͼ����ʾ
};
