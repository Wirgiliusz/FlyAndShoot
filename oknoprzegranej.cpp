#include "oknoprzegranej.h"
#include "ui_oknoprzegranej.h"

OknoPrzegranej::OknoPrzegranej(QWidget *parent, int punkty) :
    QDialog(parent),
    ui(new Ui::OknoPrzegranej)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::Desktop);

    ui->labelIloscPunktow->setText(QString::number(punkty));
}

OknoPrzegranej::~OknoPrzegranej()
{
    delete ui;
}

void OknoPrzegranej::on_pushButtonZagrajPonownie_clicked()
{
    restartGry();
    close();
}
