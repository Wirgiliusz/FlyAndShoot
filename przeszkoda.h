#ifndef PRZESZKODA_H
#define PRZESZKODA_H

/*!
* \file
* \brief Definicja klasy Przeszkoda.
*
* Plik zawiera definicję klasy Przeszkoda, która
* odpowiada za obiekt przeszkoy.
*/

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QObject>
#include <QDebug>


/*!
* \brief Implementuje obiekt przeszkody.
*
* Klasa odpowiada za obiekt przeszkody.
*/
class Przeszkoda : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy Przeszkoda.
    *
    * Inicjalizuje przeszkodę na zadanej scenie, w zadanej pozycji, o zadanej prędkości i o zadanym typie.
    * \param[in] *s - wskaźnik na scenę, na której ma pojawić się przeszkoda.
    * \param[in] _x - spółrzędna x pozycji przeszkody. Jednostką jest piksel.
    * \param[in] _v - prędkość przeszkody. Jednostką jest piksel*fps.
    * \param[in] typ - typ przeszkody.
    */
    Przeszkoda(QGraphicsScene *s, int _x, int _v, int typ);

    /*!
    * \brief Wskaźnik na obiekt grafiki.
    *
    * Pole zawiera wskaźnik na obiekt grafiki.
    * Pozwala na dodanie go do sceny i wyświetlenie.
    */
    QGraphicsPixmapItem *pixmapItem;

    /*!
    * \brief Zwraca pozycje przeszkody w osi OX.
    *
    * Zwraca przeszkody gracza w osi OX.
    * \retval posX - wpółrzędna pozycji w osi X. Jednostką jest piksel.
    */
    int getPosX() { return posX; }

    /*!
    * \brief Zwraca pozycje przeszkody w osi OY.
    *
    * Zwraca przeszkody gracza w osi OY.
    * \retval posX - wpółrzędna pozycji w osi Y. Jednostką jest piksel.
    */
    int getPosY() { return posY; }

    /*!
    * \brief Zwraca typ przeszkody.
    *
    * Zwraca typ przeszkody.
    * \retval typPrzeszkody - typ przeszkody.
    */
    int getTyp() { return typPrzeszkody; }

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
    * \brief Wskaźnik na scenę.
    *
    * Pole zawiera wskaźnik na scenę, na której
    * wyświetlona ma zostać przeszkoda.
    */
    QGraphicsScene *scena;

    /*!
    * \brief Współrzędna X przeszkody.
    *
    * Pole zawiera współrzędną X pozycji przeszkody.
    * Jednostką jest piksel.
    */
    int posX;

    /*!
    * \brief Współrzędna Y przeszkody.
    *
    * Pole zawiera współrzędną Y pozycji przeszkody.
    * Jednostką jest piksel.
    */
    int posY;

    /*!
    * \brief Prędkość przeszkody.
    *
    * Pole zawiera prędkość przeszkody.
    * Jednostką jest piksel*fps.
    */
    int speed;

    /*!
    * \brief Pixmapa (grafika) przeszkody.
    *
    * Pole przechowuje grafikę przeszkody.
    */
    QPixmap pixmap;

    /*!
    * \brief Zmienna mówiąca o żywotności.
    *
    * Pole mówi o tym, czy obiekt powinien
    * zostać usunięty.
    */
    bool doUsuniecia = false;

    /*!
    * \brief Typ przeszkody.
    *
    * Pole przechowuje typ przeszkody,
    * od którego zależy jej wygląd.
    */
    int typPrzeszkody;

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
    * \brief Sygnał usuwający przeszkodę.
    *
    * Sygnał wysyłany w momencie kolizji.
    * Wysyła głównemu oknu gry informację
    * o zniszczeniu przeszkody.
    * \param[in] *p - wskaźnik na przeskodę.
    * \param[in] trafiona - informację czy przeszkoda została trafiona.
    */
    void usunPrzeszkode(Przeszkoda *p, bool trafiona);
};

#endif // PRZESZKODA_H
