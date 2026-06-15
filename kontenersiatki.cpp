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

void KontenerSiatki::kasujWybranyPkt(int index)
{
    if (punkty.empty()|| index < 0) return;
    if(punkty[index] == nullptr) return;
    punkty.erase(punkty.begin() + index);
}

void KontenerSiatki::kasujWybranyPret(int index)
{
    if(prety.empty() || index < 0) return;
    if(prety[index]==nullptr) return;
    prety.erase(prety.begin() + index);
}

void KontenerSiatki::kasujWybranaPodpore(int index)
{
    if(podpory.empty() || index < 0) return;
    if(podpory[index] == nullptr) return;
    podpory.erase(podpory.begin() + index);

}
#include <Qdebug>
void KontenerSiatki::kasujWybranaObciazenie(int index)
{

    if(obciazenia.empty() || index < 0) return;
    qDebug() << index;
    if(obciazenia[index] == nullptr) return;
    obciazenia.erase(obciazenia.begin() + index);

}

void KontenerSiatki::wyczyscSchemat()
{
    punkty.clear();
    punkty.resize(0);

    prety.clear();
    prety.resize(0);

    podpory.clear();
    podpory.resize(0);

    obciazenia.clear();
    obciazenia.resize(0);


}


































