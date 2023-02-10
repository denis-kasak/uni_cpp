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

class Complex
{
private:
	sKart kart;
	sPolar polar;
	sPolar kartToPolar(sKart kart);
	sKart polarToKart(sPolar polar);

public:
	sKart getKart();
	void set(sKart kart);

	sPolar getPolar();
	void set(sPolar polar);
};