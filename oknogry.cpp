#include "oknogry.h"
#include "ui_oknogry.h"
#include "przeszkoda.h"
#include <cmath>

OknoGry::OknoGry(QWidget *parent, bool polaczono) :
    QDialog(parent),
    ui(new Ui::OknoGry)
{
    ui->setupUi(this);

    // Stworzenie status bara
    bar = new QStatusBar(this);
    ui->statusBarLayout->addWidget(bar);

    // Dodanie informacji o stanie polaczenia na status bar
    bar->addWidget(ui->labelStanPolaczeniaIcon);
    bar->addWidget(ui->labelStanPolaczenia);
    ui->labelStanPolaczeniaIcon->setAlignment(Qt::AlignCenter);

    // Dodanie ikony informujacej o stanie polaczenia na status bar
    QPixmap pixmap;
    if(polaczono) {
        if(pixmap.load(":/icons/iconGreen.png")) {
            ui->labelStanPolaczeniaIcon->setPixmap(pixmap);
        }
        else {
            qDebug() << "Nie wczytano ikony";
        }
    }
    else {
        if(pixmap.load(":/icons/iconRed.png")) {
            ui->labelStanPolaczeniaIcon->setPixmap(pixmap);
        }
        else {
            qDebug() << "Nie wczytano ikony";
        }
    }

    // Tworzenie sceny i obiektow
    ui->graphicsViewGra->installEventFilter(this);
    ui->graphicsViewGra->viewport()->setFocus();
    ui->graphicsViewGra->setInteractive(false);
    ui->graphicsViewGra->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsViewGra->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(this);
    ui->graphicsViewGra->setScene(scene);

    int szerokosc = 800;
    int wysokosc = 800;
    ui->graphicsViewGra->setFixedSize(szerokosc, wysokosc);
    ui->graphicsViewGra->setSceneRect(0, 0, szerokosc, wysokosc);

    // Tworzenie obiektow w losowych miejscach
    generator = new QRandomGenerator;
    timerSpawn = new QTimer(this);
    connect(timerSpawn, SIGNAL(timeout()), this, SLOT(stworzPrzeszkode()));
    timerSpawn->start(1500);

    gracz = new Gracz(scene);
    scene->addItem(gracz);

    // Stworzenie timera aktualizujacego obiekty na scenie
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000 / 33);

    // Stworzenie zakladki z wykresami
    int szerokoscWykresu = 800;
    int wysokoscWykresu = 300;
    ui->graphicsViewWykresX->setFixedSize(szerokoscWykresu, wysokoscWykresu);
    ui->graphicsViewWykresX->setSceneRect(0, 0, szerokoscWykresu, wysokoscWykresu);
    ui->graphicsViewWykresY->setFixedSize(szerokoscWykresu, wysokoscWykresu);
    ui->graphicsViewWykresY->setSceneRect(0, 0, szerokoscWykresu, wysokoscWykresu);

    osX = new QValueAxis();
    osY = new QValueAxis();
    osX2 = new QValueAxis();
    osY2 = new QValueAxis();
    //wykresPunktyX = new QSplineSeries(this);
    wykresPunktyX = new QLineSeries(this);
    wykresPunktyX->append(0,0);
    //wykresPunktyY = new QSplineSeries(this);
    wykresPunktyY = new QLineSeries(this);
    wykresPunktyY->append(0,0);

    wykresX = new QChart();
    wykresX->legend()->hide();
    wykresX->addSeries(wykresPunktyX);
    wykresX->addAxis(osX, Qt::AlignBottom);
    wykresX->addAxis(osY, Qt::AlignLeft);
    wykresY = new QChart();
    wykresY->legend()->hide();
    wykresY->addSeries(wykresPunktyY);
    wykresY->addAxis(osX2, Qt::AlignBottom);
    wykresY->addAxis(osY2, Qt::AlignLeft);

    wykresPunktyX->attachAxis(osX);
    wykresPunktyX->attachAxis(osY);
    wykresPunktyY->attachAxis(osX2);
    wykresPunktyY->attachAxis(osY2);

    osX->setTickCount(11);
    osY->setTickCount(7);
    osX->setRange(0, 10);
    osY->setRange(-90 ,90);
    osX->setLabelFormat("%d");
    osX2->setTickCount(11);
    osY2->setTickCount(7);
    osX2->setRange(0, 10);
    osY2->setRange(-90 ,90);
    osX2->setLabelFormat("%d");

    ui->graphicsViewWykresX->setRenderHint(QPainter::Antialiasing);
    ui->graphicsViewWykresX->setChart(wykresX);
    ui->graphicsViewWykresY->setRenderHint(QPainter::Antialiasing);
    ui->graphicsViewWykresY->setChart(wykresY);

    timerCzasuWykresu = new QTimer(this);
    connect(timerCzasuWykresu, SIGNAL(timeout()), this, SLOT(dodajPunkty()));
    timerCzasuWykresu->start(100);
}

