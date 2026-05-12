#ifndef PODPORA_H
#define PODPORA_H
#include "punkt.h"
#include "obciazenie.h"

class Podpora
{
protected:
    bool xBlok{ false }, yBlok{ false }, rotBlok{ false };
    //Sila* reakcja{ nullptr };//nie wiem jeszcze czy dac to jako wskaznikowe czy zwykle

    Punkt* pozycja;



public:
    Podpora(double _x, double _y);
    //virtual bool blokujeX() = 0;
    //virtual bool blokujeY() = 0; // podpora to klasa abstarkcyjna: dostępne będą tylko jej typy pochodne
    void wstawPodpore();
    Punkt* zwrocPunkt() { return pozycja; };
    //Sila* zwrocReakcje() { return reakcja; };
    //void dodajReakcje(Sila* _reakcja) { reakcja = _reakcja; }; to punkt będzie trzymał reakcje, podpora ma tylko przechowywać punkty
    // chodzi o to, że bedziemy wiliczać osobno dla każdej belki, traktując punkty łączące jako podpory
    //bez sesu trzymac siły w podporze
    bool zwrocBlok_x(){return xBlok;};
    bool zwrocBlok_y(){return yBlok;};
    bool zwrocBlok_obr(){return rotBlok;}; // jak ci sie chce to morzesz to "rot" zmienić na obr bo tak wszędzie pisałem
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
    //może jakaś mapa? ładnie by wyglądała
};
class PodporaRuchoma : public Podpora//moze tez pelnic funkcje lozyska czolowego
{
public:
    PodporaRuchoma(double _x, double _y, char freeAxis);
};

#endif // PODPORA_H
