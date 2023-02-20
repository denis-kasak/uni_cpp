#pragma once

struct sKart{
	float re;
	float im;
};

class Complex //Model
{
private:
	//daten
	float re, im, betrag, winkel;

	//hilfsfunktionen
	void kartToPolar(float re, float im, float &betrag, float &winkel);
	void polarToKart(float &re, float &im, float betrag, float winkel);

public:
	//Konstruktoren
	Complex();
	//Jeweils ein Konstruktor pro Form(Kartesisch und Polar)
	Complex(float re, float im);
	Complex(double betrag, double winkel);
	//alternativer Konstruktor: nicht gewählt, da unübersichtlich. Dafür wären Konstruktoren mit einem Wert auch möglich
	//Complex(int mode, float a, float b); für Kartesisch
	//Complex(int mode, double a, double b); für Polar

	Complex(sKart kart);
	Complex(double betrag);

	void set(Complex c);
	
	//getter und setter
	void getKart(float &re, float &im);
	void setKart(float re, float im);

	void getPolar(float &betrag, float &winkel);
	void setPolar(float betrag, float winkel);
};