#include "Konstruktor.h"
#include "podpora.h"

#include <Qdebug>


void Konstruktor::wczytaj(std::string nazwaPliku)
{

    std::ifstream plik;
    plik.open(nazwaPliku);
    std::string linia;


    while (std::getline(plik,linia))
    {
        std::string wiersz [8] = {"","","","","","","",""};
        int i = 0;
        for (unsigned int j = 0; j < linia.size();j++)
        {

            if(linia[j] != ' ')
            {
                wiersz[i] += linia[j];
            }
            else
                i++;
        }

        if ((wiersz[0][0] == '/' && wiersz[0][1] =='/'))
            continue;

        if (wiersz[0] == "punkt")
        {
            std::string nazwa = wiersz[1];
            double x = stod(wiersz[2]);
            double y = stod(wiersz[3]);
            dodajPunkt(x,y,nazwa);
        }
        else if (wiersz[0] == "pret")
        {
            if(wiersz[1] == "kwadratowy")
            {
                std::string nazwa = wiersz[2];
                double b = stod(wiersz[3]);
                double h = stod(wiersz[4]);
                Punkt* pPocz = schemat.zwrocPunkty()[stoi(wiersz[5])];
                Punkt* pKonc = schemat.zwrocPunkty()[stoi(wiersz[6])];
                double E = stod(wiersz[7]);
                dodajPret(pPocz, pKonc,E,b,h, nazwa);

            }
            else if(wiersz[1] == "kolowy")
            {
                std::string nazwa = wiersz[2];
                double d = stod(wiersz[3]);
                Punkt* pPocz = schemat.zwrocPunkty()[stoi(wiersz[4])];
                Punkt* pKonc = schemat.zwrocPunkty()[stoi(wiersz[5])];
                double E = stod(wiersz[6]);
                dodajPret(pPocz, pKonc,E,d, nazwa);
            }

        }
        else if(wiersz[0] == "sila")
        {
            std::string nazwa = wiersz[1];
            double x = stod(wiersz[2]);
            double y = stod(wiersz[3]);
            Punkt* punkt = schemat.zwrocPunkty()[stoi(wiersz[4])];
            dodajObcPunktowe(x,y, punkt,nazwa);

        }
        else if(wiersz[0]== "moment")
        {
            std::string nazwa = wiersz[1];
            double wartosc = stod(wiersz[2]);
            Punkt* punkt = schemat.zwrocPunkty()[stoi(wiersz[3])];
            dodajMomentSkupiony(wartosc,punkt,nazwa);
        }
        else if(wiersz[0] == "obcKonstrukcyjne")
        {
            std::string nazwa = wiersz[1];
            double x = stod(wiersz[2]);
            double y = stod(wiersz[3]);
            Pret* pret = schemat.zwrocPrety()[stoi(wiersz[4])];
            dodajObcKonstrukcyjne(x,y,pret,nazwa);
        }
        else if(wiersz[0]== "podpora")
        {
            Punkt* punkt = schemat.zwrocPunkty()[stoi(wiersz[1])];
            int typ = stoi(wiersz[2]);
            bool blokX;
            if(wiersz[3] == "1")
                blokX = true;
            else
                blokX = false;
            dodajPodpore(punkt, typ,blokX);
        }

    }




}

