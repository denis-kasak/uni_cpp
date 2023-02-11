#include "Ui.h"
#include <string>
#include <iostream>
using namespace std;

void Ui::set(float re, float im){//kartesische Form
	sKart kart;
	kart.re=re;
	kart.im=im;
	zahl.set(kart);
}

void Ui::setRe(float re){
	sKart kart;
	kart.re=re;
	zahl.set(kart);
}

void Ui::setIm(float im){
	sKart kart;
	kart.im=im;
	zahl.set(kart);
}

void Ui::set(double betrag, double winkel){//polarform
	sPolar polar;
	polar.betrag = betrag;
	polar.winkel = winkel;
	zahl.set(polar);
}

void Ui::setBetrag(float betrag){
	sPolar polar;
	polar.betrag = betrag;
	zahl.set(polar);
}

void Ui::setWinkel(float winkel){
	sPolar polar;
	polar.winkel = winkel;
	zahl.set(polar);
}


void Ui::printZahl(int mode)
{
	sKart kart = zahl.getKart();
	string strkart = "Kartesische Form: z= " + to_string(kart.re) + " + " + "i" + to_string(kart.im);

	sPolar polar = zahl.getPolar();
	string strpolar = "Polarform: z= " + to_string(polar.betrag) + " (cos(" + to_string(polar.winkel) + ") + i sin(" + to_string(polar.winkel) + ") )";

	switch (mode)
	{
	case 0: // beide
		cout << strkart << endl;
		cout << strpolar << endl;
		break;
	case 1: // kart
		cout << strkart << endl;
		break;
	case 2: // polar
		cout << strpolar << endl;
		break;
	}
}
