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
	connect(selectWindow->minimumSpanningTreeButton, SIGNAL(clicked()),
		this, SLOT(changeToPrimWindow()));
	connect(selectWindow->connectedComponentButton, SIGNAL(clicked()),
		this, SLOT(changeToConnected_componentWindow()));

	//连接最短路径相关信号槽
	connect(shortestPathWindow, &ShortestPathWindow::searchShortestPath,
		this, &MainWindow::startSearchShortestPathThread);
	connect(shortestPathWindow->returnButton, SIGNAL(clicked()),
		this, SLOT(changeToSelectWindow()));

	//连接最小生成树信号槽
	connect(selectWindow->minimumSpanningTreeButton, SIGNAL(clicked()),
		this, SLOT(startPrimThread()));
	connect(primWindow->returnButton, SIGNAL(clicked()),
		this, SLOT(changeToSelectWindow()));

	//连接连通分支信号槽
	connect(selectWindow->connectedComponentButton, SIGNAL(clicked()),
		this, SLOT(startConnected_componentThread()));
	connect(connected_componentWindow->returnButton, SIGNAL(clicked()),
		this, SLOT(changeToSelectWindow()));

	startExtractInformationThread();//开始信息提取进程
}

void MainWindow::init()
{
	//初始化各变量
	loadWindow = new LoadWindow(this);
	selectWindow = new SelectWindow(this);
	shortestPathWindow = new ShortestPathWindow(this);
	primWindow = new PrimWindow(this);
	connected_componentWindow = new Connected_componentWindow(this);
	backgroundController = new QStackedWidget(this);

	//将页面设置为中心窗口
	this->setCentralWidget(backgroundController);
	
	//将各界面加入到界面转换器中
	backgroundController->addWidget(loadWindow);
	backgroundController->addWidget(selectWindow);
	backgroundController->addWidget(shortestPathWindow);
	backgroundController->addWidget(primWindow);
	backgroundController->addWidget(connected_componentWindow);

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

void MainWindow::startPrimThread()
{
	WorkerThread *workerThread = new WorkerThread(2, this);
	connect(workerThread, &WorkerThread::finishPrim,
		primWindow, &PrimWindow::showResult);
	// 线程结束后，自动销毁
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}

void MainWindow::startConnected_componentThread()
{
	WorkerThread *workerThread = new WorkerThread(3, this);
	connect(workerThread, &WorkerThread::finishConnected_component,
		connected_componentWindow, &Connected_componentWindow::showResult);
	// 线程结束后，自动销毁
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}