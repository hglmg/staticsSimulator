#ifndef OBCIAZENIEKONSTRUKCYJNE_H
#define OBCIAZENIEKONSTRUKCYJNE_H
#include "pret.h"

class ObciazenieKonstrukcyjne
{
protected:
    double wartosc{ 0 }, wartoscX{ 0 }, wartoscY{ 0 };
    std::string nazwa{ "f" };
    Pret* pretPrzylozenia{ nullptr };
public:
    ObciazenieKonstrukcyjne();
    ObciazenieKonstrukcyjne(double _wartoscX, double _wartoscY);
    double getWar() { return wartosc; };
    double getWarX() { return wartoscX; };
    double getWarY() { return wartoscY; };
    void dodajPretPrz(Pret* _pretPrzylozenia) { pretPrzylozenia = _pretPrzylozenia; };
    Pret* getPret() { return pretPrzylozenia; };
    std::string getNazwa() { return nazwa; };
    void modyfikujNazwe(std::string _nazwa) { nazwa = _nazwa; };
};

#endif // OBCIAZENIEKONSTRUKCYJNE_H