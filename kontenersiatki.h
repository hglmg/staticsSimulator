#ifndef KONTENERSIATKI_H
#define KONTENERSIATKI_H
#include <vector>
#include "podpora.h"
#include "punkt.h"
#include "pret.h"
#include "obciazenie.h"

class KontenerSiatki
{
    std::vector<Punkt*> punkty; //zamaist deque wpuierdole vector - jest fajniejszy, może troche mniej optymalny
    std::vector<Pret*> prety;
    std::vector<Obciazenie*> obciazenia;//mozna tez zamienic to na map, ale nie wiem czy to cos tutaj by dalo
    std::vector<Podpora*> podpory;

public://wiem ze te metody nie sa po polimorficznemu, moze da sie to jakos uproscic
    KontenerSiatki();
    // std::string nameControl(); mozna to zrobic, tylko trzeba zrobic interfejs dla punktow pretow i obciazen jakos
    void dodajPunkt(Punkt*);
    void dodajPret(Pret* nowyPret);
    void dodajObciazenie(Obciazenie* noweObc);
    void dodajPodpore(Podpora* pod); // po chuju troche bo podajesz wskaźnik a poptem tworzysz nowy??? nie wiem, robie po swojemu
    void kasujPunkty(){punkty.clear();};
    std::vector<double> getObcX();//imo calkiem optymalne rozwiazanie, ale może jest jakiś lepszy sposób
    std::vector<double> getObcY();//10-05-2026 pojawia sie teraz problem, bo watosci obciazen konstrukcyjnych to wartosci N/m, a momentow sily - N*m
    //odnośnie błędu można po prostu zrobić 3 różne kontenery na różne obiążenie
    std::vector <Punkt*> zwrocPunkty() {return punkty;};
    std::vector <Pret*> zwrocPrety() {return prety;};
    std::vector <Podpora*> zwrocPodpory() {return podpory;};





};

#endif // KONTENERSIATKI_H