void OknoGry::dodajPunkty() {
    qreal x = wykresX->plotArea().width() / (osX->tickCount()-1);
    qreal y = (osX->max() - osX->min()) / (osX->tickCount()-1);
    czas += y;
    //qDebug() << skalibrowaneAccX;
    wykresPunktyX->append(czas, skalibrowaneAccX);
    wykresPunktyY->append(czas, skalibrowaneAccY);
    if(czas > 10) {
        wykresX->scroll(x, 0);
        wykresY->scroll(x, 0);
    }


    /*
    czas +=1;
    if(czas > 10) {
        wykresPunktyX->removePoints(0, 1);
    }
    wykresPunktyX->append(czas, accX);
    osX->setRange(czas-10, czas);
    //wykresX->scroll(100, 0);
    */

}

OknoGry::~OknoGry()
{
    delete ui;
}


void OknoGry::ustawStanPolaczenia(bool stan)
{
    qDebug() << "Otrzymalem informacje o zmianie stanu polaczenia: polaczenie =" << stan;
    QPixmap pixmap;

    // Ustawienie ikony na status barze w zaleznosci od stanu polaczenia
    if(stan == true) {
        if(pixmap.load(":/icons/iconGreen.png")) {
            ui->labelStanPolaczeniaIcon->setPixmap(pixmap);
        }
        else {
            qDebug() << "Nie wczytano ikony";
        }
    }
    else {
        if(pixmap.load(":/icons/iconRed.png")) {
            ui->labelStanPolaczeniaIcon->setPixmap(pixmap);
        }
        else {
            qDebug() << "Nie wczytano ikony";
        }
    }
}

void OknoGry::stworzPrzeszkode() {
    //Przeszkoda przeszkoda(scene, generator->bounded(0, 800), generator->bounded(5, 20));
    Przeszkoda *p = new Przeszkoda(scene, generator->bounded(0, 800), generator->bounded(5, 20));
    tabPrzeszkod.append(p);
    scene->addItem(p);
    QObject::connect(p, SIGNAL(usunPrzeszkode(Przeszkoda*)), this, SLOT(znajdzUsunPrzeszkode(Przeszkoda*)));
    QString currentDateTime = QDateTime::currentDateTime().toString("hh:mm:ss");
    qDebug() << currentDateTime << "Stworzono przeszkode";
}

void OknoGry::stworzPocisk() {
    Pocisk *p = new Pocisk(scene, gracz->getPosX()+gracz->pixmap.width()/2, gracz->getPosY()-50);
    tabPociskow.append(p);
    scene->addItem(p);
    QObject::connect(p, SIGNAL(usunPocisk(Pocisk*)), this, SLOT(znajdzUsunPocisk(Pocisk*)));
    QString currentDateTime = QDateTime::currentDateTime().toString("hh:mm:ss");
    qDebug() << currentDateTime << "Stworzono pocisk";
}


void OknoGry::znajdzUsunPrzeszkode(Przeszkoda *p) {
    for(int i=0; i<tabPrzeszkod.size(); i++) {
        if(tabPrzeszkod[i] == p) {
            tabPrzeszkod.remove(i);
            scene->removeItem(p->pixmapItem);
            p->deleteLater();
        }
    }
}

