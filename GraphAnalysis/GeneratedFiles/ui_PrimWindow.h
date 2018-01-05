/********************************************************************************
** Form generated from reading UI file 'PrimWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMWINDOW_H
#define UI_PRIMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimWindow
{
public:

    void setupUi(QWidget *PrimWindow)
    {
        if (PrimWindow->objectName().isEmpty())
            PrimWindow->setObjectName(QStringLiteral("PrimWindow"));
        PrimWindow->resize(400, 300);

        retranslateUi(PrimWindow);

        QMetaObject::connectSlotsByName(PrimWindow);
    } // setupUi

    void retranslateUi(QWidget *PrimWindow)
    {
        PrimWindow->setWindowTitle(QApplication::translate("PrimWindow", "PrimWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PrimWindow: public Ui_PrimWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMWINDOW_H
