/********************************************************************************
** Form generated from reading UI file 'betweennessWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BETWEENNESSWINDOW_H
#define UI_BETWEENNESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_betweennessWindow
{
public:

    void setupUi(QWidget *betweennessWindow)
    {
        if (betweennessWindow->objectName().isEmpty())
            betweennessWindow->setObjectName(QStringLiteral("betweennessWindow"));
        betweennessWindow->resize(400, 300);

        retranslateUi(betweennessWindow);

        QMetaObject::connectSlotsByName(betweennessWindow);
    } // setupUi

    void retranslateUi(QWidget *betweennessWindow)
    {
        betweennessWindow->setWindowTitle(QApplication::translate("betweennessWindow", "betweennessWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class betweennessWindow: public Ui_betweennessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BETWEENNESSWINDOW_H
