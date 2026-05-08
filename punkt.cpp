#include "punkt.h"

Punkt::Punkt()
{

}

Punkt::Punkt(double _x, double _y)
{
    x = _x;
    y = _y;
}

bool Punkt::jestPodpora()
{
    if (podporaPkt == nullptr) return false;
    else return true;
}