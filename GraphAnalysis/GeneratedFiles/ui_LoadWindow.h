/********************************************************************************
** Form generated from reading UI file 'LoadWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADWINDOW_H
#define UI_LOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadWindow
{
public:

    void setupUi(QWidget *LoadWindow)
    {
        if (LoadWindow->objectName().isEmpty())
            LoadWindow->setObjectName(QStringLiteral("LoadWindow"));
        LoadWindow->resize(400, 300);

        retranslateUi(LoadWindow);

        QMetaObject::connectSlotsByName(LoadWindow);
    } // setupUi

    void retranslateUi(QWidget *LoadWindow)
    {
        LoadWindow->setWindowTitle(QApplication::translate("LoadWindow", "LoadWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadWindow: public Ui_LoadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADWINDOW_H
