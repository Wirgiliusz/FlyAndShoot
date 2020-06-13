#ifndef GRACZ_H
#define GRACZ_H

/*!
* \file
* \brief Definicja klasy Gracz.
*
* Plik zawiera definicję klasy Gracz, która
* odpowiada za obiekt gracza.
*/

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QElapsedTimer>
#include <QDebug>
#include <QPainter>
#include <QDateTime>
#include <QObject>


/*!
* \brief Implementuje obiekt gracza.
*
* Klasa odpowiada za obiekt gracza.
*/
class Gracz : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy Gracz.
    *
    * Inicjalizuje gracza na zadanej scenie.
    * \param[in] *s - wskaźnik na scenę, na której ma pojawić się gracz.
    */
    Gracz(QGraphicsScene *s);

    /*!
    * \brief Rodzaj ruchu, który ma wykonać gracz.
    *
    * Wartość tego typu służy do poruszania graczem,
    * przy pomocy strzałek.
    */
    enum Kierunki {
        gora,   /*! Ruch w górę */
        lewo,   /*! Ruch w lewo */
        dol,    /*! Ruch w dół */
        prawo   /*! Ruch w prawo */
    } kierunek;

    /*!
    * \brief Ustawia ruch gracza.
    *
    * Ustawia ruch gracza w zadanym kierunku.
    * Może go rozpocząć lub zakończyć.
    * \param[in] kierunek - kierunek którego dotyczy wywołanie.
    * \param[in] stan - jaki stan ma przyjąć ruch w danym kierunku.
    */
    void setRuch(enum Kierunki kierunek, bool stan);

    /*!
    * \brief Ustawia predkosc gracza.
    *
    * Ustawia predkosc gracza
    * w zadanych osiach.
    * \param[in] Vx - predkosc w osi OX. Jednostką jest piksel*fps.
    * \param[in] Vy  - predkosc w osi OY. Jednostką jest piksel*fps.
    */
    void setPredkosc(int Vx, int Vy);

    /*!
    * \brief Zwraca pozycje gracz w osi OX.
    *
    * Zwraca pozycję gracza w osi OX.
    * \retval posX - wpółrzędna pozycji w osi X. Jednostką jest piksel.
    */
    int getPosX() {return posX;}

    /*!
    * \brief Zwraca pozycje gracz w osi OY.
    *
    * Zwraca pozycję gracza w osi OY.
    * \retval posX - wpółrzędna pozycji w osi Y. Jednostką jest piksel.
    */
    int getPosY() {return posY;}

    /*!
    * \brief Inicjalizuje prostokąt ograniczający.
    *
    * Inicjalizuje prostokąt ograniczający tworzony obiekt.
    * Jest nadpisaniem funkcji wirtualnej z klasy QGraphicsItem.
    * \retval QRectF - obiekt prostokąta Qt.
    */
    QRectF boundingRect() const override;

    /*!
    * \brief Rysuje obiekt na ekranie [nieużywana].
    *
    * Rysuje zadane kształty na ekranie.
    * Jest nadpisaniem funkcji wirtualnej z klasy QGraphicsItem.
    */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override ;

    /*!
    * \brief Pixmapa (grafika) numer 1 gracza.
    *
    * Pole przechowuje grafikę gracza
    * numer 1.
    */
    QPixmap pixmap;

    /*!
    * \brief Pixmapa (grafika) numer 2 gracza.
    *
    * Pole przechowuje grafikę gracza
    * numer 2.
    */
    QPixmap pixmap2;

    /*!
    * \brief Pixmapa (grafika) numer 1 uszkodzonego gracza.
    *
    * Pole przechowuje grafikę numer 1 gdy gracz
    * jest lekko uszkodzony.
    */
    QPixmap pixmap_zniszczony1;

    /*!
    * \brief Pixmapa (grafika) numer 2 uszkodzonego gracza.
    *
    * Pole przechowuje grafikę numer 2 gdy gracz
    * jest lekko uszkodzony.
    */
    QPixmap pixmap2_zniszczony1;

    /*!
    * \brief Pixmapa (grafika) numer 1 uszkodzonego gracza.
    *
    * Pole przechowuje grafikę numer 1 gdy gracz
    * jest mocno uszkodzony.
    */
    QPixmap pixmap_zniszczony2;

    /*!
    * \brief Pixmapa (grafika) numer 2 uszkodzonego gracza.
    *
    * Pole przechowuje grafikę numer 2 gdy gracz
    * jest mocno uszkodzony.
    */
    QPixmap pixmap2_zniszczony2;

    /*!
    * \brief Wskaźnik na obiekt grafiki.
    *
    * Pole zawiera wskaźnik na obiekt grafiki.
    * Pozwala na dodanie go do sceny i wyświetlenie.
    */
    QGraphicsPixmapItem *pixmapItem;

    /*!
    * \brief Zmienna mówiąca o stanie strzału.
    *
    * Pole mówi o tym, czy gracz właśnie oddał strzał
    * i zapobiega zbyt szybkiemu strzelaniu.
    */
    bool wlasnieStrzelil = false;

