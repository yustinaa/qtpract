#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Ellipse : public Figure
{
    Q_OBJECT

public:
    explicit Ellipse(QPointF point, QObject *parent = 0);
    ~Ellipse();
int type() const override { return EllipseType; }
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // ELLIPSE_H
