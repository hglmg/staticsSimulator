#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H
#include <QFrame>
#include <QPainter>
#include "kontenersiatki.h"
#include "podpora.h"

/*
WAŻNE!!!!!!!
Do odświeżania rysunku w MainWindow trzeba Używać ui->frame->update();

na razie dałem definiowanie punktów przyłożenia kształtów w double, może dam w Punktach, Podporach i Prętach zeby było ładniej
*/
enum TrybRysowania{edycja, przemieszczenia, reakcje};

class RenderWindow : public QFrame
{
    Q_OBJECT
    void rysujPodpore(QPainter &painter, Podpora* podpora);
    void rysujWektor(QPainter &painter, Obciazenie* obc, Qt::GlobalColor kolor);
    void rysujPoleWektorowe(QPainter &painter, Obciazenie* obc);
    void rysujMoment(QPainter &painter, Obciazenie* obc, Qt::GlobalColor kolor);
    void rysujPret(QPainter &painter, Pret* pret);
    void rysujPunkt(QPainter &painter, Punkt* punkt);
    void rysujSiatke(QPainter &painter);
    double x0 {100}, y0 {300};
    float wspolczynnikSkali {50};
    KontenerSiatki* kontener;
    TrybRysowania trybRysowania{edycja};
    void paintEvent(QPaintEvent *event) override;

    void trybEdycji(QPainter &painter);
    void trybPrzemieszczen(QPainter &painter);
    void trybReakcji(QPainter &painter);

public:
    explicit RenderWindow(QWidget *parent = nullptr);
    enum Ksztalt { Brak, PodporaStala, PodporaRuchoma, wektor, poleWektorowe, pret };
    void dodajKsztalty(KontenerSiatki* _kontener) {kontener = _kontener;};
    void przelaczTryb(TrybRysowania nowyTryb);





};

#endif // RENDERWINDOW_H
