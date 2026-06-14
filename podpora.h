#ifndef PODPORA_H
#define PODPORA_H
#include "punkt.h"

class Podpora
{
protected:
    bool xBlok{ false }, yBlok{ false }, rotBlok{ false };
    int typ;


    Punkt* pozycja;



public:

    Podpora(double _x, double _y);
    Podpora(Punkt *_pozycja);

    int getTyp() {return typ;};

    void wstawPodpore();
    Punkt* zwrocPunkt() { return pozycja; };

    bool zwrocBlok_x(){return xBlok;};
    bool zwrocBlok_y(){return yBlok;};
    bool zwrocBlok_obr(){return rotBlok;};
};

class UtwierdzenieStale : public Podpora
{
public:

    UtwierdzenieStale(Punkt *_pozycja);
};


class PodporaStala : public Podpora
{
public:

    PodporaStala(Punkt *_pozycja);

};
class PodporaRuchoma : public Podpora
{
public:

    PodporaRuchoma(Punkt *_pozycja, char freeAxis);
};

#endif // PODPORA_H
