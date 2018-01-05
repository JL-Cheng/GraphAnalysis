#include "ShortestPathWindow.h"

ShortestPathWindow::ShortestPathWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//��ʼ��
	init();

	//������Ӱ�ť���������
	connect(searchButton, SIGNAL(clicked()), this, SLOT(sendSearchSignal()));

	websiteShowWindow->showWeb("");
}

ShortestPathWindow::~ShortestPathWindow()
{
}

void ShortestPathWindow::init()
{
	startPointLabel = new QLineEdit(this);
	endPointLabel = new QLineEdit(this);
	resultLabel = new QLabel(this);
	searchButton = new QPushButton("Search",this);
	returnButton = new QPushButton("Return", this);
	websiteShowWindow = new WebsiteShow(this);

}

void ShortestPathWindow::sendSearchSignal()
{
	int start_ID = startPointLabel->text().toInt();
	int end_ID = endPointLabel->text().toInt();
	emit searchShortestPath(start_ID, end_ID);
}

void ShortestPathWindow::showResult(QString result)
{
	resultLabel->setText(result);
	websiteShowWindow->showWeb("file:///shortestPath.html");
	websiteShowWindow->show();
	resultLabel->show();
}

void ShortestPathWindow::getTotalNumber(int number)
{
	totalNumber = number;
	startPointLabel->setPlaceholderText(QString("���������,n<%1").arg(totalNumber));
	endPointLabel->setPlaceholderText(QString("�������յ�,n<%1").arg(totalNumber));
}

void ShortestPathWindow::resizeEvent(QResizeEvent *event)
{
	startPointLabel->setGeometry(5, 5, geometry().width() / 4 - 5, geometry().height() / 30);
	endPointLabel->setGeometry(geometry().width() / 4 + 5, 5, geometry().width() / 4 - 5, geometry().height() / 30);
	searchButton->setGeometry(geometry().width() / 2 + 5, 5, geometry().width() / 4 - 5, geometry().height() / 30);
	resultLabel->setGeometry(5, geometry().height() / 30 + 5, geometry().width() - 10, geometry().height() / 30);
	websiteShowWindow->setGeometry(5, geometry().height() / 15 + 10, geometry().width() - 10, geometry().height() * 12 / 15);
	returnButton->setGeometry(geometry().width() *3 / 8, geometry().height() * 13 / 15 + 25, geometry().width() / 4, geometry().height() / 30);
}
