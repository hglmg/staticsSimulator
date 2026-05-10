#include "pret.h"
#include <cmath>



Pret::Pret(Punkt* _pPocz, Punkt* _pKonc)
{
    pPocz = _pPocz;
    pKonc = _pKonc;
    dlugosc = sqrt((pow((_pKonc->getY()-_pPocz->getY()), 2) + pow((_pKonc->getX()-_pPocz->getX()), 2)));
    punkty.push_back(pPocz);
    punkty.push_back(pKonc);

}

void Pret::dodajPunkt(double odleglosc) // tworzymy punkt w konkretnej odległości od początku pręta, i wiąrze go z prętem
{
    double A [2];
    A[0] = ((pKonc->getX() - pPocz->getX())/dlugosc);
    A[1] = ((pKonc->getY() - pPocz->getY())/dlugosc); // wektor jednostkowy
    Punkt* nowy = new Punkt;
    nowy->modyfikujPozycje((pPocz->getX() + odleglosc*A[0]),(pPocz->getY() + odleglosc*A[1]));
    punkty.push_back(nowy);
}