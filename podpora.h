#ifndef PODPORA_H
#define PODPORA_H

class Podpora
{
    bool xBlok {false}, yBlok {false};
public:
    Podpora();
    bool blokujeX() {return xBlok;};
    bool blokujeY() {return yBlok;};
};

#endif // PODPORA_H
