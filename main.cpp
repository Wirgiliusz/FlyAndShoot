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
