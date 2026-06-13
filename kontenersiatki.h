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

    std::vector<unsigned int> indexySil;
    std::vector<unsigned int>indexyMomentow;
    std::vector<unsigned int> indexyObciazen;

    void dodajIndexSil(unsigned int _index) {indexySil.push_back(_index);};
    void dodajIndexMomentow(unsigned int _index) {indexyMomentow.push_back(_index);};
    void dodajIndexObciazen(unsigned int _index) {indexyObciazen.push_back(_index);};



public://wiem ze te metody nie sa po polimorficznemu, moze da sie to jakos uproscic
    KontenerSiatki();
    // std::string nameControl(); mozna to zrobic, tylko trzeba zrobic interfejs dla punktow pretow i obciazen jakos
    void dodajPunkt(Punkt*);
    void dodajPret(Pret* nowyPret);
    void dodajObciazenie(Obciazenie* noweObc);
    void dodajPodpore(Podpora* pod);

    void kasujPunkty();
    void kasujWybranyPkt(int index) { punkty.erase(punkty.begin() + index); };
    void kasujWybranyPret(int index) { prety.erase(prety.begin() + index); };
    void kasujWybranaPodpore(int index) { podpory.erase(podpory.begin() + index); };
    void kasujWybranaObciazenie(int index) {obciazenia.erase(obciazenia.begin()+index);};
    void kasujWybranaObciazenie(int index, typObciazenia _typ);

    std::vector <Punkt*> zwrocPunkty() {return punkty;};
    std::vector <Pret*> zwrocPrety() {return prety;};
    std::vector <Podpora*> zwrocPodpory() {return podpory;};
    std::vector <Obciazenie*> zwrocObciazenia() { return obciazenia; };

    std::vector <unsigned int> indekxySil(){return indexySil;};
    std::vector <unsigned int> indekxyMomentow(){return indexyMomentow;};
    std::vector <unsigned int> indekxyObciazen(){return indexyObciazen;};

    int policzStopnieSwobody();




};

#endif // KONTENERSIATKI_H
