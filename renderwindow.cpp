#include "renderwindow.h"

RenderWindow::RenderWindow(QWidget* parent) : QFrame(parent) {}
/*
Dobra wiec troche wyjasnienia jak to dziala:

wspolrzedne sa od lewego gornego rogu, mniej wiecej tak:
*-------> +x
|
|
|
v +y
wiec trzeba ZAWSZE zamieniac znak wspolrzednych y
wspolrzedne srodka to translacja (0,0) na cos blizej srodka po lewej, dla latwiejszego odczytu
ogolnie paintEvent() odpala sie co update widgeta, wiec on musi rysowac wszystko poprzez fory i case'y
*/
void RenderWindow::rysujPret(QPainter &painter, Pret* pret)
{
    painter.setPen(QPen(Qt::black, 3));
    //zamiast pisac to wewnatrz drawLine() napisalem jako osobne lokalne zmienne dla przejrzystosci
    //tak zrobie tez wszedzie indziej zeby dalo sie czytac
    double xp = pret->getPPocz()->getX()*wspolczynnikSkali + x0;
    double yp = -pret->getPPocz()->getY()*wspolczynnikSkali + y0;
    double xk = pret->getPKonc()->getX()*wspolczynnikSkali + x0;
    double yk = -pret->getPKonc()->getY()*wspolczynnikSkali + y0;
    painter.drawLine(xp, yp, xk, yk);
}

void RenderWindow::rysujPunkt(QPainter &painter, Punkt* punkt)
{
    QColor jasnoniebieski(100, 180, 255);
    painter.setPen(QPen(jasnoniebieski, 3));
    double radius = 2;
    double x = punkt->getX()*wspolczynnikSkali + x0;
    double y = -punkt->getY()*wspolczynnikSkali + y0;
    painter.drawEllipse(x-(radius/2), y-(radius/2), radius, radius);
}

void RenderWindow::rysujPodpore(QPainter &painter, Podpora* podpora)
{
    double radius = 5, bok = 30;
    QPointF linPocz, linKonc, punkty[3];
    painter.setPen(QPen(Qt::darkGray, 2));
    double x = podpora->zwrocPunkt()->getX()*wspolczynnikSkali + x0;
    double y = -podpora->zwrocPunkt()->getY()*wspolczynnikSkali + y0;
    painter.drawEllipse(x-radius, y-radius, 2*radius, 2*radius);
    if (podpora->zwrocBlok_x() && !podpora->zwrocBlok_y())
    {
        // QPointF punkty[3] = {  nie wiedziec czemu to nie dziala??? jebac Qt
        //     QPointF(x, y),
        //     QPointF(x-(bok*sqrt(3)/2), y+(bok/2)),
        //     QPointF(x-(bok*sqrt(3)/2), y-(bok/2))
        // };
        punkty[0] = QPointF(x, y);
        punkty[1] = QPointF(x-(bok*sqrt(3)/2), y+(bok/2));
        punkty[2] = QPointF(x-(bok*sqrt(3)/2), y-(bok/2));
        linPocz = QPointF(x-(bok*sqrt(3)/2)-10, y-(bok/2));
        linKonc = QPointF(x-(bok*sqrt(3)/2)-10, y+(bok/2));
        painter.drawLine(linPocz, linKonc);
    }
    if (podpora->zwrocBlok_y() && !podpora->zwrocBlok_x())
    {
        punkty[0] = QPointF(x, y);
        punkty[1] = QPointF(x+(bok*sqrt(3)/2), y+(bok/2));
        punkty[2] = QPointF(x+(bok*sqrt(3)/2), y-(bok/2));
        linPocz = QPointF(x+(bok*sqrt(3)/2)+10, y-(bok/2));
        linKonc = QPointF(x+(bok*sqrt(3)/2)+10, y+(bok/2));
        painter.drawLine(linPocz, linKonc);
    }
    if (podpora->zwrocBlok_x() && podpora->zwrocBlok_y())
    {

        punkty[0] = QPointF(x, y);
        punkty[1] = QPointF(x-(bok/2), y+(bok*sqrt(3)/2));
        punkty[2] = QPointF(x+(bok/2), y+(bok*sqrt(3)/2));
    }
    painter.drawPolygon(punkty, 3);

}

