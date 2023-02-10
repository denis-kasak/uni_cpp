#include "Ui.h"
#include <iostream>
using namespace std;

int main()
{
	Ui zahl;

	float reell = 4;
	float imag = 2;

	zahl.set(reell, imag);
	zahl.printZahl(0);

	double betrag = 4.472136;
	double winkel = 0.463648;

	zahl.set(betrag, winkel);
	zahl.printZahl(0);


	return 0;
}