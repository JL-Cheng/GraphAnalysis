#include"WorkerThread.h"

WorkerThread::WorkerThread(int startPoint, int endPoint,int number, QObject *parent)
	:QThread(parent)
{
	start_ID = startPoint;
	end_ID = endPoint;
	status = 1;
	search_shortest_path = new searchShortestPath;
	connect(search_shortest_path, &searchShortestPath::findResult,
		this, &WorkerThread::getResult);
}

WorkerThread::WorkerThread(int thresholdNum, int number, QObject *parent)
	:QThread(parent)
{
	threshold = thresholdNum;
	status = 3;
}
WorkerThread::WorkerThread(int number, QObject *parent)
	:QThread(parent),
	status(number)
{
	start_ID = 0;
	end_ID = 0;
	search_shortest_path = NULL;
	information = NULL;
	if (number == 0)
		information = new extractInformation;
}

WorkerThread::~WorkerThread()
{
	// 请求终止
	requestInterruption();
	quit();
	wait();
}

void WorkerThread::run()
{
	while (!isInterruptionRequested())
	{
		switch(status)
		{
		case 0:
			connect(information, &extractInformation::sendRateOfProgress,
				this, &WorkerThread::getRateOfProgress);
			//提取节点信息
			information->operate();
			emit tellTotalNumber(information->list.size());
			emit changeWindow();
			break;
		case 1:
			//搜寻最短路径
			search_shortest_path->search(start_ID, end_ID);
			break;
		case 2:
			newTree.findST();
			emit finishPrim();
			break;
		case 3:
			newComponent.changeThreshold(threshold);
			emit finishConnected_component();
			break;
		}
		return;
	}
}