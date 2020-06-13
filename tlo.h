#ifndef TLO_H
#define TLO_H

/*!
* \file
* \brief Definicja klasy Tlo.
*
* Plik zawiera definicję klasy Tlo, która
* odpowiada za obiekt tła.
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
* \brief Implementuje obiekt tła.
*
* Klasa odpowiada za obiekt tła.
*/
class Tlo : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy Tło.
    *
    * Inicjalizuje tło na zadanej scenie, w zadanej pozycji.
    * \param[in] *s - wskaźnik na scenę, na której ma pojawić się tło.
    * \param[in] y - spółrzędna y pozycji tła. Jednostką jest piksel.
    */
    Tlo(QGraphicsScene *s, int y);

    /*!
    * \brief Pixmapa (grafika) tła.
    *
    * Pole przechowuje grafikę tła.
    */
    QPixmap pixmap;

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
    * wyświetlony ma zostać tło.
    */
    QGraphicsScene *scena;

    /*!
    * \brief Współrzędna X tła.
    *
    * Pole zawiera współrzędną X pozycji tła.
    * Jednostką jest piksel.
    */
    int posX;

    /*!
    * \brief Współrzędna Y tła.
    *
    * Pole zawiera współrzędną Y pozycji tła.
    * Jednostką jest piksel.
    */
    int posY;

    /*!
    * \brief Prędkość przewijania tła.
    *
    * Pole zawiera prędkość przewijania tła.
    * Jednostką jest piksel*fps.
    */
    float predkosc;

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
};

#endif // TLO_H
