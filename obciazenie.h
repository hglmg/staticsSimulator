#ifndef OBCIAZENIE_H
#define OBCIAZENIE_H

class Obciazenie
{
    double wartosc {0}, wartoscX {0}, wartoscY {0};
public:
    Obciazenie();
    Obciazenie(double _wartoscX, double _wartoscY);
    double getWar() {return wartosc;};
};

#endif // OBCIAZENIE_H
