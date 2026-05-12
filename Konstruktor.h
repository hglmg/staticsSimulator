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
    KontenerSiatki Kontener() { return schemat; };
    void konfiguruj();
};

#endif // KONSTRUKTOR_H