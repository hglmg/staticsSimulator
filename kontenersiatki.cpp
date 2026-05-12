#include "kontenersiatki.h"

KontenerSiatki::KontenerSiatki() {}


void KontenerSiatki::dodajPunkt(Punkt* nowyPunkt)//ostatni bool jest dla jakiegos alertu dla logu aplikacji czy coś, choćby "INFO: konflikt nazwy, zapisano jako <zmieniona nazwa>
{
   punkty.push_back(nowyPunkt);
}
void KontenerSiatki::dodajPret(Pret* nowyPret)
{
    prety.push_back(nowyPret);
}

void KontenerSiatki::dodajObciazenie(Obciazenie* noweObc)
{

   obciazenia.push_back(noweObc);
}

void KontenerSiatki::dodajPodpore(Podpora* pod)
{
    podpory.push_back(pod);
}
void KontenerSiatki::kasujPunkty()
{
    punkty.clear();
    punkty.resize(0);
}



int KontenerSiatki::policzStopnieSwobody()
{
    return punkty.size() * 3; //w naszym układzie 2D każdy punkt ma 3 stopnie swobody
    //jeśli bedziemy chceli rozbudować o
}


































