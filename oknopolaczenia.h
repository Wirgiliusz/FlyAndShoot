#ifndef OKNOPOLACZENIA_H
#define OKNOPOLACZENIA_H

/*!
* \file
* \brief Definicja klasy OknoPolaczenia
*
* Plik zawiera definicję klasy OknoPolaczenia,
* która odpowiada za okno łączenia z akcelerometrem.
*/

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

/*!
* \brief Implementacja obiektu okna gry.
*
* Klasa odpowieda za obiekt okna gry.
*/
class OknoPolaczenia : public QDialog {
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy OknoPolaczenia.
    *
    * Inicjalizuje okno połączenia.
    * \param[in] *parent - wskaźnik na rodzica.
    */
    explicit OknoPolaczenia(QWidget *parent = nullptr);

    /*!
    * \brief Destruktor klasy OknoPolaczenia.
    *
    * Usuwa okno gry.
    */
    ~OknoPolaczenia();

private:
    /*!
    * \brief Wskaźnik na ui.
    *
    * Pole zawiera wskaźnik na ui,
    * na którym umieszczone są widgety.
    */
    Ui::OknoPolaczenia *ui;

    /*!
    * \brief Wskaźnik na aktualnie połączone urządzenie.
    *
    * Pole zawiera wskaźnik na urządzenie,
    * które jest aktualnie połączone z aplikacją.
    */
    QSerialPort *device;

    /*!
    * \brief Surowe dane osi OX akcelerometru.
    *
    * Pole przechowuje surowe dane odczytane z
    * osi OX akcelerometru.
    * Jednostka nieokreślona.
    */
    int accX;

    /*!
    * \brief Surowe dane osi OY akcelerometru.
    *
    * Pole przechowuje surowe dane odczytane z
    * osi OY akcelerometru.
    * Jednostka nieokreślona.
    */
    int accY;

    /*!
    * \brief Dane strzału z akcelerometru.
    *
    * Pole przechowuje dane dotyczące
    * strzału odczytane z akcelerometru.
    */
    int strzal;

    /*!
    * \brief Metoda parsująca ramkę danych.
    *
    * Metoda parsuje ramkę danych,
    * na którą podany zostanie wskaźnik.
    * \param[in] pRamkaDanych - ramka danych.
    * \return Czy ramka danych jest poprawna.
    */
    bool ParsujRamkeDanych(const std::string pRamkaDanych);

    /*!
    * \brief Metoda licząca CRC8 dla tablicy danych.
    *
    * Metoda liczy CRC8 dla tablicy danych,
    * o zadanej długości.
    * \param[in] *pData - wskaźnik na dane.
    * \param[in] Len - długość danych.
    * \return Zwraca wyliczony kod CRC8.
    */
    byte CRC8_DataArray(byte *pData, byte Len);

    /*!
    * \brief Metoda licząca CRC8 dla jednogo bajtu.
    *
    * Metoda liczy CRC8 dla
    * jednego bajtu danych.
    * \param[in] Data2 - dane.
    * \return Zwraca wyliczony kod CRC8.
    */
    unsigned int CRC8_SingleByte(unsigned int Data2);

    /*!
    * \brief Metoda konwertuje podane dane na hex.
    *
    * Metoda konwertuje podane dane na kod heksadecymalny,
    * który jest stringiem.
    * \param[in] *data - dane.
    * \param[in] Len - długość danych.
    * \return Zwraca przekonwertowana wartość jako hex w stringu.
    */
    std::string hexStr(byte *data, int len);

    /*!
    * \brief Metoda tworząca log.
    *
    * Metoda wpisuje odpowiednie komunikaty
    * do logu.
    * \param[in] message - wiadomość.
    */
    void addToLogs(QString message);

private slots:
    /*!
    * \brief Slot obsłgujący przycisk szukania.
    *
    * Funkcja obsługuje naciśnięcie przycisku
    * wyszukania dostępnych urządzeń.
    */
    void on_pushButtonSearch_clicked();

    /*!
    * \brief Slot obsłgujący przycisk połączenia.
    *
    * Funkcja obsługuje naciśnięcie przycisku
    * połączenia z wybranym urządzeniem.
    */
    void on_pushButtonConnect_clicked();

    /*!
    * \brief Slot obsłgujący przycisk rozłączenia.
    *
    * Funkcja obsługuje naciśnięcie przycisku
    * rozłączenia z wybranym urządzeniem.
    */
    void on_pushButtonCloseConnection_clicked();

    /*!
    * \brief Slot obsłgujący odczyt danych.
    *
    * Funkcja obsługuje odczytywanie danych
    * z portu szeregowego.
    */
    void readFromPort();

signals:
    /*!
    * \brief Sygnał zmiany stanu połączenia.
    *
    * Wysyła sygnał w momencie zmiany stanu połączenia.
    * \param[in] stan - stan połączenia.
    */
    void zmianaStanuPolaczenia(bool stan);

    /*!
    * \brief Sygnał otrzymanai danych z akcelerometru.
    *
    * Wysyła sygnał w momencie otrzymania
    * danych z akcelerometru.
    * \param[in] x - wartość wychylenia w osi OX.
    * \param[in] y - wartość wychylenia w osi OY.
    * \param[in] s - wartość naciśnięcia przycisku strzału.
    * Jednostki nieokreślone.
    */
    void otrzymanieDanychAkcelerometru(int x, int y, int strzal);
};

#endif // OKNOPOLACZENIA_H
