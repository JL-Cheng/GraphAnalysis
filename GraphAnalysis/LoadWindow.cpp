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

	QFont font;//�����ı�����
	font.setPointSize(25);
	font.setFamily("����");
	showLabel->setFont(font);
	showLabel->setStyleSheet("color:black");//�����ı���ɫ

	showProgressBar->setOrientation(Qt::Horizontal);  // ˮƽ����
	showProgressBar->setMinimum(0);  // ��Сֵ
	showProgressBar->setMaximum(total);  // ���ֵ
	showProgressBar->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // ���뷽ʽ

}

void LoadWindow::getRateOfProgress(int num)
{
	number = num;
	showLabel->setText(tr("������ȡ��Ϣ"));
	showProgressBar->setValue(number);  // ��ǰ����
	showProgressBar->setFormat(QString("��ǰ����Ϊ��%1%").arg(number * 100 / total));//��ǰ����
	showLabel->repaint();
	showProgressBar->repaint();
}

void LoadWindow::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event);//�������������
	this->setAutoFillBackground(true);//�Զ���䱳��

	//��ӱ���
	QImage image;
	QPalette palette;
	image.load(":/backgrounds/Resources/backgrounds/background.bmp");//���ر���ͼƬ

	palette.setBrush(this->backgroundRole(),
		QBrush(image.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));//���ñ�����ˢ

	this->setPalette(palette);

	//ʹ�ı�������Ӧ
	showLabel->setGeometry(geometry().x() + geometry().width() / 2 - 120, geometry().y() + geometry().height() - 220, 350, 50);
	showProgressBar->setGeometry(geometry().x() + geometry().width() / 2 - 300, geometry().y() + geometry().height() - 150, 600, 50);
}
