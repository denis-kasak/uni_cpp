#include <sstream>
#include "Kreis.h"
#include "Exceptions.h"
using namespace std;

Kreis::Kreis(float x, float y, float r) : Graf(x, y)
{
    if (r < 0)
    {
        throw new ValueError();
    }
    this->radius = r;
}

string Kreis::toString()
{
    stringstream text;
    text << "Mittelpunkt: " << this->getCenter().toString() << " Radius: " << radius;

    return text.str();
}

float Kreis::getArea()
{
    return M_PI * radius * radius;
}

float Kreis::getUmfang()
{
    return 2 * M_PI * radius;
}

sCoord Kreis::getCenter()
{
    sCoord coord;
    coord.x = this->base.getX();
    coord.y = this->base.getY();
    return coord;
}

float Kreis::getRadius()
{
    return radius;
}

void Kreis::setCenter(float x, float y)
{
    base.setX(x);
    base.setY(y);
}

void Kreis::setRadius(float radius)
{
    if (radius < 0)
    {
        throw new ValueError();
    }
    this->radius = radius;
}