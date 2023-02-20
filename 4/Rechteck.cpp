#include <cmath>
#include <string>
#include <sstream>
#include "Rechteck.h"
using namespace std;

string Rechteck::toString()
{
    stringstream text;
    sCorners c = getCorners();
    text << "Ecke 1: " << c.c1.toString()
         << " Ecke 2: " << c.c2.toString();

    return text.str();
}

float Rechteck::getArea()
{
    return abs((this->base.getX() - ecke2.getX())) * abs((this->base.getY() - ecke2.getY()));
};

float Rechteck::getUmfang()
{
    return abs((this->base.getX() - ecke2.getX())) * 2 + abs((this->base.getY() - ecke2.getY())) * 2;
}

sCorners Rechteck::getCorners()
{
    // holt zwei diagonale Ecken
    sCorners c;
    c.c1.x = this->base.getX();
    c.c1.y = this->base.getY();
    c.c2.x = ecke2.getX();
    c.c2.y = ecke2.getY();
    return c;
}
void Rechteck::setCorner1(float x, float y)
{
    this->base.setX(x);
    this->base.setY(y);
}
void Rechteck::setCorner2(float x, float y)
{
    ecke2.setX(x);
    ecke2.setY(y);
}