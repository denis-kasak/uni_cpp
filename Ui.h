#pragma once
#include "Complex.h"

class Ui {
private:
	Complex zahl;

public:
	void setKart(float re, float im);
	void setRe(float re);
	void setIm(float im);

	void setPolar(float betrag, float winkel);
	void setBetrag(float betrag);
	void setWinkel(float winkel);

	void printZahl(int mode);//mode: 0=beide, 1=kart, 2=polar
};