#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include "figure.h"

class paintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum FigureType {
        SquareType = 1,
        RombType,
        TriangleType,
        EllipseType,
        PenType
    };
public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки
    QColor drawingColor = Qt::black;
    int penWidth = 10;
    FigureType figureType = PenType;
    QPointF startPoint;
    Figure *tempFigure = nullptr;
private:
    //события мыши для рисования
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public:
    void setDrawingColor(const QColor &color);
    void setPenWidth(int width);
    void setTypeFigure(FigureType type);
    void saveToFile(const QString &fileName);
    void loadFromFile(const QString &fileName);
public slots:
    void startAllAnimations();
    void stopAllAnimations();

};
#endif // PAINTSCENE_H
