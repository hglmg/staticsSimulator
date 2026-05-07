#ifndef PRET_H
#define PRET_H
#include "punkt.h"

class Pret
{
    Punkt* pPocz {nullptr};
    Punkt* pKonc {nullptr};
    double dlugosc {0};
public:
    Pret();
    Pret(Punkt* _pPocz, Punkt* _pKonc);
    double getL() {return dlugosc;};
    Punkt* getPunktP() {return pPocz;};
    Punkt* getPunktK() {return pKonc;};
};

#endif // PRET_H
