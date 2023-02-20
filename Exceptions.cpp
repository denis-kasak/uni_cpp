#include "Exceptions.h"
using namespace std;

string ValueError::getError()
{
    return "Wert ist ungültig.";
}

string IndexError::getError()
{
    return "Index ist ungültig.";
}