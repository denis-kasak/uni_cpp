#pragma once
#include <string>

class ValueError
{
    public:
    ValueError(float invalid);
    std::string getError();

    private:
    float invalid;
};

class IndexError
{
    public:
    IndexError(float invalid);
    std::string getError();

    private:
    float invalid;
};