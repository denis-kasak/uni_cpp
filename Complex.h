#pragma once
typedef double winkelT;
typedef double betragT;
typedef float imT;
typedef float reT;

struct sPolar {
	winkelT winkel;
	betragT betrag;
};

struct sKart {
	imT im;
	reT re;
};

class Complex {
private:
	sKart kart;
	sPolar polar;
	sPolar kartToPolar(sKart kart);
	sKart polarToKart(sPolar polar);
	
public:
	Complex(reT re, imT im);
	Complex(betragT betrag, winkelT winkel);

	sKart getKart();
	void set(sKart kart);

	sPolar getPolar();
	void set(sPolar polar);
};