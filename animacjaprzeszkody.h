#ifndef ANIMACJAPRZESZKODY_H
#define ANIMACJAPRZESZKODY_H

/*!
* \file
* \brief Definicja klasy AnimacjaPrzeszkody
*
* Plik zawiera definicję klasy AnimacjaPrzeszkody, która
* jest klasą pochodną klas QObject oraz QGraphicsItem
*/

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QObject>
#include <QDebug>
#include <QTimer>


/*!
* \brief Implementuje animację przeszkód
*
* Klasa odpowiada za wyświetlenie pożądanych animacji przeszkód,
* np. podczas zniszczenia.
*/
class AnimacjaPrzeszkody : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    QGraphicsPixmapItem *pixmapItem;

    /*!
    * \brief Konstruktor klasy AnimacjaPrzeszkody
    *
    * Inicjalizuje animację na zadanej scenie, w zadanym położeniu i
    * dla przeszkody o danym typie.
    * \param[in] *s - wskaźnik na scenę, na której ma pojawić się animacja.
    * \param[in] x - współrzędna X pozycji animacji. Jednostką jest piksel.
    * \param[in] y - współrzędna Y pozycji animacji. Jednostką jest piksel.
    * \param[in] typ - typ przeszkody dla której ma zostać stworzona animacja.
    */
    AnimacjaPrzeszkody(QGraphicsScene *s, int x, int y, int typ);

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

private:
    /*!
    * \brief Wskaźnik na scenę
    *
    * Pole zawiera wskaźnik na scenę, na której
    * wyświetlona ma zostać animacja.
    */
    QGraphicsScene *scena;

    /*!
    * \brief Współrzędna X pozycji animacji.
    *
    * Pole zawiera współrzędną X pozycji animacji.
    * Jednostką jest piksel.
    */
    int posX;

    /*!
    * \brief Współrzędna Y pozycji animacji.
    *
    * Pole zawiera współrzędną Y pozycji animacji.
    * Jednostką jest piksel.
    */
    int posY;

    /*!
    * \brief Typ stworzonej przeszkody.
    *
    * Pole zawiera typ stworzonej przeszkody.
    * Istnieją 4 typy wyglądu przeszkody.
    * Dzięki temu wiadomo jaką animację odtworzyć.
    */
    int typPrzeszkody;

    /*!
    * \brief Pixmapa (grafika) animacji.
    *
    * Pole przechowuje aktualnie wczytaną
    * grafikę animacji.
    */
    QPixmap pixmap;

    /*!
    * \brief Timer kolejnych klatek animacji.
    *
    * Pole przechowuje wskaźnik na timer,
    * który odtwarza kolejne klatki animacji.
    */
    QTimer *timerKlatek;

    /*!
    * \brief Numer aktualnej klatki.
    *
    * Pole zamiera numer aktualnie odtwarzanej klatki.
    * Inkrementacja powoduje wyświetlanie kolejnych klatek.
    */
    int klatka = 0;

private slots:
    /*!
    * \brief Slot odtwarzający kolejną klatkę.
    *
    * Funkcja sprawdza, która klatka była odegrana poprzednio
    * i na tej podstawie odtwarza kolejną klatkę ładując
    * odpowiednie grafiki animacji.
    */
    void kolejnaKlatka();

signals:
    /*!
    * \brief Sygnał usunięcia animacji.
    *
    * Sygnał wysyłany w momencie zakończenia animacji.
    * Mówi głównemu oknu gry, aby usunąć dany obiekt.
    */
    void usunAnimacje(AnimacjaPrzeszkody *anim);
};

#endif // ANIMACJAPRZESZKODY_H