void Konstruktor::zapiszSchemat(std::string nazwaPliku)
{

    std::ofstream plik;
    plik.open(nazwaPliku);

    if (plik.good())
    {
        for (auto &pkt : schemat.zwrocPunkty())
        {
            plik << "punkt " << pkt->getNazwa() << " " << pkt->getX() << " " << pkt->getY() << std::endl;

        }
        for (auto &pret : schemat.zwrocPrety())
        {
            plik << "pret ";

            if (pret->zwroc_d() != 0)
            {
                plik << "kolowy " << pret->getNazwa() << " ";
                plik << pret->zwroc_d() << " ";
            }


            else if (pret->zwroc_h() != 0 && pret->zwroc_b() != 0)
            {
                plik << "kwadratowy " << pret->getNazwa() << " ";
                plik << pret->zwroc_h() << " ";
                plik << pret->zwroc_b() << " " << pret->zwroc_h() << " ";
            }


            unsigned int index = 0;
            for (auto &pkt : schemat.zwrocPunkty())
            {
                if (pret->getPPocz() == pkt)
                {
                    plik << index << " ";
                    break;
                }
                index++;
            }
            index = 0;
            for (auto &pkt : schemat.zwrocPunkty())
            {
                if (pret->getPKonc() == pkt)
                {
                    plik << index << " ";
                    break;
                }

                index++;
            }
            plik << pret->zwroc_E() << std::endl;
        }

        for(auto &podp : schemat.zwrocPodpory())
        {
            for(auto &podp : schemat.zwrocPodpory())
            {
                plik << "podpora ";

                int index = 0;
                for (auto &pkt : schemat.zwrocPunkty())
                {
                    if (podp->zwrocPunkt() == pkt)
                    {
                        plik << index << " ";
                        break;
                    }
                    index++;
                }

                if(podp->getTyp() == 0)
                {
                    plik << "0 0";
                }
                else if (podp->getTyp() == 1)
                {
                    plik << "1 ";

                    if(podp->zwrocBlok_x())
                        plik << "1";
                    else
                        plik << "0";
                }
                else
                {
                    plik << "2 0";
                }

                plik << std::endl;
            }

        }

        for (auto wybrane : schemat.zwrocObciazenia())
        {
            if (ObcPunktowe* o = dynamic_cast<ObcPunktowe*>(wybrane))
            {
                plik << "sila " << o->getNazwa() << ' ' << o->wartoscSily_x() << ' ' << o->wartoscSily_y() << ' ';
                int i = 0;
                for (auto wybrany_p : schemat.zwrocPunkty())
                {
                    if (wybrany_p == o->getPunkt())
                        break;
                    ++i;
                }
                plik << i << '\n';
            }
            if (ObcKonstrukcyjne* o = dynamic_cast<ObcKonstrukcyjne*>(wybrane))
            {
                plik << "obcKonstrukcyjne " << o->getNazwa() << ' ' << o->wartoscSily_x() << ' ' << o->wartoscSily_y() << ' ';
                int i = 0;
                for (auto wybrany_p : schemat.zwrocPrety())
                {
                    if (wybrany_p == o->getPret())
                        break;
                    ++i;
                }
                plik << i << '\n';
            }
            if (MomentSkupiony* o = dynamic_cast<MomentSkupiony*>(wybrane))
            {
                plik << "moment " << o->getNazwa() << ' ' << o->wartoscSuly_OBR() << ' ';
                int i = 0;
                for (auto wybrany_p : schemat.zwrocPunkty())
                {
                    if (wybrany_p == o->getPunkt())
                        break;
                    ++i;
                }
                plik << i << '\n';
            }
        }
        plik.close();
    }

}

void Konstruktor::zapiszWyniki(std::string nazwaPliku)
{
    std::ofstream plik;
    plik.open(nazwaPliku);
    if (plik.good())
    {
        plik << "Przemieszczenia punktow:\n";
        for (auto wybrany : schemat.zwrocPunkty())
        {
            plik << wybrany->getNazwa() << ":\n";
            plik << "X:\t" << wybrany->zwrocPrzemieszczenie_x() << "m\n";
            plik << "Y:\t" << wybrany->zwrocPrzemieszczenie_y() << "m\n";
            plik << '\n';
        }
        plik << "Wartosci sily reakcji:\n";
        for (auto wybrane : schemat.zwrocPodpory())
        {
            plik << wybrane->zwrocPunkt()->getNazwa() << ":\n";
            plik << "Wartosc X:\t" << wybrane->zwrocPunkt()->zwrocReakceX() << "N\n";
            plik << "Wartosc Y:\t" << wybrane->zwrocPunkt()->zwrocReakceY() << "N\n";
            plik << "Wartosc Momemntu:\t" << wybrane->zwrocPunkt()->zwrocReakceObr() << "Nm\n";
        }
        plik.close();
    }

}

