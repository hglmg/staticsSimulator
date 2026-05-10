#include "obciazenie.h"
#include <cmath>


Obciazenie::Obciazenie(double _wartoscX, double _wartoscY,Punkt* pkt)
{
    wartoscX = _wartoscX;
    wartoscY = _wartoscY;
    wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2)); // może warto by dodać kontruktor z punktu, wartości i kąta
    //wzgl OX? - do przemyślenia, narazie robię tak
    //brakuje punktu początkowego - dopiszę
    punktPrzylozenia = pkt;

}



ObcKonstrukcyjne::ObcKonstrukcyjne(double _wartoscX, double _wartoscY, Punkt* pkt)
{
    wartoscX = _wartoscX;
    wartoscY = _wartoscY;
    wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2));
    double _pktPozorny[2];
    //_pktPozorny[0] = (pretPrzylozenia->getPunktP()->getX() + pretPrzylozenia->getPunktK()->getX())/2;
    //_pktPozorny[1] = (pretPrzylozenia->getPunktP()->getY() + pretPrzylozenia->getPunktK()->getX())/2;
    //narazie komment, ale chyba to wyjebię, mam lepszy pomysł
    //pktPozorny = new Punkt(_pktPozorny[0], _pktPozorny[1]);
    wartoscPoz = pretPrzylozenia->getL() * wartosc;//wartosci pozorne to wartosci sily skupionej ktora jest analogiczna do sily kontrukcyjnej,
    wartoscPozX = pretPrzylozenia->getL() * wartoscX;//moze mozna to zrobic dajac wskaznik na sile skupiona
    wartoscPozY = pretPrzylozenia->getL() * wartoscY;

}

ObcPunktowe::ObcPunktowe(double _wartoscX, double _wartoscY,Punkt* pkt)
{
    wartoscX = _wartoscX;
    wartoscY = _wartoscY;
    wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2));
    punktPrzylozenia = pkt;

}
