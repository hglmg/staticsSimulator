#include "obciazeniekonstrukcyjne.h"
#include <cmath>

ObciazenieKonstrukcyjne::ObciazenieKonstrukcyjne() {}

ObciazenieKonstrukcyjne::ObciazenieKonstrukcyjne(double _wartoscX, double _wartoscY)
{
    wartoscX = _wartoscX;
    wartoscY = _wartoscY;
    wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2));
}