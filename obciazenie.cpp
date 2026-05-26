#include "obciazenie.h"
#include <cmath>


Obciazenie::Obciazenie(double _wartoscX, double _wartoscY)
{
    wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2));
    wartoscX = _wartoscX;
    wartoscY = _wartoscY;

}

 ObcPunktowe::ObcPunktowe(double _wartoscX, double _wartoscY, Punkt* pkt) : Obciazenie(_wartoscX,_wartoscY )
{
    pktPrzylozenia = pkt;
    pkt->dodajSile_x(_wartoscX);
    pkt->dodajSile_y(_wartoscY);

}



ObcKonstrukcyjne::ObcKonstrukcyjne(double _wartoscX, double _wartoscY, Pret* pret) : Obciazenie(_wartoscX,_wartoscY )
{
    pretPrzylozenia = pret;
}

MomentSkupiony::MomentSkupiony( double _wartosc, Punkt* pkt)
{
    pktPrzylozenia = pkt;
    wartoscOBR = _wartosc;
    pkt->dodajMoment_obr(_wartosc); //przekazanie przez wartość do punktu
}



























