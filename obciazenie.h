#ifndef OBCIAZENIE_H
#define OBCIAZENIE_H
#include <string>
#include "punkt.h"
#include "pret.h"



class Obciazenie // zróbmy że klasy pochodne są w tym samym pliku co bazowa - bedzie mniej plików do ogarniania, a program będzie lepiej uporzadkowany >>>>dobra, mozemy tak zrobic
{
protected:
    double wartosc {0}, wartoscX {0}, wartoscY {0};
    Punkt* punktPrzylozenia{nullptr};
    std::string nazwa {"F"};
    // Punkt* pktPrzylozenia { nullptr }; jednak nie tak, wpadlem na pomysl pod prysznicem lmao
    //słaby pomysł pod prysznicem bo jednak tego potrzebuję
    
public:
    Obciazenie() = default;
    Obciazenie(double _wartoscX, double _wartoscY,Punkt* Pkt);
    double getWar() {return wartosc;};
    double getWarX() {return wartoscX;};
    double getWarY() {return wartoscY;};
    // void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; }; panu juz podziekujemy
    // Punkt* getPunkt() { return pktPrzylozenia; }; // punkt przyłożenia potrzeby i chuj - sporo uprości
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};

};

class ObcKonstrukcyjne : public Obciazenie
{
//protected:
    Pret* pretPrzylozenia{ nullptr };
    Punkt* pktPozorny{ nullptr };
    double wartoscPoz {0}, wartoscPozX {0}, wartoscPozY {0};
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
    ObcPunktowe(double _wartoscX, double _wartoscY,Punkt* pkt);
    void dodajPunktPrz(Punkt* _pktPrzylozenia) { pktPrzylozenia = _pktPrzylozenia; };
    Punkt* getPunkt() { return pktPrzylozenia; };
};


#endif // OBCIAZENIE_H
