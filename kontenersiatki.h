#ifndef KONTENERSIATKI_H
#define KONTENERSIATKI_H
#include <vector>
#include "podpora.h"
#include "punkt.h"
#include "pret.h"
#include "obciazenie.h"

class KontenerSiatki
{
    std::vector<Punkt*> punkty;
    std::vector<Pret*> prety;
    std::vector<Obciazenie*> obciazenia;//mozna tez zamienic to na map, ale nie wiem czy to cos tutaj by dalo
    std::vector<Podpora*> podpory;

public://wiem ze te metody nie sa po polimorficznemu, moze da sie to jakos uproscic
    KontenerSiatki();
    // std::string nameControl(); mozna to zrobic, tylko trzeba zrobic interfejs dla punktow pretow i obciazen jakos
    void dodajPunkt(Punkt*);
    void dodajPret(Pret* nowyPret);
    void dodajObciazenie(Obciazenie* noweObc);
    void dodajPodpore(Podpora* pod);
    void kasujPunkty(){punkty.clear();};
    void kasujPodporePocz() { podpory.erase(podpory.begin()); };
    void kasujPodporeKonc() { podpory.pop_back(); };
    //std::vector<double> getObcX();
    //std::vector<double> getObcY();
    //odnośnie błędu można po prostu zrobić 3 różne kontenery na różne obiążenie
    std::vector <Punkt*> zwrocPunkty() {return punkty;};
    std::vector <Pret*> zwrocPrety() {return prety;};
    std::vector <Podpora*> zwrocPodpory() {return podpory;};
    std::vector <Obciazenie*> zwrocObciazenia() { return obciazenia; };





};

#endif // KONTENERSIATKI_H
