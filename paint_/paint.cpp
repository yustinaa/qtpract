#include "paint.h"
#include "ui_paint.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QColor>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new paintScene();       // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену
    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);
    QMenu *colorr;
    colorr = menuBar()->addMenu("&Change shape");
    QAction *Line = new QAction("&Line", this);
    colorr->addAction(Line);
    connect(Line, &QAction::triggered, this, [this]() {
        scene->setTypeFigure(paintScene::PenType);
    });
    QAction *Ellipse = new QAction("&Ellipse", this);
    colorr->addAction(Ellipse);
    connect(Ellipse, &QAction::triggered, this, [this]() {
        scene->setTypeFigure(paintScene::EllipseType);
    });
    QAction *Square = new QAction("&Square", this);
    colorr->addAction(Square);
    connect(Square, &QAction::triggered, this, [this]() {
        scene->setTypeFigure(paintScene::SquareType);
    });
    QAction *Triangle = new QAction("&Triangle", this);
    colorr->addAction(Triangle);
    connect(Triangle, &QAction::triggered, this, [this]() {
        scene->setTypeFigure(paintScene::TriangleType);
    });
    QAction *Romb = new QAction("&Romb", this);
    colorr->addAction(Romb);
    connect(Romb, &QAction::triggered, this, [this]() {
        scene->setTypeFigure(paintScene::RombType);
    });
    colorr = menuBar()->addMenu("&Change color");
    QAction *red = new QAction("&red", this);
    colorr->addAction(red);
    connect(red, &QAction::triggered, this, [this]() {
            scene->setDrawingColor(Qt::red);
    });
    QAction *yellow = new QAction("&yellow", this);
    colorr->addAction(yellow);
    connect(yellow, &QAction::triggered, this, [this]() {
        scene->setDrawingColor(Qt::yellow);
    });
    QAction *blue = new QAction("&blue", this);
    colorr->addAction(blue);
    connect(blue, &QAction::triggered, this, [this]() {
        scene->setDrawingColor(Qt::blue);
    });
    QAction *chooseColor = new QAction("I want other color", this);
    colorr->addAction(chooseColor);
    connect(chooseColor, &QAction::triggered, this, [this]() {
        QColor color = QColorDialog::getColor(Qt::black, this, "Other color");
        if (color.isValid()) {
            scene->setDrawingColor(color);
        }
    });
    QMenu *pen_width = menuBar()->addMenu("Change width");
    QAction *widthAction = new QAction("Thin", this);
    pen_width->addAction(widthAction);
    connect(widthAction, &QAction::triggered, this, [this]() {
        scene->setPenWidth(4);
    });
    QAction *widthAction1 = new QAction("Medium", this);
    pen_width->addAction(widthAction1);
    connect(widthAction1, &QAction::triggered, this, [this]() {
        scene->setPenWidth(10);
    });
    QAction *widthAction2 = new QAction("Large", this);
    pen_width->addAction(widthAction2);
    connect(widthAction2, &QAction::triggered, this, [this]() {
        scene->setPenWidth(20);
    });
    QMenu *menu = menuBar()->addMenu("Tools");
    QAction *clearAction = new QAction("Clear", this);
    menu->addAction(clearAction);

    connect(clearAction, &QAction::triggered, this, [this]() {
        scene->clear();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}


void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Сохранить рисунок", "", "Текстовые файлы (*.txt)");
    if (!fileName.isEmpty()) {
        scene->saveToFile(fileName);
}
}


void MainWindow::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Открыть рисунок", "", "Текстовые файлы (*.txt)");
    if (!fileName.isEmpty()) {
        scene->loadFromFile(fileName);
    }
}


void MainWindow::on_startAnimation_clicked()
{
    scene->startAllAnimations();
}


void MainWindow::on_stopAnimatio_clicked()
{
    scene->stopAllAnimations();
}

