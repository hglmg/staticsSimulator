#ifndef PODPORA_H
#define PODPORA_H
#include "Punkt.h"

class Podpora
{
protected:
    bool xBlok {false}, yBlok {false}, momentSily {false};
    Punkt* pozycja;


public:
    Podpora(double x, double y); // wyjebałem konstruktory domyśle bo tylko zaśmieciają i nic nie dają
    //virtual bool blokujeX() = 0;
    //virtual bool blokujeY() = 0; // podpora to klasa abstarkcyjna: dostępne będą tylko jej typy pochodne
    void wstawPodpore();
    Punkt* zwrocPunkt(){return pozycja;};
};

class PrzytwierdzenieStale : public Podpora
{
public:
    PrzytwierdzenieStale(double x, double y);
};


#endif // PODPORA_H
