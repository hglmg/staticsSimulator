#ifndef APLIKACJASYMULATORA_H
#define APLIKACJASYMULATORA_H
#include "kontenersiatki.h"
#include "silnikobliczeniowy.h"

class AplikacjaSymulatora
{
    int status {0}; //0 byłoby dla nieuruchomionej, 1 dla działającej, 2 i kolejne dla różnych błędów, można gdzieś zrobić case dekodujący błędy, mozna tez zastapic to enumem
    KontenerSiatki kontener;
    SilnikObliczeniowy silnikFiz;

public:
    AplikacjaSymulatora();
    void uruchom();
    int getStatus() {return status;};
};

#endif // APLIKACJASYMULATORA_H
