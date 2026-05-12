#include "silnikobliczeniowy.h"

SilnikObliczeniowy::SilnikObliczeniowy()
{

}

void SilnikObliczeniowy::obliczReakcje(double &silaRX, double &silaRY)
{
	double sumaX = 0, sumaY = 0;
	for (Obciazenie* kontrolne : kontener->zwrocObciazenia())
	{
		sumaX += kontrolne->getSila().getWarX();
		sumaY += kontrolne->getSila().getWarY();
	}
	silaRX = -sumaX;
	silaRY = -sumaY;
}
