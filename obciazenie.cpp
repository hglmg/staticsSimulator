#include "obciazenie.h"
#include <cmath>


Obciazenie::Obciazenie(double _wartoscX, double _wartoscY, std::string _nazwa)
{
    wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2));
    wartoscX = _wartoscX;
    wartoscY = _wartoscY;
    nazwa = _nazwa;

}

 ObcPunktowe::ObcPunktowe(double _wartoscX, double _wartoscY, Punkt* pkt,std::string _nazwa) : Obciazenie(_wartoscX,_wartoscY, _nazwa )
{
    typ = silaSkupiona;
    pktPrzylozenia = pkt;
    pkt->dodajSile_x(_wartoscX);
    pkt->dodajSile_y(_wartoscY);

}



ObcKonstrukcyjne::ObcKonstrukcyjne(double _wartoscX, double _wartoscY, Pret* pret,std::string _nazwa) : Obciazenie(_wartoscX,_wartoscY,_nazwa )
{
    typ = konstrukcyjne;
    pretPrzylozenia = pret;
}

MomentSkupiony::MomentSkupiony( double _wartosc, Punkt* pkt, std::string _nazwa)
{
    nazwa = _nazwa;
    typ = momentSkupiony;
    pktPrzylozenia = pkt;
    wartoscOBR = _wartosc;
    pkt->dodajMoment_obr(_wartosc); //przekazanie przez wartość do punktu
}



























