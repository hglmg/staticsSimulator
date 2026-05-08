#ifndef OBCIAZENIE_H
#define OBCIAZENIE_H
#include <string>
//#include "punkt.h"


class Obciazenie
{
protected:
    double wartosc {0}, wartoscX {0}, wartoscY {0};
    std::string nazwa {"f"};
    //Punkt* pktPrzylozenia { nullptr }; na razie useless, ale kto wie
    
public:
    Obciazenie();
    Obciazenie(double _wartoscX, double _wartoscY);
    double getWar() {return wartosc;};
    double getWarX() {return wartoscX;};
    double getWarY() {return wartoscY;};
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};

};

#endif // OBCIAZENIE_H
