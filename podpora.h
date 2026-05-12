#ifndef PODPORA_H
#define PODPORA_H
#include "punkt.h"
#include "obciazenie.h"

class Podpora
{
protected:
    bool xBlok{ false }, yBlok{ false }, rotBlok{ false };
    Sila* reakcja{ nullptr };//nie wiem jeszcze czy dac to jako wskaznikowe czy zwykle

    Punkt* pozycja;



public:
    Podpora(double _x, double _y); // wyjebałem konstruktory domyśle bo tylko zaśmieciają i nic nie dają
    //virtual bool blokujeX() = 0;
    //virtual bool blokujeY() = 0; // podpora to klasa abstarkcyjna: dostępne będą tylko jej typy pochodne
    void wstawPodpore();
    Punkt* zwrocPunkt() { return pozycja; };
    Sila* zwrocReakcje() { return reakcja; };
    void dodajReakcje(Sila* _reakcja) { reakcja = _reakcja; };
};

class UtwierdzenieStale : public Podpora
{
public:
    UtwierdzenieStale(double _x, double _y);//zostawmy moze zmienne w metodach z podloga przed, mi latwiej zapamietac ktore sa ktore wtedy
};

class PrzegubWalcowy : public Podpora
{
public:
    PrzegubWalcowy(double _x, double _y);
};

class UtwierdzeniePrzesuwne : public Podpora
{
public:
    UtwierdzeniePrzesuwne(double _x, double _y, char freeAxis);//moze uzyc czegos innego do definiowania swobodnej osi, ale chyba char bedzie najlepszy (potem mozna zrobic jakis drop-down w GUI)
};
class PodporaRuchoma : public Podpora//moze tez pelnic funkcje lozyska czolowego
{
public:
    PodporaRuchoma(double _x, double _y, char freeAxis);
};

#endif // PODPORA_H
