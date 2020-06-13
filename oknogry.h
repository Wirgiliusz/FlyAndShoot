#ifndef OKNOGRY_H
#define OKNOGRY_H

/*!
* \file
* \brief Definicja klasy MainWindow
*
* Plik zawiera definicję klasy MainWindow,
* która odpowiada za okno główne apliakcji.
*/

#include <QDialog>
#include <QStatusBar>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>
#include <QRandomGenerator>
#include <QVector>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QKeyEvent>
#include <QtCharts>
#include "przeszkoda.h"
#include "pocisk.h"
#include "gracz.h"
#include "oknoprzegranej.h"
#include "animacjaprzeszkody.h"
#include "tlo.h"


namespace Ui {
class OknoGry;
}

/*!
* \file
* \brief Implementacja obiektu okna gry.
*
* Klasa odpowieda za obiekt okna gry.
*/
class OknoGry : public QDialog {
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy OknoGry.
    *
    * Inicjalizuje okno gry.
    * \param[in] *parent - wskaźnik na rodzica.
    * \param[in] polaczono - aktualny stan połączenia.
    */
    explicit OknoGry(QWidget *parent = nullptr, bool polaczono = false);

    /*!
    * \brief Destruktor klasy OknoGry.
    *
    * Usuwa okno gry.
    */
    ~OknoGry();

private:
    /*!
    * \brief Wskaźnik na ui.
    *
    * Pole zawiera wskaźnik na ui,
    * na którym umieszczone są widgety.
    */
    Ui::OknoGry *ui;

    /*!
    * \brief Wskaźnik status bar.
    *
    * Pole zawiera wskaźnik na status bar,
    * na którym umieszczone ikony.
    */
    QStatusBar *bar;

    /*!
    * \brief Wskaźnik na scenę.
    *
    * Pole zawiera wskaźnik na scenę, na której
    * wyświetlona ma zostać gra.
    */
    QGraphicsScene *scene;

    /*!
    * \brief Wskaźnik na tło.
    *
    * Pole zawiera wskaźnik na tło gry.
    */
    Tlo* tlo;

    /*!
    * \brief Wskaźnik na gracza
    *
    * Pole zawiera wskaźnik na gracza.
    */
    Gracz *gracz;

    /*!
    * \brief Wektor wskaźników na przeszkody.
    *
    * Pole zawiera wektor wskaźników na przeszkody.
    * Służy do śledzenia stworzonych i aktualnie
    * istniejących obiektów przeszkody.
    */
    QVector<Przeszkoda*> tabPrzeszkod;

    /*!
    * \brief Wektor wskaźników na pociski.
    *
    * Pole zawiera wektor wskaźników na pociski.
    * Służy do śledzenia stworzonych i aktualnie
    * istniejących obiektów pocisku.
    */
    QVector<Pocisk*> tabPociskow;

    /*!
    * \brief Wektor wskaźników na animacje.
    *
    * Pole zawiera wektor wskaźników na animacje.
    * Służy do śledzenia stworzonych i aktualnie
    * istniejących obiektów animacji.
    */
    QVector<AnimacjaPrzeszkody*> tabAnimacji;

    /*!
    * \brief Wskaźnik na główny timer gry.
    *
    * Pole zawiera wskaźnik na główny timer gry,
    * który określa częstotliwość odświeżania
    * się obiektów na scenie.
    */
    QTimer *timer;

    /*!
    * \brief Wskaźnik na timer nowych przeszkód
    *
    * Pole zawiera wskaźnik na timer,
    * który określa czas pomiędzy pojawieniem
    * się nowych przeszkód.
    */
    QTimer *timerSpawn;

    /*!
    * \brief Wskaźnik na generator losowy.
    *
    * Pole zawiera wskaźnik na generator losowy,
    * który pozwala na tworzenie przeszkód
    * w losowych miejscach.
    */
    QRandomGenerator *generator;

    /*!
    * \brief Przechwouje ilość punktów gracza.
    *
    * Pole przechowuje aktualną liczbę punktów
    * zdobytych przez gracza.
    */
    int iloscPunktow;

    /*!
    * \brief Surowe dane osi OX akcelerometru.
    *
    * Pole przechowuje surowe dane odczytane z
    * osi OX akcelerometru.
    * Jednostka nieokreślona.
    */
    int daneAccX;

