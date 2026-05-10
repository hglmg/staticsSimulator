#include "Konstruktor.h"
#include <iostream>

void Konstruktor::konfiguruj()
{
    //ogólny pomysł jest taki: podpory dodajemy gdzie się chce, a pręty i siły tylko w punktach, które już są dodane

    //testy/denug budowania schematu - na razie while(true) (xD), docelowo event loop

    while(true)
    {
        std::cout <<" Wybierz co chcesz dodac: " << std::endl;
        std::cout << "1.Podpora" << std::endl;
        std::cout << "2.Sila" << std::endl;
        std::cout << "3.Pret" << std::endl;
        std::cout << "4.Punkt na precie" << std::endl;
        std::cout << "5.Break" << std::endl;
        int wybor;
        std::cin >> wybor;
        if(wybor == 1)
        {
            std::cout << "Podaj polozenie podpory(typ przytwierdzenie stale bo na razie nie ma innej): ";
            double x, y;
            std::cin >> x >> y;
            Podpora* podpora = new UtwierdzenieStale(x,y);
            schemat.dodajPodpore(podpora);
        }
        if(wybor == 2)
        {
            std::cout << "Podaj punkt przylozenia sily: ";
            int i = 1;
            for (const auto &punkt : schemat.zwrocPunkty())
            {
                std::cout << i << ": " << punkt->getNazwa() << " [" << punkt->getX() << ";" << punkt->getY() << "]" << std::endl;
                //wszystkie możliwe punkty - tylko w podporze wspujemy z palca, resztę trzeba gdzieś "przykleić"
                //dobre, proste podejśćie, debiloodporne, nie będzie błędów w aplikacji jeśli ktoś pomyli współrzędne
                //nie wymaga stosowania połączeń, ponieważ współrzeDne wszystko zdefiniują
                i++;
            }
            int pkt;
            std::cin >> pkt;
            std::cout << "Podaj sile zdefionowana wektorem: "<< std::endl; // pierwszy punkt to punkt przylozenia, drugi to punkt który trzeba podać
            double x, y;
            std::cin >> x >> y;
            Obciazenie* obc = new ObcPunktowe(x,y,schemat.zwrocPunkty()[pkt-1]);
            schemat.dodajObciazenie(obc);

        }
        if(wybor == 3)
        {
            std::cout << "Wybierz początek preta: " << std::endl;
            int i = 1;
            for (const auto &punkt : schemat.zwrocPunkty())
            {
                std::cout << i << ": " << punkt->getNazwa() << " [" << punkt->getX() << ";" << punkt->getY() << "]" << std::endl;
                i++;
            }
            int pkt;
            std::cin >> pkt;
            std::cout << "Podaj wsp punktu koncowego: ";
            double x, y;
            std::cin >> x >> y;
            Punkt* pom = new Punkt(x,y,"P");
            Pret* obc = new Pret(schemat.zwrocPunkty()[pkt-1],pom);
            schemat.dodajPret(obc);
        }
        if(wybor == 4)
        {
        std::cout << "Wybierz pret: " << std::endl;
        int i = 1;
        for (const auto &pret : schemat.zwrocPrety())
        {
           std::cout << i << ": " << pret->getNazwa() << " " << pret->getL() << std::endl;
            i++;
        }
        int pret;//kolego, pisze sie pręt nie prent XD
        std::cin >> pret;
        std::cout << "Podaj odleglosc od punktu poczatkowgo na precie: ";
        double l;
        std::cin >> l;
        schemat.zwrocPrety()[pret-1]->dodajPunkt(l);
        }
        if (wybor == 5)
            break;

        schemat.kasujPunkty();
        for(const auto &podpory : schemat.zwrocPodpory())
        {
            schemat.dodajPunkt(podpory->zwrocPunkt());
        }
        for(const auto &pret : schemat.zwrocPrety())
        {
            int i = 0;
            for(const auto &punkty : pret->zwrocPunkty())
            {
                schemat.dodajPunkt(pret->zwrocPunkty()[i]);
                i++;
            }

        }
    }





}
