#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Stworzenie okna polaczenia i poleczenia sygnalu i slotu stanu sygnalu
    oknoPolaczenia = new OknoPolaczenia(this);
    connect(oknoPolaczenia, SIGNAL(zmianaStanuPolaczenia(bool)), this, SLOT(ustawStanPolaczenia(bool)));

    // Dodanie informacji o stanie polaczenia na status bar
    ui->statusbar->addWidget(ui->labelStanPolaczeniaIcon);
    ui->statusbar->addWidget(ui->labelStanPolaczenia);
    ui->labelStanPolaczeniaIcon->setAlignment(Qt::AlignCenter);

    // Dodanie ikony informujacej o stanie polaczenia na status bar
    QPixmap pixmap;
    if(pixmap.load(":/icons/iconRed.png")) {
        ui->labelStanPolaczeniaIcon->setPixmap(pixmap);
    }
    else {
        qDebug() << "Nie wczytano ikony";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonWyjscie_clicked() {

}

void MainWindow::on_pushButtonPolacz_clicked()
{
    // Pokazanie okna polaczenia
    oknoPolaczenia->show();
}

void MainWindow::on_pushButtonGraj_clicked()
{
    // Stworzenie okna gry i polczenia sygnalu i slotu stanu sygnalu
    oknoGry = new OknoGry(this, polaczono);
    connect(oknoPolaczenia, SIGNAL(zmianaStanuPolaczenia(bool)), oknoGry, SLOT(ustawStanPolaczenia(bool)));
    connect(oknoPolaczenia, SIGNAL(otrzymanieDanychAkcelerometru(int, int, int)), oknoGry, SLOT(odebranieDanychAkcelerometru(int, int, int)));
    oknoGry->show();
}

void MainWindow::ustawStanPolaczenia(bool stan)
{
    QPixmap pixmap;

    // Ustawienie ikony na status barze w zaleznosci od stanu polaczenia
    if(stan == true) {
        polaczono = true;
        if(pixmap.load(":/icons/iconGreen.png")) {
            ui->labelStanPolaczeniaIcon->setPixmap(pixmap);
        }
        else {
            qDebug() << "Nie wczytano ikony";
        }
    }
    else {
        polaczono = false;
        if(pixmap.load(":/icons/iconRed.png")) {
            ui->labelStanPolaczeniaIcon->setPixmap(pixmap);
        }
        else {
            qDebug() << "Nie wczytano ikony";
        }
    }
}



