#ifndef PUNKT_H
#define PUNKT_H

#include <string>

class Punkt
{
    double x {0}, y {0};
    std::string nazwa {"p"};
    //Podpora* podporaPkt {nullptr};//wskaznik na podpore ktora mialaby byc w danym punkcie, moze trzeba to odworcic?
    // to sie chyba nie przyda, lepiej żeby podpora przechowywała info o punkcie, potencjalnie DO WYJEBANIA ale niech zostanie na razie
public:
    Punkt();
    Punkt(double _x, double _y,std::string nazwa);
    double getX() {return x;};
    double getY() {return y;};
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
    void modyfikujPozycje(double _x, double _y);
};

#endif // PUNKT_H
