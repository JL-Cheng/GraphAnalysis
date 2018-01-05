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

	//创建按钮选择界面的信号槽
	connect(selectWindow->shortestPathButton, SIGNAL(clicked()),
		this, SLOT(changeToShortestPathWindow()));

	//连接最短路径相关信号槽
	connect(shortestPathWindow, &ShortestPathWindow::searchShortestPath,
		this, &MainWindow::startSearchShortestPathThread);

	startExtractInformationThread();//开始信息提取进程
}

void MainWindow::init()
{
	//初始化各变量
	loadWindow = new LoadWindow(this);
	selectWindow = new SelectWindow(this);
	shortestPathWindow = new ShortestPathWindow(this);
	backgroundController = new QStackedWidget(this);

	//将页面设置为中心窗口
	this->setCentralWidget(backgroundController);
	
	//将各界面加入到界面转换器中
	backgroundController->addWidget(loadWindow);
	backgroundController->addWidget(selectWindow);
	backgroundController->addWidget(shortestPathWindow);

	//设置界面为加载界面
	backgroundController->setCurrentIndex(0);
}

void MainWindow::startSearchShortestPathThread(int startPoint, int endPoint)
{
	WorkerThread *workerThread = new WorkerThread(startPoint, endPoint, this);
	connect(workerThread, &WorkerThread::sendResult,
		shortestPathWindow, &ShortestPathWindow::showResult);
	// 线程结束后，自动销毁
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}

void MainWindow::startExtractInformationThread()
{
	WorkerThread *workerThread = new WorkerThread(0, this);
	connect(workerThread, &WorkerThread::tellTotalNumber,
		shortestPathWindow, &ShortestPathWindow::getTotalNumber);
	connect(workerThread, &WorkerThread::sendRateOfProgress,
		loadWindow, &LoadWindow::getRateOfProgress);
	connect(workerThread, &WorkerThread::changeWindow,
		this, &MainWindow::changeToSelectWindow);
	// 线程结束后，自动销毁
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}