/********************************************************************************
** Form generated from reading UI file 'WebsiteShow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBSITESHOW_H
#define UI_WEBSITESHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebsiteShow
{
public:

    void setupUi(QWidget *WebsiteShow)
    {
        if (WebsiteShow->objectName().isEmpty())
            WebsiteShow->setObjectName(QStringLiteral("WebsiteShow"));
        WebsiteShow->resize(400, 300);

        retranslateUi(WebsiteShow);

        QMetaObject::connectSlotsByName(WebsiteShow);
    } // setupUi

    void retranslateUi(QWidget *WebsiteShow)
    {
        WebsiteShow->setWindowTitle(QApplication::translate("WebsiteShow", "WebsiteShow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WebsiteShow: public Ui_WebsiteShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBSITESHOW_H
