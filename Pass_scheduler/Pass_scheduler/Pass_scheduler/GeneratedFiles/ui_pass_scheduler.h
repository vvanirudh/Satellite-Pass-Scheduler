/********************************************************************************
** Form generated from reading UI file 'pass_scheduler.ui'
**
** Created: Thu Jul 12 12:01:35 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASS_SCHEDULER_H
#define UI_PASS_SCHEDULER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pass_schedulerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Pass_schedulerClass)
    {
        if (Pass_schedulerClass->objectName().isEmpty())
            Pass_schedulerClass->setObjectName(QString::fromUtf8("Pass_schedulerClass"));
        Pass_schedulerClass->resize(600, 400);
        menuBar = new QMenuBar(Pass_schedulerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Pass_schedulerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Pass_schedulerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Pass_schedulerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Pass_schedulerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Pass_schedulerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Pass_schedulerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Pass_schedulerClass->setStatusBar(statusBar);

        retranslateUi(Pass_schedulerClass);

        QMetaObject::connectSlotsByName(Pass_schedulerClass);
    } // setupUi

    void retranslateUi(QMainWindow *Pass_schedulerClass)
    {
        Pass_schedulerClass->setWindowTitle(QApplication::translate("Pass_schedulerClass", "Pass_scheduler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Pass_schedulerClass: public Ui_Pass_schedulerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASS_SCHEDULER_H
