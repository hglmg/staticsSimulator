#ifndef PRET_H
#define PRET_H
#include "punkt.h"

class Pret
{
    Punkt* pPocz {nullptr};
    Punkt* pKonc {nullptr};
    double dlugosc {0};
    std::string nazwa {"l"};
public:
    Pret();
    Pret(Punkt* _pPocz, Punkt* _pKonc);
    double getL() {return dlugosc;};
    Punkt* getPunktP() {return pPocz;};
    Punkt* getPunktK() {return pKonc;};
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
};

#endif // PRET_H
