#ifndef PRZESZKODA_H
#define PRZESZKODA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QObject>
#include <QDebug>


class Przeszkoda : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    QGraphicsScene *scena;
    int posX;
    int posY;
    int speed;
    int move;
    QPixmap pixmap;
    bool doUsuniecia = false;


protected slots:
    void advance(int step) override;

signals:
    void usunPrzeszkode(Przeszkoda *p, bool trafiona);

public:
    Przeszkoda(QGraphicsScene *s, int _x, int _v);
    QGraphicsPixmapItem *pixmapItem;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override ;
};

#endif // PRZESZKODA_H
