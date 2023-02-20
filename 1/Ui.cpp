#include "Ui.h"
#include <string>
#include <iostream>
using namespace std;

void Ui::setKart(float re, float im){//kartesische Form
	zahl.setKart(re, im);
}

void Ui::setRe(float re){
	float im, reOld;
	zahl.getKart(reOld, im);
	zahl.setKart(re, im);
}

void Ui::setIm(float im){
	float imOld, re;
	zahl.getKart(re, imOld);
	zahl.setKart(re, im);
}

void Ui::setPolar(float betrag, float winkel){//polarform
	zahl.setPolar(betrag, winkel);
}

void Ui::setBetrag(float betrag){
	float betragOld, winkel;
	zahl.getPolar(betragOld, winkel);
	zahl.setPolar(betrag, winkel);
}

void Ui::setWinkel(float winkel){
	float betrag,  winkelOld;
	zahl.getPolar(betrag, winkelOld);
	zahl.setPolar(betrag, winkel);
}


void Ui::printZahl(int mode)
{	
	float re, im;
	zahl.getKart(re, im);
	string strkart = "Kartesische Form: z= " + to_string(re) + " + " + "i" + to_string(im);

	float betrag, winkel;
	zahl.getPolar(betrag, winkel);
	string strpolar = "Polarform: z= " + to_string(betrag) + " (cos(" + to_string(winkel) + ") + i sin(" + to_string(winkel) + ") )";

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
