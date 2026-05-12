#ifndef SILNIKOBLICZENIOWY_H
#define SILNIKOBLICZENIOWY_H
#include "kontenersiatki.h"
#include <vector>

class SilnikObliczeniowy
{
    int status {0};//mozna zrobic integerem, mozna zrobic enum, bez znaczenia imo, ify beda takie same
    double krokObliczen{ 0.1 };
    KontenerSiatki* kontener{ nullptr };//zeby bylo jak te obliczenia robic

public:
    SilnikObliczeniowy();
    SilnikObliczeniowy(KontenerSiatki* _kontener) { kontener = _kontener; };
    int getStatus() { return status; };
    double getKrokObliczen() { return krokObliczen; };
    void zmienKrokObliczen(double _krokObliczen) { krokObliczen = _krokObliczen; };
    void dodajKontener(KontenerSiatki* _kontener) { kontener = _kontener; };
    void inicjalizuj();//byloby odpowiedzialne za wczytanie liczb i wartosci do obliczen moze? (na razie nieużywane)
    void obliczReakcje(double& silaRX, double& silaRY);
};

#endif // SILNIKOBLICZENIOWY_H
