#include "podpora.h"

Podpora::Podpora(double _x, double _y)
{
    pozycja = new Punkt(_x, _y, "P");
}



UtwierdzenieStale::UtwierdzenieStale(double _x, double _y)  : Podpora(_x, _y)
{
    xBlok = true;
    yBlok = true;
    rotBlok = true;

}

PrzegubWalcowy::PrzegubWalcowy(double _x, double _y) : Podpora(_x, _y)
{
    xBlok = true;
    yBlok = true;
    rotBlok = false;

}

UtwierdzeniePrzesuwne::UtwierdzeniePrzesuwne(double _x, double _y, char freeAxis) : Podpora(_x, _y)
{
    rotBlok = true;
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

PodporaRuchoma::PodporaRuchoma(double _x, double _y, char freeAxis) : Podpora(_x, _y)
{
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