#include "main.h"

int main()
{
	Ui ui;

	ui.setKart(4, 2);
	ui.printZahl(0);

	ui.setRe(3);
	ui.printZahl(0);

	ui.setIm(5);
	ui.printZahl(0);

	ui.setPolar(5, 0.8);
	ui.printZahl(0);

	ui.setBetrag(3);
	ui.printZahl(0);

	ui.setWinkel(1.6);
	ui.printZahl(0);

	return 0;
}