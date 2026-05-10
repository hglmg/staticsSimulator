#ifndef OBCPUNKTOWE_H
#define OBCPUNKTOWE_H
#include "obciazenie.h"
#include "punkt.h"

class ObcPunktowe : public Obciazenie
{
protected:
    Punkt* pktPrzylozenia{ nullptr };
public:
    ObcPunktowe();
    ObcPunktowe(double _wartoscX, double _wartoscY);
    void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; };
    Punkt* getPunkt() { return pktPrzylozenia; };
};

#endif // OBCPUNKTOWE_H
