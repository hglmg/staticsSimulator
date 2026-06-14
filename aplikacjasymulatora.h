#ifndef APLIKACJASYMULATORA_H
#define APLIKACJASYMULATORA_H
#include "silnikobliczeniowy.h"
#include "Konstruktor.h"

class AplikacjaSymulatora
{

    SilnikObliczeniowy silnikFiz;
    Konstruktor konstruktor;

public:
    int status {0}; //0 byłoby dla nieuruchomionej, 1 dla działającej, 2 i kolejne dla różnych błędów, można gdzieś zrobić case dekodujący błędy, mozna tez zastapic to enumem

    AplikacjaSymulatora();
    void uruchom();
    int getStatus() {return status;};
    SilnikObliczeniowy* getSilnik() { return &silnikFiz; };
    KontenerSiatki* getSchemat() { return konstruktor.Kontener(); };
    Konstruktor* getKonstruktor() {return &konstruktor;};

};

#endif // APLIKACJASYMULATORA_H
