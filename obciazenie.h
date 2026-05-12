#ifndef OBCIAZENIE_H
#define OBCIAZENIE_H
#include <string>
#include "punkt.h"
#include "pret.h"
#include "sila.h"



class Obciazenie // zróbmy że klasy pochodne są w tym samym pliku co bazowa - bedzie mniej plików do ogarniania, a program będzie lepiej uporzadkowany >>>>dobra, mozemy tak zrobic
{
protected:
    //double wartosc {0}, wartoscX {0}, wartoscY {0};
    Sila silaObc{ Sila(0, 0) };
    Punkt* punktPrzylozenia{nullptr};
    std::string nazwa {"F"};
    
public:
    Obciazenie() = default;
    //Obciazenie(double _wartoscX, double _wartoscY, Punkt* _pkt);
    //double getWar() {return wartosc;};
    //double getWarX() {return wartoscX;};
    //double getWarY() {return wartoscY;};
    Obciazenie(double _wartoscX, double _wartoscY, Punkt* _pkt);
    Sila getSila() { return silaObc; };
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};

};

class ObcKonstrukcyjne : public Obciazenie
{
//protected:
    Pret* pretPrzylozenia{ nullptr };
    Punkt* pktPozorny{ nullptr };
    Sila silaPoz{ Sila(0, 0) };
public:
    ObcKonstrukcyjne() = default;
    ObcKonstrukcyjne(double _wartoscX, double _wartoscY,Punkt* pkt);
    void dodajPunktPrz(Pret* _pretPrzylozenia) { pretPrzylozenia = _pretPrzylozenia; };
    Pret* getPret() { return pretPrzylozenia; };
};

class ObcPunktowe : public Obciazenie
{
//protected:
    Punkt* pktPrzylozenia{ nullptr }; // dlaczego nie pirivate? >>>> szczerze to dalem tak bo mialem pare pomyslow ktore wymagalyby dziedziczenia
public:
    ObcPunktowe() = default;
    ObcPunktowe(double _wartoscX, double _wartoscY, Punkt* _pkt);
    void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; };
    Punkt* getPunkt() { return pktPrzylozenia; };
};


#endif // OBCIAZENIE_H
