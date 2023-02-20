#include <sstream>
#include "Koordinate.h"

Koordinate::Koordinate(float x, float y)
{
    this->x = x;
    this->y = y;
}

std::string sCoord::toString()
{
    std::stringstream text;
    text << "x=" << x << " y=" << y;
    return text.str();
}

float Koordinate::getX()
{
    return x;
}

float Koordinate::getY()
{
    return y;
}

void Koordinate::setX(float x)
{
    this->x = x;
}

void Koordinate::setY(float y)
{
    this->y = y;
}