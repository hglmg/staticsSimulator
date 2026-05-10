#ifndef PODPORA_H
#define PODPORA_H
#include "punkt.h"
#include "obciazenie.h"

class Podpora
{
protected:
    bool xBlok{ false }, yBlok{ false }, rotBlok{ false };
    ObcPunktowe *reakcjaX{ nullptr }, *reakcjaY{ nullptr }, *reakcjaMXY{ nullptr };//na potem do oswobodzenia z wiezow

    Punkt* pozycja;



public:
    Podpora(double x, double y); // wyjebałem konstruktory domyśle bo tylko zaśmieciają i nic nie dają
    //virtual bool blokujeX() = 0;
    //virtual bool blokujeY() = 0; // podpora to klasa abstarkcyjna: dostępne będą tylko jej typy pochodne
    void wstawPodpore();
    Punkt* zwrocPunkt(){return pozycja;};
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
    UtwierdzeniePrzesuwne(double _x, double _y, char freeAxis);//moze uzyc czegos innego do definiowania swobodnej osi, ale chyba char bedzie najlepszy
};
class PodporaRuchoma : public Podpora//moze tez pelnic funkcje lozyska czolowego
{
public:
    PodporaRuchoma(double _x, double _y, char freeAxis);
};

#endif // PODPORA_H
