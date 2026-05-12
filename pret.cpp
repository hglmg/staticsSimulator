#include "pret.h"




Pret::Pret(Punkt* _pPocz, Punkt* _pKonc)
{
    pPocz = _pPocz;
    pKonc = _pKonc;
    L = sqrt((pow((_pKonc->getY()-_pPocz->getY()), 2) + pow((_pKonc->getX()-_pPocz->getX()), 2)));
    punkty.push_back(pPocz);
    punkty.push_back(pKonc);

    cos = (pKonc->getX() - pPocz->getX())/L;
    sin = (pKonc->getY() - pPocz->getY())/L;
    utworzMacierze();



}

void Pret::dodajPunkt(double odleglosc) // tworzymy punkt w konkretnej odległości od początku pręta, i wiąrze go z prętem
{
    double A [2];
    A[0] = ((pKonc->getX() - pPocz->getX())/L);
    A[1] = ((pKonc->getY() - pPocz->getY())/L); // wektor jednostkowy
    Punkt* nowy = new Punkt((pPocz->getX() + odleglosc*A[0]),(pPocz->getY() + odleglosc*A[1]),"P");
    punkty.push_back(nowy);
}

void Pret::utworzMacierze()
{

    //czarna magia - tworzenie macierzy lokalnej zgodnie z metodą elementów skończonych
    //algorytm z profesjonalnych programów do obliczeń zmęczeniowych
    double L2 = L*L;
    double L3 = L2*L; // przypisanie L^2 i L^3

    sztywnoscLokalna(0,0) = (E*A)/L;
    sztywnoscLokalna(0,1) = 0;
    sztywnoscLokalna(0,2) = 0;
    sztywnoscLokalna(0,3) = -(E*A)/L;
    sztywnoscLokalna(0,4) = 0;
    sztywnoscLokalna(0,5) = 0;

    sztywnoscLokalna(1,0) = 0;
    sztywnoscLokalna(1,1) = (12*E*I)/L3;
    sztywnoscLokalna(1,2) = (6*E*I)/L2;
    sztywnoscLokalna(1,3) = 0;
    sztywnoscLokalna(1,4) = -(12*E*I)/L3;
    sztywnoscLokalna(1,5) = (6*E*I)/L2;

    sztywnoscLokalna(2,0) = 0;
    sztywnoscLokalna(2,1) = (6*E*I)/L2;
    sztywnoscLokalna(2,2) = (4*E*I)/L;
    sztywnoscLokalna(2,3) = 0;
    sztywnoscLokalna(2,4) = -(6*E*I)/L2;
    sztywnoscLokalna(2,5) = (2*E*I)/L;

    sztywnoscLokalna(3,0) = -(E*A)/L;
    sztywnoscLokalna(3,1) = 0;
    sztywnoscLokalna(3,2) = 0;
    sztywnoscLokalna(3,3) = (E*A)/L;
    sztywnoscLokalna(3,4) = 0;
    sztywnoscLokalna(3,5) = 0;

    sztywnoscLokalna(4,0) = 0;
    sztywnoscLokalna(4,1) = -(12*E*I)/L3;
    sztywnoscLokalna(4,2) = -(6*E*I)/L2;
    sztywnoscLokalna(4,3) = 0;
    sztywnoscLokalna(4,4) = (12*E*I)/L3;
    sztywnoscLokalna(4,5) = -(6*E*I)/L2;

    sztywnoscLokalna(5,0) = 0;
    sztywnoscLokalna(5,1) = (6*E*I)/L2;
    sztywnoscLokalna(5,2) = (2*E*I)/L;
    sztywnoscLokalna(5,3) = 0;
    sztywnoscLokalna(5,4) = -(6*E*I)/L2;
    sztywnoscLokalna(5,5) = (4*E*I)/L;

    //tworzenie macierzy transformacji (do zamiany lokalnego układu współrzędnych na układ globalny)

    transformacja(0,0) = cos;
    transformacja(0,1) = sin;
    transformacja(0,2) = 0;
    transformacja(0,3) = 0;
    transformacja(0,4) = 0;
    transformacja(0,5) = 0;

    transformacja(1,0) = -sin;
    transformacja(1,1) = cos;
    transformacja(1,2) = 0;
    transformacja(1,3) = 0;
    transformacja(1,4) = 0;
    transformacja(1,5) = 0;

    transformacja(2,0) = 0;
    transformacja(2,1) = 0;
    transformacja(2,2) = 1;
    transformacja(2,3) = 0;
    transformacja(2,4) = 0;
    transformacja(2,5) = 0;

    transformacja(3,0) = 0;
    transformacja(3,1) = 0;
    transformacja(3,2) = 0;
    transformacja(3,3) = cos;
    transformacja(3,4) = sin;
    transformacja(3,5) = 0;

    transformacja(4,0) = 0;
    transformacja(4,1) = 0;
    transformacja(4,2) = 0;
    transformacja(4,3) = -sin;
    transformacja(4,4) = cos;
    transformacja(4,5) = 0;

    transformacja(5,0) = 0;
    transformacja(5,1) = 0;
    transformacja(5,2) = 0;
    transformacja(5,3) = 0;
    transformacja(5,4) = 0;
    transformacja(5,5) = 1;

    sztywnoscGlobalna = transformacja.transpose() * sztywnoscLokalna * transformacja; // przeliczenie macierzy
    //z lokalnego układu pręta na układ globalny




}

