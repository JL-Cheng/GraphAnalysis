#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//��ʼ��
	init();

	//���ô�������
	this->resize(1200, 900);
	this->setWindowTitle("Graph Analysis");

}

void MainWindow::init()
{
	//��ʼ��������
	websiteShowWindow = new WebsiteShow(this);
	backgroundController = new QStackedWidget(this);

	//��ҳ������Ϊ���Ĵ���
	this->setCentralWidget(backgroundController);
	
	//����������뵽����ת������
	backgroundController->addWidget(websiteShowWindow);

	//���ý���Ϊ��ҳ��ʾ����
	backgroundController->setCurrentIndex(0);
}