#include "Complex.h"
#include <cmath>

void Complex::getKart(float& re, float& im)
{
    re = this->re;
    im = this->im;
}

void Complex::setKart(float re, float im)
{
    this->re = re;
    this->im = im;

    float betrag, winkel;
    kartToPolar(re, im, betrag, winkel);
    this->betrag = betrag;
    this->winkel = winkel;
}

void Complex::getPolar(float& betrag, float& winkel)
{
    betrag = this->betrag;
    winkel = this->winkel;
}

void Complex::setPolar(float betrag, float winkel)
{
    this->betrag = betrag;
    this->winkel = winkel;

    float re, im;
    polarToKart(re, im, betrag, winkel);
    this->re = re;
    this->im = im;
}

void Complex::kartToPolar(float re, float im, float& betrag, float& winkel)
{
    betrag = sqrt(re * re + im * im);
    winkel = atan2(im, re);
}

void Complex::polarToKart(float& re, float& im, float betrag, float winkel)
{
    re = betrag * cos(winkel);
    im = betrag * sin(winkel);
}
