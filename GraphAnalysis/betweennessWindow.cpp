#include "betweennessWindow.h"

betweennessWindow::betweennessWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	init();//��ʼ��

	websiteShowWindow->showWeb("");

	connect(betweennessButton, SIGNAL(clicked()),
		this, SLOT(showBetweenness()));
	connect(connectnessButton, SIGNAL(clicked()),
		this, SLOT(showConnectness()));
}

betweennessWindow::~betweennessWindow()
{
}

void betweennessWindow::init()
{
	progressLabel = new QLabel("�����У����Ե�...", this);
	betweennessButton = new QPushButton("�������Ķ�", this);
	connectnessButton = new QPushButton("��ͨ���Ķ�", this);
	websiteShowWindow = new WebsiteShow(this);
	returnButton = new QPushButton("Return", this);

	betweennessButton->setEnabled(false);
	connectnessButton->setEnabled(false);
}

void betweennessWindow::showResult()
{
	progressLabel->setText("����ɣ�������ťѡ����Ҫ��ʾ�����Ķȡ�");
	betweennessButton->setEnabled(true);
	connectnessButton->setEnabled(true);
	progressLabel->show();
}

void betweennessWindow::resizeEvent(QResizeEvent *event)
{
	betweennessButton->setGeometry(geometry().width() / 4 - 10, 5, geometry().width() / 4, geometry().height() / 30);
	connectnessButton->setGeometry(geometry().width() / 2 + 10, 5, geometry().width() / 4, geometry().height() / 30);
	progressLabel->setGeometry(5, geometry().height() / 30 + 5, geometry().width() - 10, geometry().height() / 30);
	websiteShowWindow->setGeometry(5, geometry().height() / 15 + 10, geometry().width() - 10, geometry().height() * 12 / 15);
	returnButton->setGeometry(geometry().width() * 3 / 8, geometry().height() * 13 / 15 + 25, geometry().width() / 4, geometry().height() / 30);

	/*progressLabel->setGeometry(5, 5, geometry().width() - 10, geometry().height() / 15);
	websiteShowWindow->setGeometry(5, geometry().height() / 15 + 10, geometry().width() - 10, geometry().height() * 13 / 15);
	returnButton->setGeometry(geometry().width() * 3 / 8, geometry().height() * 13 / 15 + 25, geometry().width() / 4, geometry().height() / 30);*/
}

