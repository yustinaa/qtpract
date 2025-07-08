#ifndef PAINT_H
#define PAINT_H
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <paintscene.h>
#include <QMainWindow>
#include <QColorDialog>

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

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    paintScene *scene;
private:
void resizeEvent(QResizeEvent * event);

private slots:
void slotTimer();
    void on_saveButton_clicked();
void on_openButton_clicked();
};
#endif // PAINT_H
