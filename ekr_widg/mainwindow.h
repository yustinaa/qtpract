#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "comp.h"
#include "CompModel.h"
#include "BagModel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    COMP<Comp> *M1, *M2, *M3;
    COMP<Bag> *B1, *B2, *B3;
    compModel *modelM1, *modelM2, *modelM3;
    bagModel *modelB1, *modelB2, *modelB3;
};
#endif // MAINWINDOW_H