    /*!
    * \brief Surowe dane osi OY akcelerometru.
    *
    * Pole przechowuje surowe dane odczytane z
    * osi OY akcelerometru.
    * Jednostka nieokreślona.
    */
    int daneAccY;

    /*!
    * \brief Przekonwertowane dane osi OX akcelerometru.
    *
    * Pole przechowuje przekonwertowane dane
    * osi OX akcelerometru.
    * Jednostką są stopnie.
    */
    float accX;

    /*!
    * \brief Przekonwertowane dane osi OY akcelerometru.
    *
    * Pole przechowuje przekonwertowane dane
    * osi OY akcelerometru.
    * Jednostką są stopnie.
    */
    float accY;

    /*!
    * \brief Skalibrowane dane osi OX akcelerometru.
    *
    * Pole przechowuje skalibrowane dane
    * osi OX akcelerometru.
    * Jednostką są stopnie.
    */
    float skalibrowaneAccX;

    /*!
    * \brief Skalibrowane dane osi OY akcelerometru.
    *
    * Pole przechowuje skalibrowane dane
    * osi OY akcelerometru.
    * Jednostką są stopnie.
    */
    float skalibrowaneAccY;

    /*!
    * \brief Dane strzału z akcelerometru.
    *
    * Pole przechowuje dane dotyczące
    * strzału odczytane z akcelerometru.
    */
    int strzal;

    /*!
    * \brief Wskaźnik na wykres osi OX akcelerometru.
    *
    * Pole przechowuje wskaźnik na
    * wykres, który pokazuje zachowanie osi OX
    * akcelerometru.
    */
    QChart *wykresX;

    /*!
    * \brief Wskaźnik na wykres osi OY akcelerometru.
    *
    * Pole przechowuje wskaźnik na
    * wykres, który pokazuje zachowanie osi OY
    * akcelerometru.
    */
    QChart *wykresY;

    /*!
    * \brief Wskaźnik na timer odliczający czas na wykresie.
    *
    * Pole przechowuje wskaźnik na
    * timer, który odpowiada za czas na wykresie.
    */
    QTimer *timerCzasuWykresu;

    /*!
    * \brief Przechowuje upłytnięty czas.
    *
    * Pole przechowuje czas, który
    * upłynął na wykresie.
    */
    int czas;

    /*!
    * \brief Wskaźnik na dane osi OX wykresu.
    *
    * Pole przechowuje wskaźnik na
    * dane, który pokazuje zachowanie osi OX
    * akcelerometru.
    */
    QLineSeries *wykresPunktyX;

    /*!
    * \brief Wskaźnik na dane osi OY wykresu.
    *
    * Pole przechowuje wskaźnik na
    * dane, który pokazuje zachowanie osi OY
    * akcelerometru.
    */
    QLineSeries *wykresPunktyY;

    /*!
    * \brief Wskaźnik na oś OX wykresu osi OX akcelerometru.
    *
    * Pole przechowuje wskaźnik na
    * oś OX wykresu w celu jej modyfikacji.
    */
    QValueAxis *osX;

    /*!
    * \brief Wskaźnik na oś OY wykresu osi OX akcelerometru.
    *
    * Pole przechowuje wskaźnik na
    * oś OY wykresu w celu jej modyfikacji.
    */
    QValueAxis *osY;

    /*!
    * \brief Wskaźnik na oś OX wykresu osi OY akcelerometru.
    *
    * Pole przechowuje wskaźnik na
    * oś OX wykresu w celu jej modyfikacji.
    */
    QValueAxis *osX2;

    /*!
    * \brief Wskaźnik na oś OY wykresu osi OY akcelerometru.
    *
    * Pole przechowuje wskaźnik na
    * oś OY wykresu w celu jej modyfikacji.
    */
    QValueAxis *osY2;

    /*!
    * \brief Metoda wyświetlająca animacje przeszkody.
    *
    * Metoda wywietla animację zniszczenia zadanej
    * przeszkody.
    * \param[in] *p - wskaźnik na przeszkodę.
    */
    void wyswietlAnimacjePrzeszkody(Przeszkoda *p);

