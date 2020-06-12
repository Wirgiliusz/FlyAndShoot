#include "przeszkoda.h"
#include "oknogry.h"



Przeszkoda::Przeszkoda(QGraphicsScene *s, int _x, int _v, int typ)
{
    // Ustawienie wartosci poczatkowych
    scena = s;
    posX = _x;
    posY = -150;
    speed = _v;
    move = 150;
    typPrzeszkody = typ;

    // Wczytanie i zaladowanie obrazka przeszkody
    pixmapItem = new QGraphicsPixmapItem();

    switch(typ) {
    case 1:
        pixmap.load(":/images/przeszkoda1.png");
    break;
    case 2:
        pixmap.load(":/images/przeszkoda2.png");
    break;
    case 3:
        pixmap.load(":/images/przeszkoda3.png");
    break;
    case 4:
        pixmap.load(":/images/przeszkoda4.png");
    break;
    }
    pixmapItem->setPixmap(pixmap);
    pixmapItem->setPos(posX, posY);
    scena->addItem(pixmapItem);


}

// Reimplementacja funkcji wirtualnych klasy QGraphicsItem
QRectF Przeszkoda::boundingRect() const {
    return QRectF(posX, posY, pixmap.width(), pixmap.height());
}

void Przeszkoda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter = nullptr; option = nullptr; widget = nullptr;
}

// Funkcja uaktualniajaca pozycje przeszkody
void Przeszkoda::advance(int step) {
    if(step == 0) {
        return;
    }
    else {
        if(doUsuniecia) {
            usunPrzeszkode(this, true);
        }
        if(collidingItems().size() > 3) {
            doUsuniecia = true;
        }
        if(posY > 800) {
            usunPrzeszkode(this, false);
        }
        if(posX > 800) {
            posX = 0;
        }
        posY = posY + speed;
        pixmapItem->setPos(posX, posY);
    }
}
