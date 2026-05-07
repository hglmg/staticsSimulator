#ifndef APLIKACJASYMULATORA_H
#define APLIKACJASYMULATORA_H

class AplikacjaSymulatora
{
    int status {0}; //0 byłoby dla nieuruchomionej, 1 dla działającej, 2 i kolejne dla różnych błędów, można gdzieś zrobić case dekodujący błędy
public:
    AplikacjaSymulatora();
    void uruchom();
    int getStatus() {return status;};
};

#endif // APLIKACJASYMULATORA_H
