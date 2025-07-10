#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "ellipse.h"
#include <QFile>
#include <QTextStream>
paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
    {}
paintScene::~paintScene()
    {}
void paintScene::setDrawingColor(const QColor &color) { drawingColor = color; }
void paintScene::setPenWidth(int width) { penWidth = width; }
void paintScene::setTypeFigure(FigureType type) {figureType = type;}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
    startPoint = event->scenePos();

    if (figureType == PenType) {
        addEllipse(event->scenePos().x() - penWidth/2,
                   event->scenePos().y() - penWidth/2,
                   penWidth, penWidth,
                   QPen(Qt::NoPen), QBrush(drawingColor));
    } else {
        switch (figureType) {
        case SquareType:
            tempFigure = new Square(event->scenePos());
            break;
        case TriangleType:
            tempFigure = new Triangle(event->scenePos());
            break;
        case RombType:
            tempFigure = new Romb(event->scenePos());
            break;
        case EllipseType:
            tempFigure = new Ellipse(event->scenePos());
            break;
        default:
            break;
        }
        if (tempFigure) {
            tempFigure->setColor(drawingColor);
            tempFigure->setPenWidth(penWidth);
            addItem(tempFigure);
        }
    }

    previousPoint = event->scenePos();	}
void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        if (figureType == PenType) {
            addLine(previousPoint.x(), previousPoint.y(),
                    event->scenePos().x(), event->scenePos().y(),
                    QPen(drawingColor, penWidth, Qt::SolidLine, Qt::RoundCap));
        } else if (tempFigure) {
            tempFigure->setEndPoint(event->scenePos());
        }

        previousPoint = event->scenePos();
        update();
    }
    void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
    {
        if (tempFigure) {
            tempFigure->setEndPoint(event->scenePos());
            tempFigure = nullptr;
        }
        QGraphicsScene::mouseReleaseEvent(event);
    }
void paintScene::saveToFile(const QString &fileName)
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);

        foreach(QGraphicsItem *item, items()) {
            if (Figure *figure = dynamic_cast<Figure*>(item)) {
                out << figure->startPoint().x() << " "
                    << figure->startPoint().y() << " "
                    << figure->endPoint().x() << " "
                    << figure->endPoint().y() << " "
                    << figure->type() << " "
                    << figure->color().name() << " "
                    << figure->penWidth() << "\n";
            }
        }

        file.close();
    }
void paintScene::loadFromFile(const QString &fileName)
    {
        clear();

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(" ");

            if (parts.size() < 7) continue;

            QPointF startPoint(parts[0].toDouble(), parts[1].toDouble());
            QPointF endPoint(parts[2].toDouble(), parts[3].toDouble());
            int type = parts[4].toInt();
            QColor color(parts[5]);
            int penWidth = parts[6].toInt();

            Figure *figure = nullptr;
            switch (type) {
            case SquareType:
                figure = new Square(startPoint);
                break;
            case TriangleType:
                figure = new Triangle(startPoint);
                break;
            case RombType:
                figure = new Romb(startPoint);
                break;
            case EllipseType:
                figure = new Ellipse(startPoint);
                break;
            default:
                continue;
            }

            if (figure) {
                figure->setEndPoint(endPoint);
                figure->setColor(color);
                figure->setPenWidth(penWidth);
                addItem(figure);
            }
        }

        file.close();
    }
    void paintScene::startAllAnimations()
    {
        for (QGraphicsItem* item : items()) {
            if (Figure* figure = dynamic_cast<Figure*>(item)) {
                figure->startAnimation();
            }
        }
    }

    void paintScene::stopAllAnimations()
    {
        for (QGraphicsItem* item : items()) {
            if (Figure* figure = dynamic_cast<Figure*>(item)) {
                figure->stopAnimation();
            }
        }
    }
