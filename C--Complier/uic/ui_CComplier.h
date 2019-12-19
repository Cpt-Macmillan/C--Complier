/********************************************************************************
** Form generated from reading UI file 'CComplier.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCOMPLIER_H
#define UI_CCOMPLIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CComplierClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QProgressBar *progressBar123;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CComplierClass)
    {
        if (CComplierClass->objectName().isEmpty())
            CComplierClass->setObjectName(QString::fromUtf8("CComplierClass"));
        CComplierClass->resize(918, 686);
        centralWidget = new QWidget(CComplierClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 240, 112, 34));
        progressBar123 = new QProgressBar(centralWidget);
        progressBar123->setObjectName(QString::fromUtf8("progressBar123"));
        progressBar123->setGeometry(QRect(220, 50, 381, 61));
        progressBar123->setValue(0);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 120, 201, 21));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 290, 112, 34));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 340, 112, 34));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 390, 112, 34));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 440, 112, 34));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 490, 112, 34));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(150, 240, 112, 34));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(150, 290, 112, 34));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(20, 60, 181, 51));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(150, 340, 112, 34));
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(150, 390, 112, 34));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(150, 440, 112, 34));
        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(150, 490, 112, 34));
        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(630, 50, 181, 61));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(300, 190, 551, 411));
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 197, 101, 31));
        CComplierClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CComplierClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 918, 29));
        CComplierClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CComplierClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CComplierClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CComplierClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CComplierClass->setStatusBar(statusBar);

        retranslateUi(CComplierClass);

        QMetaObject::connectSlotsByName(CComplierClass);
    } // setupUi

    void retranslateUi(QMainWindow *CComplierClass)
    {
        CComplierClass->setWindowTitle(QCoreApplication::translate("CComplierClass", "CComplier", nullptr));
        pushButton->setText(QCoreApplication::translate("CComplierClass", "\346\272\220\347\250\213\345\272\217", nullptr));
        label->setText(QCoreApplication::translate("CComplierClass", "Ready to analysis...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CComplierClass", "\345\216\273\351\231\244\346\263\250\351\207\212\347\251\272\346\240\274", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CComplierClass", "\350\257\215\346\263\225\345\210\206\346\236\220\347\273\223\346\236\234", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CComplierClass", "\350\257\255\346\263\225\350\247\204\345\210\231", nullptr));
        pushButton_5->setText(QCoreApplication::translate("CComplierClass", "\346\266\210\351\231\244\345\267\246\351\200\222\345\275\222", nullptr));
        pushButton_6->setText(QCoreApplication::translate("CComplierClass", "\346\266\210\351\231\244\345\244\232\344\272\247\347\224\237\345\274\217", nullptr));
        pushButton_7->setText(QCoreApplication::translate("CComplierClass", "\350\257\255\346\263\225\345\217\230\345\205\203\351\233\206", nullptr));
        pushButton_8->setText(QCoreApplication::translate("CComplierClass", "LL(1)\345\210\206\346\236\220\350\241\250", nullptr));
        pushButton_9->setText(QCoreApplication::translate("CComplierClass", "\345\274\200\345\247\213\345\210\206\346\236\220", nullptr));
        pushButton_10->setText(QCoreApplication::translate("CComplierClass", "\350\257\255\346\263\225\345\210\206\346\236\220\346\240\210", nullptr));
        pushButton_11->setText(QCoreApplication::translate("CComplierClass", "\347\254\246\345\217\267\350\241\250", nullptr));
        pushButton_12->setText(QCoreApplication::translate("CComplierClass", "\344\270\255\351\227\264\344\273\243\347\240\201\347\224\237\346\210\220", nullptr));
        pushButton_13->setText(QCoreApplication::translate("CComplierClass", "DAG\344\274\230\345\214\226", nullptr));
        pushButton_14->setText(QCoreApplication::translate("CComplierClass", "\346\237\245\347\234\213\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("CComplierClass", " \346\237\245\347\234\213\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CComplierClass: public Ui_CComplierClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCOMPLIER_H
