#include "pret.h"
#include "obciazenie.h"




Pret::Pret(Punkt* _pPocz, Punkt* _pKonc,std::string _nazwa)
{
    pPocz = _pPocz;
    pKonc = _pKonc;

    ustawDlugosc(_pPocz, _pKonc);

    nazwa = _nazwa;


}

void Pret::ustawDlugosc(Punkt* _pPocz, Punkt* _pKonc)
{
    L = sqrt((pow((_pKonc->getY()-_pPocz->getY()), 2) + pow((_pKonc->getX()-_pPocz->getX()), 2)));
    punkty.push_back(pPocz);
    punkty.push_back(pKonc);

    cosinus = (pKonc->getX() - pPocz->getX())/L;
    sinus = (pKonc->getY() - pPocz->getY())/L;

    utworzMacierze();
}







void Pret::dodajObciarzenie(ObcKonstrukcyjne* _obc)
{
    obc.push_back(_obc);
}



std::vector <int> Pret::zwrocStopnieSwobody()
{

    stSwobody.clear();
    stSwobody.push_back(pPocz->zwrocStopienSwobody_x());
    stSwobody.push_back(pPocz->zwrocStopienSwobody_y());
    stSwobody.push_back(pPocz->zwrocStopienSwobody_obr());

    stSwobody.push_back(pKonc->zwrocStopienSwobody_x());
    stSwobody.push_back(pKonc->zwrocStopienSwobody_y());
    stSwobody.push_back(pKonc->zwrocStopienSwobody_obr());

    return stSwobody;
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

    transformacja(0,0) = cosinus;
    transformacja(0,1) = sinus;
    transformacja(0,2) = 0;
    transformacja(0,3) = 0;
    transformacja(0,4) = 0;
    transformacja(0,5) = 0;

    transformacja(1,0) = -sinus;
    transformacja(1,1) = cosinus;
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
    transformacja(3,3) = cosinus;
    transformacja(3,4) = sinus;
    transformacja(3,5) = 0;

    transformacja(4,0) = 0;
    transformacja(4,1) = 0;
    transformacja(4,2) = 0;
    transformacja(4,3) = -sinus;
    transformacja(4,4) = cosinus;
    transformacja(4,5) = 0;

    transformacja(5,0) = 0;
    transformacja(5,1) = 0;
    transformacja(5,2) = 0;
    transformacja(5,3) = 0;
    transformacja(5,4) = 0;
    transformacja(5,5) = 1;



    sztywnoscGlobalna = transformacja.transpose() * sztywnoscLokalna * transformacja; // przeliczenie macierzy
    //z lokalnego układu pręta na układ globalny

    //tworzenie wektora obciążeń

    wektorObciazenLokalnych.setZero();

    for (auto* obciazenie : obc) // obciążenia tworzone w lokalnej osi pręta, w UI trzema wymusić podanie loklanych
    //współrzędnych pręta
    {
        double qx = obciazenie->wartoscSily_x();
        double qy = obciazenie->wartoscSily_y();

        wektorObciazenLokalnych[0] += (qx * L) / 2.0;
        wektorObciazenLokalnych[1] += -(qy * L) /2.0;
        wektorObciazenLokalnych[2] += -(qy * L * L) / 12.0;
        wektorObciazenLokalnych[3] += (qx * L) / 2.0;
        wektorObciazenLokalnych[4] += -(qy * L) / 2.0;
        wektorObciazenLokalnych[5] += (qy * L * L) / 12.0;

        //i transformacja do układu globalnego



    }
    obciazeniaGlobalne = transformacja.transpose() * wektorObciazenLokalnych;

}


PretProstokotny::PretProstokotny(Punkt* _pPocz, Punkt* _pKonc, double _E, double _b, double _h,std::string nazwa ) : Pret(_pPocz,_pKonc,nazwa)
{
    wczytajParametry(_E,_b,_h);
}

void PretProstokotny::wczytajParametry(double _E, double _b, double _h) // ew zamiast klas pochodnych można dodać paramtr
//przekroju, który były klasą zaiwerającą dane
{
    E = _E;
    A = _b * _h; // można by też rozszeżyć dla różnych kształtów np dwuetownik albo kątownik ew wycięcia wewnątrz pręta
    double h3 = _h*_h*_h; // uwaga na to co jest _b a co _h
    I =  (_b*h3)/12;
}



PretKolowy:: PretKolowy(Punkt* _pPocz, Punkt* _pKonc,double _E, double _d, std::string nazwa) : Pret(_pPocz,_pKonc,nazwa)
{

    wczytajParametry(_E,_d);
}

void PretKolowy::wczytajParametry(double _E, double _d)
{
    E = _E;
    double r2 = (_d/2.0)*(_d/2.0);
    double d4 = _d*_d*_d*_d;
    A = PI * r2; // można by też rozszeżyć dla różnych kształtów np dwuetownik albo kątownik ew wycięcia wewnątrz pręta
    I =  (PI * d4)/64;
}


