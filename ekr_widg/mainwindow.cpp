#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), M1(new COMP<Comp>()), M2(new COMP<Comp>()),
    M3(new COMP<Comp>()),B1(new COMP<Bag>()), B2(new COMP<Bag>()),
    B3(new COMP<Bag>()), modelM1(new compModel()), modelM2(new compModel()),
    modelM3(new compModel()), modelB1(new bagModel()), modelB2(new bagModel()),
    modelB3(new bagModel())



{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete M1;
    delete M2;
    delete B1;
    delete B2;
}

void MainWindow::on_pushButton_clicked()//open C1
{
    QFile file("comp.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        in >> *M1;
        file.close();}

    modelM1->setComps(M1);
    ui->tableView_3->setModel(modelM1);
    ui->tableView_3->resizeColumnsToContents();//меняем размеры таблички
}


void MainWindow::on_pushButton_2_clicked()
{
    QFile file("comp2.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        in >> *M2;
        file.close();}

    modelM2->setComps(M2);
    ui->tableView->setModel(modelM2);
    ui->tableView->resizeColumnsToContents();
}


void MainWindow::on_pushButton_3_clicked()
{
    M3->clear();
    *M3=*M1+*M2;
    modelM3->setComps(M3);
    ui->tableView_2->setModel(modelM3);
    ui->tableView_2->resizeColumnsToContents();//меняем размеры таблички
}


void MainWindow::on_pushButton_4_clicked()
{
    QFile file("bag.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        in >> *B1;
        file.close();}

    modelB1->setBags(B1);
    ui->tableView_4->setModel(modelB1);
    ui->tableView_4->resizeColumnsToContents();//меняем размеры таблички
}


void MainWindow::on_pushButton_6_clicked()
{
    QFile file("bag2.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        in >> *B2;
        file.close();}

    modelB2->setBags(B2);
    ui->tableView_5->setModel(modelB2);
    ui->tableView_5->resizeColumnsToContents();//меняем размеры таблички
}


void MainWindow::on_pushButton_5_clicked()
{
    B3->clear();
    *B3=*B1+*B2;
    modelB3->setBags(B3);
    ui->tableView_6->setModel(modelB3);
    ui->tableView_6->resizeColumnsToContents();//меняем размеры таблички
}