void Konstruktor::dodajPret(Punkt* pocz, Punkt* konc, double E, double d, std::string nazwa)
{
    Pret* pret = new PretKolowy(pocz, konc, E, d,nazwa);
    schemat.dodajPret(pret);
}

void Konstruktor::dodajPret(Punkt* pocz, Punkt* konc, double E, double b, double h, std::string nazwa)
{
    Pret* pret = new PretProstokotny(pocz, konc, E, b, h, nazwa);
    schemat.dodajPret(pret);
}

void Konstruktor::dodajPunkt(double _x, double _y, std::string _nazwa)
{
    Punkt *nowy = new Punkt(_x, _y, _nazwa);
    schemat.dodajPunkt(nowy);
}

void Konstruktor::dodajPunkt(Punkt* nowy)
{
    schemat.dodajPunkt(nowy);
}

void Konstruktor::dodajPodpore(Punkt* _pozycja, int typeIndex, bool lockedX)
{
    Podpora *nowa;
    char freeAxis;
    if (lockedX) freeAxis = 'Y';
    else freeAxis = 'X';
    switch (typeIndex)
    {
    case 0:
        nowa = new UtwierdzenieStale(_pozycja);
        break;
    case 1:
        nowa = new PodporaRuchoma(_pozycja, freeAxis);
        break;
    case 2:
        nowa = new PodporaStala(_pozycja);

    default:
        break;
    }
    schemat.dodajPodpore(nowa);
}


void Konstruktor::dodajObcPunktowe(double _x, double _y, Punkt* punkt,std::string _nazwa)
{
    Obciazenie* obc = new ObcPunktowe(_x,_y,punkt, _nazwa);
    schemat.dodajObciazenie(obc);

}

void Konstruktor::dodajObcKonstrukcyjne(double _x, double _y, Pret* pret, std::string _nazwa)
{
    Obciazenie* obc = new ObcKonstrukcyjne(_x,_y,pret,_nazwa);
    schemat.dodajObciazenie(obc);

}

void Konstruktor::dodajMomentSkupiony(double war, Punkt* punkt, std::string _nazwa)
{
    Obciazenie* obc = new MomentSkupiony(war,punkt,_nazwa);
    schemat.dodajObciazenie(obc);

}

void Konstruktor::usunObcPunktowe(int index)
{
    if (schemat.zwrocObciazenia().empty())
        return;
    int p_index = -1;
    int i = 0;
    for (auto wybrane : schemat.zwrocObciazenia())
    {
        if (ObcPunktowe* o = dynamic_cast<ObcPunktowe*>(wybrane))
            ++p_index;
        if (index == p_index)
            break;
        ++i;
    }
    if (p_index > -1)
        schemat.kasujWybranaObciazenie(i);
}

void Konstruktor::usunObcKonstrukcyjne(int index)
{
    if (schemat.zwrocObciazenia().empty())
        return;
    int k_index = -1;
    int i = 0;
    for (auto wybrane : schemat.zwrocObciazenia())
    {
        if (ObcKonstrukcyjne* o = dynamic_cast<ObcKonstrukcyjne*>(wybrane))
            ++k_index;
        if (index == k_index)
            break;
        ++i;
    }
    if (k_index > -1)
        schemat.kasujWybranaObciazenie(i);
}

void Konstruktor::usunMomentSkupiony(int index)
{
    if (schemat.zwrocObciazenia().empty())
        return;
    int m_index = -1;
    int i = 0;
    for (auto wybrane : schemat.zwrocObciazenia())
    {
        if (MomentSkupiony* o = dynamic_cast<MomentSkupiony*>(wybrane))
            ++m_index;
        if (index == m_index)
            break;
        ++i;
    }
    if (m_index > -1)
        schemat.kasujWybranaObciazenie(i);
}








