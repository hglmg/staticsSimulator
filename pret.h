#ifndef PRET_H
#define PRET_H
#include <vector>
#include <Eigen>
#include <cmath>
#include "punkt.h"

class Pret
{
    Punkt* pPocz {nullptr};
    Punkt* pKonc {nullptr};

    std::string nazwa {"l"}; // nie wiem po co nadawać nazwy prętom i punktom >>>> chodzi o to zeby byly odroznialne dla uzytkownika w gui, ale jak wolisz >> make sense
    std::vector <Punkt*> punkty; // pierwszy punkt to początek, drugi koniec, reszcza to punkty charakterystyczne

    double L {0}; // zmieniałem nazwę dlugosc na L bo łatwiej pisać we wzorach
    //stale materiałowe
    double E{210e9};
    double A{0.001};
    double I{1e-6}; // przykładowe wartości na stałe do testów, potem doda się ich wyliczanie na podstawie przekroju belki

    double sinus{0};
    double cosinus{0}; // będzie potrzebne w silniku do transformacji

    Eigen::Matrix<double,6,6> sztywnoscLokalna;
    Eigen::Matrix<double,6,6> transformacja;
    Eigen::Matrix<double,6,6> sztywnoscGlobalna;

    void utworzMacierze();
public:

    Pret(Punkt* _pPocz, Punkt* _pKonc);

    double getL() {return L;};
    //double getSin() {return ;};
    //double getCos() {return cos;};

    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
    void dodajPunkt(double odleglosc); // trzeba bedzie to zmienić - dodanie punktu w połowie musi dzielić pręt na dwa nowe
    //trzeba będzie uwzględnić w kontruktorze inną logikę dodawania punktu, ale to jest do zrobienia
    //dopuki tego się nie zrobi, to silnik ignoruje siły z punktów nie będących początkami i końami pręta
    std::vector <Punkt*> zwrocPunkty(){return punkty;};

    Eigen::MatrixXd zwrocSztywnoscGlobalna(){return sztywnoscGlobalna;};

    //dla obiążeń konstrukcyjnych: będzie działac analogicznie jak
    //w przypadku macierzy sztywności globalnej
    //jak odpowiednio zaimlementujemy, to silnik łyknie bez rónicy
    //ale to w przyszłym tygodniu - najpierw niech zacznie liczyć
};


#endif // PRET_H
