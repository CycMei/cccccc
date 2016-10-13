/********************************************************************************
** Form generated from reading UI file 'qtone.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTONE_H
#define UI_QTONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtOneClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtOneClass)
    {
        if (QtOneClass->objectName().isEmpty())
            QtOneClass->setObjectName(QStringLiteral("QtOneClass"));
        QtOneClass->resize(600, 400);
        menuBar = new QMenuBar(QtOneClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtOneClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtOneClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtOneClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtOneClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtOneClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtOneClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtOneClass->setStatusBar(statusBar);

        retranslateUi(QtOneClass);

        QMetaObject::connectSlotsByName(QtOneClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtOneClass)
    {
        QtOneClass->setWindowTitle(QApplication::translate("QtOneClass", "QtOne", 0));
    } // retranslateUi

};

namespace Ui {
    class QtOneClass: public Ui_QtOneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTONE_H
