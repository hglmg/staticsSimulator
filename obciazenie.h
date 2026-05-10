#ifndef OBCIAZENIE_H
#define OBCIAZENIE_H
#include <string>
#include "punkt.h"


class Obciazenie
{
protected:
    double wartosc {0}, wartoscX {0}, wartoscY {0};
    std::string nazwa {"f"};
    // Punkt* pktPrzylozenia { nullptr }; jednak nie tak, wpadlem na pomysl pod prysznicem lmao
    
public:
    Obciazenie();
    Obciazenie(double _wartoscX, double _wartoscY);
    double getWar() {return wartosc;};
    double getWarX() {return wartoscX;};
    double getWarY() {return wartoscY;};
    // void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; }; panu juz podziekujemy
    // Punkt* getPunkt() { return pktPrzylozenia; };
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};

};

#endif // OBCIAZENIE_H
