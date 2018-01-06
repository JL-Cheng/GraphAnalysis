#include "Connected_componentWindow.h"

Connected_componentWindow::Connected_componentWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	init();//初始化
	//点击连接按钮后进行搜索
	connect(searchButton, SIGNAL(clicked()), this, SLOT(sendSearchSignal()));

	websiteShowWindow->showWeb("");
}

Connected_componentWindow::~Connected_componentWindow()
{
}

void Connected_componentWindow::init()
{
	progressLabel = new QLabel("计算中，请稍等...", this);
	websiteShowWindow = new WebsiteShow(this);
	returnButton = new QPushButton("Return", this);
	thresholdLabel = new QLineEdit(this);
	searchButton = new QPushButton("search", this);
	threshold = 0;

	thresholdLabel->setPlaceholderText(QString("请输入阈值"));
}

void Connected_componentWindow::showResult()
{
	progressLabel->setText(QString("已完成。此时阈值为%1").arg(threshold));
	websiteShowWindow->showWeb("file:///connected_component.html");
	websiteShowWindow->show();
	progressLabel->show();
}

void Connected_componentWindow::sendSearchSignal()
{
	threshold = thresholdLabel->text().toInt();
	emit searchConnected_component(threshold);
}

void Connected_componentWindow::resizeEvent(QResizeEvent *event)
{
	thresholdLabel->setGeometry(geometry().width() / 4 + 5, 5, geometry().width() / 4 - 5, geometry().height() / 30);
	searchButton->setGeometry(geometry().width() / 2 + 5, 5, geometry().width() / 4 - 5, geometry().height() / 30);
	progressLabel->setGeometry(5, geometry().height() / 30 + 5, geometry().width() - 10, geometry().height() / 30);
	websiteShowWindow->setGeometry(5, geometry().height() / 15 + 10, geometry().width() - 10, geometry().height() * 12 / 15);
	returnButton->setGeometry(geometry().width() * 3 / 8, geometry().height() * 13 / 15 + 25, geometry().width() / 4, geometry().height() / 30);
}
