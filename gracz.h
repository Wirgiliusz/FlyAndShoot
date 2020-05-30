#ifndef GRACZ_H
#define GRACZ_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QElapsedTimer>
#include <QDebug>
#include <QPainter>
#include <QDateTime>
#include <QObject>


class Gracz : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    QGraphicsScene *scena;
    int posX;
    int posY;
    int speed;
    int predkoscX;
    int predkoscY;
    bool ruchGora = false;
    bool ruchPrawo = false;
    bool ruchDol = false;
    bool ruchLewo = false;
    int iloscZycia = 3;


    QGraphicsPixmapItem *pixmapItem;

    QElapsedTimer *czasOdKolizji;
    int czasNiesmiertelnosci = 1500;

public:
    Gracz(QGraphicsScene *s);
    enum Kierunki {gora, lewo, dol, prawo} kierunek;
    void setRuch(enum Kierunki kierunek, bool stan);
    void setPredkosc(int Vx, int Vy);
    int getPosX() {return posX;}
    int getPosY() {return posY;}
    QPixmap pixmap;
    bool wlasnieStrzelil = false;

signals:
    void zmniejszenieZycia(int atualneZycie);

protected slots:
    void advance(int step) override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override ;
};

#endif // GRACZ_H
