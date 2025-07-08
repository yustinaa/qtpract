#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Triangle : public Figure
{
    Q_OBJECT

public:
    explicit Triangle(QPointF point, QObject *parent = 0);
    ~Triangle();
    int type() const override { return TriangleType; }
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // TRIANGLE_H
