#ifndef ANIMACJAPRZESZKODY_H
#define ANIMACJAPRZESZKODY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QObject>
#include <QDebug>
#include <QTimer>

class AnimacjaPrzeszkody : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    AnimacjaPrzeszkody(QGraphicsScene *s, int x, int y, int typ);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override ;
    QGraphicsPixmapItem *pixmapItem;

private:
    QGraphicsScene *scena;
    int posX;
    int posY;
    int typPrzeszkody;
    QPixmap pixmap;
    QTimer *timerKlatek;
    int klatka = 0;

private slots:
    void kolejnaKlatka();

signals:
    void usunAnimacje(AnimacjaPrzeszkody *anim);
};

#endif // ANIMACJAPRZESZKODY_H
