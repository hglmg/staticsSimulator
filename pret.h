#ifndef PRET_H
#define PRET_H
#include <vector>
#include <Eigen>
#include <cmath>
#include "punkt.h"
class ObcKonstrukcyjne;

class Pret
{
    Punkt* pPocz {nullptr};
    Punkt* pKonc {nullptr};

    std::string nazwa {"l"};
    std::vector <Punkt*> punkty;

    double L {0};

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

    void utworzMacierze();
public:

    Pret(Punkt* _pPocz, Punkt* _pKonc);

    double getL() {return L;};
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
    void dodajPunkt(double odleglosc); // trzeba bedzie to zmienić - dodanie punktu w połowie musi dzielić pręt na dwa nowe
    //trzeba będzie uwzględnić w kontruktorze inną logikę dodawania punktu, ale to jest do zrobienia
    //dopuki tego się nie zrobi, to silnik ignoruje siły z punktów nie będących początkami i końami pręta
    void dodajObciarzenie(ObcKonstrukcyjne* _obc);

    std::vector <Punkt*> zwrocPunkty(){return punkty;};
    std::vector <int> zwrocStopnieSwobody();


    Eigen::MatrixXd zwrocSztywnoscGlobalna(){return sztywnoscGlobalna;};
    Eigen::MatrixXd zwrocObciorzeniaGlobalne(){return obciazeniaGlobalne;};

    //dla obiążeń konstrukcyjnych: będzie działac analogicznie jak
    //w przypadku macierzy sztywności globalnej
    //jak odpowiednio zaimlementujemy, to silnik łyknie bez rónicy
    //ale to w przyszłym tygodniu - najpierw niech zacznie liczyć
};


#endif // PRET_H
