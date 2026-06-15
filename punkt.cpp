#include "punkt.h"

Punkt::Punkt(double _x, double _y, std::string _nazwa)
{
    x = _x;
    y = _y;
    modyfikujNazwe(_nazwa);
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

void Punkt::zeruj_wartosci()
{


    przemieszczenie_x = 0;
    przemieszczenie_y = 0;
    przemieszczenie_obr = 0;

    reakcja_x = 0;
    reakcja_y = 0;
    reakcja_obr = 0;

    sila_x = 0;
    sila_y = 0;
    moment_obr = 0;

}