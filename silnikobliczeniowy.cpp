#include "silnikobliczeniowy.h"

void SilnikObliczeniowy::konfiguruj(KontenerSiatki *_schemat)
{
    schemat = _schemat;
}

void SilnikObliczeniowy::numerujStopnieSwobody()
{

    int numer = 0;
    for(const auto &punkt : schemat->zwrocPunkty())
    {
        punkt->nazwijStopienSwodoby_x(numer++);
        punkt->nazwijStopienSwodoby_y(numer++);
        punkt->nazwijStopienSwodoby_obr(numer++);
    }
}

void SilnikObliczeniowy:: zbudujMacierzGlobalna()
{
    numerujStopnieSwobody();
    const int N = 6;
    int n = schemat->policzStopnieSwobody(); //pobranie całkowitej liczby stopni swobody układu


    //dla belki 2D 3*stopnie swobody
    macierzGlobalna = Eigen::MatrixXd::Zero(n,n); // tworzenioe globalnej macierzy dla całego układu wypełnionej zerami

    for(const auto& p : schemat->zwrocPrety())
    {
        int stSwobody[N] = // wektor indeksów stopni swobody dla danego pręta
        {
            // to co robiliśmy cały 1 semestr, czyli tablica ststyczna (btw drugi raz użyłem na prog.2)
            p->zwrocPunkty()[0]->zwrocStopienSwobody_x(),
            p->zwrocPunkty()[0]->zwrocStopienSwobody_y(),
            p->zwrocPunkty()[0]->zwrocStopienSwobody_obr(), //pierwszy punkt w pręcie to jego początek

            p->zwrocPunkty()[1]->zwrocStopienSwobody_x(),
            p->zwrocPunkty()[1]->zwrocStopienSwobody_y(),
            p->zwrocPunkty()[1]->zwrocStopienSwobody_obr() // a drugi to koniec
        };

        auto macierzGlobalnaPreta = p->zwrocSztywnoscGlobalna(); // outo, najłatwiej, bo nie znamy rozmiaru macierzy
        //trzebna by ją zwracać a auto dobierze samo
        //mogłem bez zmiennej pomocniczej ale jest czytelniej


        for (unsigned int i = 0; i < N; i++)
        {
            for(unsigned int j = 0; j < N; j++)
            {
                macierzGlobalna(stSwobody[i],stSwobody[j]) +=  macierzGlobalnaPreta(i,j);

                //globalnym indeksom stopnia swobody dużej tablicy przypisuje te, z danego pręta
                //+=, bo wiele elementów może wpływac na ten sampunkt i modyfikowac macierz
                // ten sam punkt może należeć do kilku prętów i będzie modyfikowany kilkukrotnie
            }

        }
    }

    macierzGlobalna_podpory = macierzGlobalna;


}

void SilnikObliczeniowy::zbudujWektorObciarzen()
{
    int n = schemat->policzStopnieSwobody();
    wektorObciarzen = Eigen::VectorXd::Zero(n); //wektor zer

    for(const auto &p : schemat->zwrocPunkty())
    {
        wektorObciarzen(p->zwrocStopienSwobody_x()) = p->zwrocSila_x();
        wektorObciarzen(p->zwrocStopienSwobody_y()) = p->zwrocSila_y();
        wektorObciarzen(p->zwrocStopienSwobody_obr()) = p->zwrocMoment_obr(); // wrzucamy wszystkie siły do jednego wektora
    }


    wektorObciarzen_podpory = wektorObciarzen;
}

