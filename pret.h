#ifndef PRET_H
#define PRET_H
#include "punkt.h"

class Pret
{
    Punkt* pPocz;
    Punkt* pKonc;
    double dlugosc;
public:
    Pret();
    Pret(Punkt* _pPocz, Punkt* _pKonc);
};

#endif // PRET_H
