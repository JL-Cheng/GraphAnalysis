//��ͨ������ʾ����

#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_Connected_componentWindow.h"

#include<QLabel>
#include<QLineEdit>
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

signals:
	void searchConnected_component(int threshold);

	private slots:
	void sendSearchSignal();

private:
	Ui::Connected_componentWindow ui;
	void init();//�����ʼ������
	void resizeEvent(QResizeEvent*event);

	QLabel *progressLabel;//��ʾ���̿ؼ�
	QLineEdit *thresholdLabel;//������ֵ�Ŀؼ�
	QPushButton *searchButton;//������ť
	WebsiteShow *websiteShowWindow;//·��ͼ����ʾ

	int threshold;		//	��ֵ
};
