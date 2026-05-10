#include "silnikobliczeniowy.h"

SilnikObliczeniowy::SilnikObliczeniowy()
{

}

void SilnikObliczeniowy::obliczReakcje(double &silaRX, double &silaRY) //na razie bez momentu sily reakcji, poniewaz momenty sil wymagalyby wspolrzednych, a tego jeszcze nie ma
{
    std::vector<double> obX = kontener->getObcX();
    std::vector<double> obY = kontener->getObcY();
	double sumaX, sumaY;

	if (obX.empty()) silaRX = 0;
	else
	{
		for (double fX : obX)
		{
			sumaX += fX;
		}
		silaRX = -sumaX;
	}
	
	if (obY.empty()) silaRY = 0;
	else
	{
		for (double fY : obY)
		{
			sumaY += fY;
		}
		silaRY = -sumaY;
	}

}
