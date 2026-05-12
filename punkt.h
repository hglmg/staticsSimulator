#ifndef PUNKT_H
#define PUNKT_H
#include <string>
#include <Eigen>

class Punkt
{
    double x {0}, y {0};
    std::string nazwa {"p"};
    //Podpora* podporaPkt {nullptr};//wskaznik na podpore ktora mialaby byc w danym punkcie, moze trzeba to odworcic?
    // to sie chyba nie przyda, lepiej żeby podpora przechowywała info o punkcie, potencjalnie DO ######## ale niech zostanie na razie
    int stopienSwobody_x{-1};
    int stopienSwobody_y{-1};
    int stopienSwobody_obr{-1};

    double przemieszczenie_x{0};
    double przemieszczenie_y{0};
    double przemieszczenie_obr{0}; // w radianach

    double reakcja_x{0};
    double reakcja_y{0};
    double reakcja_obr{0};

    double siła_x{0};
    double siła_y{0};
    double moment_obr{0}; // dodać settery dla sił przyłożonych w punckie,
    //to punkt musi wiedzieć jaka siła na niego działa



public:
    Punkt(double _x, double _y,std::string nazwa);
    double getX() {return x;};
    double getY() {return y;};
    std::string getNazwa() {return nazwa;};
    void modyfikujNazwe(std::string _nazwa) {nazwa = _nazwa;};
    void modyfikujPozycje(double _x, double _y);
    void nazwijStopienSwodoby_x(int numer);
    void nazwijStopienSwodoby_y(int numer);
    void nazwijStopienSwodoby_obr(int numer);

    int zwrocStopienSwobody_x(){return stopienSwobody_x; };
    int zwrocStopienSwobody_y(){return stopienSwobody_y; };
    int zwrocStopienSwobody_obr(){return stopienSwobody_obr; };

    double zwrocSila_x(){return siła_x;};
    double zwrocSila_y(){return siła_y;};
    double zwrocMoment_obr(){return moment_obr;};

    void ustawPrzemieszczenie_x(double x){przemieszczenie_x = x;};
    void ustawPrzemieszczenie_y(double y){przemieszczenie_y = y;};
    void ustawPrzemieszczenie_obr(double obr){przemieszczenie_obr = obr;};

    void ustawReakcje_x(double war) {reakcja_x = war;};
    void ustawReakcje_y(double war){reakcja_y = war;};
    void ustawReakcje_obr(double war){reakcja_obr = war;};


};

#endif // PUNKT_H
