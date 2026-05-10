#ifndef OBCKONSTRUKCYJNE_H
#define OBCKONSTRUKCYJNE_H
#include "pret.h"
#include "obciazenie.h"

class ObcKonstrukcyjne : public Obciazenie
{
protected:
    Pret* pretPrzylozenia{ nullptr };
    Punkt* pktPozorny{ nullptr };
    double wartoscPoz {0}, wartoscPozX {0}, wartoscPozY {0};
public:
    ObcKonstrukcyjne();
    ObcKonstrukcyjne(double _wartoscX, double _wartoscY);
    void dodajPunktPrz(Pret* _pretPrzylozenia) { pretPrzylozenia = _pretPrzylozenia; };
    Pret* getPret() { return pretPrzylozenia; };
};

#endif // OBCKONSTRUKCYJNE_H
