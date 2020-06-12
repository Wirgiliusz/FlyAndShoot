#include "tlo.h"

Tlo::Tlo(QGraphicsScene *s, int y)
{
    // Nadanie wartosci poczatkowych
    scena = s;
    posX = 0;
    posY = y;
    predkosc = 1;

    // Zaladowanie i dodanie obrazka gracza
    pixmapItem = new QGraphicsPixmapItem();

    if(pixmap.load(":/images/tlo2.png")) {
        pixmapItem->setPixmap(pixmap);
        pixmapItem->setPos(posX, posY);
        scena->addItem(pixmapItem);
    }
    else {
        qDebug() << "Nie wczytano pixmapy przeszkody";
    }
}

// Reimplementacja funkcji wirtualnych klasy QGraphicsItem
QRectF Tlo::boundingRect() const { return QRectF(posX, posY, pixmap.width(), pixmap.height()); }
void Tlo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter = nullptr; option = nullptr; widget = nullptr;
}

// Funkcja uaktualniajaca pozycje tla
void Tlo::advance(int step) {
    if(step == 0) {
        return;
    }
    else {
        posY += predkosc;
        pixmapItem->setY(posY);
        if(posY >= 0) {
            posY = -1000;
        }
    }
}
