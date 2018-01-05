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
	//��ʼ������ť
	shortestPathButton = new QPushButton("���·��",this);
	minimumSpanningTreeButton = new QPushButton("��С������", this);
	degreeCentralityButton = new QPushButton("���Ķ�", this);
	connectedComponentButton = new QPushButton("��ͨ����", this);

}

void SelectWindow::resizeEvent(QResizeEvent*event)
{
	shortestPathButton->setGeometry(5, 5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);
	minimumSpanningTreeButton->setGeometry(geometry().width()/2+5,5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);
	degreeCentralityButton->setGeometry(5,geometry().height()/2+5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);
	connectedComponentButton->setGeometry(geometry().width() / 2 + 5, geometry().height() / 2 + 5, geometry().width() / 2 - 10, geometry().height() / 2 - 10);

}
