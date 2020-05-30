#include "oknoprzegranej.h"
#include "ui_oknoprzegranej.h"

OknoPrzegranej::OknoPrzegranej(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoPrzegranej)
{
    ui->setupUi(this);
}

OknoPrzegranej::~OknoPrzegranej()
{
    delete ui;
}
