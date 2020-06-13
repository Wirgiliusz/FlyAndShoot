#ifndef OKNOPRZEGRANEJ_H
#define OKNOPRZEGRANEJ_H

/*!
* \file
* \brief Definicja klasy OknoPrzegranej.
*
* Plik zawiera definicję klasy OknoPrzegranej,
* która odpowiada za okno zakończenia gry.
*/

#include <QDialog>

namespace Ui {
class OknoPrzegranej;
}

/*!
* \brief Implementacja obiektu okna przegranej.
*
* Klasa odpowieda za obiekt okna końca gry.
*/
class OknoPrzegranej : public QDialog {
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy OknoPrzegranej.
    *
    * Inicjalizuje okno przegranej.
    * \param[in] *parent - wskaźnik na rodzica.
    * \param[in] punkty - ilość uzyskanych punktów podczas gry.
    */
    explicit OknoPrzegranej(QWidget *parent = nullptr, int punkty = 0);

    /*!
    * \brief Destruktor klasy OknoPrzegranej.
    *
    * Usuwa okno przegranej.
    */
    ~OknoPrzegranej();

private:
    /*!
    * \brief Wskaźnik na ui.
    *
    * Pole zawiera wskaźnik na ui,
    * na którym umieszczone są widgety.
    */
    Ui::OknoPrzegranej *ui;

private slots:
    /*!
    * \brief Slot obsłgujący przycisk zagraj ponownie.
    *
    * Funkcja obsługuje naciśnięcie przycisku
    * zagraj ponownie. Restartuje grę.
    */
    void on_pushButtonZagrajPonownie_clicked();

signals:
    /*!
    * \brief Sygnał restartu gry..
    *
    * Wysyła sygnał, który mówi oknu gry,
    * aby zrestartować grę.
    */
    void restartGry();
};



#endif // OKNOPRZEGRANEJ_H
