//��С��������ʾ����
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

	QPushButton *returnButton;//���ذ�ť

	public slots:
	void showResult();//�����ʾ�ź�

private:
	Ui::PrimWindow ui;
	void init();//�����ʼ������
	void resizeEvent(QResizeEvent*event);

	QLabel *progressLabel;//��ʾ���̿ؼ�
	WebsiteShow *websiteShowWindow;//·��ͼ����ʾ
};
