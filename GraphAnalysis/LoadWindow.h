//����ĵļ��ؽ���

#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_LoadWindow.h"
#include<QResizeEvent>
#include<QLabel>
#include<QProgressBar>

class LoadWindow : public QWidget
{
	Q_OBJECT

public:
	LoadWindow(QWidget *parent = Q_NULLPTR);
	~LoadWindow();

	public slots:
	void getRateOfProgress(int num);//��ȡ����

private:
	Ui::LoadWindow ui;
	void resizeEvent(QResizeEvent *event);//��䱳��
	void init();//��ʼ������

	QLabel *showLabel;//��ʾ��ʾ��
	QProgressBar *showProgressBar;//��ʾ��Ϣ��ȡ����
	int number;//���ڲ�������Ϣ��
	int total;//�ܲ�����Ϣ��

};
