# FlyAndShoot
 Projekt wykorzystujący akcelerometr jako kontroler do gry w aplikacji Qt

---

## Opis projektu
Projekt polegał na stworzeniu aplikacji, która w wymyślony sposób będzie wizualizowała odczytane dane sensoryczne.
Wybranymi danymi zostały odczyty z akcelerometru *MMA7660FC* połączonego z modułem *Arduino Nano v3*, natomiast sposobem wizualizacji jest gra zręcznościowa, polegająca na omijaniu i zestrzeliwaniu przeszkód. Dodatkowo wizualizacja odbywa się także poprzez tworzone wykresy pokazujące aktualne odczyty.

---

## Efekt końcowy
Poniższy obrazek pokazuje wygląd gry.

<img src="https://puu.sh/FWlMt/915623d747.png" width="700">

---

### TO-DO
<details>
  <summary>Ukończone zadania</summary>
  
- [x] 1. System żyć
    - [x] a. Grafika pokazująca aktualną ilość żyć
    - [x] b. System obsługujący aktualną liczbę życia
    - [x] c. Ekran przegranej
    - [x] d. Restart gry
- [x] 2. Punkty
    - [x] a. Tekst pokazujący liczbę punktów
    - [x] b. System obsługujący punkty
- [x] 3. Grafika
    - [x] a. Dodanie różnych grafik dla przeszkód
    - [x] b. Animacja otrzymania obrażeń przez gracza
    - [x] c. Animacja zniszczenia przeszkody
        - [x] - przeszkoda1
        - [x] - przeszkoda2
        - [x] - przeszkoda3
        - [x] - przeszkoda4
    - [x] d. Tło 
    - [x] e. Podpisanie osi na wykresach
    - [x] f. Ikona gry
- [x] 4. Dokumentacja
    - [x] a. Zainstalowanie i skonfigurowanie Doxygena
    - [x] b. Opisanie kodu według schematu
        - [x] animacjaprzeszkody.h/.cpp
        - [x] gracz.h/.cpp
        - [x] mainwindow.h/.cpp
        - [x] oknogry.h/.cpp
        - [x] oknopolaczenia.h/.cpp
        - [x] oknoprzegranej.h/.cpp
        - [x] pocisk.h/.cpp
        - [x] przeszkoda.h/.cpp
        - [x] tlo.h/.cpp
        - [x] main.cpp
- [x] 5. Poprawki
    - [x] a. Zablokowanie przycisku w połączeniu
    - [x] b. Zablokować możliwość zamknięcia okna restartu gry
  
</details>
