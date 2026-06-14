#ifndef PODPORA_H
#define PODPORA_H
#include "punkt.h"
#include "obciazenie.h"

class Podpora
{
protected:
    bool xBlok{ false }, yBlok{ false }, rotBlok{ false };
    int typ;
    //Sila* reakcja{ nullptr };//nie wiem jeszcze czy dac to jako wskaznikowe czy zwykle

    Punkt* pozycja;



public:

    Podpora(double _x, double _y);
    Podpora(Punkt *_pozycja);

    int getTyp() {return typ;};

    void wstawPodpore();
    Punkt* zwrocPunkt() { return pozycja; };

    bool zwrocBlok_x(){return xBlok;};
    bool zwrocBlok_y(){return yBlok;};
    bool zwrocBlok_obr(){return rotBlok;}; // jak ci sie chce to morzesz to "rot" zmienić na obr bo tak wszędzie pisałem
};

class UtwierdzenieStale : public Podpora
{
public:
    UtwierdzenieStale(double _x, double _y);//zostawmy moze zmienne w metodach z podloga przed, mi latwiej zapamietac ktore sa ktore wtedy
    UtwierdzenieStale(Punkt *_pozycja);
};

class PrzegubWalcowy : public Podpora
{
public:
    PrzegubWalcowy(double _x, double _y);
    PrzegubWalcowy(Punkt *_pozycja);
};

class UtwierdzeniePrzesuwne : public Podpora
{
public:
    UtwierdzeniePrzesuwne(double _x, double _y, char freeAxis);//moze uzyc czegos innego do definiowania swobodnej osi, ale chyba char bedzie najlepszy (potem mozna zrobic jakis drop-down w GUI)
    UtwierdzeniePrzesuwne(Punkt *_pozycja, char freeAxis);
    //może jakaś mapa? ładnie by wyglądała
};
class PodporaRuchoma : public Podpora//moze tez pelnic funkcje lozyska czolowego
{
public:
    PodporaRuchoma(double _x, double _y, char freeAxis);
    PodporaRuchoma(Punkt *_pozycja, char freeAxis);
};

#endif // PODPORA_H
