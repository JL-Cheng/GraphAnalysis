#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//初始化
	init();

	//设置窗口属性
	this->resize(1200, 900);
	this->setWindowTitle("Graph Analysis");

}

void MainWindow::init()
{
	//初始化各变量
	websiteShowWindow = new WebsiteShow(this);
	backgroundController = new QStackedWidget(this);

	//将页面设置为中心窗口
	this->setCentralWidget(backgroundController);
	
	//将各界面加入到界面转换器中
	backgroundController->addWidget(websiteShowWindow);

	//设置界面为网页显示界面
	backgroundController->setCurrentIndex(0);
}