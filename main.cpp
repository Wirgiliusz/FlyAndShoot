#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/flyandshoot_icon.ico"));
    MainWindow w;
    w.show();
    return a.exec();
}

/*!
 * \mainpage Fly and Shoot
 * \author Kamil Drewniak
 *
 * \section Opis
 * Wynikiem projektu jest aplikacja stworzona przy użyciu narzędzia Qt. \n
 * Aplikacja jest grą interaktywną, w której sterowanie odby się przy pomocy
 * modułu akcelerometra. \n
 *
 * \section Gra
 * Gra polega na omijaniu lub zestrzeliwaniu nadlatujących przeszkód (Przeszkoda) i zdobyciu
 * jak największej ilości punktów. \n
 * Gracz posiada 3 życia, który wyczerpanie kończy grę. \n
 *
 * \section Sterowanie
 * Sterowanie odbywa się przy poocy modułu akcelerometru podłączonego
 * poprzez port szeregowy. \n
 * Wychylenia modułu w różnych kierunkach powodują analogiczny ruch
 * gracza w danych kierunkach. \n
 * Dodatkowo naciśnięcie przycisku powoduje strzał (Pocisk). \n
 */
