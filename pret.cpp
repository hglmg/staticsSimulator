#include "pret.h"
#include <cmath>

Pret::Pret() {}

Pret::Pret(Punkt* _pPocz, Punkt* _pKonc)
{
    pPocz = _pPocz;
    pKonc = _pKonc;
    dlugosc = sqrt((pow((_pKonc->getY()-_pPocz->getY()), 2) + pow((_pKonc->getX()-_pPocz->getX()), 2)));

}