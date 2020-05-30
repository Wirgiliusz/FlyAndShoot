#include "animacjaprzeszkody.h"

AnimacjaPrzeszkody::AnimacjaPrzeszkody(QGraphicsScene *s, int x, int y, int typ)
{
    scena = s;
    posX = x;
    posY = y;
    typPrzeszkody = typ;

    pixmapItem = new QGraphicsPixmapItem();

    switch(typPrzeszkody) {
    case 1:
        pixmap.load(":/images/przeszkoda1_zniszczenie1.png");
    break;
    case 2:
        //pixmap.load(":/images/przeszkoda2.png");
    break;
    case 3:
        //pixmap.load(":/images/przeszkoda3.png");
    break;
    case 4:
        //pixmap.load(":/images/przeszkoda4.png");
    break;
    }
    pixmapItem->setPixmap(pixmap);
    pixmapItem->setPos(posX, posY);
    scena->addItem(pixmapItem);

    timerKlatek = new QTimer(this);
    connect(timerKlatek, SIGNAL(timeout()), this, SLOT(kolejnaKlatka()));
    timerKlatek->start(50);

    klatka++;
}

void AnimacjaPrzeszkody::kolejnaKlatka()
{
    if(typPrzeszkody == 1) {
        switch(klatka) {
            case 1:
                pixmap.load(":/images/przeszkoda1_zniszczenie2.png");
            break;
            case 2:
                pixmap.load(":/images/przeszkoda1_zniszczenie3.png");
            break;
            case 3:
                pixmap.load(":/images/przeszkoda1_zniszczenie4.png");
            break;
            case 4:
                pixmap.load(":/images/przeszkoda1_zniszczenie5.png");
            break;
            case 5:
                usunAnimacje(this);
            break;
        }
    }

    pixmapItem->setPixmap(pixmap);
    klatka++;
}

// Reimplementacja funkcji wirtualnych klasy QGraphicsItem
QRectF AnimacjaPrzeszkody::boundingRect() const {
    return QRectF(0,0,0,0);
}

void AnimacjaPrzeszkody::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter = nullptr; option = nullptr; widget = nullptr;
}

