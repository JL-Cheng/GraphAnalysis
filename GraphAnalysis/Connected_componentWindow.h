//��ͨ������ʾ����

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

	QPushButton *returnButton;//���ذ�ť

	public slots:
	void showResult();//�����ʾ�ź�

private:
	Ui::Connected_componentWindow ui;
	void init();//�����ʼ������
	void resizeEvent(QResizeEvent*event);

	QLabel *progressLabel;//��ʾ���̿ؼ�
	WebsiteShow *websiteShowWindow;//·��ͼ����ʾ
};
