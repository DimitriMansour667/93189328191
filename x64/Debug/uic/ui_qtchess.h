/********************************************************************************
** Form generated from reading UI file 'qtchess.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCHESS_H
#define UI_QTCHESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtchessClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtchessClass)
    {
        if (qtchessClass->objectName().isEmpty())
            qtchessClass->setObjectName("qtchessClass");
        qtchessClass->resize(600, 400);
        menuBar = new QMenuBar(qtchessClass);
        menuBar->setObjectName("menuBar");
        qtchessClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtchessClass);
        mainToolBar->setObjectName("mainToolBar");
        qtchessClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(qtchessClass);
        centralWidget->setObjectName("centralWidget");
        qtchessClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qtchessClass);
        statusBar->setObjectName("statusBar");
        qtchessClass->setStatusBar(statusBar);

        retranslateUi(qtchessClass);

        QMetaObject::connectSlotsByName(qtchessClass);
    } // setupUi

    void retranslateUi(QMainWindow *qtchessClass)
    {
        qtchessClass->setWindowTitle(QCoreApplication::translate("qtchessClass", "qtchess", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qtchessClass: public Ui_qtchessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCHESS_H
