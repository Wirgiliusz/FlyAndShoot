#include "przeszkoda.h"
#include "oknogry.h"


Przeszkoda::Przeszkoda(QGraphicsScene *s, int _x, int _v)
{
    // Ustawienie wartosci poczatkowych
    scena = s;
    posX = _x;
    posY = -100;
    speed = _v;
    move = 150;

    // Wczytanie i zaladowanie obrazka przeszkody
    pixmapItem = new QGraphicsPixmapItem();
    if(pixmap.load(":/images/przeszkoda1.png")) {
        pixmapItem->setPixmap(pixmap);
        pixmapItem->setPos(posX, posY);
        scena->addItem(pixmapItem);
    }
    else {
        qDebug() << "Nie wczytano pixmapy przeszkody";
    }

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
            usunPrzeszkode(this);
        }
        if(collidingItems().size() > 1) {
            doUsuniecia = true;
        }
        if(posY > 800) {
            usunPrzeszkode(this);
            //posY = -100;
            //posX = posX + move;
        }
        if(posX > 800) {
            posX = 0;
        }
        posY = posY + speed;
        pixmapItem->setPos(posX, posY);
    }
}
