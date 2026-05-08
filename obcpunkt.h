#ifndef OBCPUNKT_H
#define OBCPUNKT_H

#include "obciazenie.h"
#include "punkt.h"

enum class ObcType//cos zeby je odrozniac, nie ma sensu robic kolejnej klasy imo
{
    sila,
    moment
};

class ObcPunkt : private Obciazenie//klasa do sil i momentow skupionych, aby unikac bledow domyslnie dam sile, potem mozna jakis error handler dac
{
    Punkt* fLok {nullptr};
    ObcType typObciazenia {ObcType::sila};
public:
    ObcPunkt();
    void przylozDoPunktu(Punkt* _fLok) {fLok = _fLok;};
};

#endif // OBCPUNKT_H
