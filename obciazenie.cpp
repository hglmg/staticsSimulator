#include "obciazenie.h"
#include <cmath>

Obciazenie::Obciazenie() {}

Obciazenie::Obciazenie(double _wartoscX, double _wartoscY) {
    wartoscX = _wartoscX;
    wartoscY = _wartoscY;
    wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2));
}
