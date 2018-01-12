#include "betweennessWindow.h"

betweennessWindow::betweennessWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	init();//初始化

	websiteShowWindow->showWeb("");
}

betweennessWindow::~betweennessWindow()
{
}

void betweennessWindow::init()
{
	progressLabel = new QLabel("计算中，请稍等...", this);
	websiteShowWindow = new WebsiteShow(this);
	returnButton = new QPushButton("Return", this);
}

void betweennessWindow::showResult()
{
	progressLabel->setText("已完成。");
	websiteShowWindow->showWeb("file:///betweenness.html");
	websiteShowWindow->show();
	progressLabel->show();
}

void betweennessWindow::resizeEvent(QResizeEvent *event)
{
	progressLabel->setGeometry(5, 5, geometry().width() - 10, geometry().height() / 15);
	websiteShowWindow->setGeometry(5, geometry().height() / 15 + 10, geometry().width() - 10, geometry().height() * 13 / 15);
	returnButton->setGeometry(geometry().width() * 3 / 8, geometry().height() * 13 / 15 + 25, geometry().width() / 4, geometry().height() / 30);
}

