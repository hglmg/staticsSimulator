#ifndef SILNIKOBLICZENIOWY_H
#define SILNIKOBLICZENIOWY_H
#include <iostream>
#include <Eigen>
#include "kontenersiatki.h"

//silnik bedzie rozwiązywał układ metodą elementów skończonych (MES) co pozwoli na wyliczasie sił podporowych, ugieć i okkształceń
//dla dowolnychj układów niewyznaczalnych statycznie
class SilnikObliczeniowy // wywaliłem to co zrobiłeś bo się nie przyda
{
    KontenerSiatki* schemat{nullptr};

    Eigen::MatrixXd macierzGlobalna; // nie, Matrix Xd to nie żart, tylko struktura danych // globalna macierz sztywności
    Eigen::VectorXd wektorObciarzen; //globalny wektor obiążen przyłożonych w punktach
    Eigen::VectorXd wektorPrzemieszczen; //przemieszczenia punktów (zależne od sztywności oraz obciążeń)
    Eigen::VectorXd wektorReakcji; // wartości sił reakcji w każdym z punktów

    Eigen::MatrixXd macierzGlobalna_podpory;
    Eigen::VectorXd wektorObciarzen_podpory; // to posłuży do wyznaczenia przemieszczen
    //początkowa kopie macierzGlobalna i wektorObciarzen, potem modyfikujemy

    void numerujStopnieSwobody();    //potrzebne do tworzenia globalnej macierzy
    void zbudujMacierzGlobalna();
    void zbudujWektorObciarzen();
    void narzucWarunkiBrzegowe();    // tu uwzględniamy stopnie swobody podpór
    void wyznaczPrzemieszczenia();
    void wyznaczReakcjePodporowe();




public:
    SilnikObliczeniowy() = default;
    void rozwiaz();
    void konfiguruj(KontenerSiatki *_schemat);

};

#endif // SILNIKOBLICZENIOWY_H