void RenderWindow::rysujWektor(QPainter &painter, Obciazenie* obc, Kolor kolor)
{
    if (kolor == czerwony)
        painter.setPen(QPen(Qt::red, 2));
    else if(kolor == niebieski)
        painter.setPen(QPen(Qt::blue, 2));

    if (obc->getPunkt() == nullptr)//moment warty swietowania - pierwszy w kodzie handler null pointera
    {
        qDebug() << "Blad odczytu obciazenia " << obc->getNazwa() << "\n";
        return;
    }
    double radius = 5;
    double x = obc->getPunkt()->getX()*wspolczynnikSkali + x0;
    double y = -obc->getPunkt()->getY()*wspolczynnikSkali + y0;
    double xI = x - obc->wartoscSily_x()*wspolczynnikSkali;
    double yI = y + obc->wartoscSily_y()*wspolczynnikSkali;
    painter.drawLine(x, y, xI, yI);
    painter.drawEllipse(x-radius, y-radius, 2*radius, 2*radius);
}

void RenderWindow::rysujMoment(QPainter &painter, Obciazenie* obc, Kolor kolor)
{
    if (kolor == czerwony)
        painter.setPen(QPen(Qt::red, 2));
    else if(kolor == niebieski)
        painter.setPen(QPen(Qt::blue, 2));
    if (obc->getPunkt() == nullptr)
    {
        qDebug() << "Blad odczytu obciazenia" << obc->getNazwa() << "\n";
        return;
    }
    double radius = 5;
    double x = obc->getPunkt()->getX()*wspolczynnikSkali + x0;
    double y = -obc->getPunkt()->getY()*wspolczynnikSkali + y0;
    painter.drawPoint(x, y);
    painter.drawEllipse(x, y, 2*radius, 2*radius);
    if (obc->wartoscSuly_OBR() < 0) painter.drawLine(x, y, x+(2*radius), y+(2*radius));
    if (obc->wartoscSuly_OBR() > 0) painter.drawEllipse(x, y, 2*radius*0.75, 2*radius*0.75);
    else return;
}

void RenderWindow::rysujPoleWektorowe(QPainter &painter, Obciazenie* obc)
{
    painter.setPen(QPen(Qt::red, 2));
    if (obc->getPret() == nullptr)
    {
        qDebug() << "Blad odczytu obciazenia" << obc->getNazwa() << "\n";
        return;
    }
    double radius = 5;
    double x1 = obc->getPret()->getPPocz()->getX()*wspolczynnikSkali + x0;
    double y1 = -obc->getPret()->getPPocz()->getY()*wspolczynnikSkali + y0;
    double x2 = obc->getPret()->getPKonc()->getX()*wspolczynnikSkali + x0;
    double y2 = -obc->getPret()->getPKonc()->getY()*wspolczynnikSkali + y0;
    double x1I = x1 - obc->wartoscSily_x()*wspolczynnikSkali;
    double y1I = y1 + obc->wartoscSily_y()*wspolczynnikSkali;
    double x2I = x2 - obc->wartoscSily_x()*wspolczynnikSkali;
    double y2I = y2 + obc->wartoscSily_y()*wspolczynnikSkali;
    painter.drawLine(x1, y1, x1I, y1I);
    painter.drawLine(x2, y2, x2I, y2I);
    painter.drawLine(x1I, y1I, x2I, y2I);
    painter.drawEllipse(x1-radius, y1-radius, 2*radius, 2*radius);
    painter.drawEllipse(x2-radius, y2-radius, 2*radius, 2*radius);
}


