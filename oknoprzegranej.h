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
    explicit OknoPrzegranej(QWidget *parent = nullptr);
    ~OknoPrzegranej();

private:
    Ui::OknoPrzegranej *ui;
};

#endif // OKNOPRZEGRANEJ_H
