#ifndef PRET_H
#define PRET_H
#include "punkt.h"
#include <vector>

class Pret
{
    Punkt* pPocz {nullptr};
    Punkt* pKonc {nullptr};
    double dlugosc {0};
    std::string nazwa {"l"}; // nie wiem po co nadawać nazwy prętom i punktom >>>> chodzi o to zeby byly odroznialne dla uzytkownika w gui, ale jak wolisz
    std::vector <Punkt*> punkty; // pierwszy punkt to początek, drugi koniec, reszcza to punkty charakterystyczne
public:

    Pret(Punkt* _pPocz, Punkt* _pKonc);
    double getL() {return dlugosc;};
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
    void dodajPunkt(double odleglosc);
    std::vector <Punkt*> zwrocPunkty(){return punkty;};
};


#endif // PRET_H
