#ifndef APLIKACJASYMULATORA_H
#define APLIKACJASYMULATORA_H
#include "silnikobliczeniowy.h"
#include "Konstruktor.h"

class AplikacjaSymulatora
{

    SilnikObliczeniowy silnikFiz; // silnik i kontener są prywatne, trzeba będzie dorobić metody dające dostęp
    Konstruktor konstruktor;

public:
    int status {0}; //0 byłoby dla nieuruchomionej, 1 dla działającej, 2 i kolejne dla różnych błędów, można gdzieś zrobić case dekodujący błędy, mozna tez zastapic to enumem

    AplikacjaSymulatora();
    void uruchom();
    int getStatus() {return status;};
    SilnikObliczeniowy* getSilnik() { return &silnikFiz; };//mowisz masz, metody z dostepem
    KontenerSiatki* getSchemat() { return konstruktor.Kontener(); };
};

#endif // APLIKACJASYMULATORA_H
