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


    double przemieszczenie_x = 0;
    double przemieszczenie_y = 0;
    double przemieszczenie_obr0 = 0;

    double reakcja_x = 0;
    double reakcja_y = 0;
    double reakcja_obr = 0;

    double sila_x = 0;
    double sila_y = 0;
    double moment_obr = 0;

}
