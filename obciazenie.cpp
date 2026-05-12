#include "obciazenie.h"
#include <cmath>


Obciazenie::Obciazenie(double _wartoscX, double _wartoscY, Punkt* _pkt)
{
    double wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2)); // może warto by dodać kontruktor z punktu, wartości i kąta
    //wzgl OX? - do przemyślenia, narazie robię tak
    //brakuje punktu początkowego - dopiszę
    punktPrzylozenia = _pkt;
    silaObc = Sila(_wartoscX, _wartoscY);
}



ObcKonstrukcyjne::ObcKonstrukcyjne(double _wartoscX, double _wartoscY, Punkt* pkt) // to na razie zostawiam
//pobawimy sie dziediczeniem jak skończe silnik
//na razie zrobię dla klasy bazowej
{
    //wartoscX = _wartoscX;
    //wartoscY = _wartoscY;
    //wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2));
    //double _pktPozorny[2];
    //_pktPozorny[0] = (pretPrzylozenia->zwrocPunkty().at(0)->getX() + pretPrzylozenia->zwrocPunkty().at(1)->getX()) / 2;
    //_pktPozorny[1] = (pretPrzylozenia->zwrocPunkty().at(0)->getY() + pretPrzylozenia->zwrocPunkty().at(1)->getY()) / 2;
    //narazie komment, ale chyba to wyjebię, mam lepszy pomysł
    //pktPozorny = new Punkt(_pktPozorny[0], _pktPozorny[1]);
    //wartoscPoz = pretPrzylozenia->getL() * wartosc;//wartosci pozorne to wartosci sily skupionej ktora jest analogiczna do sily kontrukcyjnej,
    //wartoscPozX = pretPrzylozenia->getL() * wartoscX;//moze mozna to zrobic dajac wskaznik na sile skupiona
    //wartoscPozY = pretPrzylozenia->getL() * wartoscY;
    // 
    // 
    //silaPoz = Sila(wartoscPozX = pretPrzylozenia->getL() * wartoscX, wartoscPozY = pretPrzylozenia->getL() * wartoscY); dostosowane do nowej architektury

}

ObcPunktowe::ObcPunktowe(double _wartoscX, double _wartoscY, Punkt* _pkt)
{
    silaObc = Sila(_wartoscX, _wartoscY);
    punktPrzylozenia = _pkt;

}
