#include "figure.h"
#include <QPainter>
#include <QTimer>
#include <QRandomGenerator>
#include <QGraphicsScene>
Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    // стартовая координата для отрисовки фигуры
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    connect(this, &Figure::pointChanged, this, &Figure::updateRomb);
    m_velocity = QPointF(0, 0);
    m_animationTimer = new QTimer(this);
    connect(m_animationTimer, &QTimer::timeout, this, &Figure::updatePosition);
}

Figure::~Figure()
{}

QRectF Figure::boundingRect() const//область, в которой лежит фигура.
{
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateRomb()//обновление области, в которой лежит фигура
{
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}
void Figure::setColor(const QColor &color) {
    figureColor = color;
    update();
}

void Figure::setPenWidth(int width) {
    figurePenWidth = width;
    update();
}
QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}
QPointF Figure::velocity() const
{
    return m_velocity;
}

void Figure::setVelocity(const QPointF &velocity)
{
    m_velocity = velocity;
}

void Figure::startAnimation()
{
    if (!m_animationTimer->isActive()) {
        qreal speed = 7;
        qreal angle = 45;
        m_velocity = QPointF(speed * cos(angle), speed * sin(angle));
        m_animationTimer->start(15);
    }
}

void Figure::stopAnimation()
{
    m_animationTimer->stop();
}

void Figure::updatePosition()
{
    QPointF center = boundingRect().center() + pos();//текущие координаты центра фигуры

    // проверка столкновения с границами сцены
    QRectF sceneRect = scene()->sceneRect();
    if (center.x() <= sceneRect.left() || center.x() >= sceneRect.right()) {
        m_velocity.setX(-m_velocity.x()); // отскок по X
    }
    if (center.y() <= sceneRect.top() || center.y() >= sceneRect.bottom()) {
        m_velocity.setY(-m_velocity.y()); // отскок по Y
    }
    setPos(pos() + m_velocity);//новая позиция
}
