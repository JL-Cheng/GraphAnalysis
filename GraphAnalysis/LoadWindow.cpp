#include "LoadWindow.h"

LoadWindow::LoadWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	init();
}

LoadWindow::~LoadWindow()
{
	delete showLabel;
	delete showProgressBar;
}

void LoadWindow::init()
{
	showLabel = new QLabel(this);
	showProgressBar = new QProgressBar(this);
	number = 0;
	total = 30000;

	QFont font;//设置文本字体
	font.setPointSize(25);
	font.setFamily("隶书");
	showLabel->setFont(font);
	showLabel->setStyleSheet("color:black");//设置文本颜色

	showProgressBar->setOrientation(Qt::Horizontal);  // 水平方向
	showProgressBar->setMinimum(0);  // 最小值
	showProgressBar->setMaximum(total);  // 最大值
	showProgressBar->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式

}

void LoadWindow::getRateOfProgress(int num)
{
	number = num;
	showLabel->setText(tr("正在提取信息"));
	showProgressBar->setValue(number);  // 当前进度
	showProgressBar->setFormat(QString("当前进度为：%1%").arg(number * 100 / total));//当前进度
	showLabel->repaint();
	showProgressBar->repaint();
}

void LoadWindow::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event);//避免编译器报警
	this->setAutoFillBackground(true);//自动填充背景

	//添加背景
	QImage image;
	QPalette palette;
	image.load(":/backgrounds/Resources/backgrounds/background.bmp");//加载背景图片

	palette.setBrush(this->backgroundRole(),
		QBrush(image.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));//设置背景画刷

	this->setPalette(palette);

	//使文本框自适应
	showLabel->setGeometry(geometry().x() + geometry().width() / 2 - 120, geometry().y() + geometry().height() - 220, 350, 50);
	showProgressBar->setGeometry(geometry().x() + geometry().width() / 2 - 300, geometry().y() + geometry().height() - 150, 600, 50);
}
