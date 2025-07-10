#ifndef FIGURE_H
#define FIGURE_H
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
enum FigureTypes {
    SquareType = 1,
    RombType,
    TriangleType,
    EllipseType,
    PenType
};
class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    // Свойство стартовой точки, относительно которой отрисовываем фигуру
    Q_PROPERTY(QPointF startPoint
                   READ startPoint WRITE setStartPoint
                       NOTIFY pointChanged)
    // Свойство конечно точки, до куда отрисовываем фигуру
    Q_PROPERTY(QPointF endPoint
                   READ endPoint WRITE setEndPoint
                       NOTIFY pointChanged)
    Q_PROPERTY(QPointF velocity READ velocity WRITE setVelocity) // Скорость движения
    Q_INTERFACES(QGraphicsItem)
public:
    explicit Figure(QPointF point, QObject *parent = 0);
    ~Figure();

    QPointF startPoint() const; // Стартовая точка
    QPointF endPoint() const;   // Конечная точка

    void setStartPoint(const QPointF point);    // Установка стартовой точки
    void setEndPoint(const QPointF point);      // Установка конечной точки
    void setColor(const QColor &color);
    void setPenWidth(int width);
    virtual int type() const = 0; // чисто виртуальный метод
    QColor color() const { return figureColor; }
    int penWidth() const { return figurePenWidth; }
    QPointF velocity() const;
    void setVelocity(const QPointF &velocity);

    void startAnimation();
    void stopAnimation();
    void updatePosition();

protected:
    QColor figureColor = Qt::black;
    int figurePenWidth = 2;

signals:
    void pointChanged();    // Сигнал об изменении точки

private:
    QPointF m_startPoint;   // Стартовая точка
    QPointF m_endPoint;     // Конечная точка

    QRectF boundingRect() const;    // Область, в которой содержится фигура
    QPointF m_velocity; // Вектор скорости
    QTimer *m_animationTimer;


public slots:
    void updateRomb();     // Слот обновления области, в которой содержится фигура
};
#endif // FIGURE_H
