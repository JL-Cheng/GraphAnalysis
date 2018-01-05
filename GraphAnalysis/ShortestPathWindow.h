//���·����ʾ����
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
	void init();//�����ʼ������
	void resizeEvent(QResizeEvent*event);

	QLineEdit *startPointLabel;//���������Ŀؼ�
	QLineEdit *endPointLabel;//���������Ŀؼ�
	QLabel *resultLabel;//�����ʾ�ؼ�
	QPushButton *searchButton;//������ť

	int totalNumber;//�ܽ����

	WebsiteShow *websiteShowWindow;//·��ͼ����ʾ
};
