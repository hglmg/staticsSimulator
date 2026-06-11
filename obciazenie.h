#ifndef OBCIAZENIE_H
#define OBCIAZENIE_H
#include <string>
#include <Eigen> // biblioteka do macierzy i obliczen algebry liniowej
#include "punkt.h"
#include "pret.h"

/*  KLASA PRZESTARZAŁA  */

enum typObciazenia {sila, moment};
class Obciazenie

{
protected:
    Pret* pretPrzylozenia{ nullptr };
    Punkt* pktPrzylozenia{ nullptr };
    std::string nazwa {"F"};
    double wartoscX{0};
    double wartoscY{0};
    double wartoscOBR{0};
    double wartosc{0}; // dałem to bezpośrednio w klasie, bez użycia klasy siła (tak jest przejżyściej)

    
public:

    Obciazenie() = default; // dodałem bo moment nie ma wartości x i y
    Obciazenie(double _wartoscX, double _wartoscY);
    double wartoscSily() { return wartosc; };
    double wartoscSily_x() { return wartoscX; };
    double wartoscSily_y() { return wartoscY; };
    double wartoscSuly_OBR() { return wartoscOBR; };
    virtual Punkt* getPunkt() = 0;
    typObciazenia typ;

    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
    virtual ~Obciazenie() = default; // klasa wirualna
};



class ObcPunktowe : public Obciazenie
{


public:

    ObcPunktowe(double _wartoscX, double _wartoscY,Punkt* pkt);
    void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; };
    Punkt* getPunkt() override { return pktPrzylozenia; };
};

class ObcKonstrukcyjne : public Obciazenie
{



public:

    ObcKonstrukcyjne(double _wartoscX, double _wartoscY, Pret* _pret);
    void dodajPunktPrz(Pret* _pretPrzylozenia) { pretPrzylozenia = _pretPrzylozenia; };
    Pret* getPret() { return pretPrzylozenia; };
};

class MomentSkupiony : public Obciazenie
{


public:

    MomentSkupiony(double _wartosc, Punkt* _pkt);
    void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; };
    Punkt* getPunkt() override { return pktPrzylozenia; };
};










#endif // OBCIAZENIE_H
