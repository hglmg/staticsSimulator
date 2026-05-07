#ifndef PUNKT_H
#define PUNKT_H

class Punkt
{
    double x {0}, y {0};

public:
    Punkt();
    Punkt(double _x, double _y);
    double getX() {return x;};
    double getY() {return y;};
};

#endif // PUNKT_H
