#include "podpora.h"

Podpora::Podpora(double x, double y)
{
    Punkt* pkt = new Punkt(x,y,"P");
    pozycja = pkt;
}



PrzytwierdzenieStale::PrzytwierdzenieStale(double x, double y)  : Podpora(x,y)
{
    xBlok = true;
    yBlok = true;
    momentSily = true;

}