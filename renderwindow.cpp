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
    painter.setPen(QPen(Qt::gray, 3));
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

void RenderWindow::rysujWektor(QPainter &painter, Obciazenie* obc)
{
    painter.setPen(QPen(Qt::red, 2));
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

void RenderWindow::rysujMoment(QPainter &painter, Obciazenie* obc)
{
    painter.setPen(QPen(Qt::green, 2));
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
    painter.setPen(QPen(Qt::blue, 2));
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



void RenderWindow::paintEvent(QPaintEvent* event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // painter.setPen(QPen(Qt::black, 15));  //stare testy
    // painter.drawLine(100, 100, 300, 100);
    // painter.setPen(QPen(Qt::black, 7));
    // painter.drawEllipse(60, 100, 40, 40);
    // painter.drawEllipse(60, 60, 40, 40);


    // painter.setPen(QPen(Qt::black, 5));//tutaj poważniejsze testy rysowania
    // painter.drawLine(100, 400, 400, 400);
    // painter.setPen(QPen(Qt::red, 3));
    // double bok = 30;
    // QPointF punkty[3] = {
    //     QPointF(100, 400),
    //     QPointF(100-(bok/2), 400+(bok*sqrt(3)/2)),
    //     QPointF(100+(bok/2), 400+(bok*sqrt(3)/2))
    // };
    // painter.drawPolygon(punkty, 3);
    // painter.setPen(QPen(Qt::blue, 3));
    // painter.drawEllipse(100-5, 400-5, 10, 10);

    for (Punkt *wybrany : kontener->zwrocPunkty())
    {
        rysujPunkt(painter, wybrany);
    }
    for (Pret *wybrany : kontener->zwrocPrety())
    {
        rysujPret(painter, wybrany);
    }
    for (Podpora *wybrana : kontener->zwrocPodpory())
    {
        rysujPodpore(painter, wybrana);
    }
    for (Obciazenie *wybrane : kontener->zwrocObciazenia())
    {
        if (wybrane->typ == typObciazenia::konstrukcyjne) rysujPoleWektorowe(painter, wybrane);
        if (wybrane->typ == typObciazenia::momentSkupiony) rysujMoment(painter, wybrane);
        if (wybrane->typ == typObciazenia::silaSkupiona) rysujWektor(painter, wybrane);

    }
}
