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

	//������ťѡ�������źŲ�
	connect(selectWindow->shortestPathButton, SIGNAL(clicked()),
		this, SLOT(changeToShortestPathWindow()));
	connect(selectWindow->minimumSpanningTreeButton, SIGNAL(clicked()),
		this, SLOT(changeToPrimWindow()));
	connect(selectWindow->connectedComponentButton, SIGNAL(clicked()),
		this, SLOT(changeToConnected_componentWindow()));
	connect(selectWindow->degreeCentralityButton, SIGNAL(clicked()),
		this, SLOT(changeToBetweennessWindow()));

	//�������·������źŲ�
	connect(shortestPathWindow, &ShortestPathWindow::searchShortestPath,
		this, &MainWindow::startSearchShortestPathThread);
	connect(shortestPathWindow->returnButton, SIGNAL(clicked()),
		this, SLOT(changeToSelectWindow()));

	//������С�������źŲ�
	connect(selectWindow->minimumSpanningTreeButton, SIGNAL(clicked()),
		this, SLOT(startPrimThread()));
	connect(primWindow->returnButton, SIGNAL(clicked()),
		this, SLOT(changeToSelectWindow()));

	//������ͨ��֧�źŲ�
	connect(connected_componentWindow, &Connected_componentWindow::searchConnected_component,
		this,&MainWindow::startConnected_componentThread);
	connect(connected_componentWindow->returnButton, SIGNAL(clicked()),
		this, SLOT(changeToSelectWindow()));

	//���ӽ������Ķ��źŲ�
	connect(selectWindow->degreeCentralityButton, SIGNAL(clicked()),
		this, SLOT(startBetweennessThread()));
	connect(degreeCentralityWindow->returnButton, SIGNAL(clicked()),
		this, SLOT(changeToSelectWindow()));

	startExtractInformationThread();//��ʼ��Ϣ��ȡ����
}

void MainWindow::init()
{
	//��ʼ��������
	loadWindow = new LoadWindow(this);
	selectWindow = new SelectWindow(this);
	shortestPathWindow = new ShortestPathWindow(this);
	primWindow = new PrimWindow(this);
	connected_componentWindow = new Connected_componentWindow(this);
	degreeCentralityWindow = new betweennessWindow(this);
	backgroundController = new QStackedWidget(this);

	//��ҳ������Ϊ���Ĵ���
	this->setCentralWidget(backgroundController);
	
	//����������뵽����ת������
	backgroundController->addWidget(loadWindow);
	backgroundController->addWidget(selectWindow);
	backgroundController->addWidget(shortestPathWindow);
	backgroundController->addWidget(primWindow);
	backgroundController->addWidget(connected_componentWindow);
	backgroundController->addWidget(degreeCentralityWindow);

	//���ý���Ϊ���ؽ���
	backgroundController->setCurrentIndex(0);
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
	// �߳̽������Զ�����
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}

void MainWindow::startSearchShortestPathThread(int startPoint, int endPoint)
{
	WorkerThread *workerThread = new WorkerThread(startPoint, endPoint, 1, this);
	connect(workerThread, &WorkerThread::sendResult,
		shortestPathWindow, &ShortestPathWindow::showResult);
	// �߳̽������Զ�����
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}

void MainWindow::startPrimThread()
{
	WorkerThread *workerThread = new WorkerThread(2, this);
	connect(workerThread, &WorkerThread::finishPrim,
		primWindow, &PrimWindow::showResult);
	// �߳̽������Զ�����
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}

void MainWindow::startConnected_componentThread(int threshold)
{
	WorkerThread *workerThread = new WorkerThread(threshold,3, this);
	connect(workerThread, &WorkerThread::finishConnected_component,
		connected_componentWindow, &Connected_componentWindow::showResult);
	// �߳̽������Զ�����
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}

void MainWindow::startBetweennessThread()
{
	WorkerThread *workerThread = new WorkerThread(4, this);
	connect(workerThread, &WorkerThread::finishBetweenness,
		degreeCentralityWindow, &betweennessWindow::showResult);
	// �߳̽������Զ�����
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}