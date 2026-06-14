#include "podpora.h"

Podpora::Podpora(double _x, double _y)
{
    pozycja = new Punkt(_x, _y, "P");
}

Podpora::Podpora(Punkt *_pozycja)
{
    pozycja = _pozycja;
}



UtwierdzenieStale::UtwierdzenieStale(Punkt *_pozycja)  : Podpora(_pozycja)
{
    typ = 0;
    xBlok = true;
    yBlok = true;
    rotBlok = true;
}



PodporaStala::PodporaStala(Punkt *_pozycja) : Podpora(_pozycja)
{
    typ = 1;
    rotBlok = false;
    xBlok = true;
    yBlok = true;
}



PodporaRuchoma::PodporaRuchoma(Punkt *_pozycja, char freeAxis) : Podpora(_pozycja)
{
    typ = 2;
    rotBlok = false;
    switch (freeAxis)
    {
    default:
        yBlok = true;
        xBlok = false;
        break;
    case 'X':
        xBlok = false;
        yBlok = true;
        break;
    case 'Y':
        xBlok = true;
        yBlok = false;
        break;
    }
}