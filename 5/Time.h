#pragma once
#include <string>

class Time
{
    private:
    int time;

    public:
    Time(int time);
    int get();
    void set(int time);
    std::string toString();
};