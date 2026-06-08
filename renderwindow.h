#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H
#include <QFrame>
#include <QPainter>
#include "kontenersiatki.h"
#include "podpora.h"

/*
WAŻNE!!!!!!!
Do odświeżania rysunku w MainWindow trzeba Używać ui->RenderArea->update();

na razie dałem definiowanie punktów przyłożenia kształtów w double, może dam w Punktach, Podporach i Prętach zeby było ładniej
*/

class RenderWindow : public QFrame
{
    Q_OBJECT
    void rysujPodpore(QPainter &painter, Podpora* podpora);
    void rysujWektor(QPainter &painter, Punkt* punktObciazenia);
    void rysujPoleWektorowe(QPainter &painter, Pret* pretObciazenia);
    void rysujPret(QPainter &painter, Pret* pret);
    double x0 {100}, y0 {300};
    KontenerSiatki* kontener;
public:
    explicit RenderWindow(QWidget *parent = nullptr);
    enum Ksztalt { Brak, PodporaStala, PodporaRuchoma, wektor, poleWektorowe, pret };
    void dodajKsztalty(KontenerSiatki* _kontener) {kontener = _kontener;};

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // RENDERWINDOW_H
