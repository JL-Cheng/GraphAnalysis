/********************************************************************************
** Form generated from reading UI file 'SelectWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTWINDOW_H
#define UI_SELECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectWindow
{
public:

    void setupUi(QWidget *SelectWindow)
    {
        if (SelectWindow->objectName().isEmpty())
            SelectWindow->setObjectName(QStringLiteral("SelectWindow"));
        SelectWindow->resize(400, 300);

        retranslateUi(SelectWindow);

        QMetaObject::connectSlotsByName(SelectWindow);
    } // setupUi

    void retranslateUi(QWidget *SelectWindow)
    {
        SelectWindow->setWindowTitle(QApplication::translate("SelectWindow", "SelectWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectWindow: public Ui_SelectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTWINDOW_H
