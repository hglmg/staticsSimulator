#ifndef KONSTRUKTOR_H
#define KONSTRUKTOR_H
#include "kontenersiatki.h"
#include "punkt.h"
#include "podpora.h"
#include "pret.h"
class KontenerSiatki;

class Konstruktor
{
    KontenerSiatki schemat;
public:
    Konstruktor() = default;
    KontenerSiatki* Kontener() { return &schemat; };
    void konfiguruj();
    void dodajPunkt();
    void dodajPret(Punkt* pocz, Punkt* konc, double E, double d, std::string nazwa);
    void dodajPret(Punkt* pocz, Punkt* konc, double E, double b, double h, std::string nazwa);
};




#endif // KONSTRUKTOR_H