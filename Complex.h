#pragma once
class Complex //Model
{
private:
	//daten
	float re, im, betrag, winkel;

	//hilfsfunktionen
	void kartToPolar(float re, float im, float &betrag, float &winkel);
	void polarToKart(float &re, float &im, float betrag, float winkel);

public:
	//getter und setter
	void getKart(float &re, float &im);
	void setKart(float re, float im);

	void getPolar(float &betrag, float &winkel);
	void setPolar(float betrag, float winkel);
};