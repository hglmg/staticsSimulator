#ifndef OBCIAZENIEPUNKTOWE_H
#define OBCIAZENIEPUNKTOWE_H
#include <string>
#include "punkt.h"


class ObciazeniePunktowe
{
protected:
    double wartosc {0}, wartoscX {0}, wartoscY {0};
    std::string nazwa {"f"};
    Punkt* pktPrzylozenia { nullptr };
    
public:
    ObciazeniePunktowe();
    ObciazeniePunktowe(double _wartoscX, double _wartoscY);
    double getWar() {return wartosc;};
    double getWarX() {return wartoscX;};
    double getWarY() {return wartoscY;};
    void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; };
    Punkt* getPunkt() { return pktPrzylozenia; };
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};

};

#endif // OBCIAZENIEPUNKTOWE_H
