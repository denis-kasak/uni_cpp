#pragma once
#include <string>
#include "Graf.h"

struct sCorners
{
    sCoord c1, c2;
};

class Rechteck : public Graf
{
private:
    Koordinate ecke2;

public:
    Rechteck(float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0) : Graf(x1, y1), ecke2(x2, y2){};
    std::string toString();
    sCorners getCorners(); // holt zwei diagonale Ecken
    void setCorner1(float x, float y);
    void setCorner2(float x, float y);
    float getArea();
    float getUmfang();
};
