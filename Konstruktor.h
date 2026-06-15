#ifndef KONSTRUKTOR_H
#define KONSTRUKTOR_H
#include "kontenersiatki.h"
#include "punkt.h"
#include "podpora.h"
#include "pret.h"
#include <fstream>
class KontenerSiatki;

class Konstruktor
{
    KontenerSiatki schemat;
public:
    Konstruktor() = default;
    KontenerSiatki* Kontener() { return &schemat; };

    void wczytaj(std::string nazwaPliku);
    void zapiszSchemat(std::string nazwaPliku);

    void dodajPunkt();
    void dodajPret(Punkt* pocz, Punkt* konc, double E, double d, std::string nazwa);
    void dodajPret(Punkt* pocz, Punkt* konc, double E, double b, double h, std::string nazwa);
    void dodajPodpore(Punkt* _pozycja, int typeIndex, bool lockedX);
    void dodajPunkt(Punkt* nowy);
    void dodajPunkt(double _x, double _y, std::string _nazwa);
    void dodajObcPunktowe(double _x, double _y, Punkt* punkt,std::string _nazwa);
    void dodajObcKonstrukcyjne(double _x, double _y, Pret* pret, std::string _nazwa);
    void dodajMomentSkupiony(double war, Punkt* punkt, std::string _nazwa);
    void usunObcKonstrukcyjne(int);
    void usunObcPunktowe(int);
    void usunMomentSkupiony(int);
};




#endif // KONSTRUKTOR_H