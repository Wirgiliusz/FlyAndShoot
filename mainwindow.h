#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include "oknopolaczenia.h"
#include "oknogry.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonWyjscie_clicked();
    void on_pushButtonPolacz_clicked();
    void on_pushButtonGraj_clicked();

    void ustawStanPolaczenia(bool stan);

private:
    Ui::MainWindow *ui;
    OknoPolaczenia *oknoPolaczenia;
    OknoGry *oknoGry;

    bool polaczono = false;
};
#endif // MAINWINDOW_H
