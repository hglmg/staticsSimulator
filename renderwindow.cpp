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
    double xp = pret->getPPocz()->getX() + x0;
    double yp = -pret->getPPocz()->getY() + y0;
    double xk = pret->getPKonc()->getX() + x0;
    double yk = -pret->getPKonc()->getY() + y0;
    painter.drawLine(xp, yp, xk, yk);
}

void RenderWindow::rysujPunkt(QPainter &painter, Punkt* punkt)
{
    painter.setPen(QPen(Qt::gray, 3));
    double radius = 2;
    double x = punkt->getX() + x0;
    double y = -punkt->getY() + y0;
    painter.drawEllipse(x-(radius/2), y-(radius/2), radius, radius);
}

void RenderWindow::rysujPodpore(QPainter &painter, Podpora* podpora)
{
    double radius = 5, bok = 30;
    QPointF linPocz, linKonc, punkty[3];
    painter.setPen(QPen(Qt::darkGray, 2));
    double x = podpora->zwrocPunkt()->getX() + x0;
    double y = -podpora->zwrocPunkt()->getY() + y0;
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

void RenderWindow::rysujWektor(QPainter &painter, Punkt* punktObciazenia)
{//mam problem z ta metoda bo tak pojebany jest ten kod ze nie mam jak odroznic ktory punkt ma obciazeni a ktory nie
    painter.setPen(QPen(Qt::red, 2));
    double radius = 5;
    double x = punktObciazenia->getX() + x0;
    double y = -punktObciazenia->getY() + y0;
    double xI = x - punktObciazenia->zwrocSila_x();
    double yI = y + punktObciazenia->zwrocSila_y();
    painter.drawLine(x, y, xI, yI);
    painter.drawEllipse(x-radius, y-radius, 2*radius, 2*radius);
}

void RenderWindow::rysujPoleWektorowe(QPainter &painter, Pret *pretObciazenia)
{
    painter.setPen(QPen(Qt::blue, 2));
    // double radius = 5;
    // double x1 = pretObciazenia->getPPocz()->getX() + x0;
    // double y1 = pretObciazenia->getPPocz()->getY() + y0;
    // double x2 = pretObciazenia->getPKonc()->getX() + x0;
    // double y2 = pretObciazenia->getPKonc()->getY() + y0;
    //na razie tego nie robie bo nie mam jak dostac sie do wartosci obciazen
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
    // for (Obciazenie *wybrane : kontener->zwrocObciazenia())
    // {
    //     rysujWektor(painter, wybrane);
    // }
}
