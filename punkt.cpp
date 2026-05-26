#include "punkt.h"

Punkt::Punkt(double _x, double _y, std::string _nazwa)
{
    x = _x;
    y = _y;
    this->modyfikujNazwe(_nazwa);
}

void Punkt::nazwijStopienSwodoby_x(int numer)
{
    stopienSwobody_x = numer;
}
void Punkt::nazwijStopienSwodoby_y(int numer)
{
    stopienSwobody_y = numer;
}
void Punkt::nazwijStopienSwodoby_obr(int numer)
{
    stopienSwobody_obr = numer;
}




// void Punkt::modyfikujPozycje(double _x, double _y)
// {
//     x = _x;
//     y = _y;
// }



// bool Punkt::jestPodpora()
// {
//     if (podporaPkt == nullptr) return false;
//     else return true;
// }