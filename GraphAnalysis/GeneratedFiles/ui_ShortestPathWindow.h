/********************************************************************************
** Form generated from reading UI file 'ShortestPathWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTESTPATHWINDOW_H
#define UI_SHORTESTPATHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShortestPathWindow
{
public:

    void setupUi(QWidget *ShortestPathWindow)
    {
        if (ShortestPathWindow->objectName().isEmpty())
            ShortestPathWindow->setObjectName(QStringLiteral("ShortestPathWindow"));
        ShortestPathWindow->resize(400, 300);

        retranslateUi(ShortestPathWindow);

        QMetaObject::connectSlotsByName(ShortestPathWindow);
    } // setupUi

    void retranslateUi(QWidget *ShortestPathWindow)
    {
        ShortestPathWindow->setWindowTitle(QApplication::translate("ShortestPathWindow", "ShortestPathWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShortestPathWindow: public Ui_ShortestPathWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTESTPATHWINDOW_H
