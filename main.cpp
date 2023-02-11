#include "Ui.h"
#include <iostream>
using namespace std;

int main()
{
	Ui ui_zahl;

	float reell = 4;
	float imag = 2;

	ui_zahl.set(reell, imag);
	ui_zahl.printZahl(0);

	double betrag = 2;
	double winkel = 1.6;

	ui_zahl.set(betrag, winkel);
	ui_zahl.printZahl(0);


	return 0;
}