#ifndef OBCIAZENIE_H
#define OBCIAZENIE_H
#include <string>
#include <Eigen> // biblioteka do macierzy i obliczen algebry liniowej
#include "punkt.h"
#include "pret.h"


enum typObciazenia {momentSkupiony, silaSkupiona, konstrukcyjne};
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
    Obciazenie(double _wartoscX, double _wartoscY,std::string _nazwa);
    double wartoscSily() { return wartosc; };
    double wartoscSily_x() { return wartoscX; };
    double wartoscSily_y() { return wartoscY; };
    double wartoscSuly_OBR() { return wartoscOBR; };
    virtual Punkt* getPunkt() = 0;
    virtual Pret* getPret() = 0;
    typObciazenia typ;

    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
    ~Obciazenie() {--pktPrzylozenia;};
};



class ObcPunktowe : public Obciazenie
{


public:

    ObcPunktowe(double _wartoscX, double _wartoscY,Punkt* pkt,std::string _nazwa);
    void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; };
    Pret* getPret() override { return nullptr; };
    Punkt* getPunkt() override { return pktPrzylozenia; };
};

class ObcKonstrukcyjne : public Obciazenie
{
public:

    ObcKonstrukcyjne(double _wartoscX, double _wartoscY, Pret* _pret,std::string _nazwa);
    void dodajPunktPrz(Pret* _pretPrzylozenia) { pretPrzylozenia = _pretPrzylozenia; };
    Pret* getPret() override { return pretPrzylozenia; };
    Punkt* getPunkt() override {return nullptr;};
};

class MomentSkupiony : public Obciazenie
{


public:

    MomentSkupiony(double _wartosc, Punkt* _pkt,std::string _nazwa);
    void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; };
    Punkt* getPunkt() override { return pktPrzylozenia; };
    Pret* getPret() override { return nullptr; }; // zrobiłem tak, żeby działało
};










#endif // OBCIAZENIE_H