void RenderWindow::trybEdycji(QPainter& painter)
{


    painter.setRenderHint(QPainter::Antialiasing);



    for (Pret *wybrany : kontener->zwrocPrety())
    {
        rysujPret(painter, wybrany);
    }
    for (Punkt *wybrany : kontener->zwrocPunkty())
    {
        rysujPunkt(painter, wybrany);
    }
    for (Podpora *wybrana : kontener->zwrocPodpory())
    {
        rysujPodpore(painter, wybrana);
    }
    for (Obciazenie *wybrane : kontener->zwrocObciazenia())
    {
        if (wybrane->typ == typObciazenia::konstrukcyjne) rysujPoleWektorowe(painter, wybrane);
        if (wybrane->typ == typObciazenia::momentSkupiony) rysujMoment(painter, wybrane,czerwony);
        if (wybrane->typ == typObciazenia::silaSkupiona) rysujWektor(painter, wybrane, czerwony);

    }

}

void RenderWindow::trybPrzemieszczen(QPainter& painter)
{
    painter.setRenderHint(QPainter::Antialiasing);

    painter.save();

    painter.setOpacity(0.5);   // stara konstrukcja

    for (Pret *wybrany : kontener->zwrocPrety())
        rysujPret(painter, wybrany);

    for (Punkt *wybrany : kontener->zwrocPunkty())
        rysujPunkt(painter, wybrany);

    painter.restore();

    // nowa konstrukcja
    for (Pret *wybrany : kontener->zwrocPrety())
    {
        double x1 = wybrany->zwrocPunkty()[0]->getX() + wybrany->zwrocPunkty()[0]->zwrocPrzemieszczenie_x();
        double y1 = wybrany->zwrocPunkty()[0]->getY() + wybrany->zwrocPunkty()[0]->zwrocPrzemieszczenie_y();

        double x2 = wybrany->zwrocPunkty()[1]->getX() + wybrany->zwrocPunkty()[1]->zwrocPrzemieszczenie_x();
        double y2 = wybrany->zwrocPunkty()[1]->getY() + wybrany->zwrocPunkty()[1]->zwrocPrzemieszczenie_y();

        Punkt punkt1(x1,y1,"P");
        Punkt punkt2(x2,y2,"P");

        Pret p(&punkt1, &punkt2, "L");
        rysujPret(painter, &p);
        rysujPunkt(painter, &punkt1);
        rysujPunkt(painter, &punkt2);

    }

    for (Podpora *wybrana : kontener->zwrocPodpory())
    {
        rysujPodpore(painter, wybrana);
    }
}

void RenderWindow::trybReakcji(QPainter &painter)
{
    for (Pret *wybrany : kontener->zwrocPrety())
    {
        rysujPret(painter, wybrany);
    }
    for (Punkt *wybrany : kontener->zwrocPunkty())
    {
        rysujPunkt(painter, wybrany);
    }
    for (Podpora *wybrana : kontener->zwrocPodpory())
    {
        rysujPodpore(painter, wybrana);
        double x = wybrana->zwrocPunkt()->zwrocReakceX();
        double y =  wybrana->zwrocPunkt()->zwrocReakceY();
        double obr =  wybrana->zwrocPunkt()->zwrocReakceObr();

        ObcPunktowe reakcjaX(x, 0 ,wybrana->zwrocPunkt(), "R");
        ObcPunktowe reakcjaY(0, y ,wybrana->zwrocPunkt(), "R");
        MomentSkupiony mom(obr, wybrana->zwrocPunkt(),"M");

        rysujWektor(painter, &reakcjaX, niebieski);
        rysujWektor(painter, &reakcjaY, niebieski);
        rysujMoment(painter, &mom, niebieski);


    }

}



void RenderWindow::paintEvent(QPaintEvent* event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    switch (trybRysowania)
    {
    case edycja:
    {
        trybEdycji(painter);
        break;
    }
    case przemieszczenia:
    {
        trybPrzemieszczen(painter);
        break;
    }

    case reakcje:
    {
        trybReakcji(painter);
        break;
    }
    default:
        break;

    }
}

void RenderWindow::przelaczTryb(TrybRysowania nowyTryb)
{
    trybRysowania = nowyTryb;
    update();
}














