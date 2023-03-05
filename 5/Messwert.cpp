#include <iostream>
#include <sstream>
#include "Messwert.h"
using namespace std;

Temp::Temp(float wert, int time) : Messwert(time)
{
    this->wert = wert;
}

float Temp::get()
{
    return this->wert;
}

void Temp::set(float wert)
{
    this->wert = wert;
}

string Temp::toString()
{
    stringstream text;
    text << t.toString() << " Durchschnittstemperatur= " << this->wert;
    return text.str();
}

Blitz::Blitz(int num, int time) : Messwert(time)
{
    this->num = num;
}

int Blitz::get()
{
    return this->num;
}

void Blitz::set(int wert)
{
    this->num = wert;
}

string Blitz::toString()
{
    stringstream text;
    text << t.toString() << " Anzahl Blitze= " << this->num; //tag 1 anzahl blitze = 3
    return text.str();
}