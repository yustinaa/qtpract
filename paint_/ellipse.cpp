#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Ellipse::~Ellipse()
{
}

// Реализуем метод отрисовки
void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(figureColor, figurePenWidth));

    // Рассчитываем прямоугольник, в который будет вписан эллипс
    QRectF ellipseRect;
    if (endPoint().x() > startPoint().x()) {
        ellipseRect.setLeft(startPoint().x());
        ellipseRect.setRight(endPoint().x());
    } else {
        ellipseRect.setLeft(endPoint().x());
        ellipseRect.setRight(startPoint().x());
    }

    if (endPoint().y() > startPoint().y()) {
        ellipseRect.setTop(startPoint().y());
        ellipseRect.setBottom(endPoint().y());
    } else {
        ellipseRect.setTop(endPoint().y());
        ellipseRect.setBottom(startPoint().y());
    }
    painter->drawEllipse(ellipseRect);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
