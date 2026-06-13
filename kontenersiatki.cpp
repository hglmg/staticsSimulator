#include "kontenersiatki.h"

KontenerSiatki::KontenerSiatki() {}


void KontenerSiatki::dodajPunkt(Punkt* nowyPunkt)
{
   punkty.push_back(nowyPunkt);
}
void KontenerSiatki::dodajPret(Pret* nowyPret)
{
    prety.push_back(nowyPret);
}

void KontenerSiatki::dodajObciazenie(Obciazenie* noweObc)
{
    // enum {momentSkupiony, silaSkupiona, konstrukcyjne}

    obciazenia.push_back(noweObc);
    int typ = noweObc->typ;
    switch(typ)
    {
    case momentSkupiony:
    {
        dodajIndexMomentow(obciazenia.size()-1);
        break;
    }
    case silaSkupiona:
    {
        dodajIndexSil(obciazenia.size()-1);
        break;
    }
    case konstrukcyjne:
    {
        dodajIndexObciazen(obciazenia.size()-1);
    }
        default:
            break;
    }




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
    //jeśli bedziemy chceli rozbudować
}

void KontenerSiatki::kasujWybranaObciazenie(int index, typObciazenia _typ)
{
    int ind = -1, realInd = 0;
    for (Obciazenie* wybrane : obciazenia)
    {
        if (wybrane->typ == _typ) ++ind;
        if (ind == index) break;
        realInd++;
    }
    obciazenia.erase(obciazenia.begin() + realInd);
}


































