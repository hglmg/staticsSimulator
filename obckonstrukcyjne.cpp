#include "obckonstrukcyjne.h"

ObcKonstrukcyjne::ObcKonstrukcyjne() {}

ObcKonstrukcyjne::ObcKonstrukcyjne(double _wartoscX, double _wartoscY)
{
    wartoscX = _wartoscX;
    wartoscY = _wartoscY;
    wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2));
    double _pktPozorny[2];
    _pktPozorny[0] = (pretPrzylozenia->getPunktP()->getX() + pretPrzylozenia->getPunktK()->getX())/2;
    _pktPozorny[1] = (pretPrzylozenia->getPunktP()->getY() + pretPrzylozenia->getPunktK()->getX())/2;
    pktPozorny = new Punkt(_pktPozorny[0], _pktPozorny[1]);
    wartoscPoz = pretPrzylozenia->getL() * wartosc;//wartosci pozorne to wartosci sily skupionej ktora jest analogiczna do sily kontrukcyjnej,
    wartoscPozX = pretPrzylozenia->getL() * wartoscX;//moze mozna to zrobic dajac wskaznik na sile skupiona
    wartoscPozY = pretPrzylozenia->getL() * wartoscY;

}
