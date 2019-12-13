/********************************************************************************
** Form generated from reading UI file 'QtGuiApplicationtest.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATIONTEST_H
#define UI_QTGUIAPPLICATIONTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplicationtestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplicationtestClass)
    {
        if (QtGuiApplicationtestClass->objectName().isEmpty())
            QtGuiApplicationtestClass->setObjectName(QString::fromUtf8("QtGuiApplicationtestClass"));
        QtGuiApplicationtestClass->resize(600, 400);
        menuBar = new QMenuBar(QtGuiApplicationtestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtGuiApplicationtestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplicationtestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiApplicationtestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGuiApplicationtestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtGuiApplicationtestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGuiApplicationtestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiApplicationtestClass->setStatusBar(statusBar);

        retranslateUi(QtGuiApplicationtestClass);

        QMetaObject::connectSlotsByName(QtGuiApplicationtestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplicationtestClass)
    {
        QtGuiApplicationtestClass->setWindowTitle(QCoreApplication::translate("QtGuiApplicationtestClass", "QtGuiApplicationtest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplicationtestClass: public Ui_QtGuiApplicationtestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATIONTEST_H
