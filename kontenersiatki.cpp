#include "kontenersiatki.h"

KontenerSiatki::KontenerSiatki() {}


void KontenerSiatki::dodajPunkt(Punkt* nowyPunkt)//ostatni bool jest dla jakiegos alertu dla logu aplikacji czy coś, choćby "INFO: konflikt nazwy, zapisano jako <zmieniona nazwa>
{
   /* nowyPunkt = new Punkt(_x, _y,"P");
    punkty.push_back(nowyPunkt);
    for (Punkt* kontrolny : punkty)
    {
        if (kontrolny->getNazwa() == _nazwa) nameChangeForced = false;//sprawdza czy jest już taka nazwa
    }
    if (nameChangeForced) _nazwa.push_back('-');//troche old Minecraft style, dodaje srednik na koniec nazwy jesli ta jest juz uzywana, dla tego kodu pewnie lepiej by wyszlo gdyby zamiast deque bylo map
    nowyPunkt->modyfikujNazwe(_nazwa);*///na koniec zmienia nazwe. Rozdzielenie tego od konstruktora moze nie byc optymalne, ale idk na razie
   //nie jest optymalne - kontener tylko przechowuje - nic nie tworzy. tworzenie wpierdalasz do kontruktora
   punkty.push_back(nowyPunkt);
}
void KontenerSiatki::dodajPret(Pret* nowyPret)
{
    // nowyPret = new Pret(_pPocz, _pKonc);
    // for (Pret* kontrolny : prety)
    // {
    //     if (kontrolny->getNazwa() == _nazwa) nameChangeForced = false;//sprawdza czy jest już taka nazwa
    // }
    // if (nameChangeForced) _nazwa.push_back('-');
    // nowyPret->modyfikujNazwe(_nazwa);
    prety.push_back(nowyPret);


}

void KontenerSiatki::dodajObciazenie(Obciazenie* noweObc)
{
   /* noweObc = new Obciazenie(_wartoscX, _wartoscY);
    for (Obciazenie* kontrolne : obciazenia)
    {
        if (kontrolne->getNazwa() == _nazwa) nameChangeForced = false;
    }
    if (nameChangeForced) _nazwa.push_back('-');
    noweObc->modyfikujNazwe(_nazwa);*/ // bardziej skłaniam się do tworzenia i przechowywania obciążweń w prętach, tu dodałbym
    //tylko wskaźniki, żeby muc szybko po nich iterować
   obciazenia.push_back(noweObc);


}

std::vector<double> KontenerSiatki::getObcX() // szczeże, zwracanie oddzielnie X i Y nie ma sensu - lepiej zwrócić całośc w postaci punktów i tylko wybrać X lub Y
//polecił bym wypierdolić te funkcjce
{
    std::vector<double> obcX;
    for (Obciazenie* wybrane : obciazenia)
    {
        obcX.push_back(wybrane->getWarX());
    }
    return obcX;
}

std::vector<double> KontenerSiatki::getObcY()
{
    std::vector<double> obcY;
    for (Obciazenie* wybrane : obciazenia)
    {
        obcY.push_back(wybrane->getWarY());
    }
    return obcY;
}
void KontenerSiatki::dodajPodpore(Podpora* pod)
{
    podpory.push_back(pod);
}
