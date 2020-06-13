#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
* \file
* \brief Definicja klasy MainWindow
*
* Plik zawiera definicję klasy MainWindow,
* która odpowiada za okno główne apliakcji.
*/

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include "oknopolaczenia.h"
#include "oknogry.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
* \brief Implementacja obiektu głównego okna.
*
* Klasa odpowieda za obiekt okna głównego.
*/
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy MainWindow
    *
    * Inicjalizuje okno główne.
    * \param[in] *parent - wskaźnik na rodzica.
    */
    MainWindow(QWidget *parent = nullptr);

    /*!
    * \brief Destruktor klasy MainWindow
    *
    * Usuwa okno główne.
    */
    ~MainWindow();

private:
    /*!
    * \brief Wskaźnik ui.
    *
    * Pole zawiera wskaźnik na ui,
    * na którym umieszczone są widgety.
    */
    Ui::MainWindow *ui;

    /*!
    * \brief Wskaźnik na okno połączenia.
    *
    * Pole zawiera wskaźnik na okno połączenia,
    * które odpowiada za łączenie z akcelerometrem.
    */
    OknoPolaczenia *oknoPolaczenia;

    /*!
    * \brief Wskaźnik na okno gry.
    *
    * Pole zawiera wskaźnik na okno gry,
    * które odpowiada za wyświetlenie gry i wykresów.
    */
    OknoGry *oknoGry;

    /*!
    * \brief Zmienna mówiąca o stanie połączenia.
    *
    * Pole mówi o aktualnym stanie połączenia.
    */
    bool polaczono = false;

private slots:
    /*!
    * \brief Slot obsłgujący przycisk wyjścia.
    *
    * Funkcja obsługuje zamknięcie okna
    * po naciśniećiu przyciusku "Wyjście".
    */
    void on_pushButtonWyjscie_clicked();

    /*!
    * \brief Slot obsłgujący przycisk połączenia.
    *
    * Funkcja obsługuje otwarcie nowego okna
    * połączenia po naciśniećiu przyciusku "Połącz".
    */
    void on_pushButtonPolacz_clicked();

    /*!
    * \brief Slot obsłgujący przycisk gry.
    *
    * Funkcja obsługuje otwarcie nowego okna
    * gry po naciśniećiu przyciusku "Graj".
    */
    void on_pushButtonGraj_clicked();

    /*!
    * \brief Slot obsługujący zmianę stanu połączenia.
    *
    * Funkcja obsługuje zmianę stanu połączenia.
    * Ustawia zmienną na odpowiedni stan.
    * \param[in] stan - aktualny stan połączenia
    */
    void ustawStanPolaczenia(bool stan);
};
#endif // MAINWINDOW_H