void SilnikObliczeniowy::narzucWarunkiBrzegowe() // ma modyfikować kopie macierzy globalnych
{
    //przypisujemy warunki początkowe, np. dla utwierdzenia słaego ruch w każej osi jest równy zero
    //rozważamy typy podpór, i dla każdego modyfikujemy globalną macierz przemieszczeń tak, aby
    //wymusić określone ruchy


    for(const auto podpora : schemat->zwrocPodpory())
    {
        Punkt* p = podpora->zwrocPunkt(); // to co pisałem w podporze - podpora nie przechowuje nic
        //ważny jest punkt na podporze

        if(podpora->zwrocBlok_x())
        {
            int i = p->zwrocStopienSwobody_x();
            macierzGlobalna_podpory.row(i).setZero();
            macierzGlobalna_podpory.col(i).setZero(); // zerujemy rząd i kolumne, odpowiadającą uwiazaniu na podporze

            macierzGlobalna_podpory(i,i) = 1;
            wektorObciarzen_podpory(i) = 0; // te warunki wymuszają brak ruchu w punkcie podpory

            // https://pl.wikipedia.org/wiki/Metoda_element%C3%B3w_sko%C5%84czonych

            //aby wyliczyć przemieszczenia równanie macierzowe

            //macierzGlobalna * /przesunięcia/ = wektorObciazen
            //dajemy macierz na 1
            //wektor na 0
            //więc przesunięcie wyjdzie zerowe


        }

        if(podpora->zwrocBlok_y()) // to samo dla y i obrotu
        {
            int i = p->zwrocStopienSwobody_y();
            macierzGlobalna_podpory.row(i).setZero();
            macierzGlobalna_podpory.col(i).setZero();

            macierzGlobalna_podpory(i,i) = 1;
            wektorObciarzen_podpory(i) = 0;
        }

        if(podpora->zwrocBlok_obr())
        {
            int i = p->zwrocStopienSwobody_obr();
            macierzGlobalna_podpory.row(i).setZero();
            macierzGlobalna_podpory.col(i).setZero();

            macierzGlobalna_podpory(i,i) = 1;
            wektorObciarzen_podpory(i) = 0;
        }

    }

}

void SilnikObliczeniowy::wyznaczPrzemieszczenia()
{
    int i;
    double war;
    for(const auto &p : schemat->zwrocPunkty())
    {
        i = p->zwrocStopienSwobody_x();
        war = wektorPrzemieszczen(i);
        p->ustawPrzemieszczenie_x(war);

        i = p->zwrocStopienSwobody_y();
        war = wektorPrzemieszczen(i);
        p->ustawPrzemieszczenie_y(war);

        i = p->zwrocStopienSwobody_obr();
        war = wektorPrzemieszczen(i);
        p->ustawPrzemieszczenie_obr(war); // zapisuje wartości przemieszczeń do punktów - pozwli na graficze
        //przeunięcie ich na ui

    }
}

void SilnikObliczeniowy::wyznaczReakcjePodporowe()
{
    wektorReakcji = macierzGlobalna * wektorPrzemieszczen - wektorObciarzen;
    //wyznacza globalny wektor reakcji w punktach
    //kożysta z zależności R = Ku - F
    int i;
    double war;
    for(const auto & p : schemat->zwrocPunkty())
    {
        i = p->zwrocStopienSwobody_x();
        war = wektorReakcji(i);
        p->ustawReakcje_x(war);


        i = p->zwrocStopienSwobody_y();
        war = wektorReakcji(i);
        p->ustawReakcje_y(war);


        i = p->zwrocStopienSwobody_obr();
        war = wektorReakcji(i);
        p->ustawReakcje_obr(war);

    }

}


void SilnikObliczeniowy::rozwiaz()
{

    if (schemat == nullptr)
    {
        std::cerr << "Brak konfiguracji silnika! (rozwiaz)" << std::endl;
        return;
    }


    zbudujMacierzGlobalna();

    zbudujWektorObciarzen();

    narzucWarunkiBrzegowe();


    wektorPrzemieszczen = macierzGlobalna_podpory.colPivHouseholderQr().solve(wektorObciarzen_podpory); // rozwiązanie równania macierzowego
    //macierzGlobalna * /przesunięcia/ = wektorObciazen
    //wektor przemieszczen zawiera przemieszczenia w danym punckie
    //colPivHouseholderQr() to funkcja do rozwiązywania równań macierzowych

    wyznaczPrzemieszczenia();
    wyznaczReakcjePodporowe();

}
















