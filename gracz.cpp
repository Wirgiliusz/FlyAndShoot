/*!
* \file
* \brief Implementacja metod klasy Gracz.
*
* Plik zawiera implementację metod klasy
* Gracz.
*/

#include "gracz.h"


Gracz::Gracz(QGraphicsScene *s)
{
    // Nadanie wartosci poczatkowych
    scena = s;
    posX = 400 - 25;
    posY = 650;
    speed = 10;
    predkoscX = 0;
    predkoscY = 0;

    // Zaladowanie i dodanie obrazka gracza
    pixmapItem = new QGraphicsPixmapItem();

    if(pixmap.load(":/images/player3-1.png") && pixmap2.load(":/images/player3-2.png")
        && pixmap_zniszczony1.load(":/images/player3-1_uszkodzenie1.png") && pixmap2_zniszczony1.load(":/images/player3-2_uszkodzenie1.png")
        && pixmap_zniszczony2.load(":/images/player3-1_uszkodzenie2.png") && pixmap2_zniszczony2.load(":/images/player3-2_uszkodzenie2.png")) {

        pixmapItem->setPixmap(pixmap);
        pixmapItem->setPos(posX, posY);
        scena->addItem(pixmapItem);
    }
    else {
        qDebug() << "Nie wczytano pixmapy gracza";
    }

    // Stworzenie timera reguljacego czas pomiedzy kolizjami
    czasOdKolizji = new QElapsedTimer();
    czasOdKolizji->start();
}

void Gracz::setRuch(enum Kierunki kierunek, bool stan)
{
    switch(kierunek) {
        case gora:
            ruchGora = stan;
        break;
        case prawo:
            ruchPrawo = stan;
        break;
        case dol:
            ruchDol = stan;
        break;
        case lewo:
            ruchLewo = stan;
        break;
    }
}

void Gracz::setPredkosc(int Vx, int Vy)
{
    predkoscX = -Vx;
    predkoscY = Vy;
}

void Gracz::advance(int step) {
    if(step == 0) {
        return;
    }
    else {
        if(klatka == 3) {
            switch(iloscZycia) {
            case 3:
                pixmapItem->setPixmap(pixmap);
            break;
            case 2:
                pixmapItem->setPixmap(pixmap_zniszczony1);
            break;
            case 1:
                pixmapItem->setPixmap(pixmap_zniszczony2);
            break;
            }
        }
        else if(klatka == 6) {
            switch(iloscZycia) {
            case 3:
                pixmapItem->setPixmap(pixmap2);
            break;
            case 2:
                pixmapItem->setPixmap(pixmap2_zniszczony1);
            break;
            case 1:
                pixmapItem->setPixmap(pixmap2_zniszczony2);
            break;
            }
            klatka = 0;
        }
        klatka++;

        if(ruchGora) {
            posY = posY - speed;
        }
        if(ruchPrawo) {
            posX = posX + speed;
        }
        if(ruchDol) {
            posY = posY + speed;
        }
        if(ruchLewo) {
            posX = posX - speed;
        }
        posX = posX + predkoscY;
        posY = posY + predkoscX;

        if(posX <= 755) {
            pixmapItem->setX(posX);
        } else {
            posX = 755;
        }
        if(posX >= -25) {
            pixmapItem->setX(posX);
        } else {
            posX = -25;
        }

        if(posY <= 750) {
            pixmapItem->setY(posY);
        } else {
            posY = 750;
        }
        if(posY >= 100) {
            pixmapItem->setY(posY);
        } else {
            posY = 100;
        }

        // Sprawdzenie kolizji
        if(collidingItems().size() > 3 && czasOdKolizji->elapsed() > czasNiesmiertelnosci) {
            QString currentDateTime = QDateTime::currentDateTime().toString("hh:mm:ss");
            qDebug() << currentDateTime << "Kolizja!";
            iloscZycia--;
            zmniejszenieZycia(iloscZycia);
            pixmapItem->setOpacity(0.5);
            czasOdKolizji->restart();
        }

        if(czasOdKolizji->elapsed() > czasNiesmiertelnosci) {
            pixmapItem->setOpacity(1);
        }
    }
}

// Reimplementacja funkcji wirtualnych klasy QGraphicsItem
QRectF Gracz::boundingRect() const { return QRectF(posX, posY, pixmap.width(), pixmap.height()); }
void Gracz::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter = nullptr; option = nullptr; widget = nullptr;
}
