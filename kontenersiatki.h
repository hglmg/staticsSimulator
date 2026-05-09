#ifndef KONTENERSIATKI_H
#define KONTENERSIATKI_H
#include <deque>
#include "punkt.h"
#include "pret.h"
#include "obciazenie.h"

class KontenerSiatki
{
    std::deque<Punkt*> punkty;
    std::deque<Pret*> prety;
    std::deque<Obciazenie*> obciazenia;//mozna tez zamienic to na map, ale nie wiem czy to cos tutaj by dalo

public://wiem ze te metody nie sa po polimorficznemu, moze da sie to jakos uproscic
    KontenerSiatki();
    // std::string nameControl(); mozna to zrobic, tylko trzeba zrobic interfejs dla punktow pretow i obciazen jakos
    void dodajPunkt(Punkt* nowyPunkt, double _x, double _y, std::string _nazwa, bool& nameChangeForced);
    void dodajPret(Pret* nowyPret, Punkt* _pPocz, Punkt* _pKonc, std::string _nazwa, bool& nameChangeForced);
    void dodajObciazenie(Obciazenie* noweObc, double _wartoscX, double _wartoscY, std::string _nazwa, bool& nameChangeForced);
    std::deque<double> getObcX();//imo calkiem optymalne rozwiazanie, ale może jest jakiś lepszy sposób
    std::deque<double> getObcY();
    std::deque<double> getObcY();

};

#endif // KONTENERSIATKI_H
