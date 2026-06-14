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

void KontenerSiatki::kasujWybranyPkt(int index)
{
    if (punkty.empty()) return;
    if(punkty[index] == nullptr) return;
    punkty.erase(punkty.begin() + index);
}

void KontenerSiatki::kasujWybranyPret(int index)
{
    if(prety.empty()) return;
    if(prety[index]==nullptr) return;
    prety.erase(prety.begin() + index);
}

void KontenerSiatki::kasujWybranaPodpore(int index)
{
    if(podpory.empty()) return;
    if(podpory[index] == nullptr) return;
    podpory.erase(podpory.begin() + index);

}
#include <Qdebug>
void KontenerSiatki::kasujWybranaObciazenie(int index)
{

    if(obciazenia.empty()) return;
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

    indexySil.clear();
    indexySil.resize(0);

    indexyMomentow.clear();
    indexyMomentow.resize(0);

    indexyObciazen.clear();
    indexyObciazen.resize(0);


}


































