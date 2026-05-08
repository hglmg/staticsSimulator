#ifndef SILNIKOBLICZENIOWY_H
#define SILNIKOBLICZENIOWY_H

class SilnikObliczeniowy
{
    int status {0};//mozna zrobic integerem, mozna zrobic enum, bez znaczenia imo, ify beda takie same
public:
    SilnikObliczeniowy();
    int getStatus() {return status;};
    void inicjalizuj();//byloby odpowiedzialne za wczytanie liczb i wartosci do obliczen moze?
    void obliczReakcje();//puste, na razie jeszcze nie wiem co i jak to dac
};

#endif // SILNIKOBLICZENIOWY_H
