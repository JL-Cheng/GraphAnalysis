#include "Connected_componentWindow.h"

Connected_componentWindow::Connected_componentWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	init();//��ʼ��

	websiteShowWindow->showWeb("");
}

Connected_componentWindow::~Connected_componentWindow()
{
}

void Connected_componentWindow::init()
{
	progressLabel = new QLabel("�����У����Ե�...", this);
	websiteShowWindow = new WebsiteShow(this);
	returnButton = new QPushButton("Return", this);
}

void Connected_componentWindow::showResult()
{
	progressLabel->setText("����ɡ�");
	websiteShowWindow->showWeb("file:///connected_component.html");
	websiteShowWindow->show();
	progressLabel->show();
}

void Connected_componentWindow::resizeEvent(QResizeEvent *event)
{
	progressLabel->setGeometry(5, 5, geometry().width() - 10, geometry().height() / 15);
	websiteShowWindow->setGeometry(5, geometry().height() / 15 + 10, geometry().width() - 10, geometry().height() * 13 / 15);
	returnButton->setGeometry(geometry().width() * 3 / 8, geometry().height() * 13 / 15 + 25, geometry().width() / 4, geometry().height() / 30);
}
