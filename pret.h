#ifndef PRET_H
#define PRET_H
#include <vector>
#include <Eigen>
#include <cmath>
#include "punkt.h"

constexpr double PI = 3.141592653589793238462643383279502884197169;


class ObcKonstrukcyjne;

class Pret
{
protected:
    Punkt* pPocz {nullptr};
    Punkt* pKonc {nullptr};

    std::string nazwa {"l"};

    double L {0};

    double d{0};
    double b{0};
    double h{0};

    double E{210e9};
    double A{0.001};
    double I{1e-6}; // przykładowe wartości na stałe do testów, potem doda się ich wyliczanie na podstawie przekroju belki

    double sinus{0};
    double cosinus{0};

    std::vector <ObcKonstrukcyjne*> obc;
    std::vector <int> stSwobody;

    Eigen::Matrix<double,6,6> sztywnoscLokalna;
    Eigen::Matrix<double,6,6> transformacja;
    Eigen::Matrix<double,6,6> sztywnoscGlobalna;

    Eigen::Matrix<double,6,1> wektorObciazenLokalnych;
    Eigen::Matrix<double,6,1> obciazeniaGlobalne;

    void ustawDlugosc(Punkt* _pPocz, Punkt* _pKonc);


public:

    Pret(Punkt* _pPocz, Punkt* _pKonc, std::string nazwa);
    void utworzMacierze();
    Punkt* getPPocz() const {return pPocz;};
    Punkt* getPKonc() const {return pKonc;};
    double getL() const {return L;};
    std::string getNazwa() const {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};

    void dodajObciarzenie(ObcKonstrukcyjne* _obc);
    void ustawMacierzTransformacji();
    std::vector <int> zwrocStopnieSwobody();


    Eigen::MatrixXd zwrocSztywnoscGlobalna() const {return sztywnoscGlobalna;};
    Eigen::MatrixXd zwrocObciorzeniaGlobalne() const {return obciazeniaGlobalne;};


    void wczytajParametry(double _E, double _d); // do prętów kołowych

    double zwroc_d() const {return d;};
    double zwroc_b() const {return b;};
    double zwroc_h() const {return h;};
    double zwroc_E() const {return E;};
};

class PretProstokotny : public Pret
{
    void wczytajParametry(double _E, double _b, double _h); //_h - lokalna wyskokość, _b lokalna szerokość
public:
    PretProstokotny(Punkt* _pPocz, Punkt* _pKonc,double _E, double _b, double _h, std::string nazwa);

};

class PretKolowy : public Pret
{

    void wczytajParametry(double _E, double _d);

public:
    PretKolowy(Punkt* _pPocz, Punkt*,double _E, double _d, std::string nazwa);
};



#endif // PRET_H
