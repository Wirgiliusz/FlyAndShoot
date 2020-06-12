#include "pocisk.h"

Pocisk::Pocisk(QGraphicsScene *s, int x, int y)
{
    scena = s;
    predkosc = 15;
    posX = x;
    posY = y;

    // Zaladowanie i dodanie obrazka pocisku
    pixmapItem = new QGraphicsPixmapItem();

    if(pixmap.load(":/images/pocisk.png")) {
        pixmapItem->setPixmap(pixmap);
        pixmapItem->setPos(posX, posY);
        scena->addItem(pixmapItem);
    }
    else {
        qDebug() << "Nie wczytano pixmapy pocisku";
    }

}

QRectF Pocisk::boundingRect() const { return QRectF(posX, posY, pixmap.width(), pixmap.height()); }
void Pocisk::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter = nullptr; option = nullptr; widget = nullptr;
}

// Funkcja uaktualniajaca pozycje gracza
void Pocisk::advance(int step) {
    if(step == 0) {
        return;
    }
    else {
        if(doUsuniecia) {
            usunPocisk(this);
        }
        if(collidingItems().size() > 3) {
            doUsuniecia = true;
        }
        if(posY < -800) {
            usunPocisk(this);
        }

        posY = posY - predkosc;
        pixmapItem->setPos(posX, posY);
    }
}
