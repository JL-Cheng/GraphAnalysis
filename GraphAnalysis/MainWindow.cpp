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

	//�������·������źŲ�
	connect(shortestPathWindow, &ShortestPathWindow::searchShortestPath,
		this, &MainWindow::startSearchShortestPathThread);

	startExtractInformationThread();//��ʼ��Ϣ��ȡ����
}

void MainWindow::init()
{
	//��ʼ��������
	loadWindow = new LoadWindow(this);
	selectWindow = new SelectWindow(this);
	shortestPathWindow = new ShortestPathWindow(this);
	backgroundController = new QStackedWidget(this);

	//��ҳ������Ϊ���Ĵ���
	this->setCentralWidget(backgroundController);
	
	//����������뵽����ת������
	backgroundController->addWidget(loadWindow);
	backgroundController->addWidget(selectWindow);
	backgroundController->addWidget(shortestPathWindow);

	//���ý���Ϊ���ؽ���
	backgroundController->setCurrentIndex(0);
}

void MainWindow::startSearchShortestPathThread(int startPoint, int endPoint)
{
	WorkerThread *workerThread = new WorkerThread(startPoint, endPoint, this);
	connect(workerThread, &WorkerThread::sendResult,
		shortestPathWindow, &ShortestPathWindow::showResult);
	// �߳̽������Զ�����
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
	// �߳̽������Զ�����
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}