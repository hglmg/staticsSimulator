#ifndef SILA_H
#define SILA_H
//nowy pomysl - zeby kod byl bardziej modulowy, daj feedback ale bez wulgaryzmow bo nie chce mi sie ich dla studenta wywalac potem
//w zalozeniu pozwoli to oddzielic obciazenia od sil, zeby nie dawac obciazen do podpor, bo to blad logiczny - jednoczesnie bez wplywu na obecny kod konstruktora

class Sila
{
	double wartosc{ 0 }, wartoscX{ 0 }, wartoscY{ 0 };//celowo nie ma punktu przylozenia - ma tylko dzialac jako swobodny wektor, przypisanie do punktow ogarna obciazenia i podpory
public:
	Sila(double _wartoscX, double _wartoscY);
	double getWarX() { return wartoscX; };
	double getWarY() { return wartoscY; };
};



#endif // !SILA_H

