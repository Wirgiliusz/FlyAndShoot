#ifndef TLO_H
#define TLO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QElapsedTimer>
#include <QDebug>
#include <QPainter>
#include <QDateTime>
#include <QObject>


class Tlo : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    QGraphicsScene *scena;
    int posX;
    int posY;
    float predkosc;

public:
    Tlo(QGraphicsScene *s, int y);
    QPixmap pixmap;
    QGraphicsPixmapItem *pixmapItem;

protected slots:
    void advance(int step) override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override ;
};

#endif // TLO_H
