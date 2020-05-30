#ifndef OKNOPOLACZENIA_H
#define OKNOPOLACZENIA_H

#include <QDialog>
#include <QSerialPort>
#include <QDebug>
#include <QList>
#include <QSerialPortInfo>
#include <QDateTime>

typedef unsigned char byte;
#define POLYMONIAL_9 0x0161

namespace Ui {
class OknoPolaczenia;
}

class OknoPolaczenia : public QDialog
{
    Q_OBJECT

public:
    explicit OknoPolaczenia(QWidget *parent = nullptr);
    ~OknoPolaczenia();

private slots:
    void on_pushButtonSearch_clicked();
    void on_pushButtonConnect_clicked();
    void on_pushButtonCloseConnection_clicked();

    void readFromPort();

signals:
    void zmianaStanuPolaczenia(bool stan);
    void otrzymanieDanychAkcelerometru(int x, int y, int strzal);

private:
    Ui::OknoPolaczenia *ui;
    QSerialPort *device;

    void addToLogs(QString message);
    bool ParsujRamkeDanych(const std::string pRamkaDanych);
    byte CRC8_DataArray(byte *pData, byte Len);
    unsigned int CRC8_SingleByte(unsigned int Data2);
    std::string hexStr(byte *data, int len);

    int accX;
    int accY;
    int strzal;
};

#endif // OKNOPOLACZENIA_H
