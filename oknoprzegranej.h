#ifndef OKNOPRZEGRANEJ_H
#define OKNOPRZEGRANEJ_H

#include <QDialog>

namespace Ui {
class OknoPrzegranej;
}

class OknoPrzegranej : public QDialog
{
    Q_OBJECT

public:
    explicit OknoPrzegranej(QWidget *parent = nullptr, int punkty = 0);
    ~OknoPrzegranej();

private:
    Ui::OknoPrzegranej *ui;

private slots:
    void on_pushButtonZagrajPonownie_clicked();

signals:
    void restartGry();
};



#endif // OKNOPRZEGRANEJ_H
