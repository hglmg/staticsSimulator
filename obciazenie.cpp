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
}



ObcKonstrukcyjne::ObcKonstrukcyjne(double _wartoscX, double _wartoscY, Pret* pret) : Obciazenie(_wartoscX,_wartoscY )
{
    pretPrzylozenia = pret;
}

MomentSkupiony::MomentSkupiony(double _wartoscX, double _wartoscY, Punkt* pkt) : Obciazenie(_wartoscX,_wartoscY )
{
    pktPrzylozenia = pkt;
}



























