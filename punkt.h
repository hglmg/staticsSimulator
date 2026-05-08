#ifndef PUNKT_H
#define PUNKT_H
#include "podpora.h"
#include <string>

class Punkt
{
    double x {0}, y {0};
    std::string nazwa {""};
    Podpora* podporaPkt {nullptr};//wskaznik na podpore ktora mialaby byc w danym punkcie, moze trzeba to odworcic?

public:
    Punkt();
    Punkt(double _x, double _y);
    double getX() {return x;};
    double getY() {return y;};
    std::string getNazwa() {return nazwa;};
    bool jestPodpora();
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
};

#endif // PUNKT_H
