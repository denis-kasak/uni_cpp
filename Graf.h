#pragma once
#include "Koordinate.h"

class Graf
{
protected:
    Koordinate base; // wenn der Konstruktor protected ist, dann kann er nur von sich selbst oder Kindklassen aufgerufen werden => es kann kein grafisches Objekt einfach so erstellt werden (unsinnig)
    Graf() : base(0, 0){};
    Graf(float x, float y) : base(x, y){};

public:
    virtual float getArea(){return 0;};
    //virtual, weil alle graf. Objekte eine Fläche und Umfang haben, aber verschiedene Formeln -> verschiedene Funktionsdefinitionen
    virtual float getUmfang(){return 0;};
};