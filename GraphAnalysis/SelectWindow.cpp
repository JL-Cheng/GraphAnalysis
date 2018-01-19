#include "SelectWindow.h"

SelectWindow::SelectWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	init();
}

SelectWindow::~SelectWindow()
{
}

void SelectWindow::init()
{
	//初始化各按钮
	shortestPathButton = new QPushButton(this);
	minimumSpanningTreeButton = new QPushButton( this);
	degreeCentralityButton = new QPushButton( this);
	connectedComponentButton = new QPushButton( this);

}

void SelectWindow::resizeEvent(QResizeEvent*event)
{
	shortestPathButton->setGeometry(5, 5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);
	minimumSpanningTreeButton->setGeometry(geometry().width()/2+5,5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);
	degreeCentralityButton->setGeometry(5,geometry().height()/2+5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);
	connectedComponentButton->setGeometry(geometry().width() / 2 + 5, geometry().height() / 2 + 5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);

	//给按钮添加图片
	QIcon shortestPathButton_icon;
	shortestPathButton_icon.addFile(":/buttons/Resources/buttons/shortestPathButton.bmp");
	shortestPathButton->setIcon(shortestPathButton_icon);
	shortestPathButton->setIconSize(QSize(shortestPathButton->width()-1 , shortestPathButton->height()-10));

	QIcon minimumSpanningTreeButton_icon;
	minimumSpanningTreeButton_icon.addFile(":/buttons/Resources/buttons/minimumSpanningTreeButton.bmp");
	minimumSpanningTreeButton->setIcon(minimumSpanningTreeButton_icon);
	minimumSpanningTreeButton->setIconSize(QSize(minimumSpanningTreeButton->width()-1, minimumSpanningTreeButton->height() - 10));

	QIcon degreeCentralityButton_icon;
	degreeCentralityButton_icon.addFile(":/buttons/Resources/buttons/centrad.bmp");
	degreeCentralityButton->setIcon(degreeCentralityButton_icon);
	degreeCentralityButton->setIconSize(QSize(degreeCentralityButton->width()-1, degreeCentralityButton->height() - 10));

	QIcon connectedComponentButton_icon;
	connectedComponentButton_icon.addFile(":/buttons/Resources/buttons/connectedComponentButton.bmp");
	connectedComponentButton->setIcon(connectedComponentButton_icon);
	connectedComponentButton->setIconSize(QSize(connectedComponentButton->width()-1, connectedComponentButton->height() - 10));

}