private:
    /*!
    * \brief Wskaźnik na scenę.
    *
    * Pole zawiera wskaźnik na scenę, na której
    * wyświetlony ma zostać gracz.
    */
    QGraphicsScene *scena;

    /*!
    * \brief Współrzędna X gracza.
    *
    * Pole zawiera współrzędną X pozycji gracza.
    * Jednostką jest piksel.
    */
    int posX;

    /*!
    * \brief Współrzędna Y gracza.
    *
    * Pole zawiera współrzędną Y pozycji gracza.
    * Jednostką jest piksel.
    */
    int posY;

    /*!
    * \brief Prędkość gracza.
    *
    * Pole zawiera prędkość gracza.
    * Jednostką jest piksel*fps.
    */
    int speed;

    /*!
    * \brief Prędkość gracza względem osi OY.
    *
    * Pole zawiera prędkość gracza względem osi OY.
    * Jednostką jest piksel*fps.
    */
    int predkoscX;

    /*!
    * \brief Prędkość gracza względem osi OX.
    *
    * Pole zawiera prędkość gracza względem osi OX.
    * Jednostką jest piksel*fps.
    */
    int predkoscY;

    /*!
    * \brief Określa czy zadany został ruch w górę.
    *
    * Pole zawiera informację o tym
    * czy gracz powinien poruszać się w górę.
    */
    bool ruchGora = false;

    /*!
    * \brief Określa czy zadany został ruch w prawo.
    *
    * Pole zawiera informację o tym
    * czy gracz powinien poruszać się w prawo.
    */
    bool ruchPrawo = false;

    /*!
    * \brief Określa czy zadany został ruch w dół.
    *
    * Pole zawiera informację o tym
    * czy gracz powinien poruszać się w dół.
    */
    bool ruchDol = false;

    /*!
    * \brief Określa czy zadany został ruch w lewo.
    *
    * Pole zawiera informację o tym
    * czy gracz powinien poruszać się w lewo.
    */
    bool ruchLewo = false;

    /*!
    * \brief Określa ilość żyć gracza.
    *
    * Pole zawiera informację o aktualnym
    * stanie życia gracza.
    */
    int iloscZycia = 3;

    /*!
    * \brief Określa aktualną klatkę animacji.
    *
    * Pole zawiera informację o aktualnej
    * klatce animacji gracza.
    * Istnieją 2 klatki animacji.
    */
    int klatka = 0;

    /*!
    * \brief Timer czasu pomiędzy obrażeniami.
    *
    * Pole przechowuje wskaźnik na timer,
    * który odlicza czas od ostaniego zderzenia.
    * Zapewnia moment nieśmiertelności po
    * otrzymaniu obrażeń.
    */
    QElapsedTimer *czasOdKolizji;

    /*!
    * \brief Ilość czasu nieśmiertelności.
    *
    * Pole przechowuje czas nieśmiertelności
    * po otrzymaniu obrażeń.
    * Jednostką są milisekundy.
    */
    int czasNiesmiertelnosci = 1500;

protected slots:
    /*!
    * \brief Slot aktualizujący pozycję na scenie.
    *
    * Funkcja aktualizuje obiekt na scenie,
    * na której się znajduje.
    * \param[in] step - krok aktualizacji.
    */
    void advance(int step) override;

signals:
    /*!
    * \brief Sygnał zmniejszenia życia.
    *
    * Sygnał wysyłany w momencie kolizji.
    * Wysyła głównemu oknu gry informację
    * o aktualnym stanie życia.
    * \param[in] aktualneZycie - aktualna ilość żyć.
    */
    void zmniejszenieZycia(int atualneZycie);
};

#endif // GRACZ_H
