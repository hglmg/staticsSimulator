#ifndef SILNIKOBLICZENIOWY_H
#define SILNIKOBLICZENIOWY_H
#include "kontenersiatki.h"

class SilnikObliczeniowy
{
    int status {0};//mozna zrobic integerem, mozna zrobic enum, bez znaczenia imo, ify beda takie same
    KontenerSiatki* kontener{ nullptr };//zeby bylo jak te obliczenia robic

public:
    SilnikObliczeniowy();
    SilnikObliczeniowy(KontenerSiatki* _kontener) { kontener = _kontener; };
    int getStatus() { return status; };
    void dodajKontener(KontenerSiatki* _kontener) { kontener = _kontener; };
    void inicjalizuj();//byloby odpowiedzialne za wczytanie liczb i wartosci do obliczen moze? (na razie nieużywane)
    void obliczReakcje(double &silaRX, double &silaRY);//puste, na razie jeszcze nie wiem co i jak to dac
};

#endif // SILNIKOBLICZENIOWY_H
