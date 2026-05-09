#include "obciazeniepunktowe.h"
#include <cmath>

ObciazeniePunktowe::ObciazeniePunktowe() {}

ObciazeniePunktowe::ObciazeniePunktowe(double _wartoscX, double _wartoscY) {
    wartoscX = _wartoscX;
    wartoscY = _wartoscY;
    wartosc = sqrt(pow(_wartoscX, 2) + pow(_wartoscY, 2));
}
