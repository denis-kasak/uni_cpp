#include <string>
#include <sstream>
#include "Exceptions.h"
using namespace std;

ValueError::ValueError(float invalid)
{
    this->invalid = invalid;
}

string ValueError::getError()
{
    stringstream text;
    text<<"Wert "<<invalid<<" ist ungültig.";
    return text.str();

}

IndexError::IndexError(float invalid)
{
    this->invalid = invalid;
}

string IndexError::getError()
{
    stringstream text;
    text<<"Index "<<invalid<<" ist ungültig.";
    return text.str();

}