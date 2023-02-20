#pragma once
#include <string>

struct sCoord
{
    float x, y;
    std::string toString();
};

class Koordinate
{
private:
    float x, y;

public:
    Koordinate(float x, float y); // Default-Werte sind nicht sinnvoll, da im usecase immer eine startkoordinate für ein grafisches Objekt bekannt ist
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
};