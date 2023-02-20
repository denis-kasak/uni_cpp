#pragma once
#include <math.h>
#include <string>
#include "Graf.h"

class Kreis : public Graf
{
private:
    float radius;

public:
    Kreis(float x=0, float y=0, float r=0);
    std::string toString();
    sCoord getCenter();
    float getRadius();
    void setCenter(float x, float y);
    void setRadius(float radius);
    float getArea();
    float getUmfang();
};