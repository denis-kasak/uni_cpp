#include "Complex.h"
#include <cmath>

Complex::Complex(reT re, imT im)
{
    this->kart.im = im;
    this->kart.re = re;

    sPolar polar = kartToPolar(this->kart);
    this->polar = polar;
}

Complex::Complex(betragT betrag, winkelT winkel)
{
    this->polar.betrag = betrag;
    this->polar.winkel = winkel;

    sKart kart = polarToKart(this->polar);
    this->kart = kart;
}

sKart Complex::getKart()
{
    return this->kart;
}

void Complex::set(sKart kart)
{
    this->kart = kart;
    this->polar = kartToPolar(kart);
}

sPolar Complex::getPolar()
{
    return this->polar;
}

void Complex::set(sPolar polar)
{
    this->polar = polar;
    this->kart = polarToKart(polar);
}

sPolar Complex::kartToPolar(sKart kart)
{
    sPolar polar;
    polar.betrag = sqrt(kart.re * kart.re + kart.im * kart.im);
    polar.winkel = atan2(kart.im, kart.re);

    return polar;
}

sKart Complex::polarToKart(sPolar polar)
{
    sKart kart;
    kart.re = polar.betrag * cos(polar.winkel);
    kart.im = polar.betrag * sin(polar.winkel);
    return kart;
}
