#ifndef PUNKT_H
#define PUNKT_H
#include <Eigen>

class Punkt
{
    double x {0}, y {0};
    std::string nazwa {"p"};


    int stopienSwobody_x{-1};
    int stopienSwobody_y{-1};
    int stopienSwobody_obr{-1};

    double przemieszczenie_x{0};
    double przemieszczenie_y{0};
    double przemieszczenie_obr{0}; // w radianach

    double reakcja_x{0};
    double reakcja_y{0};
    double reakcja_obr{0};

    double sila_x{0};
    double sila_y{0};
    double moment_obr{0};






public:
    Punkt(double _x, double _y,std::string _nazwa);
    double getY() {return y;};
    double getX() {return x;};
    std::string getNazwa() {return nazwa;};

    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
    void zeruj_wartosci();

    void nazwijStopienSwodoby_x(int numer);
    void nazwijStopienSwodoby_y(int numer);
    void nazwijStopienSwodoby_obr(int numer);

    int zwrocStopienSwobody_x(){return stopienSwobody_x; };
    int zwrocStopienSwobody_y(){return stopienSwobody_y; };
    int zwrocStopienSwobody_obr(){return stopienSwobody_obr; };

    void dodajSile_x(double _x){sila_x += _x;};
    void dodajSile_y(double _y){sila_y += _y;};
    void dodajMoment_obr(double obr){moment_obr += obr;};

    double zwrocSila_x(){return sila_x;};
    double zwrocSila_y(){return sila_y;};
    double zwrocMoment_obr(){return moment_obr;};



    void ustawPrzemieszczenie_x(double _x){przemieszczenie_x = _x;};
    void ustawPrzemieszczenie_y(double _y){przemieszczenie_y = _y;};
    void ustawPrzemieszczenie_obr(double obr){przemieszczenie_obr = obr;};

    double zwrocPrzemieszczenie_x(){return przemieszczenie_x;};
    double zwrocPrzemieszczenie_y(){return przemieszczenie_y;};

    double zwrocReakceX() { return reakcja_x;};
    double zwrocReakceY() { return reakcja_y;};
    double zwrocReakceObr() {return reakcja_obr;};

    void ustawReakcje_x(double war) {reakcja_x = war;};
    void ustawReakcje_y(double war){reakcja_y = war;};
    void ustawReakcje_obr(double war){reakcja_obr = war;};




};

#endif // PUNKT_H
