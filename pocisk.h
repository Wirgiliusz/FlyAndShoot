#ifndef POCISK_H
#define POCISK_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QElapsedTimer>
#include <QPainter>
#include <QDebug>


class Pocisk : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    QGraphicsScene *scena;
    int posX;
    int posY;
    int predkosc;

    QPixmap pixmap;
    bool doUsuniecia = false;


public:
    QGraphicsPixmapItem *pixmapItem;
    Pocisk(QGraphicsScene *s, int x, int y);

signals:
    void usunPocisk(Pocisk *p);

protected slots:
    void advance(int step) override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override ;
};

#endif // POCISK_H
