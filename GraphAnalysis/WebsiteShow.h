//用于显示界面可视化的网页

#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include<QWebEngineView>
#include "ui_WebsiteShow.h"

class WebsiteShow : public QWidget
{
	Q_OBJECT

public:
	WebsiteShow(QWidget *parent = Q_NULLPTR);
	~WebsiteShow();

	public slots:
	void showWeb(QString websitepath);

protected:
	void resizeEvent(QResizeEvent*);

private:
	Ui::WebsiteShow ui;

	QWebEngineView *webview;
};
