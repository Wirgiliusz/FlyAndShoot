#ifndef POCISK_H
#define POCISK_H

/*!
* \file
* \brief Definicja klasy Pocisk.
*
* Plik zawiera definicję klasy Pocisk, która
* odpowiada za obiekt pocisku.
*/

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QElapsedTimer>
#include <QPainter>
#include <QDebug>


/*!
* \brief Implementuje obiekt pocisku.
*
* Klasa odpowiada za obiekt pocisku.
*/
class Pocisk : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy Pocisk.
    *
    * Inicjalizuje pocisk na zadanej scenie, w zadanej pozycji.
    * \param[in] *s - wskaźnik na scenę, na której ma pojawić się pocisk.
    * \param[in] x - spółrzędna x pozycji pocisku. Jednostką jest piksel.
    * \param[in] y - spółrzędna y pozycji pocisku. Jednostką jest piksel.
    */
    Pocisk(QGraphicsScene *s, int x, int y);

    /*!
    * \brief Wskaźnik na obiekt grafiki.
    *
    * Pole zawiera wskaźnik na obiekt grafiki.
    * Pozwala na dodanie go do sceny i wyświetlenie.
    */
    QGraphicsPixmapItem *pixmapItem;

private: 
    /*!
    * \brief Wskaźnik na scenę.
    *
    * Pole zawiera wskaźnik na scenę, na której
    * wyświetlony ma zostać pocisk.
    */
    QGraphicsScene *scena;

    /*!
    * \brief Współrzędna X pocisku.
    *
    * Pole zawiera współrzędną X pozycji pocisku.
    * Jednostką jest piksel.
    */
    int posX;

    /*!
    * \brief Współrzędna Y pocisku.
    *
    * Pole zawiera współrzędną Y pozycji pocisku.
    * Jednostką jest piksel.
    */
    int posY;

    /*!
    * \brief Prędkość pocisku.
    *
    * Pole zawiera prędkość pocisku.
    * Jednostką jest piksel*fps.
    */
    int predkosc;

    /*!
    * \brief Pixmapa (grafika) pocisku.
    *
    * Pole przechowuje grafikę pocisku.
    */
    QPixmap pixmap;

    /*!
    * \brief Zmienna mówiąca o żywotności.
    *
    * Pole mówi o tym, czy obiekt powinien
    * zostać usunięty.
    */
    bool doUsuniecia = false;

protected slots:
    /*!
    * \brief Slot aktualizujący pozycję na scenie.
    *
    * Funkcja aktualizuje obiekt na scenie,
    * na której się znajduje.
    * \param[in] step - krok aktualizacji.
    */
    void advance(int step) override;

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

signals:
    /*!
    * \brief Sygnał usuwający pocisk.
    *
    * Sygnał wysyłany w momencie kolizji.
    * Wysyła głównemu oknu gry informację
    * o zniszczeniu pocisku.
    * \param[in] *p - wskaźnik na pocisk.
    */
    void usunPocisk(Pocisk *p);
};

#endif // POCISK_H
