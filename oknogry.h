#ifndef OKNOGRY_H
#define OKNOGRY_H

#include "przeszkoda.h"
#include "pocisk.h"
#include "gracz.h"
#include "oknoprzegranej.h"
#include "animacjaprzeszkody.h"
#include "tlo.h"

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


namespace Ui {
class OknoGry;
}

class OknoGry : public QDialog
{
    Q_OBJECT

public:
    explicit OknoGry(QWidget *parent = nullptr, bool polaczono = false);
    ~OknoGry();


public slots:
    void ustawStanPolaczenia(bool stan);
    void stworzPrzeszkode();
    void stworzPocisk();
    void znajdzUsunPrzeszkode(Przeszkoda *p, bool trafiona);
    void znajdzUsunPocisk(Pocisk *p);
    void znajdzUsunAnimacje(AnimacjaPrzeszkody *anim);
    void odebranieDanychAkcelerometru(int x, int y, int s);
    void dodajPunkty();
    void ustawIloscZyc(int aktualneZycie);
    void zresetujGre();

private:
    Ui::OknoGry *ui;
    void usunWszystkieElementy();
    QStatusBar *bar;
    QTimer *timer;
    QTimer *timerSpawn;
    QRandomGenerator *generator;

    QGraphicsScene *scene;
    void wyswietlAnimacjePrzeszkody(Przeszkoda *p);

    QVector<Przeszkoda*> tabPrzeszkod;
    QVector<Pocisk*> tabPociskow;
    QVector<AnimacjaPrzeszkody*> tabAnimacji;

    Tlo* tlo;

    Gracz *gracz;
    int iloscPunktow;
    void zaktualizujPunkty();

    int daneAccX;
    int daneAccY;

    void formatujDaneAkcelerometru();
    float accX;
    float accY;
    float skalibrowaneAccX;
    float skalibrowaneAccY;
    int strzal;

    QChart *wykresX;
    QChart *wykresY;
    QTimer *timerCzasuWykresu;
    int czas;
    QLineSeries *wykresPunktyX;
    QLineSeries *wykresPunktyY;
    QValueAxis *osX;
    QValueAxis *osY;
    QValueAxis *osX2;
    QValueAxis *osY2;

    void reject() override;
    bool eventFilter(QObject *object, QEvent *event) override;
};

#endif // OKNOGRY_H
