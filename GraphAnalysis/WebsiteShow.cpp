#include "WebsiteShow.h"

WebsiteShow::WebsiteShow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	webview = new QWebEngineView(this);
}

WebsiteShow::~WebsiteShow()
{
}

void WebsiteShow::showWeb(QString websitepath)
{
	webview->load(QUrl(websitepath));
	webview->show();
}

void WebsiteShow::resizeEvent(QResizeEvent *)
{
	webview->resize(this->size());
}