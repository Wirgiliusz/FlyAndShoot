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

    if(pixmap.load(":/images/player.png")) {
        pixmapItem->setPixmap(pixmap);
        pixmapItem->setPos(posX, posY);
        scena->addItem(pixmapItem);
    }
    else {
        qDebug() << "Nie wczytano pixmapy przeszkody";
    }

    // Stworzenie timera reguljacego czas pomiedzy kolizjami
    czasOdKolizji = new QElapsedTimer();
    czasOdKolizji->start();
}

// Reimplementacja funkcji wirtualnych klasy QGraphicsItem
QRectF Gracz::boundingRect() const { return QRectF(posX, posY, pixmap.width(), pixmap.height()); }
void Gracz::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter = nullptr; option = nullptr; widget = nullptr;
}

// Ustawienie ruchu gracza w zaleznosci od wcisnietego kierunku
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

// Funkcja uaktualniajaca pozycje gracza
void Gracz::advance(int step) {
    if(step == 0) {
        return;
    }
    else {
        /* Do strzalek
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
        */
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
        //pixmapItem->setPos(posX, posY);

        // Sprawdzenie kolizji
        if(collidingItems().size() > 1 && czasOdKolizji->elapsed() > czasNiesmiertelnosci) {
            QString currentDateTime = QDateTime::currentDateTime().toString("hh:mm:ss");
            qDebug() << currentDateTime << "Kolizja!";
            pixmapItem->setOpacity(0.5);
            czasOdKolizji->restart();
        }

        if(czasOdKolizji->elapsed() > czasNiesmiertelnosci) {
            pixmapItem->setOpacity(1);
        }
    }
}
