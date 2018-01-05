/********************************************************************************
** Form generated from reading UI file 'Connected_componentWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTED_COMPONENTWINDOW_H
#define UI_CONNECTED_COMPONENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connected_componentWindow
{
public:

    void setupUi(QWidget *Connected_componentWindow)
    {
        if (Connected_componentWindow->objectName().isEmpty())
            Connected_componentWindow->setObjectName(QStringLiteral("Connected_componentWindow"));
        Connected_componentWindow->resize(400, 300);

        retranslateUi(Connected_componentWindow);

        QMetaObject::connectSlotsByName(Connected_componentWindow);
    } // setupUi

    void retranslateUi(QWidget *Connected_componentWindow)
    {
        Connected_componentWindow->setWindowTitle(QApplication::translate("Connected_componentWindow", "Connected_componentWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Connected_componentWindow: public Ui_Connected_componentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTED_COMPONENTWINDOW_H
