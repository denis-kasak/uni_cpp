#pragma once
#include <string>
#include "Time.h"

class Messwert
{
    public:
    Time t;
    virtual std::string toString(){return "";};

    protected:
    Messwert(int time):t(time){};
    

};

class Temp : public Messwert
{
    public:
    Temp(float wert, int time);
    float get();
    void set(float wert);
    std::string toString();

    private:
    float wert;
};

class Blitz: public Messwert{
    public:
    Blitz(int num, int time);
    int get();
    void set(int num);
    std::string toString();

    private:
    int num;
};