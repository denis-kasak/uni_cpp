#pragma once
#include "Complex.h"

class Ui {
private:
	Complex zahl;

public:
	Ui(reT re, imT im);
	Ui(betragT betrag, winkelT winkel);
	
	void set(reT re, imT im);
	void setRe(reT re);
	void setIm(imT im);

	void set(betragT betrag, winkelT winkel);
	void setBetrag(betragT betrag);
	void setWinkel(winkelT winkel);

	void printZahl(int mode);//mode: 0=beide, 1=kart, 2=polar
};