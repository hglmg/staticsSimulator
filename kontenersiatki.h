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






public:
    KontenerSiatki();

    void dodajPunkt(Punkt*);
    void dodajPret(Pret* nowyPret);
    void dodajObciazenie(Obciazenie* noweObc);
    void dodajPodpore(Podpora* pod);

    void kasujPunkty();
    void kasujWybranyPkt(int index);
    void kasujWybranyPret(int index);
    void kasujWybranaPodpore(int index);
    void kasujWybranaObciazenie(int index);

    std::vector <Punkt*> zwrocPunkty() const {return punkty;};
    std::vector <Pret*> zwrocPrety() const {return prety;};
    std::vector <Podpora*> zwrocPodpory() const {return podpory;};
    std::vector <Obciazenie*> zwrocObciazenia() const { return obciazenia; };

    int policzStopnieSwobody();
    void wyczyscSchemat();




};

#endif // KONTENERSIATKI_H