void OknoGry::znajdzUsunPocisk(Pocisk *p) {
    for(int i=0; i<tabPociskow.size(); i++) {
        if(tabPociskow[i] == p) {
            tabPociskow.remove(i);
            scene->removeItem(p->pixmapItem);
            p->deleteLater();
        }
    }
}

void OknoGry::odebranieDanychAkcelerometru(int x, int y, int s)
{
    daneAccX = x;
    daneAccY = y;
    strzal = s;
    formatujDaneAkcelerometru();
    //qDebug() << "Sformatowane dane z akcelerometru: " << this->accX << " " << this->accY << " " << this->strzal;
    /* Ruch jak strzalkami
    if(accX > 15) {
        gracz->setRuch(gracz->gora, true);
    } else {
        gracz->setRuch(gracz->gora, false);
    }
    if(accX < -15) {
        gracz->setRuch(gracz->dol, true);
    } else {
        gracz->setRuch(gracz->dol, false);
    }
    if(accY > 10) {
        gracz->setRuch(gracz->prawo, true);
    } else {
        gracz->setRuch(gracz->prawo, false);
    }
    if(accY < -10) {
        gracz->setRuch(gracz->lewo, true);
    } else {
        gracz->setRuch(gracz->lewo, false);
    }
    */
    // Kalibracja
    skalibrowaneAccX = accX + 5;
    skalibrowaneAccY = accY - 1;

    // Zamiana na predkosc uzywajac funkcji pierwistka
    int Vx = 0;
    int Vy = 0;
    if(skalibrowaneAccX >= 0) {
        Vx = 2*sqrt(skalibrowaneAccX);
    } else {
        Vx = -2*sqrt(-skalibrowaneAccX);
    }
    if(skalibrowaneAccY >= 0) {
        Vy = 2*sqrt(skalibrowaneAccY);
    } else {
        Vy = -2*sqrt(-skalibrowaneAccY);
    }
    if(Vx < 5 && Vx > -5) {
        Vx = 0;
    }
    if(Vy < 5 && Vy > -5) {
        Vy = 0;
    }
    gracz->setPredkosc(Vx, Vy);

    if(strzal && !gracz->wlasnieStrzelil) {
        stworzPocisk();
        gracz->wlasnieStrzelil = true;
    } else if(!strzal) {
        gracz->wlasnieStrzelil = false;
    }

}

