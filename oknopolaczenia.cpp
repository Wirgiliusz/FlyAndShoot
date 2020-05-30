#include "oknopolaczenia.h"
#include "ui_oknopolaczenia.h"
#include "mainwindow.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

OknoPolaczenia::OknoPolaczenia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoPolaczenia)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);
}

OknoPolaczenia::~OknoPolaczenia()
{
    delete ui;
}


void OknoPolaczenia::on_pushButtonSearch_clicked()
{
    this->addToLogs("Szukam urządzeń...");

    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();
    ui->comboBoxDevices->clear();
    for(int i=0; i<devices.count(); i++) {
        this->addToLogs("Znalazłem urządzenie: " + devices.at(i).portName() + " " + devices.at(i).description());
        ui->comboBoxDevices->addItem(devices.at(i).portName() + "\t" + devices.at(i).description());
    }
}

void OknoPolaczenia::on_pushButtonConnect_clicked()
{
    if(ui->comboBoxDevices->count() == 0) {
        this->addToLogs("Nie wykryto żadych urządzeń!");
        return;
    }

    QString portName = ui->comboBoxDevices->currentText().split("\t").first();
    this->device->setPortName(portName);

    // Otworzenie i skonfigurowanie portu
    if(!device->isOpen()) {
        if(device->open(QSerialPort::ReadWrite)) {
            zmianaStanuPolaczenia(true);

            this->device->setBaudRate(QSerialPort::Baud9600);
            this->device->setDataBits(QSerialPort::Data8);
            this->device->setParity(QSerialPort::NoParity);
            this->device->setStopBits(QSerialPort::OneStop);
            this->device->setFlowControl(QSerialPort::NoFlowControl);

            this->addToLogs("Otwarto port szeregowy.");

            // CONNECT - odczytywanie z portu
            connect(this->device, SIGNAL(readyRead()), this, SLOT(readFromPort()));
        }
        else {
            zmianaStanuPolaczenia(false);
            this->addToLogs("Otwarcie portu szeregowego nie powiodło się!");
        }
    }
    else {
        this->addToLogs("Port jest już otwarty!");
        return;
    }

}

void OknoPolaczenia::readFromPort()
{
    while(this->device->canReadLine()) {
        QString line = this->device->readLine();
        QString terminator = "\r";
        int pos = line.lastIndexOf(terminator);
        this->addToLogs(line.left(pos));

        std::string ramkaDanych = line.left(pos).toStdString();
        if(ParsujRamkeDanych(ramkaDanych)) {
            otrzymanieDanychAkcelerometru(this->accX, this->accY, this->strzal);
        }
    }
}

unsigned int OknoPolaczenia::CRC8_SingleByte(unsigned int Data2) {
  unsigned int Poly = (POLYMONIAL_9 << 7);

  for(byte idx=0; idx<8; ++idx) {
    if((Data2 & 0x8000) != 0) {
      Data2 ^= Poly;
    }
    Data2 <<= 1;
  }

  return Data2;
}

byte OknoPolaczenia::CRC8_DataArray(byte *pData, byte Len) {
  unsigned int Data2 = pData[0] << 8;

  // zmienic poczatek na 0 w arduino (z 1)
  for(unsigned int idx=0; idx<Len; ++idx) {
    Data2 |= pData[idx];
    Data2 = CRC8_SingleByte(Data2);
  }
  Data2 = CRC8_SingleByte(Data2);

  return (byte)(Data2 >> 8);
}

// Funkcja do zamiany typu byte na hex i umieszczenie go w stringu
std::string OknoPolaczenia::hexStr(byte *data, int len)
{
     std::stringstream ss;
     ss << std::hex;

     for( int i(0) ; i < len; ++i )
         ss << (int)data[i];

     return ss.str();
}

bool OknoPolaczenia::ParsujRamkeDanych(const std::string pRamkaDanych) {
    std::istringstream IStrm(pRamkaDanych);
    std::string naglowek;
    std::string CRC8_ramka;
    std::string AccX;
    std::string AccY;
    std::string Strzal;
    IStrm >> naglowek >> AccX >> AccY >> Strzal >> CRC8_ramka;

    if(IStrm.fail() || naglowek != "X") {
        return false;
    }
    else {   
        unsigned char cAccX = char(std::stoi(AccX));
        unsigned char cAccY = char(std::stoi(AccY));
        unsigned char cStrzal = char(std::stoi(Strzal));
        unsigned char dane[3] = {cAccX, cAccY, cStrzal};
        byte CRC8_wyliczone;
        CRC8_wyliczone = CRC8_DataArray(dane, 3);
        std::string CRC8_wyliczone_string = hexStr(&CRC8_wyliczone, 1);
        if(CRC8_wyliczone_string == CRC8_ramka) {
            this->accX = std::stoi(AccX);
            this->accY = std::stoi(AccY);
            this->strzal = std::stoi(Strzal);
            return true;
        }
        else {
            return false;
        }
    }
}

void OknoPolaczenia::on_pushButtonCloseConnection_clicked()
{
    if(this->device->isOpen()) {
        zmianaStanuPolaczenia(false);
        this->device->close();
        this->addToLogs("Zamknięto połączenie.");
    }
    else {
        this->addToLogs("Port nie jest otwarty!");
        return;
    }
}

void OknoPolaczenia::addToLogs(QString message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->textEditLogs->append(currentDateTime + "\t" + message);
}