    /*!
    * \brief Metoda aktualizująca punkty gracza.
    *
    * Metoda aktualizuje aktualną liczbę
    * punktów gracza.
    */
    void zaktualizujPunkty();

    /*!
    * \brief Metoda formatująca dane akceleroemtru.
    *
    * Metoda formatuje surowe dane z akcelerometru
    * na dane wyrażone w stopniach.
    */
    void formatujDaneAkcelerometru();

    /*!
    * \brief Metoda usuwająca wszystkie stworzone obiekty.
    *
    * Metoda usuwa wszystkie stworzone obiekty
    * istniejące na scenie.
    */
    void usunWszystkieElementy();

    /*!
    * \brief Metoda obsługuje przycisk zamknięcia.
    *
    * Metoda obsługująca przycisk zamnięcia okna.
    * Zamkyka i usuwa okno.
    */
    void reject() override;

    /*!
    * \brief Metoda przechwytująca kliknięcia.
    *
    * Metoda przechwytuje klinięcia w oknie.
    * Blokuje przewijanie okna.
    * Odbiera wciśnięcia klawiszy strzałek.
    * \param[in] *object - wskaźnik na obiekt, w którym wciśnięto klawisz.
    * \param[in] *event - wskaźnik na zdarzenie, które przechwycono.
    */
    bool eventFilter(QObject *object, QEvent *event) override;

public slots:
    /*!
    * \brief Slot aktualizujący stan połączenia.
    *
    * Funkcja odbiera informacje o zmianie
    * stanu połączenie i aktualizuje je.
    * \param[in] stan - stan połączenia.
    */
    void ustawStanPolaczenia(bool stan);

    /*!
    * \brief Slot tworzący nową przeszkodę.
    *
    * Funkcja tworzy nową przeszkodę.
    */
    void stworzPrzeszkode();

    /*!
    * \brief Slot tworzący nowy pocisk.
    *
    * Funkcja tworzy nowy pocisk.
    */
    void stworzPocisk();

    /*!
    * \brief Slot znajdujący i usuwający przeszkodę.
    *
    * Funkcja znajduje zadaną przeszkodę i usuwa
    * ją zarówno z wektora przeszków jak i ze sceny.
    * \param[in] *p - wskaźnik na przeszkodę.
    * \param[in] trafiona - czy przeszkoda została trafiona
    */
    void znajdzUsunPrzeszkode(Przeszkoda *p, bool trafiona);

    /*!
    * \brief Slot znajdujący i usuwający pocisk.
    *
    * Funkcja znajduje zadany pocisk i usuwa
    * go zarówno z wektora pocisków jak i ze sceny.
    * \param[in] *p - wskaźnik na pocisk.
    */
    void znajdzUsunPocisk(Pocisk *p);

    /*!
    * \brief Slot znajdujący i usuwająy animację.
    *
    * Funkcja znajduje zadaną animację i usuwa
    * ją zarówno z wektora animacji jak i ze sceny.
    * \param[in] *anim - wskaźnik na animację.
    */
    void znajdzUsunAnimacje(AnimacjaPrzeszkody *anim);

    /*!
    * \brief Slot odbierający dane z akcelerometru.
    *
    * Funkcja odbiera otrzymane dane z akcelerometru.
    * \param[in] x - wartość wychylenia w osi OX.
    * \param[in] y - wartość wychylenia w osi OY.
    * \param[in] s - wartość naciśnięcia przycisku strzału.
    * Jednostki nieokreślone.
    */
    void odebranieDanychAkcelerometru(int x, int y, int s);

    /*!
    * \brief Slot dodający punkty na wykresy.
    *
    * Funkcja dodaje punkty na wykresy
    * pokazujące odczyty z akcelerometru.
    */
    void dodajPunkty();

    /*!
    * \brief Slot ustawiający ilość żyć gracza.
    *
    * Funkcja ustala aktualną ilość żyć
    * gracza.
    * \param[in] aktualneZycie - ilość życia gracza.
    */
    void ustawIloscZyc(int aktualneZycie);

    /*!
    * \brief Slot resetujący grę
    *
    * Funkcja restartuje całą grę
    */
    void zresetujGre();
};

#endif // OKNOGRY_H
