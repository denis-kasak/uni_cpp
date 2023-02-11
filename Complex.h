#pragma once
struct sPolar
{
	float winkel;
	float betrag;
};

struct sKart
{
	float im;
	float re;
};

class Complex //Model
{
private:
	//daten
	sKart kart;
	sPolar polar;

	//alternativ variablen so speichern
	/* float im;
	float re;
	float winkel;
	float betrag; */

	//hilfsfunktionen
	sPolar kartToPolar(sKart kart);
	sKart polarToKart(sPolar polar);

public:
	//getter und setter
	sKart getKart();
	void set(sKart kart);

	sPolar getPolar();
	void set(sPolar polar);
};