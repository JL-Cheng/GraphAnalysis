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
	shortestPathButton = new QPushButton("最短路径",this);
	minimumSpanningTreeButton = new QPushButton("最小生成树", this);
	degreeCentralityButton = new QPushButton("中心度", this);
	connectedComponentButton = new QPushButton("连通分量", this);

}

void SelectWindow::resizeEvent(QResizeEvent*event)
{
	shortestPathButton->setGeometry(5, 5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);
	minimumSpanningTreeButton->setGeometry(geometry().width()/2+5,5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);
	degreeCentralityButton->setGeometry(5,geometry().height()/2+5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);
	connectedComponentButton->setGeometry(geometry().width() / 2 + 5, geometry().height() / 2 + 5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);

}
