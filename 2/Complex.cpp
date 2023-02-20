#include "Complex.h"
#include <math.h>
#include <cmath>

Complex::Complex() : re(0), im(0), betrag(0), winkel(0) {}

Complex::Complex(sKart kart):re(kart.re), im(kart.im){
    kartToPolar(this->re, this->im, this->betrag, this->winkel);
}

Complex::Complex(double betrag):betrag(betrag)
{
    if(betrag>=0){
        this->winkel = M_PI_4; // pi/4 = 45 Grad
    }
    else{
        this->winkel = -M_PI_4;
    }
    polarToKart(this->re, this->im, this->betrag, this->winkel);
}

Complex::Complex(float re, float im) : re(re), im(im)
{
    kartToPolar(re, im, this->betrag, this->winkel);
}

Complex::Complex(double betrag, double winkel) : betrag(betrag), winkel(winkel)
{
    polarToKart(this->re, this->im, betrag, winkel);
}

void Complex::set(Complex c)
{   
    c.getKart(this->re, this->im);
    c.getPolar(this->betrag, this->winkel);
}

void Complex::getKart(float &re, float &im)
{
    re = this->re;
    im = this->im;
}

void Complex::setKart(float re, float im)
{
    this->re = re;
    this->im = im;

    kartToPolar(re, im, this->betrag, this->winkel);
}

void Complex::getPolar(float &betrag, float &winkel)
{
    betrag = this->betrag;
    winkel = this->winkel;
}

void Complex::setPolar(float betrag, float winkel)
{
    this->betrag = betrag;
    this->winkel = winkel;

    polarToKart(this->re, this->im, betrag, winkel);
}

void Complex::kartToPolar(float re, float im, float &betrag, float &winkel)
{
    betrag = sqrt(re * re + im * im);
    winkel = atan2(im, re);
}

void Complex::polarToKart(float &re, float &im, float betrag, float winkel)
{
    re = betrag * cos(winkel);
    im = betrag * sin(winkel);
}
