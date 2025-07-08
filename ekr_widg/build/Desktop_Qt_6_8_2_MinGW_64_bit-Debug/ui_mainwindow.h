/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QTableView *tableView_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTableView *tableView_3;
    QTableView *tableView_4;
    QTableView *tableView_5;
    QTableView *tableView_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1147, 833);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 251, 204);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(40, 320, 221, 192));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(40, 580, 221, 192));
        tableView_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 540, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 280, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 20, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(770, 530, 63, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(770, 270, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(770, 20, 63, 20));
        tableView_3 = new QTableView(centralwidget);
        tableView_3->setObjectName("tableView_3");
        tableView_3->setGeometry(QRect(40, 60, 221, 192));
        tableView_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableView_4 = new QTableView(centralwidget);
        tableView_4->setObjectName("tableView_4");
        tableView_4->setGeometry(QRect(740, 60, 231, 181));
        tableView_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableView_5 = new QTableView(centralwidget);
        tableView_5->setObjectName("tableView_5");
        tableView_5->setGeometry(QRect(740, 310, 231, 192));
        tableView_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableView_6 = new QTableView(centralwidget);
        tableView_6->setObjectName("tableView_6");
        tableView_6->setGeometry(QRect(740, 570, 231, 192));
        tableView_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(340, 100, 141, 91));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 205, 193);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(340, 350, 141, 101));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 205, 193);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(340, 610, 141, 101));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 205, 193);"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(520, 100, 141, 91));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 205, 193);"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(520, 610, 141, 101));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 205, 193);"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(520, 350, 141, 101));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 205, 193);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1147, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "C1 + C2", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "C2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "C1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "B1 + B2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "B2", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "B1", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Open C1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Open C2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "C1 + C2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Open B1", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "B1 + B2", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Open B2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