void OknoGry::formatujDaneAkcelerometru()
{
    switch(this->daneAccX) {
        case 0:  this->accX =   0.00; break;
        case 1:  this->accX =   2.69; break;
        case 2:  this->accX =   5.38; break;
        case 3:  this->accX =   8.08; break;
        case 4:  this->accX =  10.81; break;
        case 5:  this->accX =  13.55; break;
        case 6:  this->accX =  16.33; break;
        case 7:  this->accX =  19.16; break;
        case 8:  this->accX =  22.02; break;
        case 9:  this->accX =  24.95; break;
        case 10: this->accX =  27.95; break;
        case 11: this->accX =  31.04; break;
        case 12: this->accX =  34.23; break;
        case 13: this->accX =  37.54; break;
        case 14: this->accX =  41.01; break;
        case 15: this->accX =  44.68; break;
        case 16: this->accX =  48.59; break;
        case 17: this->accX =  52.83; break;
        case 18: this->accX =  57.54; break;
        case 19: this->accX =  62.95; break;
        case 20: this->accX =  69.64; break;
        case 21: this->accX =  79.86; break;
        case 43: this->accX = -79.86; break;
        case 44: this->accX = -69.64; break;
        case 45: this->accX = -62.95; break;
        case 46: this->accX = -57.54; break;
        case 47: this->accX = -52.83; break;
        case 48: this->accX = -48.59; break;
        case 49: this->accX = -44.68; break;
        case 50: this->accX = -41.01; break;
        case 51: this->accX = -37.54; break;
        case 52: this->accX = -34.23; break;
        case 53: this->accX = -31.04; break;
        case 54: this->accX = -27.95; break;
        case 55: this->accX = -24.95; break;
        case 56: this->accX = -22.02; break;
        case 57: this->accX = -19.16; break;
        case 58: this->accX = -16.33; break;
        case 59: this->accX = -13.55; break;
        case 60: this->accX = -10.81; break;
        case 61: this->accX = - 8.08; break;
        case 62: this->accX = - 5.38; break;
        case 63: this->accX = - 2.69; break;
    }

    switch(this->daneAccY) {
        case 0:  this->accY =   0.00; break;
        case 1:  this->accY =   2.69; break;
        case 2:  this->accY =   5.38; break;
        case 3:  this->accY =   8.08; break;
        case 4:  this->accY =  10.81; break;
        case 5:  this->accY =  13.55; break;
        case 6:  this->accY =  16.33; break;
        case 7:  this->accY =  19.16; break;
        case 8:  this->accY =  22.02; break;
        case 9:  this->accY =  24.95; break;
        case 10: this->accY =  27.95; break;
        case 11: this->accY =  31.04; break;
        case 12: this->accY =  34.23; break;
        case 13: this->accY =  37.54; break;
        case 14: this->accY =  41.01; break;
        case 15: this->accY =  44.68; break;
        case 16: this->accY =  48.59; break;
        case 17: this->accY =  52.83; break;
        case 18: this->accY =  57.54; break;
        case 19: this->accY =  62.95; break;
        case 20: this->accY =  69.64; break;
        case 21: this->accY =  79.86; break;
        case 43: this->accY = -79.86; break;
        case 44: this->accY = -69.64; break;
        case 45: this->accY = -62.95; break;
        case 46: this->accY = -57.54; break;
        case 47: this->accY = -52.83; break;
        case 48: this->accY = -48.59; break;
        case 49: this->accY = -44.68; break;
        case 50: this->accY = -41.01; break;
        case 51: this->accY = -37.54; break;
        case 52: this->accY = -34.23; break;
        case 53: this->accY = -31.04; break;
        case 54: this->accY = -27.95; break;
        case 55: this->accY = -24.95; break;
        case 56: this->accY = -22.02; break;
        case 57: this->accY = -19.16; break;
        case 58: this->accY = -16.33; break;
        case 59: this->accY = -13.55; break;
        case 60: this->accY = -10.81; break;
        case 61: this->accY = - 8.08; break;
        case 62: this->accY = - 5.38; break;
        case 63: this->accY = - 2.69; break;
    }
}

void OknoGry::reject()
{
    this->deleteLater();
    QDialog::reject();
}


bool OknoGry::eventFilter(QObject *object, QEvent *event)
{
    // Ignorowanie kolka myszy
    if(object == ui->graphicsViewGra->viewport() && event->type() == QEvent::Wheel) {
        return true;
    }

    // Przechwycenie wcisniecia klawisza strzalek
    if(event->type() == QEvent::KeyPress || event->type() == QEvent::ShortcutOverride) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch(keyEvent->key()) {
            case Qt::Key_Up:
                gracz->setRuch(gracz->gora, true);
            break;
            case Qt::Key_Right:
                gracz->setRuch(gracz->prawo, true);
            break;
            case Qt::Key_Down:
                gracz->setRuch(gracz->dol, true);
            break;
            case Qt::Key_Left:
                gracz->setRuch(gracz->lewo, true);
            break;
        }
        return true;
    }

    // Przechwycenie puszczenia klawisza strzalek
    if(event->type() == QEvent::KeyRelease) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch(keyEvent->key()) {
            case Qt::Key_Up:
                gracz->setRuch(gracz->gora, false);
            break;
            case Qt::Key_Right:
                gracz->setRuch(gracz->prawo, false);
            break;
            case Qt::Key_Down:
                gracz->setRuch(gracz->dol, false);
            break;
            case Qt::Key_Left:
                gracz->setRuch(gracz->lewo, false);
            break;
        }
        return true;
    }

    return QObject::eventFilter(object, event);
}
