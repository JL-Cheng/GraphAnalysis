#include "WebsiteShow.h"

WebsiteShow::WebsiteShow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	webview = new QWebEngineView(this);
	webview->load(QUrl("http://localhost/projects/project_6/"));
	webview->show();
}

WebsiteShow::~WebsiteShow()
{
}

void WebsiteShow::resizeEvent(QResizeEvent *)
{
	webview->resize(this->size());
}