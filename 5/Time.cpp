#include <string>
#include <sstream>
#include "Time.h"
using namespace std;

Time::Time(int time)
{
    this->time=time;
}

int Time::get()
{
    return this->time;
}

void Time::set(int time)
{
    this->time = time;
}

string Time::toString()
{
    stringstream text;
    text<<"Tag "<<this->time;
    return text.str();
}