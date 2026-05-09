#include "kontenersiatki.h"

KontenerSiatki::KontenerSiatki() {}


void KontenerSiatki::dodajPunkt(Punkt* nowyPunkt, double _x, double _y, std::string _nazwa, bool& nameChangeForced)//ostatni bool jest dla jakiegos alertu dla logu aplikacji czy coś, choćby "INFO: konflikt nazwy, zapisano jako <zmieniona nazwa>
{
    nowyPunkt = new Punkt(_x, _y);
    punkty.push_back(nowyPunkt);
    for (Punkt* kontrolny : punkty)
    {
        if (kontrolny->getNazwa() == _nazwa) nameChangeForced = false;//sprawdza czy jest już taka nazwa
    }
    if (nameChangeForced) _nazwa.push_back('-');//troche old Minecraft style, dodaje srednik na koniec nazwy jesli ta jest juz uzywana, dla tego kodu pewnie lepiej by wyszlo gdyby zamiast deque bylo map
    nowyPunkt->modyfikujNazwe(_nazwa);//na koniec zmienia nazwe. Rozdzielenie tego od konstruktora moze nie byc optymalne, ale idk na razie

}
void KontenerSiatki::dodajPret(Pret* nowyPret, Punkt* _pPocz, Punkt* _pKonc, std::string _nazwa, bool& nameChangeForced)
{
    nowyPret = new Pret(_pPocz, _pKonc);
    for (Pret* kontrolny : prety)
    {
        if (kontrolny->getNazwa() == _nazwa) nameChangeForced = false;//sprawdza czy jest już taka nazwa
    }
    if (nameChangeForced) _nazwa.push_back('-');
    nowyPret->modyfikujNazwe(_nazwa);

}

void KontenerSiatki::dodajObciazenieP(ObciazeniePunktowe* noweObc, double _wartoscX, double _wartoscY, std::string _nazwa, bool& nameChangeForced)
{
    noweObc = new ObciazeniePunktowe(_wartoscX, _wartoscY);
    for (ObciazeniePunktowe* kontrolne : obcPunktowe)
    {
        if (kontrolne->getNazwa() == _nazwa) nameChangeForced = false;
    }
    if (nameChangeForced) _nazwa.push_back('-');
    noweObc->modyfikujNazwe(_nazwa);

}

std::deque<double> KontenerSiatki::getObcPX()
{
    std::deque<double> obcX;
    for (ObciazeniePunktowe* wybrane : obcPunktowe)
    {
        obcX.push_back(wybrane->getWarX());
    }
    return obcX;
}

std::deque<double> KontenerSiatki::getObcPY()
{
    std::deque<double> obcY;
    for (ObciazeniePunktowe* wybrane : obcPunktowe)
    {
        obcY.push_back(wybrane->getWarY());
    }
    return obcY;
}